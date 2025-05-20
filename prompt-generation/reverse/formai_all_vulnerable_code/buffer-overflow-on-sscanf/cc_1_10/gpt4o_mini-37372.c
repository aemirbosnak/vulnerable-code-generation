//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 256

// Function to convert a natural language date string to a structured time representation
void convertNaturalLanguageDate(const char *input, struct tm *result) {
    char month[10];
    int day, year;

    // Parsing the input string
    sscanf(input, "%d %s %d", &day, month, &year);

    // Mapping months to numbers
    if (strcmp(month, "January") == 0) {
        result->tm_mon = 0; // January is month 0
    } else if (strcmp(month, "February") == 0) {
        result->tm_mon = 1; 
    } else if (strcmp(month, "March") == 0) {
        result->tm_mon = 2; 
    } else if (strcmp(month, "April") == 0) {
        result->tm_mon = 3; 
    } else if (strcmp(month, "May") == 0) {
        result->tm_mon = 4; 
    } else if (strcmp(month, "June") == 0) {
        result->tm_mon = 5; 
    } else if (strcmp(month, "July") == 0) {
        result->tm_mon = 6; 
    } else if (strcmp(month, "August") == 0) {
        result->tm_mon = 7; 
    } else if (strcmp(month, "September") == 0) {
        result->tm_mon = 8; 
    } else if (strcmp(month, "October") == 0) {
        result->tm_mon = 9; 
    } else if (strcmp(month, "November") == 0) {
        result->tm_mon = 10; 
    } else if (strcmp(month, "December") == 0) {
        result->tm_mon = 11; 
    } else {
        fprintf(stderr, "Unknown month: %s\n", month);
        exit(EXIT_FAILURE);
    }

    // Assign day and year
    result->tm_mday = day;
    result->tm_year = year - 1900; // tm_year counts years since 1900
    result->tm_hour = 0;
    result->tm_min = 0;
    result->tm_sec = 0;
    result->tm_isdst = -1; // Not considering daylight saving 

    // Normalize the time structure
    mktime(result);
}

// Function to print the structured time in a friendly format
void printFriendlyDate(struct tm *date) {
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", date);
    printf("The formatted date is: %s\n", buffer);
}

// Main function
int main() {
    char input[MAX_BUFFER_SIZE];
    struct tm date = {0};

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format: 'Day Month Year' (e.g., '25 December 2023'):\n");
    
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Removing newline character if it exists
        input[strcspn(input, "\n")] = 0;
    
        // Convert the natural language date
        convertNaturalLanguageDate(input, &date);
        
        // Print the friendly formatted date
        printFriendlyDate(&date);
    } else {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}