//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char input[20];

    printf("Enter a date in natural language (e.g. today, tomorrow): ");
    fgets(input, 20, stdin);

    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    int day = local_time->tm_mday;
    int month = local_time->tm_mon + 1;
    int year = local_time->tm_year + 1900;

    if (strstr(input, "today")) {
        // no changes needed
    } else if (strstr(input, "tomorrow")) {
        day++;
    } else if (strstr(input, "yesterday")) {
        day--;
    } else {
        printf("Invalid input.\n");
        return 1;
    }

    // check for leap year
    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    // adjust for months with less than 31 days
    int num_days;
    if (month == 2) {
        num_days = leap ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        num_days = 30;
    } else {
        num_days = 31;
    }

    if (day < 1) {
        day = num_days;
        month--;
        if (month == 0) {
            month = 12;
            year--;
        }
    } else if (day > num_days) {
        day = 1;
        month++;
        if (month == 13) {
            month = 1;
            year++;
        }
    }

    printf("The date in standard format is: %02d/%02d/%d\n", day, month, year);

    return 0;
}