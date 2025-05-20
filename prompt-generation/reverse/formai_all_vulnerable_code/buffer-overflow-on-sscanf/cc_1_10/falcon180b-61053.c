//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 20
#define MONTH_NAMES_LENGTH 3

/* Function prototypes */
void print_date(int day, int month, int year);
int is_valid_date(int day, int month, int year);
char *get_month_name(int month);

int main() {
    char input_date[MAX_DATE_LENGTH];
    int day, month, year;
    char *month_name;

    /* Get input date from user */
    printf("Enter a date in MM/DD/YYYY format: ");
    fgets(input_date, MAX_DATE_LENGTH, stdin);

    /* Remove newline character */
    input_date[strcspn(input_date, "\n")] = '\0';

    /* Parse input date */
    sscanf(input_date, "%d/%d/%d", &month, &day, &year);

    /* Check if date is valid */
    if (!is_valid_date(day, month, year)) {
        printf("Invalid date.\n");
        exit(1);
    }

    /* Convert month number to name */
    month_name = get_month_name(month);

    /* Print date in natural language format */
    printf("Today is %s %d, %d.\n", month_name, day, year);

    return 0;
}

/* Print date in natural language format */
void print_date(int day, int month, int year) {
    char *month_name = get_month_name(month);
    printf("%s %d, %d\n", month_name, day, year);
}

/* Check if date is valid */
int is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return 0;
    }

    if (day < 1 || day > 31) {
        return 0;
    }

    if (year < 1900 || year > 2099) {
        return 0;
    }

    return 1;
}

/* Get month name from month number */
char *get_month_name(int month) {
    static char *month_names[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return month_names[month - 1];
}