//Code Llama-13B DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
/*
 * C Natural Language Date Converter
 *
 * This program converts dates from natural language to a standardized format.
 *
 * Example usage:
 *
 *     $ ./nl_date_converter "today"
 *     Today: 2023-03-25
 *
 *     $ ./nl_date_converter "yesterday"
 *     Yesterday: 2023-03-24
 *
 *     $ ./nl_date_converter "next friday"
 *     Next Friday: 2023-03-31
 *
 *     $ ./nl_date_converter "last week"
 *     Last Week: 2023-03-20
 *
 *     $ ./nl_date_converter "last month"
 *     Last Month: 2023-02-01
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Check if the user provided a date
    if (argc != 2) {
        printf("Usage: %s <date>\n", argv[0]);
        return 1;
    }

    // Get the current date and time
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    // Parse the user-provided date
    char *date = argv[1];
    int year, month, day;
    if (strcmp(date, "today") == 0) {
        year = current_time->tm_year + 1900;
        month = current_time->tm_mon + 1;
        day = current_time->tm_mday;
    } else if (strcmp(date, "yesterday") == 0) {
        year = current_time->tm_year + 1900;
        month = current_time->tm_mon + 1;
        day = current_time->tm_mday - 1;
    } else if (strcmp(date, "next friday") == 0) {
        year = current_time->tm_year + 1900;
        month = current_time->tm_mon + 1;
        day = current_time->tm_mday + (6 - current_time->tm_wday);
    } else if (strcmp(date, "last week") == 0) {
        year = current_time->tm_year + 1900;
        month = current_time->tm_mon + 1;
        day = current_time->tm_mday - 7;
    } else if (strcmp(date, "last month") == 0) {
        year = current_time->tm_year + 1900;
        month = current_time->tm_mon;
        day = current_time->tm_mday;
    } else {
        printf("Invalid date: %s\n", date);
        return 1;
    }

    // Print the converted date
    printf("%s: %d-%02d-%02d\n", date, year, month, day);

    return 0;
}