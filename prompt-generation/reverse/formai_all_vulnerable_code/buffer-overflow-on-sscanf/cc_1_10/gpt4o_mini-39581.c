//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

// Function prototypes
void getCurrentDate();
void convertToDate(char *input);
int isValidDate(int day, int month, int year);
char* getMonthName(int month);
void displayHelp();

int main() {
    char input[MAX_INPUT_SIZE];
    int shouldExit = 0;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Type a date in natural language (e.g., 'July 4th, 1776') or 'exit' to quit.\n");

    while (!shouldExit) {
        printf("\n> ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            shouldExit = 1;
        } else if (strcmp(input, "current") == 0){
            getCurrentDate();
        } else if (strcmp(input, "help") == 0){
            displayHelp();
        } else {
            convertToDate(input);
        }
    }

    printf("Thank you for using the Natural Language Date Converter!\n");
    return 0;
}

void getCurrentDate() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Current Date: %02d-%02d-%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void convertToDate(char *input) {
    int day, month, year;
    char monthStr[20];

    // Extracting date components from the string
    int matched = sscanf(input, "%s %d, %d", monthStr, &day, &year);
    
    if (matched == 3) {
        // Convert month name to number
        month = -1; // Invalid month initially
        for (int i = 1; i <= 12; i++) {
            if (strcasecmp(monthStr, getMonthName(i)) == 0) {
                month = i;
                break;
            }
        }

        if (month != -1 && isValidDate(day, month, year)) {
            printf("Converted Date: %02d-%02d-%04d\n", day, month, year);
        } else {
            printf("Error: Invalid date format or values. Please try again.\n");
        }
    } else {
        printf("Error: Unable to parse the date. Please try a different format.\n");
    }
}

int isValidDate(int day, int month, int year) {
    if (year < 0 || month < 1 || month > 12) {
        return 0; // Invalid year or month
    }

    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2) {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth[2] = 29;
        }
    }

    return (day >= 1 && day <= daysInMonth[month]);
}

char* getMonthName(int month) {
    static char* monthNames[] = {
        "Invalid", "January", "February", "March", "April", "May", 
        "June", "July", "August", "September", "October", "November", "December"
    };
    return monthNames[month];
}

void displayHelp() {
    printf("Help - Natural Language Date Converter\n");
    printf("1. Enter dates in a natural language format: e.g., 'July 4, 1776'.\n");
    printf("2. To get the current date, type 'current'.\n");
    printf("3. Type 'exit' to close the application.\n");
    printf("4. For more information, contact support.\n");
}