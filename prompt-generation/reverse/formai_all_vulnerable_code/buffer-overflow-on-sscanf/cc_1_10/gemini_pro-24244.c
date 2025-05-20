//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 11

typedef struct {
    int year;
    int month;
    int day;
} Date;

void print_date(Date date) {
    printf("%04d-%02d-%02d\n", date.year, date.month, date.day);
}

int is_leap_year(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
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
        case 2:
            return is_leap_year(year) ? 29 : 28;
        default:
            return 30;
    }
}

int days_in_year(int year) {
    return is_leap_year(year) ? 366 : 365;
}

int days_between_dates(Date date1, Date date2) {
    int days = 0;
    for (int i = date1.year; i < date2.year; i++) {
        days += days_in_year(i);
    }
    for (int i = 1; i < date2.month; i++) {
        days += days_in_month(i, date2.year);
    }
    days += date2.day - date1.day;
    return days;
}

Date add_days_to_date(Date date, int days) {
    int year = date.year;
    int month = date.month;
    int day = date.day;
    while (days >= days_in_year(year) + (month == 2 && is_leap_year(year))) {
        days -= days_in_year(year) + (month == 2 && is_leap_year(year));
        year++;
    }
    while (days >= days_in_month(month, year)) {
        days -= days_in_month(month, year);
        month++;
    }
    day += days;
    Date new_date = {
        .year = year,
        .month = month,
        .day = day,
    };
    return new_date;
}

Date subtract_days_from_date(Date date, int days) {
    int year = date.year;
    int month = date.month;
    int day = date.day;
    while (days >= days_in_year(year - 1)) {
        days -= days_in_year(year - 1);
        year--;
    }
    while (days >= days_in_month(month - 1, year)) {
        days -= days_in_month(month - 1, year);
        month--;
    }
    day -= days;
    Date new_date = {
        .year = year,
        .month = month,
        .day = day,
    };
    return new_date;
}

int main() {
    char date_string[MAX_DATE_LENGTH];
    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%s", date_string);

    int year, month, day;
    sscanf(date_string, "%d-%d-%d", &year, &month, &day);

    Date date = {
        .year = year,
        .month = month,
        .day = day,
    };

    print_date(date);

    int days_to_add;
    printf("Enter the number of days to add: ");
    scanf("%d", &days_to_add);

    Date new_date = add_days_to_date(date, days_to_add);

    print_date(new_date);

    int days_to_subtract;
    printf("Enter the number of days to subtract: ");
    scanf("%d", &days_to_subtract);

    new_date = subtract_days_from_date(date, days_to_subtract);

    print_date(new_date);

    return 0;
}