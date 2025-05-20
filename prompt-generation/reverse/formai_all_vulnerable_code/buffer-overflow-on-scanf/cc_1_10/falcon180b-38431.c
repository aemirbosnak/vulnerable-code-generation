//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_MONTH_NAME_LEN 10
#define MAX_DAY_NAME_LEN 10

enum {
    JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

char *month_name[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

char *day_name[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

struct tm get_date(char *date_str) {
    struct tm result = {0};
    char *ptr;
    int year, month, day, hour, minute, second;

    ptr = strptime(date_str, "%Y-%m-%d %H:%M:%S", &result);
    if (ptr == NULL) {
        printf("Invalid date format.\n");
        exit(1);
    }

    year = result.tm_year + 1900;
    month = result.tm_mon + 1;
    day = result.tm_mday;
    hour = result.tm_hour;
    minute = result.tm_min;
    second = result.tm_sec;

    return (struct tm) {
       .tm_year = year,
       .tm_mon = month,
       .tm_mday = day,
       .tm_hour = hour,
       .tm_min = minute,
       .tm_sec = second
    };
}

void print_date(struct tm date) {
    time_t t = mktime(&date);
    char buf[80];

    strftime(buf, sizeof(buf), "%A, %B %d, %Y %I:%M %p", &date);
    printf("%s\n", buf);
}

int main() {
    char date_str[80];

    printf("Enter a date (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", date_str);

    struct tm date = get_date(date_str);
    print_date(date);

    return 0;
}