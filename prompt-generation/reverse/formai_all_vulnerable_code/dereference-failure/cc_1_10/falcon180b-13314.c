//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 100
#define MAX_MONTH_LENGTH 9
#define MAX_YEAR_LENGTH 4
#define MAX_DAY_LENGTH 2

typedef struct {
    char day[MAX_DAY_LENGTH];
    char month[MAX_MONTH_LENGTH];
    char year[MAX_YEAR_LENGTH];
} Date;

void print_date(const Date *date) {
    printf("%s %s, %s\n", date->month, date->day, date->year);
}

int parse_date(const char *date_str, Date *date) {
    char *token = strtok(date_str, " ");
    if (token == NULL) {
        return 0;
    }

    strcpy(date->month, token);

    token = strtok(NULL, " ");
    if (token == NULL) {
        return 0;
    }

    strcpy(date->day, token);

    token = strtok(NULL, ", ");
    if (token == NULL) {
        return 0;
    }

    strcpy(date->year, token);

    if (strlen(date->month)!= MAX_MONTH_LENGTH ||
        strlen(date->day)!= MAX_DAY_LENGTH ||
        strlen(date->year)!= MAX_YEAR_LENGTH) {
        return 0;
    }

    if (!isdigit(date->day[0]) ||!isdigit(date->day[1])) {
        return 0;
    }

    if (!isdigit(date->month[0]) ||!isdigit(date->month[1]) ||
       !isdigit(date->month[2])) {
        return 0;
    }

    if (!isdigit(date->year[0]) ||!isdigit(date->year[1]) ||
       !isdigit(date->year[2]) ||!isdigit(date->year[3])) {
        return 0;
    }

    return 1;
}

int main() {
    char input[MAX_DATE_LENGTH];
    Date date;

    printf("Enter a date in the format 'MM DD, YYYY': ");
    fgets(input, MAX_DATE_LENGTH, stdin);

    if (parse_date(input, &date)) {
        print_date(&date);
    } else {
        printf("Invalid date format\n");
    }

    return 0;
}