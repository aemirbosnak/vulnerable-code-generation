//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char* month;
    char* day;
    char* year;
} Date;

Date* parse_date(char* input) {
    Date* date = malloc(sizeof(Date));
    char* month_start = strtok(input, " ");
    char* day_start = strtok(NULL, " ");
    char* year_start = strtok(NULL, " ");

    date->month = malloc(strlen(month_start) + 1);
    strcpy(date->month, month_start);

    date->day = malloc(strlen(day_start) + 1);
    strcpy(date->day, day_start);

    date->year = malloc(strlen(year_start) + 1);
    strcpy(date->year, year_start);

    return date;
}

void print_date(Date* date) {
    printf("Month: %s\n", date->month);
    printf("Day: %s\n", date->day);
    printf("Year: %s\n", date->year);
}

int main() {
    char input[MAX_STRING_LENGTH];
    printf("Enter a date (MM/DD/YYYY): ");
    scanf("%s", input);

    Date* date = parse_date(input);
    print_date(date);

    free(date->month);
    free(date->day);
    free(date->year);
    free(date);

    return 0;
}