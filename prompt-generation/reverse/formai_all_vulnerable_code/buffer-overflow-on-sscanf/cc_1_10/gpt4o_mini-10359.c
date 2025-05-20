//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
#define MAX_MONTH_SIZE 20
#define MAX_YEAR_SIZE 5

// A function to detect and convert month from string to number.
int monthToNumber(const char *monthName) {
    const char *months[] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(monthName, months[i]) == 0) {
            return i + 1; // Return month number (1-12)
        }
    }
    return -1; // Invalid month
}

// A helper function to remove unnecessary spaces
void trimSpaces(char *input) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*input)) input++;

    // Trim trailing space
    end = input + strlen(input) - 1;
    while (end > input && isspace((unsigned char)*end)) end--;

    // Null terminate trimmed string
    *(end + 1) = '\0';
}

// A function to parse the date input from natural language
void parseDate(char *input, int *day, int *month, int *year) {
    char monthStr[MAX_MONTH_SIZE];
    
    // Check for common formats
    if (sscanf(input, "%d %s %d", day, monthStr, year) == 3) {
        *month = monthToNumber(monthStr);
    } else if (sscanf(input, "%s %d, %d", monthStr, day, year) == 3) {
        *month = monthToNumber(monthStr);
    } else if (sscanf(input, "%d/%d/%d", day, month, year) == 3) {
        // fscanf won't convert month name; just grab numbers
        return;
    } else {
        printf("\033[1;31mInvalid date format. Please use a recognized format.\033[0m\n");
    }
}

// A function to display the date in a standard format
void displayDate(int day, int month, int year) {
    printf("\033[1;34mConverted Date: %02d-%02d-%04d\033[0m\n", day, month, year);
}

int main() {
    char input[MAX_INPUT_SIZE];
    int day = 0, month = 0, year = 0;

    // Artistic welcome message
    printf("\033[1;32m========================================\n");
    printf("    Natural Language Date Converter\n");
    printf("========================================\033[0m\n\n");

    // Get user input
    printf("\033[1;33mEnter a date (e.g., '22 March 2021' or 'March 22, 2021'): \033[0m");
    fgets(input, sizeof(input), stdin);

    // Trim spaces and parse date
    trimSpaces(input);
    parseDate(input, &day, &month, &year);

    // If valid day and month are obtained, display the result
    if (day > 0 && month > 0 && year > 0) {
        displayDate(day, month, year);
    } else {
        printf("\033[1;31mUnable to parse date from input.\033[0m\n");
    }

    printf("\033[1;32m========================================\n");
    printf("         Thank you for using!\n");
    printf("========================================\033[0m\n");

    return 0;
}