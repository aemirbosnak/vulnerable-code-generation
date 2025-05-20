//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char *month;
    int days_in_month;
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

char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100!= 0) || (year % 400 == 0);
}

int get_month_days(Month *month) {
    if (month->month[0] == 'F' && month->month[1] == 'e' && month->month[2] == 'b' && month->month[3] == 'r' && month->month[4] == 'u' && month->month[5] == 'a' && month->month[6] == 'r' && month->month[7] == 'y') {
        if (is_leap_year(month->days_in_month)) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return month->days_in_month;
    }
}

int get_day_of_week(int year, int month, int day) {
    int days_in_year = 365;
    if (is_leap_year(year)) {
        days_in_year = 366;
    }
    int days_in_month = get_month_days(&months[month]);
    int day_of_year = day;
    int day_of_week = (day_of_year + 13 * (month - 1) + 100 * (year - 1) + 100) % 7;
    return day_of_week;
}

void print_date(int year, int month, int day) {
    printf("%s %d, %d\n", weekdays[get_day_of_week(year, month, day)], day, month + 1);
}

int main() {
    int year, month, day;
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter day: ");
    scanf("%d", &day);
    print_date(year, month, day);
    return 0;
}