//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100
#define MAX_BUFFER_LENGTH 50

// Function to convert month name to month number
int getMonthNumber(const char* month) {
    const char* months[] = { 
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December" 
    };
    for(int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1; // Month numbers start from 1
        }
    }
    return -1; // Invalid month name
}

// Function to validate date
int isValidDate(int day, int month, int year) {
    if (year < 1 || year > 9999) return 0;
    
    if (month < 1 || month > 12) return 0;
    
    int days_in_month[] = { 31, (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    return day > 0 && day <= days_in_month[month - 1];
}

// Function to convert natural language date to structured date
void convertNaturalLanguageDate(const char* input, int* day, int* month, int* year) {
    char monthString[20];
    if (sscanf(input, "%d %s %d", day, monthString, year) != 3) {
        printf("Invalid format. Expected format: 'DD Month YYYY'\n");
        exit(EXIT_FAILURE);
    }

    *month = getMonthNumber(monthString);
    if (*month == -1) {
        printf("Invalid month name: %s\n", monthString);
        exit(EXIT_FAILURE);
    }
}

// Function to format date into a string
void formatDateToString(int day, int month, int year, char* output) {
    sprintf(output, "%02d-%02d-%04d", day, month, year);
}

// Main function
int main() {
    char input[MAX_INPUT_LENGTH];
    int day, month, year;

    printf("Enter the date in format 'DD Month YYYY': ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Remove newline character
    input[strcspn(input, "\n")] = 0;

    // Convert natural language date
    convertNaturalLanguageDate(input, &day, &month, &year);

    // Validate the date
    if (!isValidDate(day, month, year)) {
        printf("The date %s is invalid.\n", input);
        return EXIT_FAILURE;
    }

    // Format and print the date
    char formattedDate[MAX_BUFFER_LENGTH];
    formatDateToString(day, month, year, formattedDate);
    printf("Formatted Date: %s\n", formattedDate);

    return EXIT_SUCCESS;
}