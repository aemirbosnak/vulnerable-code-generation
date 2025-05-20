//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MAX_MONTH 12

// Function prototypes
int getMonthNumber(char *month);
void formatDate(int day, int month, int year);

int main() {
    char input[MAX_INPUT];
    int day, month, year;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can enter dates in the following formats:\n");
    printf("1. '2nd January 2023'\n");
    printf("2. 'January 2, 2023'\n");
    printf("3. '3/4/2023'\n");
    printf("Please enter your date: ");
    
    // Read user input
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Check for formatted date input
    if (sscanf(input, "%d/%d/%d", &month, &day, &year) == 3) {
        // Interpret as MM/DD/YYYY
        printf("You entered a date in MM/DD/YYYY format.\n");
        formatDate(day, month, year);
    } else {
        // Try to interpret as natural language
        char monthStr[20];
        
        if (sscanf(input, "%d %s %d", &day, monthStr, &year) == 3 ||
            sscanf(input, "%s %d, %d", monthStr, &day, &year) == 3) {
            // Convert month name to number
            month = getMonthNumber(monthStr);
            if (month != -1) {
                printf("You entered a date in natural language format.\n");
                formatDate(day, month, year);
            } else {
                printf("Error: Invalid month name entered!\n");
            }
        } else {
            printf("Error: Could not parse the given date format. Please try again.\n");
        }
    }

    return 0;
}

// Function to convert month name to number
int getMonthNumber(char *month) {
    const char *months[MAX_MONTH] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    for (int i = 0; i < MAX_MONTH; ++i) {
        if (strcasecmp(month, months[i]) == 0) {
            return i + 1; // Months are 1-indexed
        }
    }
    return -1; // Invalid month
}

// Function to format the date into a more readable format
void formatDate(int day, int month, int year) {
    if (day < 1 || day > 31 || month < 1 || month > 12) {
        printf("Error: Invalid date provided!\n");
        return;
    }

    struct tm date = {0};
    date.tm_mday = day;
    date.tm_mon = month - 1; // tm_mon is 0-indexed
    date.tm_year = year - 1900; // tm_year is years since 1900

    // Normalize the date to account for invalid days of the month, e.g. February 30
    mktime(&date);

    char buffer[100];
    strftime(buffer, sizeof(buffer), "Formatted date: %A, %B %d, %Y", &date);
    printf("%s\n", buffer);
}