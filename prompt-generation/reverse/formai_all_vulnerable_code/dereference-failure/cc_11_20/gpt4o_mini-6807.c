//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100

void parseDate(const char *input, struct tm *dateStruct) {
    char temp[MAX_INPUT];
    int day, month, year;
    char *token;

    // Initializing dateStruct to zero
    memset(dateStruct, 0, sizeof(struct tm));
    
    // Get today's date to work with
    time_t now = time(NULL);
    struct tm *currentDate = localtime(&now);
  
    // Copy input string to temp
    snprintf(temp, sizeof(temp), "%s", input);
  
    // Determine day/ month/ year from input
    if (strstr(temp, "next") != NULL) {
        strtok(temp, " ");  // Remove 'next'
        strcpy(temp, strtok(NULL, " "));
        dateStruct->tm_mday = -1;  // Mark day for finding
        
    } else if (strstr(temp, "last") != NULL) {
        strtok(temp, " ");  // Remove 'last'
        strcpy(temp, strtok(NULL, " "));
        dateStruct->tm_mday = -1;  // Mark day for finding
    } else if (sscanf(temp, "the %d", &day) == 1) {
        dateStruct->tm_mday = day;
    } else {
        printf("Unknown date format.\n");
        return;
    }

    // Handle weekday input (Monday, Tuesday, etc.)
    if (strstr(temp, "Monday")) {
        dateStruct->tm_wday = 1;  // Set to Monday
    } else if (strstr(temp, "Tuesday")) {
        dateStruct->tm_wday = 2;  // Set to Tuesday
    } else if (strstr(temp, "Wednesday")) {
        dateStruct->tm_wday = 3;  // Set to Wednesday
    } else if (strstr(temp, "Thursday")) {
        dateStruct->tm_wday = 4;  // Set to Thursday
    } else if (strstr(temp, "Friday")) {
        dateStruct->tm_wday = 5;  // Set to Friday
    } else if (strstr(temp, "Saturday")) {
        dateStruct->tm_wday = 6;  // Set to Saturday
    } else if (strstr(temp, "Sunday")) {
        dateStruct->tm_wday = 0;  // Set to Sunday
    }

    // Handle month input (January, February, etc.)
    if (strstr(temp, "January")) {
        month = 0;  // January
    } else if (strstr(temp, "February")) {
        month = 1;  // February
    } else if (strstr(temp, "March")) {
        month = 2;  // March
    } else if (strstr(temp, "April")) {
        month = 3;  // April
    } else if (strstr(temp, "May")) {
        month = 4;  // May
    } else if (strstr(temp, "June")) {
        month = 5;  // June
    } else if (strstr(temp, "July")) {
        month = 6;  // July
    } else if (strstr(temp, "August")) {
        month = 7;  // August
    } else if (strstr(temp, "September")) {
        month = 8; // September
    } else if (strstr(temp, "October")) {
        month = 9; // October
    } else if (strstr(temp, "November")) {
        month = 10; // November
    } else if (strstr(temp, "December")) {
        month = 11; // December
    } else {
        month = currentDate->tm_mon; // Current month
    }
    
    if (dateStruct->tm_mday < 0) {
        // If we are looking for a specific day of the week
        time_t futureDate = now + (7 * 24 * 60 * 60); // 7 days later
        struct tm *futureStruct = localtime(&futureDate);
        
        // Set desired month
        futureStruct->tm_mon = month;
        futureStruct->tm_year = currentDate->tm_year; // Current Year
        mktime(futureStruct); // Normalize date
        // Find the next occurrence of the specified weekday
        while (futureStruct->tm_wday != dateStruct->tm_wday) {
            futureStruct->tm_mday++;
            mktime(futureStruct); // Normalize
        }
        
        // Update dateStruct
        dateStruct->tm_year = futureStruct->tm_year;
        dateStruct->tm_mon = futureStruct->tm_mon;
        dateStruct->tm_mday = futureStruct->tm_mday;
    } else {
        dateStruct->tm_mon = month;
        dateStruct->tm_year = currentDate->tm_year;
    }
    // Normalize the final tm structure to set all values correctly
    mktime(dateStruct);
}

int main() {
    char input[MAX_INPUT];
    struct tm dateStruct;

    printf("Enter a date in natural language (e.g., 'next Thursday', 'the third Monday of November 2023'):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character

    parseDate(input, &dateStruct);
    
    // Output the converted date
    printf("Converted date: %04d-%02d-%02d\n", dateStruct.tm_year + 1900, dateStruct.tm_mon + 1, dateStruct.tm_mday);
    
    return 0;
}