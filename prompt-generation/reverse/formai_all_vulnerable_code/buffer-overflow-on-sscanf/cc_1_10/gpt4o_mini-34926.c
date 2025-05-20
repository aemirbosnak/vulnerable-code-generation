//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to parse the date from natural language
void parseDate(const char *input, int *day, int *month, int *year) {
    char monthName[20];
    
    if (sscanf(input, "%d %s %d", day, monthName, year) == 3) {
        if (strcmp(monthName, "January") == 0) *month = 1;
        else if (strcmp(monthName, "February") == 0) *month = 2;
        else if (strcmp(monthName, "March") == 0) *month = 3;
        else if (strcmp(monthName, "April") == 0) *month = 4;
        else if (strcmp(monthName, "May") == 0) *month = 5;
        else if (strcmp(monthName, "June") == 0) *month = 6;
        else if (strcmp(monthName, "July") == 0) *month = 7;
        else if (strcmp(monthName, "August") == 0) *month = 8;
        else if (strcmp(monthName, "September") == 0) *month = 9;
        else if (strcmp(monthName, "October") == 0) *month = 10;
        else if (strcmp(monthName, "November") == 0) *month = 11;
        else if (strcmp(monthName, "December") == 0) *month = 12;
        else {
            *month = -1; // invalid month
        }
    } else {
        *day = -1; *month = -1; *year = -1; // parsing failed
    }
}

// Function to print the date in standard format
void printDate(int day, int month, int year) {
    if (day <= 0 || month <= 0 || year <= 0) {
        printf("Invalid date format.\n");
        return;
    }
    
    printf("Converted Date: %04d-%02d-%02d\n", year, month, day);
}

// Function to convert natural language date input to structured date
void convertNaturalDate() {
    char input[100];
    int day, month, year;

    printf("Enter a date in the format 'DD Month YYYY' (e.g., 25 December 2021):\n");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    parseDate(input, &day, &month, &year);
    printDate(day, month, year);
}

int main() {
    char choice;
    do {
        convertNaturalDate();
        printf("Do you want to convert another date? (y/n): ");
        choice = getchar();
        getchar(); // clear newline character from input buffer
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Natural Language Date Converter! Goodbye!\n");
    return 0;
}