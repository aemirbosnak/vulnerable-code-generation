//Code Llama-13B DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 2023
#define MIN_YEAR 1900

int main() {
    int year, month, day, hour, minute, second;
    time_t now;
    struct tm *tm_struct;

    printf("Enter the year, month, day, hour, minute, and second (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &second);

    now = time(NULL);
    tm_struct = localtime(&now);

    if (year < MIN_YEAR || year > MAX_YEAR) {
        printf("Invalid year, please enter a valid year between %d and %d\n", MIN_YEAR, MAX_YEAR);
        return 1;
    }

    if (month < 1 || month > 12) {
        printf("Invalid month, please enter a valid month between 1 and 12\n");
        return 1;
    }

    if (day < 1 || day > 31) {
        printf("Invalid day, please enter a valid day between 1 and 31\n");
        return 1;
    }

    if (hour < 0 || hour > 23) {
        printf("Invalid hour, please enter a valid hour between 0 and 23\n");
        return 1;
    }

    if (minute < 0 || minute > 59) {
        printf("Invalid minute, please enter a valid minute between 0 and 59\n");
        return 1;
    }

    if (second < 0 || second > 59) {
        printf("Invalid second, please enter a valid second between 0 and 59\n");
        return 1;
    }

    tm_struct->tm_year = year - 1900;
    tm_struct->tm_mon = month - 1;
    tm_struct->tm_mday = day;
    tm_struct->tm_hour = hour;
    tm_struct->tm_min = minute;
    tm_struct->tm_sec = second;

    now = mktime(tm_struct);
    tm_struct = localtime(&now);

    printf("The current time and date is: %s", asctime(tm_struct));

    return 0;
}