//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 100

// Function prototypes
void parseDate(const char *dateString, int *day, int *month, int *year);
void convertDateToTimestamp(int day, int month, int year);
void displayCurrentDate();
void handleInvalidInput();

int main() {
    char dateInput[MAX_DATE_LENGTH];
    int day, month, year;

    // Display current date
    displayCurrentDate();

    // Get user input
    printf("Enter a date (e.g., 12 January 2023): ");
    fgets(dateInput, MAX_DATE_LENGTH, stdin);
    dateInput[strcspn(dateInput, "\n")] = 0; // Remove newline character

    // Parse the input date
    parseDate(dateInput, &day, &month, &year);
    
    // Convert to timestamp and display
    convertDateToTimestamp(day, month, year);
    
    return 0;
}

void parseDate(const char *dateString, int *day, int *month, int *year) {
    char monthName[20];
    if (sscanf(dateString, "%d %s %d", day, monthName, year) != 3) {
        handleInvalidInput();
        exit(EXIT_FAILURE);
    }

    // Convert month name to month number
    if (strcmp(monthName, "January") == 0) {
        *month = 1;
    } else if (strcmp(monthName, "February") == 0) {
        *month = 2;
    } else if (strcmp(monthName, "March") == 0) {
        *month = 3;
    } else if (strcmp(monthName, "April") == 0) {
        *month = 4;
    } else if (strcmp(monthName, "May") == 0) {
        *month = 5;
    } else if (strcmp(monthName, "June") == 0) {
        *month = 6;
    } else if (strcmp(monthName, "July") == 0) {
        *month = 7;
    } else if (strcmp(monthName, "August") == 0) {
        *month = 8;
    } else if (strcmp(monthName, "September") == 0) {
        *month = 9;
    } else if (strcmp(monthName, "October") == 0) {
        *month = 10;
    } else if (strcmp(monthName, "November") == 0) {
        *month = 11;
    } else if (strcmp(monthName, "December") == 0) {
        *month = 12;
    } else {
        handleInvalidInput();
        exit(EXIT_FAILURE);
    }
}

void convertDateToTimestamp(int day, int month, int year) {
    struct tm timeStruct = {0};

    timeStruct.tm_mday = day;
    timeStruct.tm_mon = month - 1; // tm_mon is 0-based
    timeStruct.tm_year = year - 1900; // tm_year is years since 1900

    time_t timestamp = mktime(&timeStruct);
    if (timestamp == -1) {
        handleInvalidInput();
        exit(EXIT_FAILURE);
    }

    printf("The timestamp for the given date is: %ld\n", (long)timestamp);
}

void displayCurrentDate() {
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);

    printf("Current date: %02d %s %04d\n", currentTime->tm_mday,
            "January February March April May June July August September October November December"[currentTime->tm_mon * 9], 
            currentTime->tm_year + 1900);
}

void handleInvalidInput() {
    printf("Invalid date format. Please ensure it's of the form 'dd Month yyyy'.\n");
}