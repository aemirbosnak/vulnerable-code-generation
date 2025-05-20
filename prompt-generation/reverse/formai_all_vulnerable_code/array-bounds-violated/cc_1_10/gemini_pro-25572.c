//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_DATE_SIZE 11

enum {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

static const char *month_names[12] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

static const int month_lengths[12] = {
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
};

static const char *day_names[7] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

static bool is_leap_year(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

static int get_month_length(int month, int year) {
    if (month == FEB && is_leap_year(year)) {
        return month_lengths[month] + 1;
    }
    else {
        return month_lengths[month - 1];
    }
}

static int get_day_of_week(int day, int month, int year) {
    int days = day + 1;

    for (int i = 0; i < month - 1; ++i) {
        days += get_month_length(i, year);
    }

    for (int i = year - 1900; i >= 0; --i) {
        days += is_leap_year(i) ? 366 : 365;
    }

    return days % 7;
}

static void print_date(int day, int month, int year) {
    printf("%s, %s %d, %d\n",
           day_names[get_day_of_week(day, month, year)],
           month_names[month - 1],
           day,
           year);
}

int main(void) {
    char date[MAX_DATE_SIZE + 1];
    int day, month, year;

    printf("Enter a date in the format dd/mm/yyyy: ");
    if (fgets(date, sizeof(date), stdin) == NULL) {
        fprintf(stderr, "Error: could not read input\n");
        return EXIT_FAILURE;
    }

    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) {
        fprintf(stderr, "Error: invalid date format\n");
        return EXIT_FAILURE;
    }

    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1) {
        fprintf(stderr, "Error: invalid date range\n");
        return EXIT_FAILURE;
    }

    if (day > get_month_length(month, year)) {
        fprintf(stderr, "Error: invalid day for month\n");
        return EXIT_FAILURE;
    }

    print_date(day, month, year);

    return EXIT_SUCCESS;
}