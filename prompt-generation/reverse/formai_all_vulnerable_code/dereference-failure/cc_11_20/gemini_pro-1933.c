//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DAYS 365
#define MAX_MONTHS 12

enum {
    JAN = 0,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

int main(void) {
    int year, month, day;
    char *date;
    int days_in_month[MAX_MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%s", date);
    if (strlen(date) != 10) {
        printf("Invalid date format.\n");
        return EXIT_FAILURE;
    }
    if ((sscanf(date, "%d-%d-%d", &year, &month, &day)) != 3) {
        printf("Invalid date format.\n");
        return EXIT_FAILURE;
    }
    if ((year < 0) || (month < 0) || (day < 0)) {
        printf("Invalid date.\n");
        return EXIT_FAILURE;
    }
    if ((month < 0) || (month > 11)) {
        printf("Invalid month.\n");
        return EXIT_FAILURE;
    }
    if ((day < 0) || (day > days_in_month[month])) {
        printf("Invalid day.\n");
        return EXIT_FAILURE;
    }
    int total_days = 0;
    for (int i = 0; i < month; i++) {
        total_days += days_in_month[i];
    }
    total_days += day;
    printf("The day of the year is: %d\n", total_days);
    return EXIT_SUCCESS;
}