//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to parse date from natural language input
void parseDate(const char *input, struct tm *date) {
    time_t now;
    time(&now);
    struct tm *current_time = localtime(&now);
    char day[20], month[20];
    int delta_days = 0, year = current_time->tm_year + 1900;

    // Check if the input is in a specific format: "January 25, 2023"
    if (sscanf(input, "%s %d, %d", month, &date->tm_mday, &year) == 3) {
        // Mapping month names to numbers
        if (strcasecmp(month, "January") == 0) date->tm_mon = 0;
        else if (strcasecmp(month, "February") == 0) date->tm_mon = 1;
        else if (strcasecmp(month, "March") == 0) date->tm_mon = 2;
        else if (strcasecmp(month, "April") == 0) date->tm_mon = 3;
        else if (strcasecmp(month, "May") == 0) date->tm_mon = 4;
        else if (strcasecmp(month, "June") == 0) date->tm_mon = 5;
        else if (strcasecmp(month, "July") == 0) date->tm_mon = 6;
        else if (strcasecmp(month, "August") == 0) date->tm_mon = 7;
        else if (strcasecmp(month, "September") == 0) date->tm_mon = 8;
        else if (strcasecmp(month, "October") == 0) date->tm_mon = 9;
        else if (strcasecmp(month, "November") == 0) date->tm_mon = 10;
        else if (strcasecmp(month, "December") == 0) date->tm_mon = 11;
        date->tm_year = year - 1900;
    } 
    // Check for relative date formats: "next Friday", "two days from now"
    else if (strstr(input, "next") != NULL || strstr(input, "days") != NULL) {
        if (strstr(input, "next") != NULL) {
            if (strstr(input, "Monday") != NULL) delta_days = 7 - current_time->tm_wday + 1;
            else if (strstr(input, "Tuesday") != NULL) delta_days = 7 - current_time->tm_wday + 2;
            else if (strstr(input, "Wednesday") != NULL) delta_days = 7 - current_time->tm_wday + 3;
            else if (strstr(input, "Thursday") != NULL) delta_days = 7 - current_time->tm_wday + 4;
            else if (strstr(input, "Friday") != NULL) delta_days = 7 - current_time->tm_wday + 5;
            else if (strstr(input, "Saturday") != NULL) delta_days = 7 - current_time->tm_wday + 6;
            else if (strstr(input, "Sunday") != NULL) delta_days = 7 - current_time->tm_wday + 7;
        } else if (sscanf(input, "%d days", &delta_days) == 1) {
            delta_days = delta_days; // Use the provided number of days
        }

        // Adding the number of days to the current time
        date->tm_mday = current_time->tm_mday + delta_days;
        date->tm_mon = current_time->tm_mon;
        date->tm_year = current_time->tm_year;

        // Normalize date if necessary
        mktime(date); // Adjust the tm structure accordingly.
    } else {
        printf("Could not understand the date format. Please try again.\n");
        exit(1);
    }

    // Print the final date
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", date);
    printf("Converted Date: %s\n", buffer);
}

int main() {
    char input[100];
    struct tm date = {0}; // Initialize date structure to zero

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date (e.g. 'next Friday', 'January 25, 2023', '2 days from now'):\n");
    
    // Get user input
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from fgets
    input[strcspn(input, "\n")] = 0;

    // Parse the input date
    parseDate(input, &date);
    
    return 0;
}