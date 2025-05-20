//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a given year is a leap year
int isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return 1;
            else
                return 0;
        }
        else
            return 1;
    }
    else
        return 0;
}

// Function to get the number of days in a given month of a given year
int getNumDays(int month, int year)
{
    int days;
    if (month == 2)
    {
        if (isLeapYear(year))
            days = 29;
        else
            days = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else
        days = 31;
    return days;
}

// Function to convert a date in natural language to standard format (YYYY-MM-DD)
void convertDate(char *inputDate, char *outputDate)
{
    char *monthNames[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char *tokens[4];
    int month = 0, day = 0, year = 0;
    int count = 0;

    // Parse the input date using strtok
    char *token = strtok(inputDate, " ");
    while (token != NULL)
    {
        tokens[count++] = token;
        token = strtok(NULL, " ");
    }

    // Determine the month from the input
    for (int i = 1; i <= 12; i++)
    {
        if (strcasecmp(tokens[0], monthNames[i]) == 0)
        {
            month = i;
            break;
        }
    }

    // Determine the day and year from the input
    sscanf(tokens[1], "%d,", &day);
    sscanf(tokens[2], "%d", &year);

    // Determine the number of days in the given month of the given year
    int numDays = getNumDays(month, year);

    // If the given day is larger than the number of days in the given month, set it to the last day of the month
    if (day > numDays)
        day = numDays;

    // Format the output string
    sprintf(outputDate, "%04d-%02d-%02d", year, month, day);
}

int main()
{
    char inputDate[50], outputDate[11];

    // Get the date input from the user
    printf("Enter a date in natural language: ");
    fgets(inputDate, 50, stdin);

    // Convert the input date to standard format
    convertDate(inputDate, outputDate);

    // Print the converted date
    printf("The converted date is: %s\n", outputDate);

    return 0;
}