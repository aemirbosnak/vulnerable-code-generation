//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 256

// Function to convert month name to month number
int monthNumber(const char *month) {
    if (strcasecmp(month, "January") == 0) return 1;
    else if (strcasecmp(month, "February") == 0) return 2;
    else if (strcasecmp(month, "March") == 0) return 3;
    else if (strcasecmp(month, "April") == 0) return 4;
    else if (strcasecmp(month, "May") == 0) return 5;
    else if (strcasecmp(month, "June") == 0) return 6;
    else if (strcasecmp(month, "July") == 0) return 7;
    else if (strcasecmp(month, "August") == 0) return 8;
    else if (strcasecmp(month, "September") == 0) return 9;
    else if (strcasecmp(month, "October") == 0) return 10;
    else if (strcasecmp(month, "November") == 0) return 11;
    else if (strcasecmp(month, "December") == 0) return 12;

    return 0; // Unknown month
}

// Function to parse date from natural language
void parseDate(const char *input, int *day, int *month, int *year) {
    char monthStr[20];
    char *token;
    
    // Assume the format "day month year", e.g., "25 December 2023"
    token = strtok(input, " ");
    if (token != NULL) {
        *day = atoi(token);
        token = strtok(NULL, " ");
    }
    
    if (token != NULL) {
        strcpy(monthStr, token);
        *month = monthNumber(monthStr);
        token = strtok(NULL, " ");
    }
    
    if (token != NULL) {
        *year = atoi(token);
    }
}

// Validate the given date
int isValidDate(int day, int month, int year) {
    struct tm tm_date = {0};
    tm_date.tm_mday = day;
    tm_date.tm_mon = month - 1; // months are zero-based in struct tm
    tm_date.tm_year = year - 1900; // years since 1900

    // Check if the date is valid using mktime
    time_t t = mktime(&tm_date);
    
    if (t == -1) return 0; // Invalid date
    return 1; // Valid date
}

// Display the date in YYYY-MM-DD format
void displayDate(int day, int month, int year) {
    printf("Converted date: %04d-%02d-%02d\n", year, month, day);
}

int main() {
    char input[MAX_INPUT];
    int day, month, year;

    printf("Enter a date (e.g., '25 December 2023'): ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    parseDate(input, &day, &month, &year);

    if (isValidDate(day, month, year)) {
        displayDate(day, month, year);
    } else {
        printf("Error: Invalid date entered.\n");
    }

    return 0;
}