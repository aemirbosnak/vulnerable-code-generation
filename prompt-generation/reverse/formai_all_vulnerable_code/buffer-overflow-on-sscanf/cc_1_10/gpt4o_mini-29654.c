//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100

// Structure to hold parsed date components
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function prototypes
void parseNaturalDate(const char *input, Date *date);
void printDate(const Date *date);
int isLeapYear(int year);
int getDaysInMonth(int month, int year);
void formatAndPrint(Date date);

// Main function
int main() {
    char input[MAX_INPUT_LENGTH];
    Date date;

    printf("Welcome to the C Natural Language Date Converter!\n");
    printf("Please enter a date (e.g., '15th of April 2022'): ");
    
    // Read input from user
    fgets(input, sizeof(input), stdin);
    
    // Parse the input date
    parseNaturalDate(input, &date);

    // Format and print the parsed date
    formatAndPrint(date);
    
    return 0;
}

// Function to parse a natural language date input
void parseNaturalDate(const char *input, Date *date) {
    char monthString[20];
    int numParsed;

    // Initialize date
    date->day = 0;
    date->month = 0;
    date->year = 0;
    
    // Scan for day, month and year using formatted string
    numParsed = sscanf(input, "%d of %s %d", &date->day, monthString, &date->year);
    
    // Convert month name to month number
    if (numParsed == 3) {
        if (strcasecmp(monthString, "January") == 0) date->month = 1;
        else if (strcasecmp(monthString, "February") == 0) date->month = 2;
        else if (strcasecmp(monthString, "March") == 0) date->month = 3;
        else if (strcasecmp(monthString, "April") == 0) date->month = 4;
        else if (strcasecmp(monthString, "May") == 0) date->month = 5;
        else if (strcasecmp(monthString, "June") == 0) date->month = 6;
        else if (strcasecmp(monthString, "July") == 0) date->month = 7;
        else if (strcasecmp(monthString, "August") == 0) date->month = 8;
        else if (strcasecmp(monthString, "September") == 0) date->month = 9;
        else if (strcasecmp(monthString, "October") == 0) date->month = 10;
        else if (strcasecmp(monthString, "November") == 0) date->month = 11;
        else if (strcasecmp(monthString, "December") == 0) date->month = 12;
        else {
            printf("Invalid month entered: %s\n", monthString);
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Failed to parse date: %s\n", input);
        exit(EXIT_FAILURE);
    }

    // Validate day and month
    if (date->day < 1 || date->day > getDaysInMonth(date->month, date->year)) {
        printf("Invalid day for the given month: %d\n", date->day);
        exit(EXIT_FAILURE);
    }
}

// Function to check for a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0; // Invalid month
    }
}

// Function to format and print the date
void formatAndPrint(Date date) {
    const char *monthNames[] = {
        "Invalid", "January", "February", "March", "April",
        "May", "June", "July", "August", "September",
        "October", "November", "December"
    };

    // Output formatted date
    printf("Parsed date: %d %s %d\n", date.day, monthNames[date.month], date.year);
}