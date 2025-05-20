//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 256
#define MAX_RESULT 50

// Function Declarations
void to_lowercase(char *str);
void parse_date(const char *input, char *result);
int extract_date_components(const char *input, int *day, int *month, int *year);
void format_date(int day, int month, int year, char *result);
void print_usage();

int main() {
    char input[MAX_BUFFER];
    char result[MAX_RESULT];

    while (1) {
        printf("Enter a date in natural language (or type 'exit' to quit): ");
        fgets(input, MAX_BUFFER, stdin);

        // Remove newline character if present
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Convert input date to lowercase for easier parsing
        to_lowercase(input);

        parse_date(input, result);
        printf("Converted Date: %s\n", result);
    }

    return 0;
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void parse_date(const char *input, char *result) {
    int day, month, year;
    
    if(extract_date_components(input, &day, &month, &year)) {
        format_date(day, month, year, result);
    } else {
        snprintf(result, MAX_RESULT, "Invalid date format. Please try again.");
    }
}

int extract_date_components(const char *input, int *day, int *month, int *year) {
    // Example of supported formats:
    // "25th of December 2023"
    // "December 25, 2023"

    char month_str[20];
    if (sscanf(input, "%d of %19s %d", day, month_str, year) == 3 ||
        sscanf(input, "%19s %d, %d", month_str, day, year) == 3) {
        
        // Convert month string to month number
        if (strcmp(month_str, "january") == 0) *month = 1;
        else if (strcmp(month_str, "february") == 0) *month = 2;
        else if (strcmp(month_str, "march") == 0) *month = 3;
        else if (strcmp(month_str, "april") == 0) *month = 4;
        else if (strcmp(month_str, "may") == 0) *month = 5;
        else if (strcmp(month_str, "june") == 0) *month = 6;
        else if (strcmp(month_str, "july") == 0) *month = 7;
        else if (strcmp(month_str, "august") == 0) *month = 8;
        else if (strcmp(month_str, "september") == 0) *month = 9;
        else if (strcmp(month_str, "october") == 0) *month = 10;
        else if (strcmp(month_str, "november") == 0) *month = 11;
        else if (strcmp(month_str, "december") == 0) *month = 12;
        else return 0; // Invalid month

        return 1; // Successfully extracted date components
    }
    return 0; // Failed to extract
}

void format_date(int day, int month, int year, char *result) {
    snprintf(result, MAX_RESULT, "%04d-%02d-%02d", year, month, day);
}

void print_usage() {
    printf("Usage: Enter a date in one of the following formats:\n");
    printf("1. '25th of December 2023'\n");
    printf("2. 'December 25, 2023'\n");
}