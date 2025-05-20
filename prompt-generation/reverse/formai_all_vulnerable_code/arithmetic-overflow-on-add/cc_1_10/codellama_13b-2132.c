//Code Llama-13B DATASET v1.0 Category: Natural Language Date Converter ; Style: sophisticated
// NLDC.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} date_t;

void nldc_init(date_t *date) {
    date->year = 0;
    date->month = 0;
    date->day = 0;
}

void nldc_set_date(date_t *date, int year, int month, int day) {
    date->year = year;
    date->month = month;
    date->day = day;
}

void nldc_get_date(date_t *date, int *year, int *month, int *day) {
    *year = date->year;
    *month = date->month;
    *day = date->day;
}

void nldc_print_date(date_t *date) {
    printf("%d-%d-%d\n", date->year, date->month, date->day);
}

void nldc_add_days(date_t *date, int days) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    tm->tm_year = date->year - 1900;
    tm->tm_mon = date->month - 1;
    tm->tm_mday = date->day;
    tm->tm_hour = 0;
    tm->tm_min = 0;
    tm->tm_sec = 0;
    tm->tm_isdst = -1;
    t = mktime(tm);
    t += days * 24 * 60 * 60;
    tm = localtime(&t);
    date->year = tm->tm_year + 1900;
    date->month = tm->tm_mon + 1;
    date->day = tm->tm_mday;
}

int main() {
    date_t date;
    nldc_init(&date);
    nldc_set_date(&date, 2022, 2, 28);
    nldc_add_days(&date, 10);
    nldc_print_date(&date);
    return 0;
}