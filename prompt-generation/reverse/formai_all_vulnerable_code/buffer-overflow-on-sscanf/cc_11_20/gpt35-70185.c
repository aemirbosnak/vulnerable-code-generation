//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: peaceful
#include <stdio.h>

// function to check if a given year is a leap year or not
int isLeapYear(int year)
{
    if(year%400 == 0)
        return 1;
    if(year%100 == 0)
        return 0;
    if(year%4 == 0)
        return 1;
    return 0;
}

// function to get the number of days in a given month
int getDaysInMonth(int month, int year)
{
    switch(month)
    {
        case 1:
            return 31;
        case 2:
            if(isLeapYear(year))
                return 29;
            else
                return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }
}

// function to convert a given date in natural language to a numeric date in dd/mm/yyyy format
void convertDate(char date[])
{
    // variables to store the day, month and year of the date
    int day, month, year;

    // variables to store the current date, month and year
    int curDay, curMonth, curYear;

    // get the current date, month and year
    sscanf(__DATE__, "%s %d %d", &curMonth, &curDay, &curYear);

    // split the date into the day, month and year components
    sscanf(date, "%d %s %d", &day, &month, &year);

    // convert the month to a numeric value
    if(month == "Jan")
        month = 1;
    else if(month == "Feb")
        month = 2;
    else if(month == "Mar")
        month = 3;
    else if(month == "Apr")
        month = 4;
    else if(month == "May")
        month = 5;
    else if(month == "Jun")
        month = 6;
    else if(month == "Jul")
        month = 7;
    else if(month == "Aug")
        month = 8;
    else if(month == "Sep")
        month = 9;
    else if(month == "Oct")
        month = 10;
    else if(month == "Nov")
        month = 11;
    else if(month == "Dec")
        month = 12;

    // adjust the year if it is two-digit
    if(year < 100)
    {
        if(year < 50)
            year += 2000;
        else
            year += 1900;
    }

    // check if the date is valid
    if(month < 1 || month > 12 || day < 1 || day > getDaysInMonth(month, year))
    {
        printf("Invalid date.\n");
        return;
    }

    // check if the date is in the future
    if(year > curYear || (year == curYear && month > curMonth) || (year == curYear && month == curMonth && day > curDay))
    {
        printf("This date is in the future.\n");
        return;
    }

    // display the converted date
    printf("%02d/%02d/%04d\n", day, month, year);
}

int main()
{
    // convert a natural language date to a numeric date
    convertDate("25 Dec 2020");

    // convert an invalid date
    convertDate("31 Nov 2020");

    // convert a date in the future
    convertDate("01 Jan 2022");

    return 0;
}