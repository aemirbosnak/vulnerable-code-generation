//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>

// Function to check if given year is a leap year
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

// Function to calculate number of days in given month and year
int daysInMonth(int month, int year)
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

// Function to convert date in natural language to standard date format
void convertDate(char date[])
{
    int day, month, year;
    sscanf(date, "%d %s %d", &day, month, &year);
    
    // Convert month string to month number
    if (strcmp(month, "January") == 0)
        month = 1;
    else if (strcmp(month, "February") == 0)
        month = 2;
    else if (strcmp(month, "March") == 0)
        month = 3;
    else if (strcmp(month, "April") == 0)
        month = 4;
    else if (strcmp(month, "May") == 0)
        month = 5;
    else if (strcmp(month, "June") == 0)
        month = 6;
    else if (strcmp(month, "July") == 0)
        month = 7;
    else if (strcmp(month, "August") == 0)
        month = 8;
    else if (strcmp(month, "September") == 0)
        month = 9;
    else if (strcmp(month, "October") == 0)
        month = 10;
    else if (strcmp(month, "November") == 0)
        month = 11;
    else if (strcmp(month, "December") == 0)
        month = 12;
    
    // Calculate number of days passed since Jan 1, 0000
    int numDays = 0;
    for (int i = 0; i < year; i++)
    {
        if (isLeapYear(i))
            numDays += 366;
        else
            numDays += 365;
    }
    for (int i = 1; i < month; i++)
        numDays += daysInMonth(i, year);
    numDays += day;
    
    // Convert number of days passed to standard date format
    year = 1;
    while (numDays > 365)
    {
        if (isLeapYear(year))
            numDays -= 366;
        else
            numDays -= 365;
        year++;
    }
    month = 1;
    while (numDays > daysInMonth(month, year))
    {
        numDays -= daysInMonth(month, year);
        month++;
    }
    day = numDays;
    
    // Print the standard date format
    printf("%02d/%02d/%d", day, month, year);
}

int main()
{
    char date[20];
    printf("Enter date in natural language (ex: 5th July 2022): ");
    fgets(date, sizeof(date), stdin);
    
    // Remove the trailing newline character
    date[strcspn(date, "\n")] = 0;
    
    // Convert the natural language date to standard date format
    convertDate(date);
    
    return 0;
}