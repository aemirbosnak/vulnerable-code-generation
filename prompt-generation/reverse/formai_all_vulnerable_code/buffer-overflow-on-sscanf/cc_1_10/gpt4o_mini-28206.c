//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100
#define MONTHS_IN_YEAR 12

// Month names
const char *months[MONTHS_IN_YEAR] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Function to convert month name to a number
int monthToNumber(const char *month) {
    for (int i = 0; i < MONTHS_IN_YEAR; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1; // Month should be 1 to 12
        }
    }
    return 0; // Invalid month
}

// Function to parse a date string
int parseDateString(const char *input, int *day, int *month, int *year) {
    char monthName[20];
    
    // Expected format: "20th of March, 2023" or "March 20, 2023"
    int res = sscanf(input, "%d %s %d", day, monthName, year);
    
    if (res == 3) {
        *month = monthToNumber(monthName);
        if (*month == 0) {
            return 0; // Invalid month
        }
        return 1; // Successful parse
    }

    // Alternative format: "20th of March 2023"
    res = sscanf(input, "%d of %s %d", day, monthName, year);
    
    if (res == 3) {
        *month = monthToNumber(monthName);
        if (*month == 0) {
            return 0; // Invalid month
        }
        return 1; // Successful parse
    }

    return 0; // Parsing failed
}

// Function to format the date
void formatDate(int day, int month, int year, char *output) {
    sprintf(output, "%04d-%02d-%02d", year, month, day);
}

// Main function
int main() {
    char input[MAX_INPUT_LENGTH];
    int day, month, year;
    char output[11]; // Format YYYY-MM-DD is 10 + 1 for null terminator

    printf("Welcome to the Retro Natural Language Date Converter!\n");
    printf("Please enter a date in the format: '20th of March, 2023' or 'March 20, 2023'\n");
    
    // Get user input
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;
    
    // Attempt to parse the date
    if (parseDateString(input, &day, &month, &year)) {
        // Validate day and month
        if (day < 1 || day > 31 || month < 1 || month > MONTHS_IN_YEAR) {
            printf("Error: Invalid day or month.\n");
            return 1;
        }

        // Format the date
        formatDate(day, month, year, output);
        printf("Formatted date: %s\n", output);
    } else {
        printf("Error: Could not parse the date. Please check your format.\n");
    }
    
    return 0;
}