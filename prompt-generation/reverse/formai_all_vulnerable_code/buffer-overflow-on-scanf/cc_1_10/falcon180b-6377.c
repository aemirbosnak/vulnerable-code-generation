//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

int is_leap_year(int year);
void parse_date_string(char *date_string, int *day, int *month, int *year);
void print_date(int day, int month, int year);

int main() {
    char date_string[MAX_STRING_LENGTH];
    int day, month, year;

    // Ask user to enter a date in mm/dd/yyyy format
    printf("Enter a date in mm/dd/yyyy format: ");
    scanf("%s", date_string);

    // Parse the date string
    parse_date_string(date_string, &day, &month, &year);

    // Check if the entered date is valid
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Invalid date.\n");
        return 1;
    }

    // Check if the entered year is valid
    if (year < 1000 || year > 3000) {
        printf("Invalid year.\n");
        return 1;
    }

    // Check if the entered date is a leap year
    if (is_leap_year(year)) {
        printf("The entered date is a leap year.\n");
    } else {
        printf("The entered date is not a leap year.\n");
    }

    // Print the entered date
    printf("The entered date is: ");
    print_date(day, month, year);

    return 0;
}

int is_leap_year(int year) {
    if (year % 4 == 0 && year % 100!= 0 || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

void parse_date_string(char *date_string, int *day, int *month, int *year) {
    char *token = strtok(date_string, "/");
    if (token == NULL) {
        printf("Invalid date format.\n");
        exit(1);
    }

    *day = atoi(token);

    token = strtok(NULL, "/");
    if (token == NULL) {
        printf("Invalid date format.\n");
        exit(1);
    }

    *month = atoi(token);

    token = strtok(NULL, "/");
    if (token == NULL) {
        printf("Invalid date format.\n");
        exit(1);
    }

    *year = atoi(token);
}

void print_date(int day, int month, int year) {
    printf("%d/%d/%d\n", day, month, year);
}