//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUT 100

// Function to parse the natural language date
void parseDate(const char *input, int *day, int *month, int *year) {
    char monthNames[12][10] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    char *token = strtok((char *)input, " ");
    
    while (token != NULL) {
        // Check for numeric dates
        if (isdigit(token[0])) {
            sscanf(token, "%d", day);
        }
        // Check for month names
        for (int i = 0; i < 12; i++) {
            if (strcasecmp(token, monthNames[i]) == 0) {
                *month = i + 1; // Months are 1-indexed
                break;
            }
        }
        // Check for year
        if (strlen(token) == 4 && isdigit(token[0])) {
            sscanf(token, "%d", year);
        }
        
        token = strtok(NULL, " ");
    }
}

// Function to print the date in standard format
void printDate(int day, int month, int year) {
    printf("Your date in standard format is: %04d-%02d-%02d\n", year, month, day);
}

int main() {
    char input[MAX_INPUT];
    int day = 0, month = 0, year = 0;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in formats such as:\n");
    printf("1. January 5th, 2023\n");
    printf("2. 5th of February, 2022\n");
    printf("3. 2023-03-15\n");
    printf("4. 15 March 2021\n");
    printf("5. March 15, 2020\n\n");

    printf("Enter the date: ");
    fgets(input, MAX_INPUT, stdin);

    // Removing the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Parse the input date
    parseDate(input, &day, &month, &year);

    // Validate the parsed date
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1000 || year > 9999) {
        printf("Invalid date entered. Please try again.\n");
        return 1;
    }

    // Print the standardized date
    printDate(day, month, year);

    return 0;
}