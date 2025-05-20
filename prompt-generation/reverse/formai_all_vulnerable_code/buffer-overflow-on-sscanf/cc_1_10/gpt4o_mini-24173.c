//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

// Function to convert month name to number
int monthToNumber(const char *month) {
    if (strcasecmp(month, "January") == 0) return 1;
    else if (strcasecmp(month, "February") == 0) return 2;
    else if (strcasecmp(month, "March") == 0) return 3;
    else if (strcasecmp(month, "April") == 0) return 4;
    else if (strcasecmp(month, "May") == 0) return 5;
    else if (strcasecmp(month, "June") == 0) return 6;
    else if (strcasecmp(month, "July") == 0) return 7;
    else if (strcasecmp(month, "August") == 0) return 8;
    else if (strcasecmp(month, "September") == 0) return 9;
    else if (strcasecmp(month, "October") == 0) return 10;
    else if (strcasecmp(month, "November") == 0) return 11;
    else if (strcasecmp(month, "December") == 0) return 12;
    else return -1; // Invalid month
}

// Function to determine if year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0; // divisible by 400
        }
        return 1; // divisible by 4 but not 100
    }
    return 0; // not a leap year
}

// Function to validate the date
int isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) return 0;
    if (month == 2) {
        return (day <= (isLeapYear(year) ? 29 : 28));
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11)) {
        return day <= 30;
    }
    return day <= 31;
}

// Function to convert input date to structured format
void parseDate(const char *dateInput, int *day, int *month, int *year) {
    char monthName[20];
    sscanf(dateInput, "%d %s %d", day, monthName, year);
    *month = monthToNumber(monthName);
}

// Function to format the date as a string
void formatDateString(char *outputDate, int day, int month, int year) {
    sprintf(outputDate, "%04d-%02d-%02d", year, month, day);
}

// Main program function
int main() {
    char input[MAX_INPUT_SIZE];
    char formattedDate[20];
    int day, month, year;

    printf("Welcome to the Magical Natural Language Date Converter!\n");
    printf("Please enter a date in natural language format (e.g., \"21 July 2023\"):\n");
    
    // Input from user
    while (fgets(input, sizeof(input), stdin)) {
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        // Parse the input date
        parseDate(input, &day, &month, &year);

        // Validate the parsed date
        if (!isValidDate(day, month, year)) {
            printf("Oh no! The date you entered is invalid. Please try again.\n");
            continue; // Prompt again
        }

        // Format the date into YYYY-MM-DD format
        formatDateString(formattedDate, day, month, year);

        // Display the result
        printf("Your splendid date in YYYY-MM-DD format is: %s\n", formattedDate);
        printf("Want to convert another date? (Type your date or 'exit' to quit)\n");

        // Check for exit condition
        if (strcasecmp(input, "exit") == 0) {
            break;
        }
    }
    
    printf("Thank you for using the Magical Natural Language Date Converter! Goodbye!\n");
    return 0;
}