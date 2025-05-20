//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum lengths for the date strings
#define MAX_DATE_LENGTH 20
#define MAX_BUFFER_LENGTH 100

// Function to convert month names to numbers
int monthToNumber(const char *month) {
    const char *months[] = {"January", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1; // Months are 1-indexed
        }
    }
    return -1; // Invalid month
}

// Function to validate a date
int isValidDate(int year, int month, int day) {
    if (month < 1 || month > 12 || day < 1)
        return 0;

    // Days in each month
    int daysInMonth[] = {0, 31, 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)), 31, 
                         30, 31, 30, 31, 31, 30, 31, 30, 31};

    return day <= daysInMonth[month];
}

// Function to convert natural language date to standard date format
void convertDate(const char *input) {
    char month[MAX_BUFFER_LENGTH], day[MAX_BUFFER_LENGTH], year[MAX_BUFFER_LENGTH];

    // Parse the input date string
    if (sscanf(input, "%s %s %s", month, day, year) != 3) {
        printf("Invalid date format. Please use 'Month Day Year'.\n");
        return;
    }

    // Convert the month to a number
    int monthNum = monthToNumber(month);
    if (monthNum == -1) {
        printf("Invalid month: %s\n", month);
        return;
    }

    // Convert day and year from strings to integers
    int dayNum = atoi(day);
    int yearNum = atoi(year);

    // Validate the date
    if (!isValidDate(yearNum, monthNum, dayNum)) {
        printf("Invalid date: %s %s %s\n", month, day, year);
        return;
    }

    // Create a struct tm for formatting
    struct tm date = {0};
    date.tm_year = yearNum - 1900; // Years since 1900
    date.tm_mon = monthNum - 1;    // Months are 0-indexed
    date.tm_mday = dayNum;

    // Print date in standard format (YYYY-MM-DD)
    char output[MAX_DATE_LENGTH];
    strftime(output, sizeof(output), "%Y-%m-%d", &date);
    printf("Converted date: %s\n", output);
}

// Main function
int main() {
    char input[MAX_BUFFER_LENGTH];
    
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format 'Month Day Year' (e.g., 'January 25 2023'):\n");

    // Get input from the user
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Convert the date
        convertDate(input);
    } else {
        printf("Error reading input.\n");
    }
    
    return 0;
}