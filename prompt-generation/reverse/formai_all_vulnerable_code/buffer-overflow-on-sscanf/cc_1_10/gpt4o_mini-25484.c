//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100

// Function prototypes
void parseDate(const char *input, int *day, int *month, int *year);
void displayDate(int day, int month, int year);
int isLeapYear(int year);
void getCurrentDate(int *day, int *month, int *year);
int validateDate(int day, int month, int year);

int main() {
    char userInput[MAX_INPUT_LENGTH];
    int day, month, year;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format of \"DD/MM/YYYY\" or \"DD Month YYYY\" (e.g., \"15 August 2023\").\n");
    
    // Get user input
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0;  // Remove newline character

    // Parse the date entered by the user
    parseDate(userInput, &day, &month, &year);

    // Validate the parsed date
    if (validateDate(day, month, year)) {
        displayDate(day, month, year);
    } else {
        printf("The date you entered is invalid. Please check your input and try again.\n");
    }

    // Display current date for reference
    int today, currentMonth, currentYear;
    getCurrentDate(&today, &currentMonth, &currentYear);
    printf("Today's date is: %02d/%02d/%d\n", today, currentMonth, currentYear);

    return 0;
}

// Function to parse input date
void parseDate(const char *input, int *day, int *month, int *year) {
    char monthString[10];
    
    // Check for "DD Month YYYY" format
    if (sscanf(input, "%d %s %d", day, monthString, year) == 3) {
        // Convert month string to month number
        if (strcasecmp(monthString, "January") == 0) {
            *month = 1;
        } else if (strcasecmp(monthString, "February") == 0) {
            *month = 2;
        } else if (strcasecmp(monthString, "March") == 0) {
            *month = 3;
        } else if (strcasecmp(monthString, "April") == 0) {
            *month = 4;
        } else if (strcasecmp(monthString, "May") == 0) {
            *month = 5;
        } else if (strcasecmp(monthString, "June") == 0) {
            *month = 6;
        } else if (strcasecmp(monthString, "July") == 0) {
            *month = 7;
        } else if (strcasecmp(monthString, "August") == 0) {
            *month = 8;
        } else if (strcasecmp(monthString, "September") == 0) {
            *month = 9;
        } else if (strcasecmp(monthString, "October") == 0) {
            *month = 10;
        } else if (strcasecmp(monthString, "November") == 0) {
            *month = 11;
        } else if (strcasecmp(monthString, "December") == 0) {
            *month = 12;
        } else {
            *month = -1;  // Invalid month
        }
    } 
    // Check for "DD/MM/YYYY" format
    else if (sscanf(input, "%d/%d/%d", day, month, year) != 3) {
        *day = *month = *year = 0;  // Invalid date
    }
}

// Function to display the formatted date
void displayDate(int day, int month, int year) {
    printf("You entered the date: %02d/%02d/%d\n", day, month, year);
}

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the current system date
void getCurrentDate(int *day, int *month, int *year) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    *day = tm_info->tm_mday;
    *month = tm_info->tm_mon + 1; // tm_mon is 0-11
    *year = tm_info->tm_year + 1900; // tm_year is years since 1900
}

// Function to validate a date
int validateDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12) {
        return 0;
    }

    int daysInMonth[] = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 
                         31, 31, 30, 31, 30, 31};

    return day > 0 && day <= daysInMonth[month - 1];
}