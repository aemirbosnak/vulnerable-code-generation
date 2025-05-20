//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

/* Function declarations */
void printCurrentDate();
int convertDate(const char* inputDate);
void handleUserInput();
void displayHelp();

/* 
 * Knuth would encourage us to comment and document properly. 
 * Therefore, I'll walk through the next steps with clarity.
 * 
 * This program aims to convert natural language date input into a 
 * standard format (YYYY-MM-DD). 
 */

int main() {
    // Print current date at the beginning to set context
    printCurrentDate();
    handleUserInput();
    return 0;
}

/* This function prints the current date in the specified format. */
void printCurrentDate() {
    time_t now;
    struct tm *timeinfo;
    char buffer[80];

    time(&now);
    timeinfo = localtime(&now);

    strftime(buffer, sizeof(buffer), "Current Date: %Y-%m-%d", timeinfo);
    printf("%s\n", buffer);
}

/* 
 * The function convertDate will take a user input date in natural language 
 * and convert it into a standard format.
 */
int convertDate(const char* inputDate) {
    char month[20];
    int day, year;
    char buffer[11]; // YYYY-MM-DD

    // Parsing the input for expected format: "March 12 2023"
    if (sscanf(inputDate, "%s %d %d", month, &day, &year) != 3) {
        fprintf(stderr, "Error: Invalid date format. Please use 'Month Day Year'.\n");
        return 1;
    }

    // Convert month string to digit
    int monthNumber = 0;
    if (strcmp(month, "January") == 0) monthNumber = 1;
    else if (strcmp(month, "February") == 0) monthNumber = 2;
    else if (strcmp(month, "March") == 0) monthNumber = 3;
    else if (strcmp(month, "April") == 0) monthNumber = 4;
    else if (strcmp(month, "May") == 0) monthNumber = 5;
    else if (strcmp(month, "June") == 0) monthNumber = 6;
    else if (strcmp(month, "July") == 0) monthNumber = 7;
    else if (strcmp(month, "August") == 0) monthNumber = 8;
    else if (strcmp(month, "September") == 0) monthNumber = 9;
    else if (strcmp(month, "October") == 0) monthNumber = 10;
    else if (strcmp(month, "November") == 0) monthNumber = 11;
    else if (strcmp(month, "December") == 0) monthNumber = 12;
    else {
        fprintf(stderr, "Error: Unknown month: %s\n", month);
        return 1;
    }

    // Formulate the standard date format
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", year, monthNumber, day);
    printf("Converted Date: %s\n", buffer);
    return 0;
}

/* 
 * This function handles the user input while prompting for a natural language 
 * date format. 
 */
void handleUserInput() {
    char input[MAX_LENGTH];
    printf("Enter a date (e.g., 'March 12 2023') or type 'help' for usage: ");

    while (1) {
        if (!fgets(input, sizeof(input), stdin)) {
            break; // Exit on EOF or read error
        }

        // Remove new line character if present
        input[strcspn(input, "\n")] = 0;

        // Check for help request
        if (strcmp(input, "help") == 0) {
            displayHelp();
            continue;
        }

        // Convert the input date and handle any errors
        if (convertDate(input)) {
            fprintf(stderr, "Failed to convert the date. Please try again.\n");
        }
        
        printf("Enter another date or 'help': ");
    }
}

/* The help function displays instructions to assist the user. */
void displayHelp() {
    printf("Date Converter Help:\n");
    printf("This program converts your natural language date into a 'YYYY-MM-DD' format.\n");
    printf("Please use the format: 'Month Day Year' (e.g., 'March 12 2023').\n");
    printf("Available months: January, February, March, April, May, June, July, August, September, October, November, December.\n");
    printf("Type 'exit' to end the program.\n");
}