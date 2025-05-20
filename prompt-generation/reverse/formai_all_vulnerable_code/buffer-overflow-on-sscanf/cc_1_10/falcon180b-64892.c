//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LEN 20
#define DAYS_PER_MONTH(m) ((m) == 2? (m % 4 == 0 && m % 100!= 0 || m % 400 == 0)? 29 : 28 : (m % 7!= 0 && m % 100!= 0 || m % 400 == 0)? 31 : 30)

struct tm parse_date(const char *date_str) {
    struct tm tm = {0};
    int year, month, day;
    char *endptr;

    if (sscanf(date_str, "%d-%d-%d", &day, &month, &year)!= 3) {
        printf("Invalid date format: %s\n", date_str);
        exit(1);
    }

    if (month < 1 || month > 12) {
        printf("Invalid month: %d\n", month);
        exit(1);
    }

    if (day < 1 || day > DAYS_PER_MONTH(month)) {
        printf("Invalid day: %d\n", day);
        exit(1);
    }

    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = -1;

    return tm;
}

char *format_date(const struct tm *tm) {
    char date_str[MAX_DATE_LEN];
    strftime(date_str, MAX_DATE_LEN, "%d-%m-%Y", tm);
    return strdup(date_str);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <date>\n", argv[0]);
        exit(1);
    }

    struct tm tm = parse_date(argv[1]);
    char *formatted_date = format_date(&tm);

    printf("Input date: %s\n", argv[1]);
    printf("Formatted date: %s\n", formatted_date);

    free(formatted_date);
    return 0;
}