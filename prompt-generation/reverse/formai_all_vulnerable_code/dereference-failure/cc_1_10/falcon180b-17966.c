//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MONTH_NAMES_LEN 12
#define WEEK_DAY_NAMES_LEN 7

typedef struct {
    char *name;
    int length;
} Month;

typedef struct {
    char *name;
    int length;
} WeekDay;

Month months[] = {
    {"January", 7},
    {"February", 7},
    {"March", 6},
    {"April", 6},
    {"May", 4},
    {"June", 5},
    {"July", 5},
    {"August", 6},
    {"September", 9},
    {"October", 7},
    {"November", 7},
    {"December", 7}
};

WeekDay week_days[] = {
    {"Sunday", 6},
    {"Monday", 6},
    {"Tuesday", 7},
    {"Wednesday", 8},
    {"Thursday", 8},
    {"Friday", 6},
    {"Saturday", 7}
};

int main() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("Today is %s, %d %s %d\n",
        week_days[t->tm_wday].name,
        t->tm_mday,
        months[t->tm_mon].name,
        t->tm_year + 1900);

    return 0;
}