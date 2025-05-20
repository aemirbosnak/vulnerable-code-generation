//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DATE_LEN 11
#define MIN_DATE_LEN 6
#define MAX_DAY 31
#define MIN_DAY 1
#define MAX_MONTH 12
#define MIN_MONTH 1
#define MAX_YEAR 2023
#define MIN_YEAR 1

int main()
{
    char *date;
    int day, month, year;
    bool valid = false;

    printf("Enter a date in the format MM/DD/YYYY: ");
    scanf("%s", &date);

    if (strlen(date) < MIN_DATE_LEN || strlen(date) > MAX_DATE_LEN) {
        printf("Invalid date - length must be between %d and %d characters\n", MIN_DATE_LEN, MAX_DATE_LEN);
        return EXIT_FAILURE;
    }

    if (date[2] != '/' || date[5] != '/') {
        printf("Invalid date - must contain forward slashes (/) as date separators\n");
        return EXIT_FAILURE;
    }

    day = atoi(&date[3]);
    if (day < MIN_DAY || day > MAX_DAY) {
        printf("Invalid day - must be between %d and %d\n", MIN_DAY, MAX_DAY);
        return EXIT_FAILURE;
    }

    month = atoi(&date[0]);
    if (month < MIN_MONTH || month > MAX_MONTH) {
        printf("Invalid month - must be between %d and %d\n", MIN_MONTH, MAX_MONTH);
        return EXIT_FAILURE;
    }

    year = atoi(&date[6]);
    if (year < MIN_YEAR || year > MAX_YEAR) {
        printf("Invalid year - must be between %d and %d\n", MIN_YEAR, MAX_YEAR);
        return EXIT_FAILURE;
    }

    printf("Valid date: %s\n", date);
    return EXIT_SUCCESS;
}