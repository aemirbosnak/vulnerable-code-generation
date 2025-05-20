//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MONTHS 12
#define DAYS_IN_WEEK 7
#define DAYS_IN_MONTH 31

// Function prototypes
void print_cyberpunk_date(int day, int month, int year);
int get_day_of_week(int day, int month, int year);

int main() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    int day = t->tm_mday;
    int month = t->tm_mon + 1;
    int year = t->tm_year + 1900;

    print_cyberpunk_date(day, month, year);

    return 0;
}

void print_cyberpunk_date(int day, int month, int year) {
    printf("Cyberpunk Date: ");

    if (month < 10) {
        printf("0");
    }

    printf("%d/", month);

    if (day < 10) {
        printf("0");
    }

    printf("%d/", day);

    if (year < 2000) {
        printf("20");
    }

    printf("%d\n", year);
}

int get_day_of_week(int day, int month, int year) {
    int c, y, m;

    if (month < 3) {
        month += 12;
        year--;
    }

    c = year / 100;
    y = year % 100;
    m = month;

    return (day + 13 * (m + 1) / 5 + y + y / 4 + c / 4 - 2 * c) % 7;
}