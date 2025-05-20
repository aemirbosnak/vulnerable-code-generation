//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MONTHS 12
#define DAYS_IN_MONTH(m) ((m) == 2? (is_leap_year(m)? 29 : 28) : 31)

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            }
        }
        return 1;
    }
    return 0;
}

int is_valid_date(int day, int month, int year) {
    if (month < 1 || month > MONTHS) {
        return 0;
    }
    if (day < 1 || day > DAYS_IN_MONTH(month)) {
        if (month == 2 && is_leap_year(year)) {
            if (day > 29) {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[100];
    int day, month, year;
    printf("Enter a date in the format DD/MM/YYYY: ");
    fgets(input, 100, stdin);
    sscanf(input, "%d/%d/%d", &day, &month, &year);
    if (!is_valid_date(day, month, year)) {
        printf("Invalid date.\n");
        return 0;
    }
    printf("The date is valid.\n");
    return 0;
}