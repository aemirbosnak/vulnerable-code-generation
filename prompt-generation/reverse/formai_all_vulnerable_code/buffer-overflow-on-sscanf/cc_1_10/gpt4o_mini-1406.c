//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_STRING_LENGTH 100

// Function prototypes
void getDateFromUser(char* buffer, size_t length);
int convertNaturalLanguageDate(const char* input, struct tm* outputDate);
void printDate(struct tm date);

int main() {
    char dateInput[MAX_DATE_STRING_LENGTH];
    struct tm parsedDate;

    printf("Welcome to the C Natural Language Date Converter!\n");
    printf("Please enter a date in natural language (e.g., 'April 5, 2021', 'next Monday', '2 days ago'):\n");
    
    getDateFromUser(dateInput, sizeof(dateInput));

    if (convertNaturalLanguageDate(dateInput, &parsedDate)) {
        printf("You have entered a valid date.\n");
        printDate(parsedDate);
    } else {
        printf("The date you entered could not be parsed. Please try again.\n");
    }

    return 0;
}

void getDateFromUser(char* buffer, size_t length) {
    // Get input from the user
    if (fgets(buffer, length, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
    }
}

// Helper function to convert month name to month number (1-12)
int getMonthNumber(const char* month) {
    const char* months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    
    for (int i = 0; i < 12; ++i) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1; // Months are 1-indexed
        }
    }

    return 0; // Invalid month
}

int convertNaturalLanguageDate(const char* input, struct tm* outputDate) {
    // Initialize outputDate
    memset(outputDate, 0, sizeof(struct tm));
    time_t now;
    time(&now);
    struct tm *currentTime = localtime(&now);
    
    // Handle different cases for parsing
    if (strstr(input, "next") != NULL) {
        // For handling phrases like "next Monday"
        char* dayStr = strtok(input, " ");
        if (strstr(dayStr, "Monday") != NULL) {
            outputDate->tm_wday = 1; // Monday
        } else if (strstr(dayStr, "Tuesday") != NULL) {
            outputDate->tm_wday = 2; // Tuesday
        } else if (strstr(dayStr, "Wednesday") != NULL) {
            outputDate->tm_wday = 3; // Wednesday
        } else if (strstr(dayStr, "Thursday") != NULL) {
            outputDate->tm_wday = 4; // Thursday
        } else if (strstr(dayStr, "Friday") != NULL) {
            outputDate->tm_wday = 5; // Friday
        } else if (strstr(dayStr, "Saturday") != NULL) {
            outputDate->tm_wday = 6; // Saturday
        } else if (strstr(dayStr, "Sunday") != NULL) {
            outputDate->tm_wday = 0; // Sunday
        } else {
            return 0; // Invalid day
        }
        
        // Set the date to the next occurrence of that day
        outputDate->tm_year = currentTime->tm_year; // Current year
        outputDate->tm_mon = currentTime->tm_mon; // Current month
        outputDate->tm_mday = currentTime->tm_mday + (7 - (currentTime->tm_wday - outputDate->tm_wday + 7) % 7);
        mktime(outputDate); // Normalize date
        return 1;
    } else if (strstr(input, "ago") != NULL) {
        // For phrases like "2 days ago"
        char* token = strtok(input, " ");
        int daysAgo = atoi(token);
        if (token != NULL) {
            outputDate->tm_mday = currentTime->tm_mday - daysAgo;
            outputDate->tm_year = currentTime->tm_year;
            outputDate->tm_mon = currentTime->tm_mon;
            mktime(outputDate); // Normalize date
            return 1;
        }
    } else {
        // For standard date formats like "April 5, 2021"
        char month[20];
        int day, year;
        if (sscanf(input, "%19s %d, %d", month, &day, &year) == 3) {
            outputDate->tm_year = year - 1900;
            outputDate->tm_mon = getMonthNumber(month) - 1;
            outputDate->tm_mday = day;
            outputDate->tm_isdst = -1; // Let mktime determine whether DST is in effect
            mktime(outputDate); // Normalize date
            return 1;
        }
    }
    
    return 0; // Failed to parse the date
}

void printDate(struct tm date) {
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", &date); // Format the output
    printf("Parsed Date: %s\n", buffer);
}