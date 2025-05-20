//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATE_LENGTH 80

typedef struct {
    char day[MAX_DATE_LENGTH];
    char month[MAX_DATE_LENGTH];
    char year[MAX_DATE_LENGTH];
} Date;

void initialize_date(Date* date) {
    strcpy(date->day, "");
    strcpy(date->month, "");
    strcpy(date->year, "");
}

void parse_date(Date* date, char* input_date) {
    char* day_str = strtok(input_date, " ");
    char* month_str = strtok(NULL, " ");
    char* year_str = strtok(NULL, " ");

    strcpy(date->day, day_str);
    strcpy(date->month, month_str);
    strcpy(date->year, year_str);
}

int is_valid_date(Date* date) {
    int day, month, year;
    char* endptr;

    day = strtol(date->day, &endptr, 10);
    month = strtol(date->month, &endptr, 10);
    year = strtol(date->year, &endptr, 10);

    if (day < 1 || day > 31) {
        return 0;
    }

    if (month < 1 || month > 12) {
        return 0;
    }

    if (year < 1000 || year > 9999) {
        return 0;
    }

    return 1;
}

void format_date(Date* date, char* output_date) {
    char* day_str = strdup(date->day);
    char* month_str = strdup(date->month);
    char* year_str = strdup(date->year);

    strcat(output_date, day_str);
    strcat(output_date, " ");
    strcat(output_date, month_str);
    strcat(output_date, " ");
    strcat(output_date, year_str);
}

int main() {
    Date input_date, output_date;
    char input_string[MAX_DATE_LENGTH];
    char output_string[MAX_DATE_LENGTH];

    initialize_date(&input_date);
    initialize_date(&output_date);

    printf("Enter a date in the format day/month/year: ");
    scanf("%s", input_string);

    parse_date(&input_date, input_string);
    if (!is_valid_date(&input_date)) {
        printf("Invalid date.\n");
        return 1;
    }

    format_date(&input_date, output_string);
    printf("Formatted date: %s\n", output_string);

    return 0;
}