//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100
#define MAX_DATE_LENGTH 11

// Function prototypes
void get_date_input(char *input);
int parse_date(const char *input, struct tm *date);
void format_date(const struct tm *date, char *output);
void display_result(const char *output);

int main() {
    char user_input[MAX_INPUT_LENGTH];
    struct tm date;
    char formatted_date[MAX_DATE_LENGTH];

    // Get date input from the user
    get_date_input(user_input);
    
    // Parse the user input into date structure
    if (parse_date(user_input, &date)) {
        // Format the parsed date
        format_date(&date, formatted_date);
        // Display the result
        display_result(formatted_date);
    } else {
        printf("Invalid date format. Please try again.\n");
    }

    return 0;
}

// Function to get date input from the user
void get_date_input(char *input) {
    printf("Enter a date (e.g., 'January 15, 2021'): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;  // Remove trailing newline
}

// Function to parse the date from the input string
int parse_date(const char *input, struct tm *date) {
    char month[20];
    int day, year;

    // Check the format of input and parse it
    int matches = sscanf(input, "%19s %d, %d", month, &day, &year);
    
    if (matches != 3) {
        return 0;  // Return failure if parsing fails
    }

    // Convert month string to lowercase for comparison
    for (int i = 0; month[i]; i++) {
        month[i] = tolower(month[i]);
    }

    // Map month string to month number
    const char *months[] = {
        "january", "february", "march", "april", "may",
        "june", "july", "august", "september", "october",
        "november", "december"
    };

    date->tm_mon = -1;  // Initialize to an invalid month
    for (int i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0) {
            date->tm_mon = i;  // Set month
            break;
        }
    }

    // Check if month was a valid one
    if (date->tm_mon == -1) {
        return 0; // Invalid month
    }

    date->tm_mday = day;
    date->tm_year = year - 1900; // Year since 1900
    date->tm_hour = 0;
    date->tm_min = 0;
    date->tm_sec = 0;
    date->tm_isdst = -1; // Determine if DST is in effect

    // Normalize date
    if (mktime(date) == -1) {
        return 0; // Failed to normalize date
    }

    return 1; // Success
}

// Function to format the date into a standard format
void format_date(const struct tm *date, char *output) {
    strftime(output, MAX_DATE_LENGTH, "%Y-%m-%d", date);
}

// Function to display the result
void display_result(const char *output) {
    printf("Converted date: %s\n", output);
}