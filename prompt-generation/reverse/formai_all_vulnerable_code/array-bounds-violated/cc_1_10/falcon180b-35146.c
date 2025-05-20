//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATE_LENGTH 100
#define MAX_MONTH_NAMES_LENGTH 12
#define MONTH_NAMES_LENGTH 3

enum {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

char* month_names[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

struct tm* parse_date(char* date_string) {
    struct tm* date = malloc(sizeof(struct tm));
    strptime(date_string, "%d %b %Y", date);
    return date;
}

char* format_date(struct tm* date, char* format) {
    char* result = malloc(MAX_DATE_LENGTH);
    strftime(result, MAX_DATE_LENGTH, format, date);
    return result;
}

int main() {
    char input[MAX_DATE_LENGTH];
    char* token;
    struct tm* date;
    char* month_name;
    int year, month, day;

    printf("Enter a date in the format DD/MM/YYYY: ");
    fgets(input, MAX_DATE_LENGTH, stdin);

    token = strtok(input, "/");
    day = atoi(token);
    token = strtok(NULL, "/");
    month = atoi(token);
    token = strtok(NULL, "/");
    year = atoi(token);

    date = parse_date(input);
    month_name = month_names[date->tm_mon];

    printf("Today's date is %s, %d %s %d\n", month_name, day, month_names[date->tm_mon], year);

    free(date);
    return 0;
}