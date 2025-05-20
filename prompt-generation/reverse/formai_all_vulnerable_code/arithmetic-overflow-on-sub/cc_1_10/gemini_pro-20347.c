//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
} date_t;

int get_num_days_in_month(int month, int year) {
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
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return -1;
    }
}

int get_num_days_in_year(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 366;
    } else {
        return 365;
    }
}

int compare_dates(date_t d1, date_t d2) {
    if (d1.year != d2.year) {
        return d1.year - d2.year;
    } else if (d1.month != d2.month) {
        return d1.month - d2.month;
    } else {
        return d1.day - d2.day;
    }
}

int days_between_dates(date_t d1, date_t d2) {
    int days = 0;
    int i;

    if (compare_dates(d1, d2) < 0) {
        for (i = d1.year; i < d2.year; i++) {
            days += get_num_days_in_year(i);
        }
        for (i = d1.month; i < d2.month; i++) {
            days += get_num_days_in_month(i, d2.year);
        }
        for (i = d1.day; i < d2.day; i++) {
            days += 1;
        }
    } else {
        for (i = d2.year; i < d1.year; i++) {
            days += get_num_days_in_year(i);
        }
        for (i = d2.month; i < d1.month; i++) {
            days += get_num_days_in_month(i, d1.year);
        }
        for (i = d2.day; i < d1.day; i++) {
            days += 1;
        }
    }

    return days;
}

main() {
    date_t d1, d2;
    int days;

    printf("Enter the first date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d1.day, &d1.month, &d1.year);

    printf("Enter the second date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d2.day, &d2.month, &d2.year);

    days = days_between_dates(d1, d2);

    printf("The number of days between %d/%d/%d and %d/%d/%d is %d.\n",
        d1.day, d1.month, d1.year,
        d2.day, d2.month, d2.year,
        days);
}