//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DATE_LENGTH 80
#define MAX_MONTH_LENGTH 20
#define MAX_YEAR_LENGTH 20

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
    DECEMBER,
};

char* month_name(int month) {
    static char months[13][MAX_MONTH_LENGTH] = {
        [JANUARY] = "January",
        [FEBRUARY] = "February",
        [MARCH] = "March",
        [APRIL] = "April",
        [MAY] = "May",
        [JUNE] = "June",
        [JULY] = "July",
        [AUGUST] = "August",
        [SEPTEMBER] = "September",
        [OCTOBER] = "October",
        [NOVEMBER] = "November",
        [DECEMBER] = "December",
    };
    return months[month];
}

char* format_date(int day, int month, int year) {
    static char date[MAX_DATE_LENGTH];
    snprintf(date, MAX_DATE_LENGTH, "%d %s %d", day, month_name(month), year);
    return date;
}

int main() {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    int day = tm->tm_mday;
    int month = tm->tm_mon + 1;
    int year = tm->tm_year + 1900;

    printf("Today's date is: %s\n", format_date(day, month, year));

    return 0;
}