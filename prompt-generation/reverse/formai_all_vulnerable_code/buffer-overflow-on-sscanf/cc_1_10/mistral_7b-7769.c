//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 21

int main(void) {
    char input[MAX_INPUT_SIZE];
    int day, month, year;
    struct tm converted_time;
    time_t unix_timestamp;

    printf("Enter a date in the format DD-MM-YYYY: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    sscanf(input, "%d-%d-%d", &day, &month, &year);

    if (check_validity(day, month, year)) {
        memset(&converted_time, 0, sizeof(converted_time));
        converted_time.tm_sec = 0;
        converted_time.tm_min = 0;
        converted_time.tm_hour = 0;
        converted_time.tm_mday = day;
        converted_time.tm_mon = month - 1;
        converted_time.tm_year = year - 1900;

        unix_timestamp = mktime(&converted_time);
        printf("The Unix timestamp for the given date is: %ld\n", (long)unix_timestamp);
    } else {
        printf("Invalid date format or invalid date.\n");
    }

    return 0;
}

int check_validity(int day, int month, int year) {
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1) {
        return 0;
    }

    if (month == 2) {
        if (is_leap_year(year)) {
            if (day > 29) {
                return 0;
            }
        } else {
            if (day > 28) {
                return 0;
            }
        }
    }

    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day > month_days[month - 1]) {
        return 0;
    }

    return 1;
}

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}