//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_MONTHS 12
#define MAX_DAYS 31
#define MAX_MONTH_NAMES 12
#define MAX_DAY_NAMES 7

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

enum {
    SUN = 1,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
};

char *month_names[MAX_MONTHS] = {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};

char *day_names[MAX_DAYS] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

int get_day_of_week(int day, int month, int year) {
    int c, y, m;
    int century;

    c = year / 100;
    y = year % 100;
    m = month;

    if (m < 3) {
        m += 12;
        y--;
    }

    century = c * 100 + y;

    return (day + 13 * (m + 1) / 5 + y + y / 4 + century / 4 - 2 * century) % 7;
}

void print_date(int day, int month, int year) {
    int day_of_week;
    char day_name[MAX_DAY_NAMES];
    char month_name[MAX_MONTH_NAMES];

    day_of_week = get_day_of_week(day, month, year);

    strftime(month_name, MAX_MONTH_NAMES, "%B", localtime(&year));
    strftime(day_name, MAX_DAY_NAMES, "%A", localtime(&year));

    printf("Today is %s, %s %d, %d\n", day_name[day_of_week], month_name, day, year);
}

int main() {
    int day, month, year;

    printf("Enter the day (1-31): ");
    scanf("%d", &day);

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    printf("Enter the year (YYYY): ");
    scanf("%d", &year);

    print_date(day, month, year);

    return 0;
}