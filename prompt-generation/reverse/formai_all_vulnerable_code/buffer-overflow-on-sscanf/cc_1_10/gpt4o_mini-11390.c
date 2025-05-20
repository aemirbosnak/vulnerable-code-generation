//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_DATE_LENGTH 100

// Structure to hold the date components
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function to parse date string in natural language
bool parseDate(const char *input, Date *date) {
    // Define array of month names
    const char *months[] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
    
    char monthStr[20];
    int day;
    char *token;

    // Extract day and month from the input
    if (sscanf(input, "%d %s", &day, monthStr) != 2) {
        return false;
    }
    
    // Convert month string to month number
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], monthStr) == 0) {
            date->month = i + 1; // Months are 1-12
            break;
        }
    }

    // Check if month was found
    if (date->month == 0) {
        return false;
    }

    // Assign parsed day and reset year
    date->day = day;
    date->year = 0; // year will be set later

    return true;
}

// Function to get the current year
int getCurrentYear() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return tm.tm_year + 1900; // tm_year is years since 1900
}

// Function to display parsed date in a formatted way
void displayDate(const Date *date) {
    if (date->year == 0) {
        printf("Parsed Date: %02d/%02d (Year not specified)\n", date->day, date->month);
    } else {
        printf("Parsed Date: %02d/%02d/%04d\n", date->day, date->month, date->year);
    }
}

// Main function that prompts for input and parses the date
int main() {
    char input[MAX_DATE_LENGTH];
    Date date;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format 'day month' (e.g., '10 February'):\n");

    // Read input
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        // Parse the date
        if (parseDate(input, &date)) {
            // Get the current year
            date.year = getCurrentYear();
            // Display the result
            displayDate(&date);
        } else {
            printf("Invalid date format. Please try again.\n");
        }
    } else {
        printf("An error occurred while reading input.\n");
    }

    return 0;
}