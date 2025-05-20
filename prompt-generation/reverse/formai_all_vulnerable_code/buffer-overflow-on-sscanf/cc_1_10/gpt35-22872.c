//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to check if given year is a leap year or not */
int isLeapYear(int year)
{
    /* A year is a leap year if it is divisible by 4 and not divisible by 100, or if it is divisible by 400 */
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

/* Function to get the number of days in a month */
int getNumDaysInMonth(int month, int year)
{
    int numDays;

    /* Check if month is February and leap year is involved */
    if (month == 2 && isLeapYear(year))
        numDays = 29;
    else if (month == 2)
        numDays = 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        numDays = 30;
    else
        numDays = 31;

    return numDays;
}

/* Function to convert a given date from natural language form to numerical */
void convertToNumericalDate(char* sentence)
{
    int day, month, year;
    char monthName[10];
    sscanf(sentence, "%d %s %d", &day, monthName, &year);

    /* Convert month name to month number */
    if (strcmp(monthName, "January") == 0)
        month = 1;
    else if (strcmp(monthName, "February") == 0)
        month = 2;
    else if (strcmp(monthName, "March") == 0)
        month = 3;
    else if (strcmp(monthName, "April") == 0)
        month = 4;
    else if (strcmp(monthName, "May") == 0)
        month = 5;
    else if (strcmp(monthName, "June") == 0)
        month = 6;
    else if (strcmp(monthName, "July") == 0)
        month = 7;
    else if (strcmp(monthName, "August") == 0)
        month = 8;
    else if (strcmp(monthName, "September") == 0)
        month = 9;
    else if (strcmp(monthName, "October") == 0)
        month = 10;
    else if (strcmp(monthName, "November") == 0)
        month = 11;
    else if (strcmp(monthName, "December") == 0)
        month = 12;
    else
    {
        printf("Invalid date format. Please enter date in natural language format (e.g. 'March 14, 2022').");
        return;
    }

    /* Validate day */
    if (day <= 0 || day > getNumDaysInMonth(month, year))
    {
        printf("Invalid day. Please enter a valid day for the given month and year.");
        return;
    }

    printf("The numerical date is: %02d/%02d/%d", month, day, year);
}

int main()
{
    char sentence[100];

    /* Get input in natural language form */
    printf("Enter date in natural language format (e.g. 'March 14, 2022'): ");
    fgets(sentence, sizeof(sentence), stdin);

    /* Remove newline character from input */
    sentence[strcspn(sentence, "\n")] = '\0';

    /* Convert to numerical date and print */
    convertToNumericalDate(sentence);

    return 0;
}