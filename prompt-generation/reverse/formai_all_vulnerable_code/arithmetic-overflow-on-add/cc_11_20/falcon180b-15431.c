//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef enum {
    JANUARY,
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
} Month;

int main() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    Date date = {
       .day = t->tm_mday,
       .month = t->tm_mon + 1,
       .year = t->tm_year + 1900
    };

    Month month = date.month;
    int day = date.day;
    int year = date.year;

    char *day_str;
    char *month_str;
    char *year_str;

    switch (month) {
        case JANUARY:
            month_str = "January";
            break;
        case FEBRUARY:
            month_str = "February";
            break;
        case MARCH:
            month_str = "March";
            break;
        case APRIL:
            month_str = "April";
            break;
        case MAY:
            month_str = "May";
            break;
        case JUNE:
            month_str = "June";
            break;
        case JULY:
            month_str = "July";
            break;
        case AUGUST:
            month_str = "August";
            break;
        case SEPTEMBER:
            month_str = "September";
            break;
        case OCTOBER:
            month_str = "October";
            break;
        case NOVEMBER:
            month_str = "November";
            break;
        case DECEMBER:
            month_str = "December";
            break;
        default:
            month_str = "Unknown";
            break;
    }

    if (day == 1) {
        day_str = "first";
    } else if (day == 2) {
        day_str = "second";
    } else if (day == 3) {
        day_str = "third";
    } else {
        day_str = "unknown";
    }

    if (year % 100 == 0 && year % 400!= 0) {
        year_str = "leap";
    } else if (year % 400 == 0) {
        year_str = "leap";
    } else {
        year_str = "not leap";
    }

    printf("Today is the %s day of %s, %d.\n", day_str, month_str, day);
    printf("This year, %d, is a %s year.\n", year, year_str);

    return 0;
}