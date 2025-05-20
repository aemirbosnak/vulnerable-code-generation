//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Function prototypes
int parse_date(char *input, struct tm *date);
void display_date(struct tm *date);
void to_lower(char *str);

int main() {
    char input[100];
    struct tm date = {0};
    char again;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can enter a date in formats like 'July 4th, 1776' or 'Next Friday'.\n");

    do {
        printf("\nPlease enter a date: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;  // Remove newline character

        // Parsing the date entered by the user
        if (parse_date(input, &date)) {
            display_date(&date);
        } else {
            printf("I couldn't understand that date. Please try again in a different format.\n");
        }

        printf("Would you like to enter another date? (y/n): ");
        scanf(" %c", &again);
        while (getchar() != '\n'); // Clear the input buffer

    } while (tolower(again) == 'y');

    printf("Thank you for using the Natural Language Date Converter! Goodbye!\n");
    return 0;
}

// Function to convert user input into structured date format
int parse_date(char *input, struct tm *date) {
    char month[20];
    int day, year;

    // Convert input to lowercase for easier parsing
    to_lower(input);

    // Check for common date formats
    if (sscanf(input, "%s %d, %d", month, &day, &year) == 3) {
        // Mapping month names to numbers
        if (strcmp(month, "january") == 0) date->tm_mon = 0;
        else if (strcmp(month, "february") == 0) date->tm_mon = 1;
        else if (strcmp(month, "march") == 0) date->tm_mon = 2;
        else if (strcmp(month, "april") == 0) date->tm_mon = 3;
        else if (strcmp(month, "may") == 0) date->tm_mon = 4;
        else if (strcmp(month, "june") == 0) date->tm_mon = 5;
        else if (strcmp(month, "july") == 0) date->tm_mon = 6;
        else if (strcmp(month, "august") == 0) date->tm_mon = 7;
        else if (strcmp(month, "september") == 0) date->tm_mon = 8;
        else if (strcmp(month, "october") == 0) date->tm_mon = 9;
        else if (strcmp(month, "november") == 0) date->tm_mon = 10;
        else if (strcmp(month, "december") == 0) date->tm_mon = 11;
        else {
            printf("Invalid month entered.\n");
            return 0;
        }

        // Set day and year
        date->tm_mday = day;
        date->tm_year = year - 1900; // tm_year is years since 1900
        date->tm_isdst = -1; // Let mktime determine if DST is in effect

        return 1; // Successful parsing
    } else {
        printf("Could not parse the date from the input.\n");
        return 0; // Parsing failed
    }
}

// Function to display the parsed date back to the user
void display_date(struct tm *date) {
    char buffer[80];
    // Use mktime to normalize the tm structure
    mktime(date);
    
    // Format the date into a readable string
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", date);
    printf("You entered a date that corresponds to: %s\n", buffer);
}

// Function to convert a string to lowercase
void to_lower(char *str) {
    for (char *p = str; *p; p++) {
        *p = tolower(*p);
    }
}