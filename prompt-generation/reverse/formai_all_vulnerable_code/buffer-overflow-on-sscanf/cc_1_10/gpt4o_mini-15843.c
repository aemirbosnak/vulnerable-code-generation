//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: puzzling
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Function to convert month string to month number
int monthStringToNumber(const char *month) {
    if (strcmp(month, "January") == 0) return 1;
    else if (strcmp(month, "February") == 0) return 2;
    else if (strcmp(month, "March") == 0) return 3;
    else if (strcmp(month, "April") == 0) return 4;
    else if (strcmp(month, "May") == 0) return 5;
    else if (strcmp(month, "June") == 0) return 6;
    else if (strcmp(month, "July") == 0) return 7;
    else if (strcmp(month, "August") == 0) return 8;
    else if (strcmp(month, "September") == 0) return 9;
    else if (strcmp(month, "October") == 0) return 10;
    else if (strcmp(month, "November") == 0) return 11;
    else if (strcmp(month, "December") == 0) return 12;
    return -1; // Error code for invalid month
}

// Function to print the help guide
void printHelp() {
    printf("~~ Welcome to the C Natural Language Date Converter ~~\n");
    printf("Instructions:\n");
    printf("1. Input date in the format: 'Day Month Year'.\n");
    printf("   Example: '25 December 2023'\n");
    printf("2. For the list of months, refer to: January, February, ... , December.\n");
    printf("3. Type 'exit' to leave the program.\n");
}

// Function to convert a string date to a structured date object
int parseDate(const char *input, struct tm *date) {
    int day, year;
    char month[20];
    
    int scanned = sscanf(input, "%d %s %d", &day, month, &year);
    
    if (scanned != 3) {
        return 0; // Parsing failed
    }

    int monthNum = monthStringToNumber(month);
    
    if (monthNum == -1 || day < 1 || year < 1900) {
        return 0; // Invalid month or day/year
    }

    // Fill the date structure
    date->tm_mday = day;
    date->tm_mon = monthNum - 1; // tm_mon is 0-indexed
    date->tm_year = year - 1900;  // tm_year is years since 1900
    date->tm_isdst = -1; // Not considering daylight saving time
    
    return 1; // Parsing succeeded
}

// Function to handle user commands
void handleUserInput() {
    char input[100];
    struct tm date;
    time_t rawtime;
    char buffer[80];

    printf("\n");
    printHelp();

    while (1) {
        printf("Enter a date: ");
        fgets(input, sizeof(input), stdin);
        
        // Check for exit command
        if (strncmp(input, "exit", 4) == 0) break;
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Attempt to parse the date
        if (parseDate(input, &date)) {
            // Convert to time_t
            rawtime = mktime(&date);
            
            // Format the time
            strftime(buffer, sizeof(buffer), "%d-%m-%Y", localtime(&rawtime));
            printf("Formatted date: %s\n", buffer);
        } else {
            printf("Invalid date format. Please try again.\n");
        }
    }
}

// Main function
int main() {
    printf("~~~ C Natural Language Date Converter Starting ~~~\n");
    handleUserInput();
    printf("~~~ Thank you for using the converter! Goodbye! ~~~\n");
    return 0;
}