//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256
#define MAX_DATE_SIZE 11

// Function Prototypes
void toLowerCase(char *str);
int convertDate(char *input, char *output);
int parseDate(char *monthStr, int day, int year, char *output);
int isLeapYear(int year);
int getMonthNumber(char *monthStr);

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_DATE_SIZE];

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Enter dates in the format: 'Month Day, Year' (e.g. 'January 1, 2023')\n");
    printf("Type 'exit' to quit the program.\n");

    while (1) {
        printf("Please enter a date: ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (convertDate(input, output)) {
            printf("Converted Date: %s\n", output);
        } else {
            printf("Error: Unable to convert the date. Please check your input format.\n");
        }
    }

    return 0;
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

int convertDate(char *input, char *output) {
    char monthStr[20];
    int day, year;

    // Parse the input string
    if (sscanf(input, "%19s %d, %d", monthStr, &day, &year) != 3) {
        return 0; // Failed to parse
    }

    toLowerCase(monthStr);    

    // Convert month and validate
    int month = getMonthNumber(monthStr);
    if (month == 0 || day < 1 || year < 1) {
        return 0; // Invalid date
    }

    // Create output string in DD/MM/YYYY
    sprintf(output, "%02d/%02d/%04d", day, month, year);
    
    // Check for day validity in case of months with less days
    if (!isLeapYear(year) && month == 2 && day > 28) {
        return 0; // Invalid February day
    }
    
    if ((month == 2 && day > 28) || 
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
        return 0; // Invalid day for month
    }

    return 1; // Success
}

int getMonthNumber(char *monthStr) {
    if (strcmp(monthStr, "january") == 0) return 1;
    if (strcmp(monthStr, "february") == 0) return 2;
    if (strcmp(monthStr, "march") == 0) return 3;
    if (strcmp(monthStr, "april") == 0) return 4;
    if (strcmp(monthStr, "may") == 0) return 5;
    if (strcmp(monthStr, "june") == 0) return 6;
    if (strcmp(monthStr, "july") == 0) return 7;
    if (strcmp(monthStr, "august") == 0) return 8;
    if (strcmp(monthStr, "september") == 0) return 9;
    if (strcmp(monthStr, "october") == 0) return 10;
    if (strcmp(monthStr, "november") == 0) return 11;
    if (strcmp(monthStr, "december") == 0) return 12;
    return 0; // Invalid month
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}