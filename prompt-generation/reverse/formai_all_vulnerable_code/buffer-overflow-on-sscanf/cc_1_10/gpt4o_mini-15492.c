//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LEN 100

// Function to convert month string to month number
int monthStrToNum(char *monthStr) {
    char *months[] = { "January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December" };
    
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(monthStr, months[i]) == 0) {
            return i + 1; // Months are 1-indexed
        }
    }
    
    return -1; // Invalid month
}

// Function to validate the day of the month
int isValidDate(int day, int month, int year) {
    if (day < 1 || day > 31) return 0;
    if (month < 1 || month > 12) return 0;

    // Check for months with 30 days
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return 0;
    }

    // Check for February
    if (month == 2) {
        int leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (leapYear ? 29 : 28)) return 0;
    }

    return 1; // Valid date
}

// Function to convert natural language date to structured date
void convertToStructuredDate(char *input, int *day, int *month, int *year) {
    char monthStr[20];

    // Simple parsing for "5th May 2023" or "May 5, 2023"
    if (sscanf(input, "%d %s %d", day, monthStr, year) == 3) {
        // Do nothing, extracted correctly
    } else if (sscanf(input, "%s %d, %d", monthStr, day, year) == 3) {
        // Do nothing, extracted correctly
    } else {
        printf("Could not parse the date format. Please try again.\n");
        exit(EXIT_FAILURE);
    }

    *month = monthStrToNum(monthStr);
    if (*month == -1) {
        printf("Invalid month: %s\n", monthStr);
        exit(EXIT_FAILURE);
    }
}

// Function to display the structured date
void displayStructuredDate(int day, int month, int year) {
    printf("Structured Date: %04d-%02d-%02d\n", year, month, day);
}

int main() {
    char input[MAX_DATE_LEN];
    int day, month, year;

    // Retro welcome message
    printf("**********************************\n");
    printf("*       Natural Language Date    *\n");
    printf("*        Converter Program        *\n");
    printf("**********************************\n");

    // Prompt user for input
    printf("Enter a date (e.g., '5th May 2023' or 'May 5, 2023'): ");
    fgets(input, MAX_DATE_LEN, stdin);
    input[strcspn(input, "\n")] = 0; // Remove the trailing newline

    // Convert the input date into structured components
    convertToStructuredDate(input, &day, &month, &year);
    
    // Validate the date
    if (!isValidDate(day, month, year)) {
        printf("Invalid date entered: %d/%d/%d. Please try again.\n", day, month, year);
        return EXIT_FAILURE;
    }

    // Display the structured date
    displayStructuredDate(day, month, year);
    
    // Program end message
    printf("Thank you for using the Date Converter!\n");
    printf("Have a splendid day!\n");

    return EXIT_SUCCESS;
}