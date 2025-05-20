//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
#define MAX_DATE_STR_SIZE 30

// Function prototypes
void to_lowercase(char *str);
void parse_date(const char *input, char *output);
int get_month(const char *month_str);
int get_day(const char *day_str);
int get_year(const char *year_str);
void print_usage();

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_DATE_STR_SIZE];

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Enter dates in formats like 'June 5, 2023', '5th of June, 2023', or '2023-06-05':\n");

    // Get user input
    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove the newline character from the input
        input[strcspn(input, "\n")] = 0;

        // Exit condition
        if (strcmp(input, "exit") == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        // Parse the date
        parse_date(input, output);
        printf("Parsed Date: %s\n", output);
    }

    return 0;
}

// Convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Main parsing function
void parse_date(const char *input, char *output) {
    char month[20], day[10], year[10];

    // Clear output
    output[0] = 0;

    // Attempt to match various date formats
    if (sscanf(input, "%s %s %s", month, day, year) == 3) { // e.g., "June 5, 2023"
        to_lowercase(month);
        int m = get_month(month);
        int d = get_day(day);
        int y = atoi(year);
        sprintf(output, "%04d-%02d-%02d", y, m, d);
    } else if (sscanf(input, "%s of %s %s", day, month, year) == 3) { // e.g., "5th of June, 2023"
        to_lowercase(month);
        int m = get_month(month);
        int d = get_day(day);
        int y = atoi(year);
        sprintf(output, "%04d-%02d-%02d", y, m, d);
    } else if (sscanf(input, "%s-%s-%s", year, month, day) == 3) { // e.g., "2023-06-05"
        sprintf(output, "%s-%s-%s", year, month, day);
    } else {
        sprintf(output, "Invalid date format! Please try again.");
    }
}

// Get month as integer from string
int get_month(const char *month_str) {
    const char *months[] = {
        "jan", "feb", "mar", "apr", "may", "jun",
        "jul", "aug", "sep", "oct", "nov", "dec"
    };

    for (int i = 0; i < 12; i++) {
        if (strncmp(month_str, months[i], 3) == 0) {
            return i + 1; // Months are 1-indexed
        }
    }
    return 0; // Invalid month
}

// Get day as integer from string
int get_day(const char *day_str) {
    // Handle ordinal numbers
    char* end;
    long d = strtol(day_str, &end, 10);
    if (end != day_str) {
        return (int)d;
    }
    return 0; // Invalid day
}

// Print usage instructions
void print_usage() {
    printf("Usage:\n");
    printf(" - Enter dates in various formats.\n");
    printf(" - Type 'exit' to quit the program.\n");
}