//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100

// A structure to hold the date information
typedef struct Date {
    int day;
    int month;
    int year;
} Date;

// Function prototypes
void printInstructions();
void parseDate(char *input, Date *date);
void getCurrentDate(Date *date);
void convertToNaturalDate(Date *date, char *naturalDate);
int validateDate(Date *date);
void toLexicalDate(Date *date, char *lexicalDate);

// Main program entry point
int main() {
    char input[MAX_INPUT];
    Date date;
    char naturalDate[200];

    printInstructions();

    printf("\nEnter a date (e.g., 2023-10-09): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    // Parse the input date
    parseDate(input, &date);

    // Validate the parsed date
    if (!validateDate(&date)) {
        printf("Invalid date entered. Please try again.\n");
        return 1;
    }

    // Convert to natural language date
    convertToNaturalDate(&date, naturalDate);
    printf("Natural Language Date: %s\n", naturalDate);

    return 0;
}

// Function to print instructions
void printInstructions() {
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can enter your date in the format YYYY-MM-DD.\n");
    printf("The program will then convert it to a natural language format.\n");
}

// Function to parse the date from the input string
void parseDate(char *input, Date *date) {
    sscanf(input, "%d-%d-%d", &date->year, &date->month, &date->day);
}

// Function to get the current date
void getCurrentDate(Date *date) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    date->day = tm_info->tm_mday;
    date->month = tm_info->tm_mon + 1; // Months are zero-indexed
    date->year = tm_info->tm_year + 1900; // Year since 1900
}

// Function to convert date to natural language format
void convertToNaturalDate(Date *date, char *naturalDate) {
    char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    sprintf(naturalDate, "%d %s %d", date->day, months[date->month - 1], date->year);
}

// Function to validate the date
int validateDate(Date *date) {
    if (date->year < 0 || date->month < 1 || date->month > 12 || date->day < 1) {
        return 0; // Invalid
    }

    int daysInMonth;
    switch (date->month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            // Check for leap year
            if ((date->year % 4 == 0 && date->year % 100 != 0) || (date->year % 400 == 0)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        default:
            return 0; // Invalid
    }

    return date->day <= daysInMonth; // Valid if day is within range
}

// Function to convert date to lexical format (not used in this example, but added for completeness)
void toLexicalDate(Date *date, char *lexicalDate) {
    sprintf(lexicalDate, "%d %d %d", date->day, date->month, date->year);
}