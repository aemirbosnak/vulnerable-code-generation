//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *MONTHS[] = { "January", "February", "March", "April", 
                    "May", "June", "July", "August",
                    "September", "October", "November", "December" };

int MONTH_DAYS[] = { 31, 28, 31, 30, 
                    31, 30, 31, 31, 
                    30, 31, 30, 31 };

struct Date {
    int day;
    int month;
    int year;
};

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int days_in_month(int month, int year) {
    if (month == 2 && is_leap_year(year)) {
        return 29;
    } else {
        return MONTH_DAYS[month-1];
    }
}

int is_valid_date(int day, int month, int year) {
    if (year < 1 || year > 9999) {
        return 0;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    if (day < 1 || day > days_in_month(month, year)) {
        return 0;
    }
    return 1;
}

int days_between_dates(struct Date d1, struct Date d2) {
    int days = 0;
    if (d1.year == d2.year) {
        if (d1.month == d2.month) {
            days = d2.day - d1.day;
        } else {
            for (int i = d1.month; i < d2.month; i++) {
                days += days_in_month(i, d1.year);
            }
            days -= d1.day;
            days += d2.day;
        }
    } else {
        for (int i = d1.year; i < d2.year; i++) {
            if (is_leap_year(i)) {
                days += 366;
            } else {
                days += 365;
            }
        }
        days -= day_of_year(d1);
        days += day_of_year(d2);
    }
    return days;
}

int day_of_year(struct Date d) {
    int day = 0;
    for (int i = 0; i < d.month-1; i++) {
        day += days_in_month(i+1, d.year);
    }
    day += d.day;
    return day;
}

void print_date(struct Date d) {
    printf("%s %d, %d", MONTHS[d.month-1], d.day, d.year);
}

void convert_date(char *input) {
    int day, month, year;
    struct Date d;

    // parse input string
    if (sscanf(input, "%d/%d/%d", &day, &month, &year) != 3) {
        printf("Invalid date format\n");
        return;
    }

    // validate date
    if (!is_valid_date(day, month, year)) {
        printf("Invalid date\n");
        return;
    }

    // create date object
    d.day = day;
    d.month = month;
    d.year = year;

    // print output
    printf("Date: ");
    print_date(d);
    printf("\n");
    printf("Day of year: %d\n", day_of_year(d));
}

int main() {
    convert_date("10/15/2021");
    return 0;
}