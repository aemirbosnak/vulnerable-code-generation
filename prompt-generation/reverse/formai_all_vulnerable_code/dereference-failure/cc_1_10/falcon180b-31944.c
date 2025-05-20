//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

#define MAX_STRING_LENGTH 100
#define MAX_DATE_LENGTH 11

struct tm get_current_time() {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    return *timeinfo;
}

int is_leap_year(int year) {
    if (year % 4 == 0 && year % 100!= 0) {
        return 1;
    } else if (year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int get_month_days(int month, int year) {
    static int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    } else {
        return days_in_month[month];
    }
}

int get_weekday(struct tm date) {
    return date.tm_wday;
}

char* get_weekday_name(int weekday) {
    static char* weekday_names[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return weekday_names[weekday];
}

char* get_month_name(int month) {
    static char* month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return month_names[month];
}

int main() {
    setlocale(LC_TIME, "");
    struct tm current_time = get_current_time();
    int year = current_time.tm_year + 1900;
    int month = current_time.tm_mon + 1;
    int day = current_time.tm_mday;
    char date_string[MAX_DATE_LENGTH];
    sprintf(date_string, "%04d-%02d-%02d", year, month, day);
    printf("Today's date is: %s\n", date_string);
    return 0;
}