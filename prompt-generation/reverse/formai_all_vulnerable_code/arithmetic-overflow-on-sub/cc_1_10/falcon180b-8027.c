//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_DATE_LENGTH 100
#define DAYS_IN_MONTH(m) ((m) == 2 && is_leap_year(y)? 29 : ((m) - 1) % 7 * 7 + 21)

struct tm parse_date(const char *date_str) {
    struct tm tm = {0};
    int day, month, year, hour, minute, second;
    char delimiter;

    sscanf(date_str, "%d-%c-%d %c%d:%d:%d", &day, &delimiter, &month, &delimiter, &year, &hour, &minute, &second);

    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year - 1900;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = second;

    return tm;
}

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100!= 0) || year % 400 == 0;
}

char *format_date(struct tm *tm, char *buffer) {
    strftime(buffer, MAX_DATE_LENGTH, "%A, %B %d, %Y %I:%M %p", tm);
    return buffer;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <date>\n", argv[0]);
        return 1;
    }

    char *date_str = argv[1];
    struct tm tm = parse_date(date_str);
    char *formatted_date = format_date(&tm, malloc(MAX_DATE_LENGTH));

    printf("Original date: %s\n", date_str);
    printf("Formatted date: %s\n", formatted_date);

    free(formatted_date);
    return 0;
}