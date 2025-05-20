//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

// Function to convert month name to its corresponding number
int getMonthNumber(const char* month) {
    const char* months[] = {
        "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December"
    };

    for (int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1; // Month numbers are 1-indexed
        }
    }
    return -1; // Invalid month
}

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to validate the given date
int validateDate(int day, int month, int year) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month < 1 || month > 12) {
        return 0; // Invalid month
    }

    // Adjust for leap years
    if (month == 2 && isLeapYear(year)) {
        daysInMonth[2] = 29;
    }

    if (day < 1 || day > daysInMonth[month]) {
        return 0; // Invalid day for the month
    }

    return 1; // Valid date
}

// Function to convert a natural language date to structured format
void parseDate(const char* input, int* day, int* month, int* year) {
    char monthName[20];
    sscanf(input, "%d %s %d", day, monthName, year);
    *month = getMonthNumber(monthName);
}

// Main function
int main() {
    char input[MAX_INPUT_SIZE];
    int day, month, year;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format 'DD Month YYYY' (e.g., '25 December 2023'):\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove newline character from the input
        input[strcspn(input, "\n")] = 0;

        parseDate(input, &day, &month, &year);

        if (!validateDate(day, month, year)) {
            printf("Invalid date. Please try again.\n");
            continue;
        }

        // Convert the validated date into a more readable format
        char formattedDate[100];
        sprintf(formattedDate, "%02d/%02d/%d", day, month, year);

        struct tm tm_date;
        tm_date.tm_mday = day;
        tm_date.tm_mon = month - 1; // tm_mon is 0-indexed
        tm_date.tm_year = year - 1900; // tm_year counts years since 1900

        // Calculate the number of seconds since epoch
        time_t epochTime = mktime(&tm_date);
        if (epochTime == -1) {
            printf("Error in converting date to epoch time.\n");
            continue;
        }

        // Output the result
        printf("You entered: %s\n", input);
        printf("Formatted Date: %s\n", formattedDate);
        printf("Epoch Time: %ld seconds since the epoch\n", epochTime);
        break;
    }

    return 0;
}