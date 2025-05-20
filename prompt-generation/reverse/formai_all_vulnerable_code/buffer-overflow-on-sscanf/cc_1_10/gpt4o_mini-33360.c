//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

// Function to convert month name to month number
int monthToNumber(const char *month) {
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1;
        }
    }
    return -1; // Invalid month
}

// Function to validate the given date
int isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12 || day < 1 || year < 1900) {
        return 0; // Invalid date
    }
    int daysInMonth;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            // Check for leap year
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        default:
            return 0; // Invalid month
    }
    return day <= daysInMonth;
}

// Function to print the date in standard format
void printDate(int day, int month, int year) {
    printf("Converted Date: %04d-%02d-%02d\n", year, month, day);
}

// Function to convert a string representing a natural language date into a structured date
void convertNaturalLanguageDate(const char *input) {
    char month[MAX_STRING_LENGTH], datePart[MAX_STRING_LENGTH], yearPart[MAX_STRING_LENGTH];
    int day, monthNum, year;

    // Parse input
    if (sscanf(input, "%s %s %s", month, datePart, yearPart) >= 3) {
        day = atoi(datePart);
        year = atoi(yearPart);
        monthNum = monthToNumber(month);
        
        if (monthNum == -1 || !isValidDate(day, monthNum, year)) {
            printf("Invalid date format or values in: '%s'\n", input);
            return;
        }
        
        printDate(day, monthNum, year);
    } else {
        printf("Failed to parse the natural language date from: '%s'\n", input);
    }
}

int main() {
    char input[MAX_STRING_LENGTH];
    printf("Enter a date in the natural language format (e.g., \"January 15 2023\"):\n");

    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input. Exiting.\n");
            break;
        }
        
        // Remove the newline character from input
        input[strcspn(input, "\n")] = 0;
        
        if (strcasecmp(input, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        }

        convertNaturalLanguageDate(input);
    }

    return 0;
}