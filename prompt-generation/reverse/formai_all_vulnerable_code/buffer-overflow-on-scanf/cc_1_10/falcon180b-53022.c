//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define DAYS_IN_MONTH(m) ((m) == 2? (is_leap_year(y)? 29 : 28) : ((m) - 1) % 7 % 2? 31 : 30)
#define IS_LEAP_YEAR(y) ((y) % 400 == 0 || ((y) % 4 == 0 && (y) % 100!= 0))

int is_leap_year(int y) {
    return IS_LEAP_YEAR(y);
}

int days_in_month(int m, int y) {
    return DAYS_IN_MONTH(m);
}

void print_date(int d, int m, int y) {
    printf("%02d/%02d/%04d\n", d, m, y);
}

int main() {
    char input[100];
    int day, month, year;

    printf("Enter a date in the format DD/MM/YYYY: ");
    scanf("%s", input);

    if (sscanf(input, "%02d/%02d/%04d", &day, &month, &year)!= 3) {
        printf("Invalid date format.\n");
        return 1;
    }

    if (day < 1 || day > 31) {
        printf("Invalid day.\n");
        return 1;
    }

    if (month < 1 || month > 12) {
        printf("Invalid month.\n");
        return 1;
    }

    if (!is_leap_year(year) && month == 2 && day > 29) {
        printf("Invalid day for non-leap year.\n");
        return 1;
    }

    print_date(day, month, year);

    return 0;
}