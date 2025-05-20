//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100

// Structure to hold date components
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function to parse a date string into Date structure
int parseDate(const char *dateString, Date *date) {
    char monthName[20];
    int day;
    int year;
    
    // Looking for the date in the format "DD Month YYYY"
    int tokens = sscanf(dateString, "%d %s %d", &day, monthName, &year);
    
    if (tokens != 3) {
        return -1; // Parse error
    }

    // Map month names to month numbers
    if (strcmp(monthName, "January") == 0) {
        date->month = 1;
    } else if (strcmp(monthName, "February") == 0) {
        date->month = 2;
    } else if (strcmp(monthName, "March") == 0) {
        date->month = 3;
    } else if (strcmp(monthName, "April") == 0) {
        date->month = 4;
    } else if (strcmp(monthName, "May") == 0) {
        date->month = 5;
    } else if (strcmp(monthName, "June") == 0) {
        date->month = 6;
    } else if (strcmp(monthName, "July") == 0) {
        date->month = 7;
    } else if (strcmp(monthName, "August") == 0) {
        date->month = 8;
    } else if (strcmp(monthName, "September") == 0) {
        date->month = 9;
    } else if (strcmp(monthName, "October") == 0) {
        date->month = 10;
    } else if (strcmp(monthName, "November") == 0) {
        date->month = 11;
    } else if (strcmp(monthName, "December") == 0) {
        date->month = 12;
    } else {
        return -1; // Invalid month name
    }

    date->day = day;
    date->year = year;

    return 0; // Success
}

// Function to validate if the date is valid
int isValidDate(Date *date) {
    struct tm timeStruct = {0};
    timeStruct.tm_mday = date->day;
    timeStruct.tm_mon = date->month - 1; // tm_mon is 0-11
    timeStruct.tm_year = date->year - 1900; // tm_year is year since 1900

    // Normalize to check for validity
    time_t t = mktime(&timeStruct);
    
    // If `mktime` was successful, the original date can be recreated
    struct tm *checkDate = localtime(&t);
    return (checkDate->tm_mday == date->day &&
            checkDate->tm_mon == date->month - 1 &&
            checkDate->tm_year == date->year - 1900);
}

// Function to display date in standard format
void displayDate(Date *date) {
    printf("Converted Date: %02d/%02d/%04d\n", date->day, date->month, date->year);
}

int main() {
    char dateInput[MAX_LEN];
    Date date;
    
    printf("Enter a date in the format 'DD Month YYYY' (e.g., 23 March 2023): ");
    fgets(dateInput, MAX_LEN, stdin);
    
    // Remove newline character if exists
    dateInput[strcspn(dateInput, "\n")] = 0;

    if (parseDate(dateInput, &date) == -1) {
        printf("Error: Invalid date format. Please try again.\n");
        return EXIT_FAILURE;
    }

    if (!isValidDate(&date)) {
        printf("Error: The date is invalid. Please check your input.\n");
        return EXIT_FAILURE;
    }

    displayDate(&date);
    
    return EXIT_SUCCESS;
}