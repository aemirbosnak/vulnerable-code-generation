//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

// Function to map the month names to their respective numbers
int monthToNumber(const char* month) {
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1; // Months are 1-indexed
        }
    }
    return -1; // Invalid month
}

// Function to convert a date in natural language to a struct tm
int convertToDate(const char* naturalDate, struct tm* date) {
    char month[MAX_LENGTH];
    int day, year;
    
    // Parsing the natural language date
    if (sscanf(naturalDate, "%d %s %d", &day, month, &year) == 3) {
        date->tm_mday = day;
        date->tm_mon = monthToNumber(month) - 1; // tm_mon is 0-indexed
        date->tm_year = year - 1900; // tm_year is years since 1900
        date->tm_hour = 0;
        date->tm_min = 0;
        date->tm_sec = 0;
        date->tm_isdst = -1; // Not considering daylight saving time

        // Validate the date
        if (mktime(date) == -1) {
            return -1; // Invalid date
        }
        return 0; // Successfully parsed date
    }
    return -1; // Failed to parse date
}

// Function to print the date in a formatted way
void printFormattedDate(const struct tm* date) {
    char buffer[MAX_LENGTH];
    
    // Formatting the date as "YYYY-MM-DD"
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", date);
    printf("Converted Date: %s\n", buffer);
}

// The main function
int main() {
    char naturalDate[MAX_LENGTH];
    struct tm date = {0};

    printf("Enter a date in the format 'DD Month YYYY' (e.g., '24 March 2023'): ");
    fgets(naturalDate, MAX_LENGTH, stdin);
    
    // Removing newline character from the input
    naturalDate[strcspn(naturalDate, "\n")] = 0;

    if (convertToDate(naturalDate, &date) == 0) {
        printFormattedDate(&date);
    } else {
        printf("Error: Invalid date format. Please use 'DD Month YYYY'.\n");
    }

    return 0;
}