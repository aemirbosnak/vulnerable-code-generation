//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include <stdio.h>
#include <stdbool.h>

// Function to check if the given year is a leap year or not
bool isLeapYear(int year)
{
    if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
        return true;

    return false;
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year)
{
    // January
    if (month == 1)
        return 31;

    // February
    if (month == 2)
    {
        if (isLeapYear(year))
            return 29;
        else
            return 28;
    }

    // March
    if (month == 3)
        return 31;

    // April
    if (month == 4)
        return 30;

    // May
    if (month == 5)
        return 31;

    // June
    if (month == 6)
        return 30;

    // July
    if (month == 7)
        return 31;

    // August
    if (month == 8)
        return 31;

    // September
    if (month == 9)
        return 30;

    // October
    if (month == 10)
        return 31;

    // November
    if (month == 11)
        return 30;

    // December
    if (month == 12)
        return 31;

    return 0;
}

// Function to convert the given date to number of days since 1/1/1 AD
int convertDateToDays(int d, int m, int y)
{
    int days = 0;
    int i;

    // Add the number of days in the previous months
    for (i = 1; i < m; i++)
        days += getDaysInMonth(i, y);

    // Add the number of days in the current month
    days += d;

    // Add the number of days in the previous years
    for (i = 1; i < y; i++)
    {
        if (isLeapYear(i))
            days += 366;
        else
            days += 365;
    }

    return days;
}

// Function to convert the given number of days since 1/1/1 AD to a date
void convertDaysToDate(int days, int *d, int *m, int *y)
{
    int i;

    // Calculate the year
    for (i = 1; days > 365; i++)
    {
        if (isLeapYear(i))
            days -= 366;
        else
            days -= 365;
    }
    *y = i;

    // Calculate the month
    for (i = 1; days > getDaysInMonth(i, *y); i++)
        days -= getDaysInMonth(i, *y);
    *m = i;

    // Calculate the day
    *d = days;
}

// Main function to test the program
int main()
{
    int d, m, y, days;

    // Get the date from the user
    printf("Enter the date in dd/mm/yyyy format: ");
    scanf("%d/%d/%d", &d, &m, &y);

    // Convert the date to number of days
    days = convertDateToDays(d, m, y);

    // Display the number of days since 1/1/1 AD
    printf("The number of days since 1/1/1 AD is: %d\n", days);

    // Convert the number of days to a date
    convertDaysToDate(days, &d, &m, &y);

    // Display the converted date
    printf("The date is: %02d/%02d/%04d\n", d, m, y);

    return 0;
}