//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DAYS_IN_WEEK 7
#define MONTHS_IN_YEAR 12

typedef struct {
    int day;
    int month;
    int year;
} Date;

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int days_in_month(int month, int year) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return is_leap_year(year) ? 29 : 28;
        default:
            return -1;
    }
}

int days_between(Date date1, Date date2) {
    int days = 0;
    for (int year = date1.year; year < date2.year; year++) {
        days += is_leap_year(year) ? 366 : 365;
    }
    for (int month = date1.month; month < date2.month; month++) {
        days += days_in_month(month, date2.year);
    }
    days += date2.day - date1.day;
    return days;
}

int main() {
    Date date1, date2;

    printf("Enter the first date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &date1.day, &date1.month, &date1.year);

    printf("Enter the second date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &date2.day, &date2.month, &date2.year);

    int days = days_between(date1, date2);

    printf("There are %d days between the two dates.\n", days);

    return 0;
}