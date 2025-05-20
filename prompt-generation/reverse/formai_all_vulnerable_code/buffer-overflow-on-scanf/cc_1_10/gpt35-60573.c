//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>

// function to check if a given year is a leap year or not
int isLeapYear(int year)
{
    if(year % 400 == 0)
        return 1;
    if(year % 100 == 0)
        return 0;
    if(year % 4 == 0)
        return 1;
    return 0;
}

// function to get the number of days in a given month
int getDaysInMonth(int month, int year)
{
    int days;
    switch(month)
    {
        case 1:
            days = 31;
            break;
        case 2:
            if(isLeapYear(year))
                days = 29;
            else
                days = 28;
            break;
        case 3:
            days = 31;
            break;
        case 4:
            days = 30;
            break;
        case 5:
            days = 31;
            break;
        case 6:
            days = 30;
            break;
        case 7:
            days = 31;
            break;
        case 8:
            days = 31;
            break;
        case 9:
            days = 30;
            break;
        case 10:
            days = 31;
            break;
        case 11:
            days = 30;
            break;
        case 12:
            days = 31;
            break;
        default:
            days = -1;
            break;
    }
    return days;
}

// function to convert the given date to days since January 1, 1900
int convertToDays(int day, int month, int year)
{
    int days = 0;
    int i;

    // sum up the days from 1900 to the previous year
    for(i = 1900; i < year; i++)
    {
        if(isLeapYear(i))
            days += 366;
        else
            days += 365;
    }

    // sum up the days from January 1 to the previous month
    for(i = 1; i < month; i++)
    {
        days += getDaysInMonth(i, year);
    }

    // add the current day
    days += day;

    return days;
}

// function to convert the number of days since January 1, 1900 to a date
void convertToDate(int days, int *day, int *month, int *year)
{
    int i;
    *day = days;
    *year = 1900;

    // find the year
    while(1)
    {
        if(isLeapYear(*year))
        {
            if(*day >= 366)
            {
                *day -= 366;
                (*year)++;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(*day >= 365)
            {
                *day -= 365;
                (*year)++;
            }
            else
            {
                break;
            }
        }
    }

    // find the month
    for(i = 1; i <= 12; i++)
    {
        int daysInMonth = getDaysInMonth(i, *year);
        if(*day >= daysInMonth)
        {
            *day -= daysInMonth;
            *month = i;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int day, month, year;

    // get the input from the user
    printf("Enter a date in the format dd/mm/yyyy: ");
    scanf("%d/%d/%d", &day, &month, &year);

    // convert the date to days
    int days = convertToDays(day, month, year);

    // output the number of days
    printf("The date %d/%d/%d is %d days since January 1, 1900.\n", day, month, year, days);

    // convert the number of days back to a date
    int newDay, newMonth, newYear;
    convertToDate(days, &newDay, &newMonth, &newYear);

    // output the new date
    printf("%d days since January 1, 1900 is %d/%d/%d.\n", days, newDay, newMonth, newYear);

    return 0;
}