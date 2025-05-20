//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100
#define MAX_MONTH_LENGTH 10

// Function to convert month name to month number
int monthToNumber(const char *month) {
    if (strcasecmp(month, "January") == 0) return 1;
    if (strcasecmp(month, "February") == 0) return 2;
    if (strcasecmp(month, "March") == 0) return 3;
    if (strcasecmp(month, "April") == 0) return 4;
    if (strcasecmp(month, "May") == 0) return 5;
    if (strcasecmp(month, "June") == 0) return 6;
    if (strcasecmp(month, "July") == 0) return 7;
    if (strcasecmp(month, "August") == 0) return 8;
    if (strcasecmp(month, "September") == 0) return 9;
    if (strcasecmp(month, "October") == 0) return 10;
    if (strcasecmp(month, "November") == 0) return 11;
    if (strcasecmp(month, "December") == 0) return 12;
    return -1; // Invalid month
}

// Function to print current date
void printCurrentDate() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\nToday is %02d-%02d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

// Function to convert natural language date to structured date
void convertNaturalLanguageDate(char *input) {
    int day, month, year;
    char monthName[MAX_MONTH_LENGTH];
    
    // Expecting input in the format: "July 4, 2023" or "4 July 2023"
    if (sscanf(input, "%d %s %d", &day, monthName, &year) == 3 ||
        sscanf(input, "%s %d, %d", monthName, &day, &year) == 3) {
        
        // Convert month name to month number
        month = monthToNumber(monthName);
        if (month == -1) {
            printf("Oops! Invalid month name: %s\n", monthName);
            return;
        }

        printf("Converted date: %02d-%02d-%d\n", day, month, year);
    } else {
        printf("Oops! Could not parse the input. Please use the format 'Month Day, Year' or 'Day Month Year'.\n");
    }
}

// Main function
int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Welcome to the Exciting Natural Language Date Converter!\n");
    printf("Please enter a date in natural language format (e.g., 'July 4, 2023' or '4 July 2023'):\n");

    // Get user input
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Remove newline character from input if present
    input[strcspn(input, "\n")] = 0;

    // Print the current date for reference
    printCurrentDate();

    // Convert the natural language date
    convertNaturalLanguageDate(input);

    printf("\nThank you for using the Exciting Natural Language Date Converter! Have an amazing day ahead!\n");
    return 0;
}