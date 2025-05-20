//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DATE_LEN 80
#define MAX_MONTH_LEN 20

enum {
    JANUARY = 1,
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

char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int get_day_of_week(int year, int month, int day) {
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    time_t t = mktime(&date);
    return (int) (t % 7);
}

int get_month_days(int year, int month) {
    if (month == FEBRUARY) {
        if ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER) {
        return 30;
    } else {
        return 31;
    }
}

int get_year_days(int year) {
    if (year % 4 == 0 && year % 100!= 0) {
        return 366;
    } else if (year % 400 == 0) {
        return 366;
    } else {
        return 365;
    }
}

void print_date(int year, int month, int day) {
    printf("Today is %s, %d %s %d\n", months[month - 1], day, months[month - 1], year);
}

int main() {
    time_t t = time(NULL);
    struct tm* date = localtime(&t);

    int year = date->tm_year + 1900;
    int month = date->tm_mon + 1;
    int day = date->tm_mday;

    printf("Today is %s, %d %s %d\n", months[month - 1], day, months[month - 1], year);

    return 0;
}