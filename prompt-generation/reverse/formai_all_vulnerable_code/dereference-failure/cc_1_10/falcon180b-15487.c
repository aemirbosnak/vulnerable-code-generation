//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

#define MAX_DATE_LENGTH 21
#define MAX_MONTH_LENGTH 9
#define MAX_DAY_LENGTH 9
#define MAX_YEAR_LENGTH 4

char *get_date_string(int day, int month, int year) {
    char *date_string = malloc(MAX_DATE_LENGTH * sizeof(char));
    snprintf(date_string, MAX_DATE_LENGTH, "%02d/%02d/%04d", day, month, year);
    return date_string;
}

int get_day(char *date_string) {
    char *day_str = strtok(date_string, "/");
    int day = atoi(day_str);
    return day;
}

int get_month(char *date_string) {
    char *month_str = strtok(NULL, "/");
    int month = atoi(month_str);
    return month;
}

int get_year(char *date_string) {
    char *year_str = strtok(NULL, "/");
    int year = atoi(year_str);
    return year;
}

void print_date(int day, int month, int year) {
    printf("%s/%s/%s\n", get_date_string(day, month, year), get_month(get_date_string(day, month, year)), get_year(get_date_string(day, month, year)));
}

int main() {
    char *date_string;
    int day, month, year;

    printf("Enter a date in the format DD/MM/YYYY: ");
    scanf("%s", date_string);

    day = get_day(date_string);
    month = get_month(date_string);
    year = get_year(date_string);

    printf("Today's date is: ");
    print_date(day, month, year);

    return 0;
}