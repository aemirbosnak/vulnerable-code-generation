//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 256

// Function to convert a month string to an integer
int monthToInt(const char *month) {
    const char *months[] = {"January", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December"};
    
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(month, months[i]) == 0) {
            return i + 1; // Months are 1-indexed
        }
    }
    return -1; // Invalid month
}

// Function to convert a natural language date to a struct tm
int naturalDateToStruct(const char *inputDate, struct tm *tmDate) {
    char month[MAX_LENGTH];
    int day, year;

    // Use sscanf to read the natural language date
    int matched = sscanf(inputDate, "%d %s %d", &day, month, &year);
    
    if (matched != 3) {
        printf("Invalid date format. Please use 'Day Month Year' format.\n");
        return -1;
    }

    int monthNum = monthToInt(month);
    if (monthNum == -1) {
        printf("Invalid month provided.\n");
        return -1;
    }

    // Prepare tm structure
    tmDate->tm_mday = day;
    tmDate->tm_mon = monthNum - 1; // tm_mon is 0-indexed
    tmDate->tm_year = year - 1900; // tm_year is years since 1900
    tmDate->tm_hour = 0;
    tmDate->tm_min = 0;
    tmDate->tm_sec = 0;
    tmDate->tm_isdst = -1; // Let mktime determine if DST is in effect

    return 0; // Success
}

// Function to print the date in a readable format
void printFormattedDate(struct tm *tmDate) {
    char buffer[MAX_LENGTH];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", tmDate);
    printf("Formatted Date: %s\n", buffer);
}

// Main function where the magic unfolds
int main() {
    char userInput[MAX_LENGTH];
    struct tm tmDate;

    printf("Welcome to the Imaginative Date Converter!\n");
    printf("Enter a date in 'Day Month Year' format (e.g., 25 December 2023):\n");
    
    // Get user input
    if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
        userInput[strcspn(userInput, "\n")] = '\0'; // Remove newline character

        // Convert to struct tm
        if (naturalDateToStruct(userInput, &tmDate) == 0) {
            printFormattedDate(&tmDate);
            
            // Convert to time_t for further manipulation
            time_t timeStamp = mktime(&tmDate);
            if (timeStamp == -1) {
                printf("Failed to convert to a time_t value.\n");
            } else {
                printf("Timestamp: %ld\n", timeStamp);
                printf("The date and time are now in Unix timestamp format!\n");
            }
        }
    } else {
        printf("Encountered an error while reading input. Please try again.\n");
    }

    printf("Thank you for using the Imaginative Date Converter! Have a magical day!\n");
    return 0;
}