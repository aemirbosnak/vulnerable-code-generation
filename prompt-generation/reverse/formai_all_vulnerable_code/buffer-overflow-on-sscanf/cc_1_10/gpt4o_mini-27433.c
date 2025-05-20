//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LINE_LENGTH 256

// Function prototypes
void getCurrentDate(char *dateBuffer);
void convertDate(const char *inputDate, char *outputDate);
void parseDate(const char *dateString, int *day, int *month, int *year);
int isLeapYear(int year);
const char* getMonthName(int month);
int getMonthNumber(const char *monthName);

// Main function
int main() {
    char inputDate[LINE_LENGTH];
    char outputDate[LINE_LENGTH];
    char currentDate[LINE_LENGTH];
    
    // Get the current date
    getCurrentDate(currentDate);
    
    printf("Natural Language Date Converter\n");
    printf("Current Date: %s\n", currentDate);
    
    while (1) {
        printf("Enter a date (or type 'exit' to quit): ");
        fgets(inputDate, sizeof(inputDate), stdin);
        
        // Remove the newline character
        inputDate[strcspn(inputDate, "\n")] = 0;
        
        // Exit condition
        if (strcmp(inputDate, "exit") == 0) {
            break;
        }

        // Convert the date
        convertDate(inputDate, outputDate);
        printf("Converted Date: %s\n", outputDate);
    }
    
    return 0;
}

// Get the current date
void getCurrentDate(char *dateBuffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(dateBuffer, "%02d-%02d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

// Convert the input natural language date to standard format
void convertDate(const char *inputDate, char *outputDate) {
    int day, month, year;
    char monthName[20];
    
    // Check for format like "1st January 2023"
    if (sscanf(inputDate, "%d %s %d", &day, monthName, &year) == 3) {
        month = getMonthNumber(monthName);
        if (month < 1 || month > 12) {
            sprintf(outputDate, "Invalid month: %s", monthName);
            return;
        }
        sprintf(outputDate, "%02d-%02d-%d", day, month, year);
        return;
    }
    
    // Check for format like "January 1, 2023"
    if (sscanf(inputDate, "%s %d, %d", monthName, &day, &year) == 3) {
        month = getMonthNumber(monthName);
        if (month < 1 || month > 12) {
            sprintf(outputDate, "Invalid month: %s", monthName);
            return;
        }
        sprintf(outputDate, "%02d-%02d-%d", day, month, year);
        return;
    }

    // If no valid format, return error
    sprintf(outputDate, "Invalid date format: %s", inputDate);
}

// Get the month number from the month name
int getMonthNumber(const char *monthName) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(monthName, months[i]) == 0) {
            return i + 1;
        }
    }
    return -1; // Invalid month
}

// Determine if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Get the month name (for future use)
const char* getMonthName(int month) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return (month >= 1 && month <= 12) ? months[month - 1] : "Invalid month";
}