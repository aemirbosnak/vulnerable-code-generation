//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100
#define MAX_DATE_SIZE 20

// Function to convert a month name to its corresponding numeric value
int monthToNumber(const char *month) {
    char *months[] = { 
        "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December" 
    };

    for (int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1;  // Return month number (1-12)
        }
    }

    return -1;  // Invalid month
}

// Function to convert a date string in "Day Month Year" format to timestamp
time_t convertDateToTimestamp(const char *date) {
    int day, month, year;
    char monthStr[20];

    if (sscanf(date, "%d %s %d", &day, monthStr, &year) == 3) {
        month = monthToNumber(monthStr);
        if (month == -1) {
            fprintf(stderr, "Error: Invalid month '%s'\n", monthStr);
            exit(EXIT_FAILURE);
        }

        struct tm timeinfo = {0};
        timeinfo.tm_year = year - 1900; // tm_year is years since 1900
        timeinfo.tm_mon = month - 1;     // tm_mon is 0-11
        timeinfo.tm_mday = day;

        return mktime(&timeinfo);
    } else {
        fprintf(stderr, "Error: Invalid date format. Use 'Day Month Year'.\n");
        exit(EXIT_FAILURE);
    }
}

// Function to print the date in a human-readable format
void printReadableDate(time_t timestamp) {
    struct tm *timeinfo = localtime(&timestamp);
    char buffer[MAX_DATE_SIZE];

    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", timeinfo);
    printf("Converted Date: %s\n", buffer);
}

// Function to read date input from the user
void readUserInput(char *input) {
    printf("Enter a date (e.g., '25 December 2023'): ");
    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }
    
    // Remove newline character if present
    char *newline = strchr(input, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    readUserInput(input);
    
    // Convert the input date to timestamp
    time_t timestamp = convertDateToTimestamp(input);

    // Print the human-readable date
    printReadableDate(timestamp);

    return EXIT_SUCCESS;
}