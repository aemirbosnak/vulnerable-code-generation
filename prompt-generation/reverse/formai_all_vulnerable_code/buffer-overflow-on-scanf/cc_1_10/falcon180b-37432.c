//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_SIZE 1000

typedef struct {
    char *month;
    char *day;
    char *year;
} Date;

void parse_date(char *date_string, Date *date) {
    char *month_str = strtok(date_string, " ");
    date->month = strdup(month_str);

    char *day_str = strtok(NULL, " ");
    date->day = strdup(day_str);

    char *year_str = strtok(NULL, " ");
    date->year = strdup(year_str);
}

void print_date(Date *date) {
    printf("Date: %s %s, %s\n", date->month, date->day, date->year);
}

void convert_date(Date *date) {
    struct tm tm = {0};
    strptime(date->day, "%d", &tm);
    tm.tm_mon = (int) strtol(date->month, NULL, 10) - 1;
    tm.tm_year = (int) strtol(date->year, NULL, 10) - 1900;

    char date_str[MAX_STRING_SIZE];
    strftime(date_str, MAX_STRING_SIZE, "%B %d, %Y", &tm);

    date->month = strdup(date_str);
}

int main() {
    char date_string[MAX_STRING_SIZE];
    printf("Enter a date in the format 'Month Day, Year': ");
    scanf("%[^\n]", date_string);

    Date date = {0};
    parse_date(date_string, &date);

    printf("Original date: ");
    print_date(&date);

    convert_date(&date);

    printf("Converted date: ");
    print_date(&date);

    return 0;
}