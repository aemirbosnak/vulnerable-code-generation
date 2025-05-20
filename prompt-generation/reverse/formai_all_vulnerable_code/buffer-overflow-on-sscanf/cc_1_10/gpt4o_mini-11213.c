//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100

// Function to convert natural language date to time_t
time_t parse_date(const char *input_date) {
    struct tm tm = {0};
    char month[20], day[10], year[10], ampm[3];
    
    // Define the format of the input string
    if (sscanf(input_date, "%s %s %s %s", month, day, year, ampm) == 4) {
        
        // Map month names to numbers
        if (strcasecmp(month, "January") == 0) {
            tm.tm_mon = 0; // January
        } else if (strcasecmp(month, "February") == 0) {
            tm.tm_mon = 1; // February
        } else if (strcasecmp(month, "March") == 0) {
            tm.tm_mon = 2; // March
        } else if (strcasecmp(month, "April") == 0) {
            tm.tm_mon = 3; // April
        } else if (strcasecmp(month, "May") == 0) {
            tm.tm_mon = 4; // May
        } else if (strcasecmp(month, "June") == 0) {
            tm.tm_mon = 5; // June
        } else if (strcasecmp(month, "July") == 0) {
            tm.tm_mon = 6; // July
        } else if (strcasecmp(month, "August") == 0) {
            tm.tm_mon = 7; // August
        } else if (strcasecmp(month, "September") == 0) {
            tm.tm_mon = 8; // September
        } else if (strcasecmp(month, "October") == 0) {
            tm.tm_mon = 9; // October
        } else if (strcasecmp(month, "November") == 0) {
            tm.tm_mon = 10; // November
        } else if (strcasecmp(month, "December") == 0) {
            tm.tm_mon = 11; // December
        } else {
            fprintf(stderr, "Unknown month: %s\n", month);
            return -1;
        }

        // Convert day and year to integers
        tm.tm_mday = atoi(day);
        tm.tm_year = atoi(year) - 1900;

        // Set the hour based on the am/pm marker
        if (strncasecmp(ampm, "pm", 2) == 0 && tm.tm_hour < 12) {
            tm.tm_hour += 12;
        } else if (strncasecmp(ampm, "am", 2) == 0 && tm.tm_hour == 12) {
            tm.tm_hour = 0;
        }

        return mktime(&tm);
    } else {
        fprintf(stderr, "Incorrect date format.\n");
        return -1;
    }
}

// Function to format the time_t date back to a readable string
void format_date(time_t time_date, char *buffer, size_t buffer_size) {
    struct tm *tm_info;

    tm_info = localtime(&time_date);
    strftime(buffer, buffer_size, "%B %d, %Y", tm_info);
}

// Main function to execute the converter
int main() {
    char input[BUFFER_SIZE];
    char formatted_date[BUFFER_SIZE];
    
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format: Month Day Year AM/PM (e.g., 'January 1 2023 AM')\n");
    
    // Input date
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    
    // Remove trailing newline character from the input
    input[strcspn(input, "\n")] = 0;

    // Convert input date
    time_t converted_date = parse_date(input);
    
    // Check for conversion success
    if (converted_date == -1) {
        return 1; // Error already printed in parse_date
    }

    // Format the converted date for output
    format_date(converted_date, formatted_date, sizeof(formatted_date));

    // Output the formatted date
    printf("The formatted date is: %s\n", formatted_date);
    
    return 0;
}