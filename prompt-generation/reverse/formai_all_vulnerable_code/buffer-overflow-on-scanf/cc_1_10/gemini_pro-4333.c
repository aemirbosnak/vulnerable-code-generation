//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_MONTHS 12

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char *name;
    int days;
} Month;

Month months[] = {
    {"January", 31},
    {"February", 28},
    {"March", 31},
    {"April", 30},
    {"May", 31},
    {"June", 30},
    {"July", 31},
    {"August", 31},
    {"September", 30},
    {"October", 31},
    {"November", 30},
    {"December", 31}
};

int is_leap_year(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int days_in_month(int month, int year) {
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return months[month - 1].days;
}

Date convert_date_to_julian(Date date) {
    Date julian_date;
    julian_date.year = date.year;
    julian_date.month = date.month;
    julian_date.day = date.day;

    for (int i = 0; i < date.month - 1; i++) {
        julian_date.day += days_in_month(i + 1, date.year);
    }

    return julian_date;
}

Date convert_julian_date_to_date(Date julian_date) {
    Date date;
    date.year = julian_date.year;

    int days_in_year = 365;
    if (is_leap_year(date.year)) {
        days_in_year = 366;
    }

    int days_passed = julian_date.day;

    for (int i = 0; i < NUM_MONTHS; i++) {
        if (days_passed <= months[i].days) {
            date.month = i + 1;
            date.day = days_passed;
            break;
        } else {
            days_passed -= months[i].days;
        }
    }

    return date;
}

int main() {
    Date date;

    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%d-%d-%d", &date.year, &date.month, &date.day);

    Date julian_date = convert_date_to_julian(date);

    printf("The Julian date is: %d\n", julian_date.day);

    Date converted_date = convert_julian_date_to_date(julian_date);

    printf("The converted date is: %d-%02d-%02d\n", converted_date.year, converted_date.month, converted_date.day);

    return 0;
}