//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100

// Function to parse natural language date input
void parse_date(const char* input, struct tm* date) {
    char month[20];
    int day, year;

    // Extracting month, day and year from the input
    sscanf(input, "%s %d, %d", month, &day, &year);
    
    // Determine the month number from the string input
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
    
    // Set the day and year in struct tm
    date->tm_mday = day;
    date->tm_year = year - 1900;  // tm_year is years since 1900
}

// Function to convert struct tm to time_t for easy output
time_t convert_to_time_t(struct tm* date) {
    return mktime(date);
}

// Function to format the date back to a readable string
void format_date(time_t rawtime, char* buffer, size_t size) {
    struct tm *info;
    info = localtime(&rawtime);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", info);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    struct tm date = {0}; // Initialize to zero
    time_t rawtime;
    char output_buffer[100];

    printf("Welcome to the Enchanted Date Converter!\n");
    printf("Please enter a date in the format: 'Month Day, Year' (e.g., 'January 1, 2023'): ");
    
    // Getting input from the user
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Removing newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        
        // Parsing the input into a tm structure
        parse_date(input, &date);
        
        // Convert struct tm to time_t
        rawtime = convert_to_time_t(&date);

        // Format the output back to a string
        format_date(rawtime, output_buffer, sizeof(output_buffer));
        
        printf("The magical date you entered is: %s\n", output_buffer);
    } else {
        printf("Oops! It seems there was a problem reading your date.\n");
    }
    
    return 0;
}