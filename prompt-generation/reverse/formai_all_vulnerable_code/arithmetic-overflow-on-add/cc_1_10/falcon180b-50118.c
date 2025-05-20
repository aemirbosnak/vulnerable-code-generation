//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

#define NUM_DAYS_IN_WEEK 7
#define NUM_MONTHS_IN_YEAR 12

enum {
    SUNDAY = 0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

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

struct tm get_time() {
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    return *timeinfo;
}

void print_date(struct tm date) {
    printf("%s, %d %s %d\n",
           date.tm_wday == 0? "Sunday" :
           date.tm_wday == 1? "Monday" :
           date.tm_wday == 2? "Tuesday" :
           date.tm_wday == 3? "Wednesday" :
           date.tm_wday == 4? "Thursday" :
           date.tm_wday == 5? "Friday" :
           date.tm_wday == 6? "Saturday" : "Invalid day of week",
           date.tm_mday,
           date.tm_mon + 1,
           date.tm_year + 1900);
}

int main() {
    setlocale(LC_ALL, "");
    struct tm date = get_time();
    print_date(date);
    return 0;
}