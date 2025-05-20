//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LEN 20

typedef struct Date {
    int year;
    int month;
    int day;
} Date;

int main() {
    char input[MAX_DATE_LEN];
    Date date;

    printf("Enter a date (YYYY-MM-DD): ");
    scanf("%s", input);

    if (parse_date(input, &date) == 0) {
        printf("Date: %d-%d-%d\n", date.year, date.month, date.day);
    } else {
        printf("Invalid date.\n");
    }

    return 0;
}

int parse_date(char *date_str, Date *date) {
    char *year_str, *month_str, *day_str;
    int year, month, day;

    if (strlen(date_str) < 10) {
        return 1;
    }

    year_str = strtok(date_str, "-");
    month_str = strtok(NULL, "-");
    day_str = strtok(NULL, "");

    year = atoi(year_str);
    month = atoi(month_str);
    day = atoi(day_str);

    if (year < 1000 || year > 2023) {
        return 1;
    }

    if (month < 1 || month > 12) {
        return 1;
    }

    if (day < 1 || day > 31) {
        return 1;
    }

    date->year = year;
    date->month = month;
    date->day = day;

    return 0;
}