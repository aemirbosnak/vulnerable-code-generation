//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LEN 100

// Function to parse date from natural language input
int parseDate(const char *input, struct tm *date) {
    char month[20];
    int day, year;

    // Search for keywords in the input string
    if (sscanf(input, "%d %s %d", &day, month, &year) == 3) {
        // Map month names to numbers
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
        else return 0;

        date->tm_mday = day;
        date->tm_year = year - 1900; // Years since 1900
        date->tm_isdst = -1; // Let the system determine if DST is in effect
        return 1;
    }
    return 0;
}

// Function to validate the parsed date
int validateDate(struct tm *date) {
    time_t t = mktime(date);
    return t != -1;
}

// Function to format the date into a string
void formatDate(struct tm *date, char *buffer, size_t size) {
    strftime(buffer, size, "%Y-%m-%d", date);
}

// Main function
int main() {
    char input[MAX_INPUT_LEN];
    struct tm date = {0};
    char formattedDate[11]; // YYYY-MM-DD

    printf("Welcome to the Brave Natural Language Date Converter!\n");
    printf("Please enter a date in the format 'DD Month YYYY' (e.g., '25 December 2023'):\n");

    // Get user input
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // Parse the input date
        if (parseDate(input, &date)) {
            // Validate the parsed date
            if (validateDate(&date)) {
                formatDate(&date, formattedDate, sizeof(formattedDate));
                printf("Congratulations! You've entered a valid date: %s\n", formattedDate);
            } else {
                printf("Oh no! The date you entered is invalid.\n");
            }
        } else {
            printf("Oops! I couldn't understand the format you provided.\n");
        }
    } else {
        printf("An error occurred while reading input. Please try again.\n");
    }

    return 0;
}