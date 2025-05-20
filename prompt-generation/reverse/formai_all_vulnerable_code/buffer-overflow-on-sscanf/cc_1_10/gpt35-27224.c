//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
// C Natural Language Date Converter Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100        // Maximum length of input string
#define INVALID_DATE -1       // Return value if date is invalid
#define LEAP_YEAR 1           // Return value if year is a leap year

// Function to check if the given year is a leap year or not
int isLeapYear(int year) {
    if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)) {
        return LEAP_YEAR;
    }

    return 0;
}

// Function to validate the given date
int isValidDate(int day, int month, int year) {
    int maxDays = 0;

    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return INVALID_DATE;
    }

    if (month == 2) {
        maxDays = 28 + isLeapYear(year);
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDays = 30;
    }
    else {
        maxDays = 31;
    }

    if (day > maxDays) {
        return INVALID_DATE;
    }

    return 0;
}

// Function to convert month name to month number
int monthNameToNumber(char *monthName) {
    char *months[] = {
        "january", "february", "march", "april", "may", "june",
        "july", "august", "september", "october", "november", "december"
    };

    for (int i = 0; i < 12; ++i) {
        if (strcasecmp(monthName, months[i]) == 0) {
            return i + 1;
        }
    }

    return 0;
}

// Function to parse the input string and extract the date components
int parseDate(char *input, int *day, int *month, int *year) {
    char *ptr = input;
    char buffer[MAX_LENGTH];

    // Initialize values to zero
    *day = *month = *year = 0;

    // Extract day
    sscanf(input, "%d", day);

    // Extract month
    while (isdigit(*ptr)) {
        ptr++;
    }

    while (!isdigit(*ptr) && *ptr != '\0') {
        ptr++;
    }

    sscanf(ptr, "%s", buffer);
    *month = monthNameToNumber(buffer);

    // Extract year
    while (isdigit(*ptr)) {
        ptr++;
    }

    while (!isdigit(*ptr) && *ptr != '\0') {
        ptr++;
    }

    sscanf(ptr, "%d", year);

    if (isValidDate(*day, *month, *year) == INVALID_DATE) {
        return INVALID_DATE;
    }

    return 0;
}

// Main function
int main() {
    char input[MAX_LENGTH];
    int day, month, year;

    printf("Enter date in natural language (e.g. January 1, 2022): ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Parse input string
    if (parseDate(input, &day, &month, &year) == INVALID_DATE) {
        printf("Invalid date!\n");
        return -1;
    }

    // Print output
    printf("Day: %d\n", day);
    printf("Month: %d\n", month);
    printf("Year: %d\n", year);

    return 0;
}