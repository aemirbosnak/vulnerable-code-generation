//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DAY_IN_YEAR 365
#define DAYS_IN_LEAP_YEAR 366

int getDaysInMonth(int month, int year);
int isLeapYear(int year);
int calculateJulianDate(int day, int month, int year);
void convertJulianDateToGregorian(int julianDate, int *day, int *month, int *year);

int main()
{
    int day, month, year;
    int julianDate;

    //Get date from the user
    printf("Enter date in format dd/mm/yyyy: ");
    scanf("%d/%d/%d", &day, &month, &year);

    //Convert the date to julian date
    julianDate = calculateJulianDate(day, month, year);
    printf("Julian Date: %d\n", julianDate);

    //Convert the julian date back to Gregorian date
    convertJulianDateToGregorian(julianDate, &day, &month, &year);
    printf("Gregorian Date: %d/%d/%d\n", day, month, year);

    return 0;
}

/**
 * Calculate the julian date for a given date.
 */
int calculateJulianDate(int day, int month, int year)
{
    int julianDate = 0;

    //Add up the days for all the years.
    for (int i = 1; i < year; i++)
    {
        if (isLeapYear(i))
            julianDate += DAYS_IN_LEAP_YEAR;
        else
            julianDate += DAY_IN_YEAR;
    }

    //Add up the days for all the months.
    for (int i = 1; i < month; i++)
    {
        julianDate += getDaysInMonth(i, year);
    }

    //Add the days of the given month.
    julianDate += day;

    return julianDate;
}

/**
 * Convert a julian date to Gregorian date.
 */
void convertJulianDateToGregorian(int julianDate, int *day, int *month, int *year)
{
    int daysInYear;
    int daysInMonth;

    *year = julianDate / DAY_IN_YEAR;
    daysInYear = isLeapYear(*year) ? DAYS_IN_LEAP_YEAR : DAY_IN_YEAR;

    while (julianDate > daysInYear)
    {
        julianDate -= daysInYear;
        (*year)++;
        daysInYear = isLeapYear(*year) ? DAYS_IN_LEAP_YEAR : DAY_IN_YEAR;
    }

    *month = 1;
    while (julianDate > getDaysInMonth(*month, *year))
    {
        julianDate -= getDaysInMonth(*month, *year);
        (*month)++;
    }

    *day = julianDate;
}

/**
 * Determine if the given year is a leap year.
 */
int isLeapYear(int year)
{
    if (year % 4 != 0)
        return 0;
    else if (year % 100 != 0)
        return 1;
    else if (year % 400 != 0)
        return 0;

    return 1;
}

/**
 * Get the number of days in the given month of the year.
 */
int getDaysInMonth(int month, int year)
{
    switch (month)
    {
    case 2:
        return isLeapYear(year) ? 29 : 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}