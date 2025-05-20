//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if a year is a leap year
int isLeapYear(int year) {
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

// function to get the number of days in a month
int daysInMonth(int month, int year) {
    if(month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else if(month == 2 && isLeapYear(year)) {
        return 29;
    } else if(month == 2 && !isLeapYear(year)) {
        return 28;
    } else {
        return 31;
    }
}

int main() {
    // get date string from user
    char dateString[11];
    printf("Enter date in format DD/MM/YYYY: ");
    scanf("%s", dateString);

    // extract day, month, and year from date string
    char dayString[3], monthString[3], yearString[5];
    strncpy(dayString, dateString, 2);
    strncpy(monthString, dateString + 3, 2);
    strncpy(yearString, dateString + 6, 4);
    int day = atoi(dayString);
    int month = atoi(monthString);
    int year = atoi(yearString);

    // convert date to number of days since 01/01/0001
    int days = 0;
    for(int i = 1; i < year; i++) {
        if(isLeapYear(i)) {
            days += 366;
        } else {
            days += 365;
        }
    }
    for(int i = 1; i < month; i++) {
        days += daysInMonth(i, year);
    }
    days += day;

    // print number of days since 01/01/0001
    printf("Number of days since 01/01/0001: %d\n", days);

    return 0;
}