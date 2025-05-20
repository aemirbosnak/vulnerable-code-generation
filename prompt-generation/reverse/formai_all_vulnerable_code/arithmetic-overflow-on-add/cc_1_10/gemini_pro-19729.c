//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS_IN_YEAR 12
#define DAYS_IN_WEEK 7

typedef struct {
    int year;
    int month;
    int day;
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
        case 2:
            return is_leap_year(year) ? 29 : 28;
        default:
            return 30;
    }
}

int day_of_week(Date date) {
    int y = date.year - (date.month <= 2);
    int m = date.month + 11 - (date.month <= 2);
    int c = date.year / 100;
    int y0 = date.year % 100;
    return (date.day + (13 * m - 1) / 5 + y0 + y0 / 4 + c / 4 - 2 * c + 777) % DAYS_IN_WEEK;
}

void print_date(Date date) {
    printf("%d-%02d-%02d\n", date.year, date.month, date.day);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [date]\n", argv[0]);
        return EXIT_FAILURE;
    }

    Date date;
    if (sscanf(argv[1], "%d-%d-%d", &date.year, &date.month, &date.day) != 3) {
        printf("Invalid date format: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (date.year < 1 || date.month < 1 || date.month > MONTHS_IN_YEAR || date.day < 1 || date.day > days_in_month(date.month, date.year)) {
        printf("Invalid date: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    print_date(date);

    Date tomorrow = date;
    tomorrow.day++;
    if (tomorrow.day > days_in_month(tomorrow.month, tomorrow.year)) {
        tomorrow.day = 1;
        tomorrow.month++;
        if (tomorrow.month > MONTHS_IN_YEAR) {
            tomorrow.month = 1;
            tomorrow.year++;
        }
    }

    print_date(tomorrow);

    Date yesterday = date;
    yesterday.day--;
    if (yesterday.day < 1) {
        yesterday.month--;
        if (yesterday.month < 1) {
            yesterday.month = MONTHS_IN_YEAR;
            yesterday.year--;
        }
        yesterday.day = days_in_month(yesterday.month, yesterday.year);
    }

    print_date(yesterday);

    printf("Day of week: %d\n", day_of_week(date));

    return EXIT_SUCCESS;
}