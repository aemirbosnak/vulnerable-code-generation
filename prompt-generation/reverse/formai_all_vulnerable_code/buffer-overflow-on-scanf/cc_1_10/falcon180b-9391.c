//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MONTHS 12
#define DAYS_PER_MONTH 28
#define WEEK_DAYS 7
#define SECS_PER_MIN 60
#define SECS_PER_HOUR 3600
#define SECS_PER_DAY 86400

enum {
    SUNDAY = 0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

enum {
    JANUARY = 0,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

enum {
    SUN = 0,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
};

void print_date(int year, int month, int day) {
    char day_str[10];
    char month_str[10];
    char date_str[20];

    strftime(date_str, 20, "%Y-%m-%d", localtime(&day));
    strftime(month_str, 10, "%B", localtime(&day));
    strftime(day_str, 10, "%A", localtime(&day));

    printf("Today is %s, %s %d, %s.\n", day_str, month_str, day, date_str);
}

int main() {
    char input[100];
    int year, month, day;

    setlocale(LC_ALL, "");

    printf("Enter a date (YYYY-MM-DD): ");
    scanf("%s", input);

    sscanf(input, "%d-%d-%d", &year, &month, &day);

    print_date(year, month, day);

    return 0;
}