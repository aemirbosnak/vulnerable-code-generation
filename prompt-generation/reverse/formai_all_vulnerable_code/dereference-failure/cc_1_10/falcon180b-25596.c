//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_MONTH_NAME_LENGTH 9
#define MAX_WEEKDAY_NAME_LENGTH 9

typedef struct {
    int day;
    int month;
    int year;
} date_t;

typedef struct {
    char *name;
    int length;
} month_name_t;

typedef struct {
    char *name;
    int length;
} weekday_name_t;

month_name_t month_names[] = {
    {"January", 9},
    {"February", 9},
    {"March", 6},
    {"April", 7},
    {"May", 4},
    {"June", 5},
    {"July", 6},
    {"August", 7},
    {"September", 9},
    {"October", 8},
    {"November", 9},
    {"December", 9}
};

weekday_name_t weekday_names[] = {
    {"Sunday", 7},
    {"Monday", 6},
    {"Tuesday", 8},
    {"Wednesday", 9},
    {"Thursday", 8},
    {"Friday", 6},
    {"Saturday", 8}
};

date_t get_current_date() {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    date_t date = {
       .day = tm->tm_mday,
       .month = tm->tm_mon + 1,
       .year = tm->tm_year + 1900
    };

    return date;
}

void print_date(date_t date) {
    printf("%02d/%02d/%04d\n", date.day, date.month, date.year);
}

void print_month_name(date_t date) {
    int month_index = date.month - 1;
    if (month_index < 0 || month_index >= 12) {
        printf("Invalid month\n");
        return;
    }

    month_name_t *month_name = &month_names[month_index];
    printf("%s\n", month_name->name);
}

void print_weekday_name(date_t date) {
    int weekday_index = date.day % 7;
    if (weekday_index < 0 || weekday_index >= 7) {
        printf("Invalid weekday\n");
        return;
    }

    weekday_name_t *weekday_name = &weekday_names[weekday_index];
    printf("%s\n", weekday_name->name);
}

int main() {
    date_t date = get_current_date();
    printf("Today's date is: ");
    print_date(date);
    printf("Today's month is: ");
    print_month_name(date);
    printf("Today's weekday is: ");
    print_weekday_name(date);

    return 0;
}