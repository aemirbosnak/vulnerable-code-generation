//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>

int isLeapYear(int year);
int daysInMonth(int month, int year);
int countDays(int day, int month, int year);

int main() {
    int day, month, year;

    printf("Enter a date in the format DD/MM/YYYY: ");
    scanf("%d/%d/%d", &day, &month, &year);

    int totalDays = countDays(day, month, year);
    printf("The number of days since 1st January 1970 is %d\n", totalDays);

    return 0;
}

int isLeapYear(int year) {
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0)
                return 1;
            else
                return 0;
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

int daysInMonth(int month, int year) {
    if(month == 2) {
        if(isLeapYear(year))
            return 29;
        else
            return 28;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int countDays(int day, int month, int year) {
    int totalDays = 0;

    // Add number of days in all the years before the current year
    for(int i = 1970; i < year; i++) {
        if(isLeapYear(i))
            totalDays += 366;
        else
            totalDays += 365;
    }

    // Add number of days in all the months before the current month in the current year
    for(int i = 1; i < month; i++) {
        totalDays += daysInMonth(i, year);
    }

    // Add number of days in the current month
    totalDays += day - 1;

    return totalDays;
}