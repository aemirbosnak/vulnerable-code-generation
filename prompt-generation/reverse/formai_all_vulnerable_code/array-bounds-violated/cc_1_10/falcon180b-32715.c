//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_YEAR 9999
#define MAX_MONTH 12
#define MAX_DAY 31
#define MAX_HOUR 23
#define MAX_MINUTE 59
#define MAX_SECOND 59

struct tm *get_current_time() {
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    return timeinfo;
}

int is_leap_year(int year) {
    if (year % 4 == 0 && year % 100!= 0 || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int get_days_in_month(int month, int year) {
    if (month == 2) {
        if (is_leap_year(year)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

char *get_day_of_week(int day) {
    static char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return weekdays[day % 7];
}

int main() {
    struct tm *timeinfo = get_current_time();
    int year = timeinfo->tm_year + 1900;
    int month = timeinfo->tm_mon + 1;
    int day = timeinfo->tm_mday;
    int hour = timeinfo->tm_hour;
    int minute = timeinfo->tm_min;
    int second = timeinfo->tm_sec;

    printf("Today is %s, %d %s %d\n", get_day_of_week(timeinfo->tm_wday), day, get_day_of_week(timeinfo->tm_wday), year);

    return 0;
}