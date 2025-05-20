//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 100
#define MONTH_NAMES_LENGTH 12

typedef struct {
    int day, month, year;
} Date;

void print_date(Date date) {
    printf("%d/%d/%d\n", date.month, date.day, date.year);
}

int is_valid_date(Date date, int *error_code) {
    if (date.month < 1 || date.month > 12) {
        *error_code = 1;
        return 0;
    }
    if (date.day < 1 || date.day > 31) {
        *error_code = 2;
        return 0;
    }
    if (date.year < 1000 || date.year > 9999) {
        *error_code = 3;
        return 0;
    }
    return 1;
}

int main() {
    char input_date[MAX_DATE_LENGTH];
    Date date;
    int error_code;

    printf("Enter a date in MM/DD/YYYY format: ");
    fgets(input_date, MAX_DATE_LENGTH, stdin);

    if (sscanf(input_date, "%d/%d/%d", &date.month, &date.day, &date.year)!= 3) {
        printf("Invalid date format.\n");
        return 1;
    }

    if (is_valid_date(date, &error_code)) {
        printf("Valid date.\n");
        print_date(date);
    } else {
        switch (error_code) {
            case 1:
                printf("Invalid month.\n");
                break;
            case 2:
                printf("Invalid day.\n");
                break;
            case 3:
                printf("Invalid year.\n");
                break;
        }
    }

    return 0;
}