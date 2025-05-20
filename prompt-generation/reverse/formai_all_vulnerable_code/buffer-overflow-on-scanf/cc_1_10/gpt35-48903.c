//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
#include <stdio.h>

// Function declaration
int convertToDays(int month, int day, int year);

int main()
{
    int month, day, year, days;

    // Get user input
    printf("Enter date in natural language (e.g. January 1st, 2022): ");
    scanf("%s %d, %d", month, &day, &year);

    // Convert date to number of days since January 1st, 2000
    days = convertToDays(month, day, year);

    // Output number of days
    printf("Number of days since January 1st, 2000: %d", days);

    return 0;
}

// Function definition
int convertToDays(int month, int day, int year)
{
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    int i;

    // Add up days for each year since 2000
    for (i = 2000; i < year; i++)
    {
        // Leap year
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
            days += 366;
        // Regular year
        else
            days += 365;
    }

    // Special cases for leap year
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        monthDays[1] = 29;

    // Add up days for each month
    for (i = 0; i < month - 1; i++)
        days += monthDays[i];

    // Add remaining days
    days += day;

    return days;
}