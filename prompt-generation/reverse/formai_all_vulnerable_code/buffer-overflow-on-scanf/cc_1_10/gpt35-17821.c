//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

// function to get the number of days in a given month of a given year
int getDaysInMonth(int month, int year) {
    int daysInMonth;

    // check for February
    if (month == 2) {
        if (isLeapYear(year)) {
            daysInMonth = 29;
        }
        else {
            daysInMonth = 28;
        }
    }
    // check for months with 31 days
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        daysInMonth = 31;
    }
    // check for months with 30 days
    else {
        daysInMonth = 30;
    }

    return daysInMonth;
}

int main() {
    int day, month, year;
    int daysSinceEpoch = 0;

    // ask the user for the date
    printf("Enter a date in the format DD/MM/YYYY: ");
    scanf("%d/%d/%d", &day, &month, &year);

    // calculate the number of days since the start of the epoch (01/01/1970)
    for (int i = 1970; i < year; i++) {
        if (isLeapYear(i)) {
            daysSinceEpoch += 366;
        }
        else {
            daysSinceEpoch += 365;
        }
    }

    for (int i = 1; i < month; i++) {
        daysSinceEpoch += getDaysInMonth(i, year);
    }

    daysSinceEpoch += day - 1;

    printf("The number of days since the start of the epoch is: %d\n", daysSinceEpoch);

    return 0;
}