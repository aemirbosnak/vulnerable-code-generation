//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function Prototypes
void convertDate(const char *input);
int monthFromName(const char *monthName);
void printUsage();

int main() {
    char input[100];
    
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date (e.g., 'March 5th, 2023' or '5th of March, 2023'):\n");

    while (1) {
        // Read input date
        printf("> ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from input
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        
        // Check for exit condition
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Convert and print the result
        convertDate(input);
    }
    
    return 0;
}

// Convert natural language date input to YYYY-MM-DD format
void convertDate(const char *input) {
    int day, year, month;
    char monthName[20];

    // Parse input for the date components
    if (sscanf(input, "%s %d, %d", monthName, &day, &year) == 3 || 
        sscanf(input, "%d of %s, %d", &day, monthName, &year) == 3) {
        
        month = monthFromName(monthName);
        
        if (month == -1) {
            printf("Invalid month name: '%s'. Please try again.\n", monthName);
            return;
        }

        printf("Converted Date: %04d-%02d-%02d\n", year, month, day);
    } else {
        printf("Could not parse the input. Please try again using a format like 'March 5th, 2023'.\n");
    }
}

// Convert month name to month number
int monthFromName(const char *monthName) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    for (int i = 0; i < 12; i++) {
        if (strcasecmp(monthName, months[i]) == 0) {
            return i + 1; // Month numbers start at 1
        }
    }

    return -1; // Invalid month
}

// Prints usage instructions
void printUsage() {
    printf("Usage:\n");
    printf("Enter a date in one of the following formats:\n");
    printf("1. 'Month Day, Year' (e.g., 'March 5, 2023')\n");
    printf("2. 'Day of Month, Year' (e.g., '5 of March, 2023')\n");
    printf("Type 'exit' to close the program.\n");
}