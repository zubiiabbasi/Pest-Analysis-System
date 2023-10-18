#include <iostream>
using namespace std;
int** create_array(int** table, int row, int column);
int field_no(int field);
void insert_value(int** table, int column, int& count, int field);
void dell_value(int** table, int column, int& count, int field);
void top_two_values(int** table, int row, int column, int& count);
float average_data(int** table, int row, int column, int& count);
int max_field_score(int** table, int row, int column, int& max);
void display(int** table, int row, int column);
int main()
{
	cout << "     ----------------------------------------------   Pest analysis   -------------------------------------------------" << endl;
	int row = 4;
	int column = 6;
	int** table = 0;
	table = create_array(table, row, column);
	int count = 0;
	int choice = 0;
	int field = 0;
	do
	{
		cout << endl;
		cout << "1. Insert a new value in any field" << endl;
		cout << "2. Count the number of filled location in whole table" << endl;
		cout << "3. Delete any filled value from any filed" << endl;
		cout << "4. Find and display the top two values in whole table" << endl;
		cout << "5. Calculate Average test score of all the field values" << endl;
		cout << "6. Tell the field no having maximum success scores value" << endl;
		cout << "7. Exit program" << endl;
		cout << endl;
		cout << "Enter your desire choice (from 1 - 7): ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
		{
			cout << "Enter the field number in you want to insert number: ";
			field = field_no(field);
			insert_value(table, column, count, field);
			display(table, row, column);
			break;
		}
		case 2:
		{
			cout << "Total number of filled location: " << count << endl;
			break;
		}
		case 3:
		{
			cout << "Enter the field number in you want to delete number: ";
			field = field_no(field);
			dell_value(table, column, count, field);
			display(table, row, column);
			break;
		}
		case 4:
		{
			top_two_values(table, row, column, count);
			break;
		}
		case 5:
		{
			float average = 0;
			average = average_data(table, row, column, count);
			cout << "Average test score of all the field values: " << average << endl;
			break;
		}
		case 6:
		{
			int max_field = 0, max = 0;
			max_field = max_field_score(table, row, column, max);
			cout << max_field << " field no having maximum success scores value: " << max << endl;
			break;
		}
		case 7:
		{
			cout << "Thank you" << endl;
			break;
		}
		default:
		{
			cout << "You have enter the invalid number" << endl;
		}
		}
	} while (choice != 7);
	return 0;
}
int** create_array(int** table, int row, int column)
{
	table = new int* [row];
	for (int i = 0; i < row; i++)
	{
		table[i] = new int[column];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			table[i][j] = -1;
		}
	}
	return table;
}
void insert_value(int** table, int column, int& count, int field)
{
	int new_value = 0;
	bool flag = 0;
	cout << "Insert new value: ";
	cin >> new_value;
	for (int j = 0; j < column; j++)
	{
		if (table[field][j] == -1)
		{
			table[field][j] = new_value;
			count++;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "No empty location available" << endl;
	}
	return;
}
int field_no(int field)
{
	cin >> field;
	while (field > 4 || field < 1)
	{
		cout << "Please re-enter field number again from 1 - 4: ";
		cin >> field;
	}
	field = field - 1;
	return field;
}
void dell_value(int** table, int column, int& count, int field)
{
	bool flag2 = 0;
	int dell = 0;
	cout << "Enter the number you want to delete: ";
	cin >> dell;
	for (int j = 0; j < column; j++)
	{
		if (table[field][j] == dell)
		{
			table[field][j] = -1;
			cout << "Number has been deleted successfully" << endl;
			flag2 = 1;
			count--;
			break;
		}
	}
	if (flag2 == 0)
	{
		cout << "Number not found in this field";
	}
	return;
}
void top_two_values(int** table, int row, int column, int& count)
{
	int frequency = 0;
	int max_count = 0, max_value = 0;
	int second_max = 0, second_count = 0;
	int* check = new int[count];
	int k = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (table[i][j] != -1)
			{
				check[k] = table[i][j];
				k++;
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		frequency = 1;
		if (check[i] != -1)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (check[i] == check[j])
				{
					frequency++;
					check[j] = -1;
				}
			}
			if (frequency > max_count)
			{
				second_max = max_value;
				second_count = max_count;
				max_count = frequency;
				max_value = check[i];
			}
			else if (frequency > second_count && frequency < max_count)
			{
				second_count = frequency;
				second_max = check[i];
			}
		}
	}
	cout << max_value << " has maximum occurrence of " << max_count << " times" << endl;
	cout << second_max << " has maximum occurrence of " << second_count << " times" << endl;
	delete[]check;
	check = 0;
	return;
}
float average_data(int** table, int row, int column, int& count)
{
	int sum = 0;
	float average = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (table[i][j] != -1)
			{
				sum = sum + table[i][j];
			}
		}
	}
	average = (float)sum / count;
	return average;
}
int max_field_score(int** table, int row, int column, int& max)
{
	int sum2 = 0;
	int max_field = 0;
	for (int i = 0; i < row; i++)
	{
		sum2 = 0;
		for (int j = 0; j < column; j++)
		{
			if (table[i][j] != -1)
			{
				sum2 = sum2 + table[i][j];
			}
		}
		if (max < sum2)
		{
			max = sum2;
			max_field = i + 1;
		}
	}
	return max_field;
}
void display(int** table, int row, int column)
{
	cout << endl;
	cout << "Table : " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	return;
}