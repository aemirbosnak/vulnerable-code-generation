//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to parse the date from natural language input
void parseDate(char *input, struct tm *date) {
    char *token;
    time_t now;
    time(&now);
    localtime_r(&now, date);

    // If input is a specific date
    if (sscanf(input, "%d %s %d", &date->tm_mday, &date->tm_mon, &date->tm_year) == 3) {
        date->tm_year -= 1900;    // Year since 1900
        date->tm_mon -= 1;        // Months are 0-11
        return;
    }

    // If input is something like "next Friday"
    if (strstr(input, "next")) {
        char dayName[20];
        sscanf(input + 5, "%s", dayName);
        if (strcmp(dayName, "Friday") == 0) {
            date->tm_wday = 5; // Friday
            date->tm_mday += (7 - date->tm_wday) % 7 + 1; // Move to next week
        }
        // Add other days as needed
        return;
    }

    // Handle if the input contains "today"
    if (strstr(input, "today")) {
        return; // Use current date
    }

    fprintf(stderr, "Could not parse date input: %s\n", input);
}

// Function to format the date into YYYY-MM-DD format
void formatDate(struct tm *date, char *output) {
    strftime(output, 11, "%Y-%m-%d", date);
}

int main() {
    char input[100];
    struct tm date;
    char formattedDate[11];

    printf("Enter a date (e.g., 'August 15, 2023', 'next Friday', or 'today'): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    parseDate(input, &date);
    formatDate(&date, formattedDate);

    printf("The formatted date is: %s\n", formattedDate);
    
    return 0;
}