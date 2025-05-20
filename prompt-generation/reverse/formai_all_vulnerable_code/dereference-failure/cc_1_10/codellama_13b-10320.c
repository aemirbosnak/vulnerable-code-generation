//Code Llama-13B DATASET v1.0 Category: Natural Language Date Converter ; Style: light-weight
/*
* C Natural Language Date Converter
*
* This program converts a natural language date to a machine-readable date.
*
* Usage:
*   ./nl_date_converter <natural language date>
*
* Example:
*   ./nl_date_converter "today"
*   ./nl_date_converter "tomorrow"
*   ./nl_date_converter "next monday"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to convert a natural language date to a machine-readable date
int nl_date_to_mr_date(const char *nl_date, struct tm *mr_date) {
    // Convert the natural language date to lowercase
    char nl_date_lower[strlen(nl_date) + 1];
    strcpy(nl_date_lower, nl_date);
    for (int i = 0; i < strlen(nl_date_lower); i++) {
        nl_date_lower[i] = tolower(nl_date_lower[i]);
    }

    // Check if the date is "today"
    if (strcmp(nl_date_lower, "today") == 0) {
        time_t now = time(NULL);
        struct tm *now_tm = localtime(&now);
        mr_date->tm_year = now_tm->tm_year;
        mr_date->tm_mon = now_tm->tm_mon;
        mr_date->tm_mday = now_tm->tm_mday;
        return 1;
    }

    // Check if the date is "tomorrow"
    if (strcmp(nl_date_lower, "tomorrow") == 0) {
        time_t now = time(NULL);
        struct tm *now_tm = localtime(&now);
        mr_date->tm_year = now_tm->tm_year;
        mr_date->tm_mon = now_tm->tm_mon;
        mr_date->tm_mday = now_tm->tm_mday + 1;
        return 1;
    }

    // Check if the date is "next <day of the week>"
    char *day_of_week = strtok(nl_date_lower, " ");
    if (strcmp(day_of_week, "next") == 0) {
        day_of_week = strtok(NULL, " ");
        time_t now = time(NULL);
        struct tm *now_tm = localtime(&now);
        int today = now_tm->tm_wday;
        int day_diff = 0;
        if (strcmp(day_of_week, "monday") == 0) {
            day_diff = 1 - today;
        } else if (strcmp(day_of_week, "tuesday") == 0) {
            day_diff = 2 - today;
        } else if (strcmp(day_of_week, "wednesday") == 0) {
            day_diff = 3 - today;
        } else if (strcmp(day_of_week, "thursday") == 0) {
            day_diff = 4 - today;
        } else if (strcmp(day_of_week, "friday") == 0) {
            day_diff = 5 - today;
        } else if (strcmp(day_of_week, "saturday") == 0) {
            day_diff = 6 - today;
        } else if (strcmp(day_of_week, "sunday") == 0) {
            day_diff = 7 - today;
        }
        mr_date->tm_year = now_tm->tm_year;
        mr_date->tm_mon = now_tm->tm_mon;
        mr_date->tm_mday = now_tm->tm_mday + day_diff;
        return 1;
    }

    // Invalid date
    return 0;
}

int main(int argc, char **argv) {
    // Check the number of command-line arguments
    if (argc != 2) {
        printf("Usage: %s <natural language date>\n", argv[0]);
        return 1;
    }

    // Convert the natural language date to a machine-readable date
    struct tm mr_date;
    if (nl_date_to_mr_date(argv[1], &mr_date) == 0) {
        printf("Invalid date: %s\n", argv[1]);
        return 1;
    }

    // Print the machine-readable date
    char buf[100];
    strftime(buf, sizeof(buf), "%Y-%m-%d", &mr_date);
    printf("%s\n", buf);

    return 0;
}