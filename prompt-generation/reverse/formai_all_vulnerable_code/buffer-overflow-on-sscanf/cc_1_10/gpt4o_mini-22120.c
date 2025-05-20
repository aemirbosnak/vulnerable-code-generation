//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

// Function prototypes
void getInput(char *input);
void parseDate(char *input, int *day, int *month, int *year);
void validateDate(int day, int month, int year);
void convertToNaturalLanguage(int day, int month, int year, char *output);
const char* monthToString(int month);
const char* daySuffix(int day);

int main() {
    char input[MAX_INPUT_SIZE];
    int day, month, year;
    char dateInNaturalLanguage[200];

    // Get user input
    getInput(input);
    
    // Parse the input date
    parseDate(input, &day, &month, &year);
    
    // Validate the parsed date
    validateDate(day, month, year);
    
    // Convert to natural language
    convertToNaturalLanguage(day, month, year, dateInNaturalLanguage);
    
    // Output the result
    printf("Natural Language Date: %s\n", dateInNaturalLanguage);

    return 0;
}

// Function to get input from the user
void getInput(char *input) {
    printf("Enter a date (DD-MM-YYYY): ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;  // Remove newline character
}

// Function to parse the input date
void parseDate(char *input, int *day, int *month, int *year) {
    sscanf(input, "%d-%d-%d", day, month, year);
}

// Function to validate the date
void validateDate(int day, int month, int year) {
    if (month < 1 || month > 12) {
        fprintf(stderr, "Invalid month: %d. Month must be between 1 and 12.\n", month);
        exit(EXIT_FAILURE);
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
            // Leap year consideration
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        default:
            daysInMonth = 0; // Shouldn't reach here
    }

    if (day < 1 || day > daysInMonth) {
        fprintf(stderr, "Invalid day: %d for month: %d. Must be between 1 and %d.\n", day, month, daysInMonth);
        exit(EXIT_FAILURE);
    }
}

// Function to convert date to natural language
void convertToNaturalLanguage(int day, int month, int year, char *output) {
    char yearString[5];
    sprintf(yearString, "%d", year);
    snprintf(output, 200, "The %d%s day of %s in the year %s", day, daySuffix(day), monthToString(month), yearString);
}

// Function to convert month number to string
const char* monthToString(int month) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return months[month - 1];
}

// Function to get the suffix for the day
const char* daySuffix(int day) {
    if (day % 10 == 1 && day != 11) return "st";
    if (day % 10 == 2 && day != 12) return "nd";
    if (day % 10 == 3 && day != 13) return "rd";
    return "th";
}