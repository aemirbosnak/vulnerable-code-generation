//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int dateToDays(int day, int month, int year) {
    int days = 0;
    for (int y = 1; y < year; y++) {
        days += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        days += daysInMonth(m, year);
    }
    days += day;
    return days;
}

void daysToDate(int days, int year[]) {
    int y, m, d;
    int daysInYear;
    for (y = 1; y < 10000; y++) {
        daysInYear = isLeapYear(y) ? 366 : 365;
        if (days <= daysInYear) {
            break;
        }
        days -= daysInYear;
    }
    for (m = 1; m <= 12; m++) {
        if (m == 2) {
            daysInYear = isLeapYear(y) ? 29 : 28;
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            daysInYear = 30;
        }
        else {
            daysInYear = 31;
        }
        if (days <= daysInYear) {
            break;
        }
        days -= daysInYear;
    }
    d = days;
    year[0] = y;
    year[1] = m;
    year[2] = d;
}

int main() {
    int day, month, year;
    printf("Enter a date in the format dd/mm/yyyy: ");
    scanf("%d/%d/%d", &day, &month, &year);
    int days = dateToDays(day, month, year);
    printf("The number of days since January 1st, 1 AD is: %d\n", days);
    
    int yearArray[3];
    daysToDate(days, yearArray);
    printf("The date corresponding to this number of days is: %d/%d/%d\n", yearArray[2], yearArray[1], yearArray[0]);
    
    return 0;
}