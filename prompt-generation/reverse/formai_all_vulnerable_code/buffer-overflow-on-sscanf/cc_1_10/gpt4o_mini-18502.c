//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
int parseDate(const char* input, struct tm *date);
void printDate(struct tm *date);
void printHelp();

int main() {
    char userInput[100];
    struct tm date;
    char response;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can enter a date in natural language format.\n");
    printf("Type 'help' to see accepted formats.\n");

    while (1) {
        printf("Enter a date: ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = 0; // Remove trailing newline

        // Check for help command
        if (strcmp(userInput, "help") == 0) {
            printHelp();
            continue;
        }

        // Attempt to parse the date
        if (parseDate(userInput, &date)) {
            printDate(&date);
        } else {
            printf("Could not parse the date. Would you like to try again? (y/n): ");
            scanf(" %c", &response);
            getchar(); // Clear newline from the buffer
            if (response != 'y') {
                printf("Exiting the program. Goodbye!\n");
                break;
            }
        }
    }

    return 0;
}

// Function to parse the natural language date
int parseDate(const char* input, struct tm *date) {
    char month[20], day[3], year[5];

    // Initialize date structure
    memset(date, 0, sizeof(struct tm));

    // Compare against different patterns
    if (sscanf(input, "%s %s %s", month, day, year) == 3) {
        // Month first (e.g., "January 1 2022")
        date->tm_mday = atoi(day);
        date->tm_year = atoi(year) - 1900;

        // Month conversion
        if (strcmp(month, "January") == 0) date->tm_mon = 0;
        else if (strcmp(month, "February") == 0) date->tm_mon = 1;
        else if (strcmp(month, "March") == 0) date->tm_mon = 2;
        else if (strcmp(month, "April") == 0) date->tm_mon = 3;
        else if (strcmp(month, "May") == 0) date->tm_mon = 4;
        else if (strcmp(month, "June") == 0) date->tm_mon = 5;
        else if (strcmp(month, "July") == 0) date->tm_mon = 6;
        else if (strcmp(month, "August") == 0) date->tm_mon = 7;
        else if (strcmp(month, "September") == 0) date->tm_mon = 8;
        else if (strcmp(month, "October") == 0) date->tm_mon = 9;
        else if (strcmp(month, "November") == 0) date->tm_mon = 10;
        else if (strcmp(month, "December") == 0) date->tm_mon = 11;
        else return 0; // Unknown month

        // Check if date is valid
        if (date->tm_mday <= 0 || date->tm_mday > 31 || date->tm_mon < 0 || date->tm_mon > 11) {
            return 0;
        }
        
        // Normalize the date
        mktime(date);
        return 1;
    }
    return 0; // Failed to parse
}

// Function to print the parsed date in a human-readable format
void printDate(struct tm *date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "Parsed Date: %A, %B %d, %Y", date);
    printf("%s\n", buffer);
}

// Function to print help information
void printHelp() {
    printf("Accepted Natural Language Date Formats:\n");
    printf("- 'January 1 2022' for direct input.\n");
    printf("- 'February 20 2020' to represent a specific day.\n");
    printf("- You can type 'exit' to quit the program.\n");
}