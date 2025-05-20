//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 100

#define DAYS_IN_MONTH(month, year) \
    ((month) == 2 && ((year) % 4 == 0 && (year) % 100!= 0 || (year) % 400 == 0))? 29 : \
    ((month) == 4 || (month) == 6 || (month) == 9 || (month) == 11)? 30 : 31

typedef struct {
    int day;
    int month;
    int year;
} date_t;

void parse_date(date_t *date, const char *input) {
    int i = 0;
    while (isspace(input[i])) {
        i++;
    }
    if (i >= MAX_DATE_LENGTH) {
        printf("Invalid date format\n");
        exit(1);
    }
    if (sscanf(input + i, "%d/%d/%d", &date->day, &date->month, &date->year)!= 3) {
        printf("Invalid date format\n");
        exit(1);
    }
    if (date->month < 1 || date->month > 12) {
        printf("Invalid month\n");
        exit(1);
    }
    if (date->day < 1 || date->day > DAYS_IN_MONTH(date->month, date->year)) {
        printf("Invalid day\n");
        exit(1);
    }
}

void print_date(const date_t *date) {
    printf("%d-%02d-%02d", date->year, date->month, date->day);
}

int main() {
    date_t date;
    char input[MAX_DATE_LENGTH];
    printf("Enter a date (YYYY-MM-DD): ");
    fgets(input, MAX_DATE_LENGTH, stdin);
    parse_date(&date, input);
    printf("Parsed date: ");
    print_date(&date);
    return 0;
}