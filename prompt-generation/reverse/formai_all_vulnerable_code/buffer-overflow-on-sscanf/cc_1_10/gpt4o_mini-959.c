//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to parse the date
void parseDate(const char* input, struct tm* date) {
    char weekday[10];
    int day, month, year;
    char monthStr[20];

    // Clear the date structure
    memset(date, 0, sizeof(struct tm));
    
    // Get current time
    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);

    // Parse the input date
    if (sscanf(input, "next %s", weekday) == 1) {
        if (strcmp(weekday, "Monday") == 0) {
            date->tm_wday = 1;
        } else if (strcmp(weekday, "Tuesday") == 0) {
            date->tm_wday = 2;
        } else if (strcmp(weekday, "Wednesday") == 0) {
            date->tm_wday = 3;
        } else if (strcmp(weekday, "Thursday") == 0) {
            date->tm_wday = 4;
        } else if (strcmp(weekday, "Friday") == 0) {
            date->tm_wday = 5;
        } else if (strcmp(weekday, "Saturday") == 0) {
            date->tm_wday = 6;
        } else if (strcmp(weekday, "Sunday") == 0) {
            date->tm_wday = 0;
        }
        
        // Calculate the date
        date->tm_mday = currentTime->tm_mday + ((date->tm_wday >= currentTime->tm_wday) ? 
            (date->tm_wday - currentTime->tm_wday) : (7 + date->tm_wday - currentTime->tm_wday));

        date->tm_mon = currentTime->tm_mon;
        date->tm_year = currentTime->tm_year;

    } else if (sscanf(input, "the %d of %s", &day, monthStr) == 2) {
        if (strcmp(monthStr, "January") == 0) {
            month = 0;
        } else if (strcmp(monthStr, "February") == 0) {
            month = 1;
        } else if (strcmp(monthStr, "March") == 0) {
            month = 2;
        } else if (strcmp(monthStr, "April") == 0) {
            month = 3;
        } else if (strcmp(monthStr, "May") == 0) {
            month = 4;
        } else if (strcmp(monthStr, "June") == 0) {
            month = 5;
        } else if (strcmp(monthStr, "July") == 0) {
            month = 6;
        } else if (strcmp(monthStr, "August") == 0) {
            month = 7;
        } else if (strcmp(monthStr, "September") == 0) {
            month = 8;
        } else if (strcmp(monthStr, "October") == 0) {
            month = 9;
        } else if (strcmp(monthStr, "November") == 0) {
            month = 10;
        } else if (strcmp(monthStr, "December") == 0) {
            month = 11;
        } else {
            fprintf(stderr, "Invalid month: %s\n", monthStr);
            exit(EXIT_FAILURE);
        }

        date->tm_mday = day;
        date->tm_mon = month;
        date->tm_year = currentTime->tm_year;

    } else {
        fprintf(stderr, "Invalid date input format!\n");
        exit(EXIT_FAILURE);
    }

    // Normalize the tm structure
    mktime(date);
}

// Function to format the date into YYYY-MM-DD
void formatDate(const struct tm* date, char* buffer) {
    sprintf(buffer, "%04d-%02d-%02d", date->tm_year + 1900, date->tm_mon + 1, date->tm_mday);
}

int main() {
    char input[100];
    struct tm date;
    char formattedDate[11]; // YYYY-MM-DD format

    printf("Enter a date (e.g., 'next Friday' or 'the 25th of December'): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character

    parseDate(input, &date);
    formatDate(&date, formattedDate);

    printf("The formatted date is: %s\n", formattedDate);

    return 0;
}