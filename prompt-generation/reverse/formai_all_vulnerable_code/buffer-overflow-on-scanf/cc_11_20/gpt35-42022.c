//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <string.h>

// Function to validate the input date in natural language format
int validate_date(char *month, int day, int year)
{
    // Check if month input is valid
    if (strcmp(month, "January") != 0 && strcmp(month, "February") != 0 && strcmp(month, "March") != 0 && strcmp(month, "April") != 0 && strcmp(month, "May") != 0 && strcmp(month, "June") != 0 && strcmp(month, "July") != 0 && strcmp(month, "August") != 0 && strcmp(month, "September") != 0 && strcmp(month, "October") != 0 && strcmp(month, "November") != 0 && strcmp(month, "December") != 0)
    {
        printf("Invalid month input. Please enter a valid month in natural language format (e.g. January).\n");
        return 0;
    }

    // Check if day input is valid for the given month
    if ((strcmp(month, "January") == 0 || strcmp(month, "March") == 0 || strcmp(month, "May") == 0 || strcmp(month, "July") == 0 || strcmp(month, "August") == 0 || strcmp(month, "October") == 0 || strcmp(month, "December") == 0) && (day < 1 || day > 31))
    {
        printf("Invalid day input. Please enter a valid day for %s.\n", month);
        return 0;
    }
    else if ((strcmp(month, "April") == 0 || strcmp(month, "June") == 0 || strcmp(month, "September") == 0 || strcmp(month, "November") == 0) && (day < 1 || day > 30))
    {
        printf("Invalid day input. Please enter a valid day for %s.\n", month);
        return 0;
    }
    else if (strcmp(month, "February") == 0)
    {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            if (day < 1 || day > 29)
            {
                printf("Invalid day input. Please enter a valid day for %s.\n", month);
                return 0;
            }
        }
        else
        {
            if (day < 1 || day > 28)
            {
                printf("Invalid day input. Please enter a valid day for %s.\n", month);
                return 0;
            }
        }
    }

    // Check if year input is valid
    if (year < 1)
    {
        printf("Invalid year input. Please enter a valid year.\n");
        return 0;
    }

    return 1; // Return 1 if input date is valid
}

// Function to convert the input date to standard format (YYYY-MM-DD)
void convert_to_standard(char *month, int day, int year, char *standard_date)
{
    // Convert month input to numeric format
    int month_num;
    if (strcmp(month, "January") == 0)
        month_num = 1;
    else if (strcmp(month, "February") == 0)
        month_num = 2;
    else if (strcmp(month, "March") == 0)
        month_num = 3;
    else if (strcmp(month, "April") == 0)
        month_num = 4;
    else if (strcmp(month, "May") == 0)
        month_num = 5;
    else if (strcmp(month, "June") == 0)
        month_num = 6;
    else if (strcmp(month, "July") == 0)
        month_num = 7;
    else if (strcmp(month, "August") == 0)
        month_num = 8;
    else if (strcmp(month, "September") == 0)
        month_num = 9;
    else if (strcmp(month, "October") == 0)
        month_num = 10;
    else if (strcmp(month, "November") == 0)
        month_num = 11;
    else if (strcmp(month, "December") == 0)
        month_num = 12;

    // Build the standard format date string
    sprintf(standard_date, "%d-%02d-%02d", year, month_num, day);
}

// Main function to get input from user and convert the date to standard format
int main()
{
    char month[10];
    int day, year;

    // Get input from user
    printf("Please enter a date in natural language format (e.g. January 1, 2022): ");
    scanf("%s %d, %d", month, &day, &year);

    // Check if date input is valid
    if (validate_date(month, day, year))
    {
        char standard_date[11]; // Initialize standard format date string
        convert_to_standard(month, day, year, standard_date); // Convert input date to standard format
        printf("Standard format date: %s\n", standard_date);
    }

    return 0;
}