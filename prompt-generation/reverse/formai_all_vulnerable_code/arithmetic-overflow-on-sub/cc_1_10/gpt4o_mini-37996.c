//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

// Function to convert natural language date to struct tm
int parseDate(const char *input, struct tm *date) {
    char monthStr[20];
    int day, year;

    // Use sscanf to extract the date components
    if (sscanf(input, "%d %s %d", &day, monthStr, &year) == 3) {
        // Convert month string to month number (1-12)
        char *months[] = {
            "January", "February", "March", "April", "May", "June", 
            "July", "August", "September", "October", "November", "December"
        };
        for (int i = 0; i < 12; i++) {
            if (strcasecmp(monthStr, months[i]) == 0) {
                date->tm_mon = i; // 0-11
                date->tm_mday = day;
                date->tm_year = year - 1900; // Year since 1900
                date->tm_hour = 0;
                date->tm_min = 0;
                date->tm_sec = 0;
                date->tm_isdst = -1; // Not considering DST for simplicity
                return 0; // Success
            }
        }
    }
    return -1; // Parsing failed
}

// Function to format a struct tm to a string date
void formatDate(struct tm *date, char *output, size_t size) {
    // Use strftime to format the date
    strftime(output, size, "%A, %B %d, %Y", date);
}

int main() {
    char input[MAX_INPUT_SIZE];
    struct tm date;
    char output[50];

    // Prompt user for input
    printf("Enter a date (e.g., 15 August 2023): ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

    // Parse the date
    if (parseDate(input, &date) == 0) {
        // Format the date for output
        formatDate(&date, output, sizeof(output));
        printf("Formatted date: %s\n", output);
    } else {
        printf("Invalid date format. Please use 'DD Month YYYY'.\n");
    }

    return 0;
}