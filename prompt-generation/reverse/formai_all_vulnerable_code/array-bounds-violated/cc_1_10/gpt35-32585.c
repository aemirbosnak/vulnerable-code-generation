//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given year is leap year or not
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

// Function to get the number of days in a given month
int getDaysInMonth(int month, int year)
{
    if (month == 2)
    {
        if (isLeapYear(year))
            return 29;
        else
            return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}

// Function to convert a given date from a natural language format to a numerical date format
void dateConverter(char *date)
{
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month, day, year;
    char *p;

    // Extract month, day, and year from the input string
    p = strtok(date, " ");
    month = -1;
    for (int i = 0; i < 12; i++)
    {
        if (strcmp(p, months[i]) == 0)
        {
            month = i + 1;
            break;
        }
    }

    if (month == -1)
    {
        printf("Invalid month name.\n");
        return;
    }

    p = strtok(NULL, " ");
    day = atoi(p);

    p = strtok(NULL, " ");
    year = atoi(p);

    if (day > getDaysInMonth(month, year))
    {
        printf("Invalid day.\n");
        return;
    }

    printf("%02d/%02d/%04d\n", month, day, year);
}

// Driver program
int main()
{
    char date[100];

    printf("Enter a date in natural language format (e.g. January 1 2022): ");
    fgets(date, 100, stdin);

    // Remove trailing newline character from the input string
    date[strlen(date) - 1] = '\0';

    // Call the dateConverter function to convert the date to numerical format
    dateConverter(date);

    return 0;
}