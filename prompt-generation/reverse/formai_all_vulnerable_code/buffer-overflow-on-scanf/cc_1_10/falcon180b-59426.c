//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 80

typedef struct {
    char* month_name;
    int month_number;
    char* day_name;
    int day_number;
} date_info;

date_info get_date_info(int year, int month, int day) {
    struct tm date_time = {0};
    time_t time = mktime(&date_time);
    date_info info = {0};

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        info.month_name = "Invalid date";
        info.month_number = 0;
        info.day_name = "Invalid date";
        info.day_number = 0;
        return info;
    }

    date_time.tm_year = year - 1900;
    date_time.tm_mon = month - 1;
    date_time.tm_mday = day;

    strftime(info.month_name, MAX_STRING_LENGTH, "%B", &date_time);
    info.month_number = date_time.tm_mon + 1;
    strftime(info.day_name, MAX_STRING_LENGTH, "%A", &date_time);
    info.day_number = day;

    return info;
}

void print_date_info(date_info info) {
    printf("Today is %s, the %d of %s.\n", info.day_name, info.day_number, info.month_name);
}

int main() {
    int year, month, day;

    printf("Enter the year: ");
    scanf("%d", &year);

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    printf("Enter the day (1-31): ");
    scanf("%d", &day);

    date_info info = get_date_info(year, month, day);
    if (info.month_number == 0) {
        printf("Invalid date.\n");
    } else {
        print_date_info(info);
    }

    return 0;
}