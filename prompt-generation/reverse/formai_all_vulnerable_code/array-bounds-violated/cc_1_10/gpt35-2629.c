//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: automated
#include <stdio.h>
#include <string.h>

/*
This program converts natural language dates to standard date format.
Valid input example: "Today is October twenty third, twenty twenty one."
Output example: "10/23/2021"
*/

int main() {
	
	// Initialize arrays to hold month names and their corresponding numbers
	char* months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int month_nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	
	// Initialize arrays to hold numbers and their corresponding suffixes
	char* num_suffixes[] = {"th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th"};
	int num_suffix_nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	// Initialize variables
	char input[100];
	char month[20];
	int month_num;
	int day;
	int year;
	
	// Get input from user
	printf("Enter a natural language date: ");
	fgets(input, 100, stdin);
	
	// Search for month name in input
	for(int i = 1; i <= 12; i++)
	{
		if(strstr(input, months[i]) != NULL)
		{
			month_num = month_nums[i];
			strcpy(month, months[i]);
			break;
		}
	}
	
	// Find day in input
	char* day_str = strtok(input, " ");
	while(day_str != NULL)
	{
		if(sscanf(day_str, "%d", &day) == 1)
		{
			break;
		}
		day_str = strtok(NULL, " ");
	}
	
	// Get day suffix
	int day_suffix_num = day % 10;
	char* day_suffix = num_suffixes[day_suffix_num];
	
	// Find year in input
	char* year_str = strtok(NULL, " ");
	year_str = strtok(NULL, " ");
	sscanf(year_str, "%d", &year);
	
	// Print output in standard date format
	printf("%d/%d/%d\n", month_num, day, year);
	
	return 0;
}