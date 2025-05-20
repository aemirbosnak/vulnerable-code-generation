//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void getCurrentDate(char* buffer);
int parseNaturalDate(const char *input, char *output);

// Main function where everything sparks to life
int main() {
    char input[256];
    char output[11]; // YYYY-MM-DD format
    char currentDate[11];

    // Get the current date
    getCurrentDate(currentDate);
    printf("Today's date is: %s\n", currentDate);
    
    // Welcome message
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Type a date in natural language (e.g., 'tomorrow', 'next Friday', 'last week', etc.)\n");
    printf("Type 'exit' to leave the program. Let's get started!\n\n");

    // Main loop
    while (1) {
        // User input
        printf("Enter your date: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        // Exit condition
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Parse the date
        if (parseNaturalDate(input, output) == 0) {
            printf("The date you entered is: %s\n", output);
        } else {
            printf("Sorry, I couldn't understand that date format. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}

// Function to get current date in YYYY-MM-DD format
void getCurrentDate(char* buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

// Function to parse the natural language date
int parseNaturalDate(const char *input, char *output) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int dayAdjustment = 0;
    char temp[256];
    
    // Normalize input to lower case for easier comparison
    for (int i = 0; input[i]; i++) {
        temp[i] = tolower(input[i]);
    }
    temp[strcspn(temp, "\n")] = 0; // Remove newline character

    // Understand natural date phrases
    if (strcmp(temp, "today") == 0) {
        // Do nothing, the date is today
    } else if (strcmp(temp, "tomorrow") == 0) {
        dayAdjustment = 1;
    } else if (strcmp(temp, "yesterday") == 0) {
        dayAdjustment = -1;
    } else if (strstr(temp, "next") != NULL) {
        if (strstr(temp, "week") != NULL) {
            // Adding 7 days for next week
            dayAdjustment = 7;
        } else if (strstr(temp, "month") != NULL) {
            // Adding 30 days for next month approximation
            dayAdjustment = 30;
        }
    } else if (strstr(temp, "last") != NULL) {
        if (strstr(temp, "week") != NULL) {
            dayAdjustment = -7;
        } else if (strstr(temp, "month") != NULL) {
            dayAdjustment = -30;
        }
    } else {
        // Parse direct date format 'dd-mm-yyyy'
        // Simplified parsing, expects proper format
        if (sscanf(temp, "%d-%d-%d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year) == 3) {
            tm.tm_mon -= 1; // Adjust for 0 index
            tm.tm_year -= 1900; // Year since 1900
        } else {
            return -1; // Unrecognized format
        }
    }

    // Adjust the day
    tm.tm_mday += dayAdjustment;

    // Normalize if the adjustment crosses month boundaries
    mktime(&tm);
    sprintf(output, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    
    return 0; // Success
}