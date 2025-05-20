//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: systematic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

struct tm get_date_from_string(char *date_str) {
    struct tm date = {0};
    char delimiter = '/';
    char *token;
    int day, month, year;

    // Extract day
    token = strtok(date_str, &delimiter);
    if (token == NULL) {
        printf("Invalid date format: %s\n", date_str);
        exit(1);
    }
    day = atoi(token);

    // Extract month
    token = strtok(NULL, &delimiter);
    if (token == NULL) {
        printf("Invalid date format: %s\n", date_str);
        exit(1);
    }
    month = atoi(token) - 1;

    // Extract year
    token = strtok(NULL, &delimiter);
    if (token == NULL) {
        printf("Invalid date format: %s\n", date_str);
        exit(1);
    }
    year = atoi(token);

    // Check if date is valid
    if (year < 1000 || year > 9999) {
        printf("Invalid date: %s\n", date_str);
        exit(1);
    }
    if (month < 0 || month > 11) {
        printf("Invalid month: %s\n", date_str);
        exit(1);
    }
    if (day < 1 || day > 31) {
        printf("Invalid day: %s\n", date_str);
        exit(1);
    }

    // Set date fields
    date.tm_year = year - 1900;
    date.tm_mon = month;
    date.tm_mday = day;

    return date;
}

char *get_date_string(struct tm date) {
    char date_str[MAX_LEN] = {0};
    strftime(date_str, MAX_LEN, "%d/%m/%Y", &date);
    return strdup(date_str);
}

int main() {
    char input_date[MAX_LEN] = {0};
    struct tm date;
    char *output_date;

    // Get input date from user
    printf("Enter a date in DD/MM/YYYY format: ");
    scanf("%s", input_date);

    // Convert input date to struct tm
    date = get_date_from_string(input_date);

    // Convert struct tm to output date string
    output_date = get_date_string(date);

    // Print output date
    printf("Input date: %s\n", input_date);
    printf("Output date: %s\n", output_date);

    return 0;
}