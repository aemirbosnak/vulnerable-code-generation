//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 20
#define MAX_MONTH_LENGTH 9
#define MAX_YEAR_LENGTH 4
#define MAX_HOUR_LENGTH 2
#define MAX_MINUTE_LENGTH 2
#define MAX_SECOND_LENGTH 2
#define MAX_TIMEZONE_LENGTH 10

typedef struct {
    char day[MAX_DATE_LENGTH];
    char month[MAX_MONTH_LENGTH];
    char year[MAX_YEAR_LENGTH];
    char hour[MAX_HOUR_LENGTH];
    char minute[MAX_MINUTE_LENGTH];
    char second[MAX_SECOND_LENGTH];
    char timezone[MAX_TIMEZONE_LENGTH];
} Date;

void parse_date(const char* input, Date* date) {
    strncpy(date->day, input, MAX_DATE_LENGTH);
    strncpy(date->month, input + 8, MAX_MONTH_LENGTH);
    strncpy(date->year, input + 4, MAX_YEAR_LENGTH);
}

void parse_time(const char* input, Date* date) {
    strncpy(date->hour, input + 11, MAX_HOUR_LENGTH);
    strncpy(date->minute, input + 14, MAX_MINUTE_LENGTH);
    strncpy(date->second, input + 17, MAX_SECOND_LENGTH);
    strncpy(date->timezone, input + 20, MAX_TIMEZONE_LENGTH);
}

void print_date(const Date* date) {
    printf("Date: %s/%s/%s\n", date->day, date->month, date->year);
}

void print_time(const Date* date) {
    printf("Time: %s:%s:%s %s\n", date->hour, date->minute, date->second, date->timezone);
}

int main() {
    char input[MAX_DATE_LENGTH + MAX_TIMEZONE_LENGTH + 1];
    Date date;

    printf("Enter date and time in the format YYYY/MM/DD HH:MM:SS TIMEZONE:\n");
    scanf("%s", input);

    parse_date(input, &date);
    parse_time(input, &date);

    printf("Original input: %s\n", input);
    print_date(&date);
    print_time(&date);

    return 0;
}