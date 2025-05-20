//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

char* month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void print_date(Date* date) {
    printf("%s %d, %d\n", month_names[date->month], date->day, date->year);
}

bool is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0) {
        return true;
    }
    return false;
}

int days_in_month(int month, int year) {
    if (month == 2) {
        if (is_leap_year(year)) {
            return 29;
        }
        return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

Date* parse_date(char* input) {
    Date* date = malloc(sizeof(Date));
    char* token = strtok(input, " ");
    if (token == NULL) {
        printf("Invalid date format\n");
        exit(1);
    }
    date->month = atoi(token) - 1;
    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Invalid date format\n");
        exit(1);
    }
    date->day = atoi(token);
    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Invalid date format\n");
        exit(1);
    }
    date->year = atoi(token);
    return date;
}

int main() {
    char* input;
    Date* date;
    input = malloc(1000 * sizeof(char));
    printf("Enter a date in the format 'Month Day, Year': ");
    scanf("%s", input);
    date = parse_date(input);
    printf("Date: ");
    print_date(date);
    free(date);
    free(input);
    return 0;
}