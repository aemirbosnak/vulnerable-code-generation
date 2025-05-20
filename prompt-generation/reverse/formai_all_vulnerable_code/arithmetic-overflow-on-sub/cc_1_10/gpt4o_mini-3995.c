//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100

// Function to convert natural language dates into struct tm
int parse_date(const char *input, struct tm *date) {
    char month[10];
    int day, year;

    // Basic parsing for natural language dates
    if (sscanf(input, "%d %s %d", &day, month, &year) == 3) {
        // Convert month from string to number
        if (strcasecmp(month, "January") == 0) date->tm_mon = 0;
        else if (strcasecmp(month, "February") == 0) date->tm_mon = 1;
        else if (strcasecmp(month, "March") == 0) date->tm_mon = 2;
        else if (strcasecmp(month, "April") == 0) date->tm_mon = 3;
        else if (strcasecmp(month, "May") == 0) date->tm_mon = 4;
        else if (strcasecmp(month, "June") == 0) date->tm_mon = 5;
        else if (strcasecmp(month, "July") == 0) date->tm_mon = 6;
        else if (strcasecmp(month, "August") == 0) date->tm_mon = 7;
        else if (strcasecmp(month, "September") == 0) date->tm_mon = 8;
        else if (strcasecmp(month, "October") == 0) date->tm_mon = 9;
        else if (strcasecmp(month, "November") == 0) date->tm_mon = 10;
        else if (strcasecmp(month, "December") == 0) date->tm_mon = 11;
        else return 0; // Month not recognized

        date->tm_mday = day;
        date->tm_year = year - 1900; // tm_year is years since 1900
        date->tm_hour = 0; // Default hour
        date->tm_min = 0;  // Default minute
        date->tm_sec = 0;  // Default second
        date->tm_isdst = -1; // Let mktime decide whether it's daylight saving time
        return 1; // Successfully parsed
    }
    return 0; // Parsing failed
}

// Function to convert struct tm to formatted date string
void format_date(struct tm *date, char *output, size_t len) {
    strftime(output, len, "%A, %B %d, %Y", date);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    struct tm date;
    char formatted_date[100];

    printf("Enter a date in natural language (e.g., '15 March 2023'): ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (parse_date(input, &date)) {
            // Convert struct tm to time_t and then format it
            time_t time_val = mktime(&date);
            
            if (time_val != -1) {
                format_date(&date, formatted_date, sizeof(formatted_date));
                printf("Formatted Date: %s\n", formatted_date);
            } else {
                printf("Error converting date to time.\n");
            }
        } else {
            printf("Failed to parse date. Please use format 'DD Month YYYY'.\n");
        }
    }
    return 0;
}