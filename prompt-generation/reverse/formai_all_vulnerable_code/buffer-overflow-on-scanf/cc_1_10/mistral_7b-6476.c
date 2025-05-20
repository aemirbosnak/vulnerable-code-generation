//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 11

int main() {
    char date_str[MAX_LEN];
    int day, month, year, total_seconds;

    printf("Enter a date in dd-mm-yyyy format: ");
    scanf("%s", date_str);

    sscanf(date_str, "%d-%d-%d", &day, &month, &year);

    // Check if the given date is valid
    if (isValidDate(day, month, year)) {
        int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear(year))
            days_in_month[1] = 29;

        int total_days = 0;

        for (int i = 0; i < month - 1; i++)
            total_days += days_in_month[i];

        total_days += day;

        total_seconds = total_days * 24 * 60 * 60;

        printf("The number of seconds elapsed since 1st January 1970 for %d-%d-%d is %ld.\n", day, month, year, total_seconds);
    } else {
        printf("Invalid date!\n");
    }

    return 0;
}

int isValidDate(int day, int month, int year) {
    // Check if the given month has valid number of days
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month < 1 || month > 12 || day < 1 || day > days_in_month[month - 1])
        return 0;

    // Check if the given year is valid
    if (year < 1 || year > 3000)
        return 0;

    return 1;
}

int isLeapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}