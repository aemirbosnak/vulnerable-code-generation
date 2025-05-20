//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MONTHS_IN_YEAR 12
#define DATE_FORMAT "M j,Y"
#define MAX_INPUT_SIZE 100

typedef struct {
    int month;
    int day;
    int year;
} Date;

int get_month_length(int month, int year) {
    static int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return month_days[month - 1];
    if (is_leap_year(year))
        return month_days[1] + 1;
    else
        return month_days[1] - 1;
}

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return 1;
            else
                return 0;
        } else
            return 1;
    } else
        return 0;
}

int parse_date_string(char *date_str, Date *date) {
    char month[3], day[3], year[5];
    int mon, day_num, idx;

    strncpy(month, date_str, 2);
    month[2] = '\0';
    mon = atoi(month);

    idx = strcspn(date_str, " ,-") + 1;
    strncpy(day, date_str + idx, 2);
    day_num = atoi(day);

    idx = strcspn(date_str + idx, "\n") + idx;
    strncpy(year, date_str + idx, 5);

    date->month = mon;
    date->day = day_num;
    date->year = atoi(year);

    if (mon < 1 || mon > MONTHS_IN_YEAR || day_num < 1 || day_num > get_month_length(mon, date->year))
        return 0;

    return 1;
}

int main() {
    char input[MAX_INPUT_SIZE];
    Date date;

    printf("Enter a date in the format 'M j,Y' (e.g. '3 M 2022'): ");
    scanf("%s", input);

    if (parse_date_string(input, &date)) {
        printf("The date %d-%02d-%02d is valid.\n", date.year, date.month, date.day);
    } else {
        printf("Invalid date format.\n");
    }

    return 0;
}