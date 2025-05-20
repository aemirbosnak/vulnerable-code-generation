//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date {
    int day;
    int month;
    int year;
};

int isLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    } else if (year % 100 == 0) {
        return 0;
    } else if (year % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else {
        return monthDays[month - 1];
    }
}

int dateToNumDays(struct Date d) {
    int numDays = 0;
    for (int y = 1900; y < d.year; y++) {
        numDays += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < d.month; m++) {
        numDays += daysInMonth(m, d.year);
    }
    numDays += d.day - 1;
    return numDays;
}

struct Date numDaysToDate(int numDays) {
    struct Date d = {1, 1, 1900};
    while (numDays > 0) {
        int daysInYear = isLeapYear(d.year) ? 366 : 365;
        if (numDays >= daysInYear) {
            numDays -= daysInYear;
            d.year += 1;
        } else {
            int month = 1;
            while (numDays >= daysInMonth(month, d.year)) {
                numDays -= daysInMonth(month, d.year);
                month += 1;
            }
            d.month = month;
            d.day = numDays + 1;
            break;
        }
    }
    return d;
}

int main() {
    struct Date d;
    printf("Enter a date in the format DD/MM/YYYY: ");
    scanf("%d/%d/%d", &d.day, &d.month, &d.year);
    int numDays = dateToNumDays(d);
    printf("The date %02d/%02d/%04d is day %d of the year %d.\n", d.day, d.month, d.year, numDays + 1, d.year);
    int daysUntilEndOfYear = isLeapYear(d.year) ? 366 - numDays : 365 - numDays;
    printf("There are %d days until the end of the year.\n", daysUntilEndOfYear);
    printf("Enter a number of days since 01/01/1900: ");
    scanf("%d", &numDays);
    d = numDaysToDate(numDays);
    printf("The date corresponding to day %d since 01/01/1900 is %02d/%02d/%04d.\n", numDays, d.day, d.month, d.year);
    return 0;
}