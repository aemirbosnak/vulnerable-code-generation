//Code Llama-13B DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define YEARS 10000
#define MONTHS 12
#define DAYS 30
#define HOURS 24
#define MINUTES 60
#define SECONDS 60

struct date_t {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

struct date_t current_date;

int get_current_date(struct date_t *date) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    date->year = timeinfo->tm_year + 1900;
    date->month = timeinfo->tm_mon + 1;
    date->day = timeinfo->tm_mday;
    date->hour = timeinfo->tm_hour;
    date->minute = timeinfo->tm_min;
    date->second = timeinfo->tm_sec;

    return 0;
}

int set_date(struct date_t *date) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    timeinfo->tm_year = date->year - 1900;
    timeinfo->tm_mon = date->month - 1;
    timeinfo->tm_mday = date->day;
    timeinfo->tm_hour = date->hour;
    timeinfo->tm_min = date->minute;
    timeinfo->tm_sec = date->second;

    mktime(timeinfo);

    return 0;
}

int main(int argc, char *argv[]) {
    struct date_t date;

    get_current_date(&date);
    printf("Current date: %d-%d-%d %d:%d:%d\n", date.year, date.month, date.day, date.hour, date.minute, date.second);

    date.year = 2025;
    date.month = 1;
    date.day = 1;
    date.hour = 0;
    date.minute = 0;
    date.second = 0;

    set_date(&date);

    printf("New date: %d-%d-%d %d:%d:%d\n", date.year, date.month, date.day, date.hour, date.minute, date.second);

    return 0;
}