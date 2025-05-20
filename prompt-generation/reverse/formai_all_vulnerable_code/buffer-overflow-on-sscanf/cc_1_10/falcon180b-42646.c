//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define DAYS_PER_MONTH [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
#define MONTHS_PER_YEAR 12

void print_date(int day, int month, int year);
void print_month(int month);
void print_year(int year);

int main() {
    char input[100];
    int day, month, year;
    int valid_input = 0;

    while (!valid_input) {
        printf("Enter a date in the format DD/MM/YYYY: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d/%d/%d", &day, &month, &year);

        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2099) {
            printf("Invalid date. Please try again.\n");
        } else {
            valid_input = 1;
        }
    }

    printf("You entered: ");
    print_date(day, month, year);

    return 0;
}

void print_date(int day, int month, int year) {
    printf("%d/%d/%d\n", day, month, year);
}

void print_month(int month) {
    if (month == 1) {
        printf("January\n");
    } else if (month == 2) {
        printf("February\n");
    } else if (month == 3) {
        printf("March\n");
    } else if (month == 4) {
        printf("April\n");
    } else if (month == 5) {
        printf("May\n");
    } else if (month == 6) {
        printf("June\n");
    } else if (month == 7) {
        printf("July\n");
    } else if (month == 8) {
        printf("August\n");
    } else if (month == 9) {
        printf("September\n");
    } else if (month == 10) {
        printf("October\n");
    } else if (month == 11) {
        printf("November\n");
    } else if (month == 12) {
        printf("December\n");
    }
}

void print_year(int year) {
    printf("%d\n", year);
}