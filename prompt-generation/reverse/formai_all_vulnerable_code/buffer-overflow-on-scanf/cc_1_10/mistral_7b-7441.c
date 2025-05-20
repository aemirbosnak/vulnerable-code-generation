//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATE_LENGTH 11

// Function to check if a given year is a leap year
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to calculate the number of days in a given month
int days_in_month(int month, int year) {
    if (month == 2) {
        return is_leap_year(year) ? 29 : 28;
    }

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        default:
            return 30;
    }
}

// Function to validate a given date string
int validate_date(char *date) {
    int day, month, year;

    sscanf(date, "%d-%d-%d", &day, &month, &year);

    if (day < 1 || day > 31 || month < 1 || month > 12) {
        return 0;
    }

    if (month == 2 && day > days_in_month(month, year)) {
        return 0;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return 0;
        }
    }

    return 1;
}

// Function to convert a given date string to the number of days elapsed since January 1, 1900
int date_to_days(char *date) {
    int day, month, year, total_days;

    if (!validate_date(date)) {
        fprintf(stderr, "Invalid date format\n");
        exit(1);
    }

    sscanf(date, "%d-%d-%d", &day, &month, &year);

    total_days = day;
    for (int i = 1; i < month; i++) {
        total_days += days_in_month(i, year);
    }

    total_days += is_leap_year(year) ? 366 : 365;
    total_days += year * 365;
    total_days += year / 4 - year / 100 + year / 400;

    return total_days;
}

int main() {
    char date[MAX_DATE_LENGTH];

    printf("Enter a date in the format 'dd-mm-yyyy': ");
    scanf("%s", date);

    int days_elapsed = date_to_days(date);
    printf("The number of days elapsed since January 1, 1900 for the given date is: %d\n", days_elapsed);

    return 0;
}