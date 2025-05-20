//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define YEAR_MAX 9999
#define MONTH_MAX 12
#define DAY_MAX 31

typedef struct {
    int year;
    int month;
    int day;
} Date;

void print_date(Date date) {
    printf("%d-%d-%d\n", date.year, date.month, date.day);
}

int is_valid_date(Date date) {
    if (date.year < 1000 || date.year > YEAR_MAX || date.month < 1 || date.month > MONTH_MAX || date.day < 1 || date.day > DAY_MAX) {
        return 0;
    }
    return 1;
}

int convert_date(char* input, Date* date) {
    char* token = strtok(input, "-");
    if (token == NULL) {
        return 0;
    }
    date->year = atoi(token);

    token = strtok(NULL, "-");
    if (token == NULL) {
        return 0;
    }
    date->month = atoi(token);

    token = strtok(NULL, "-");
    if (token == NULL) {
        return 0;
    }
    date->day = atoi(token);

    if (!is_valid_date(*date)) {
        return 0;
    }
    return 1;
}

int main() {
    char input[100];
    Date date;

    printf("Enter a date in YYYY-MM-DD format:\n");
    scanf("%s", input);

    if (convert_date(input, &date)) {
        printf("Valid date: ");
        print_date(date);
    } else {
        printf("Invalid date.\n");
    }

    return 0;
}