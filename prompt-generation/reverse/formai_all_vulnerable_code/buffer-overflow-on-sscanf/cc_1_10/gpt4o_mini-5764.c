//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int daysInMonth(int month, int year) {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0; // Invalid month
    }
}

// Function to convert a date string to day, month, and year
void parseDate(const char* dateStr, int* day, int* month, int* year) {
    sscanf(dateStr, "%d-%d-%d", day, month, year);
}

// Function to convert date from string format to natural language format
void convertToNaturalLanguage(int day, int month, int year, char* result) {
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    if (month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year)) {
        sprintf(result, "Invalid date: %02d-%02d-%d", day, month, year);
        return;
    }

    sprintf(result, "%d %s, %d", day, months[month - 1], year);
}

// Function to interact with the user
void getUserDateInput() {
    char dateStr[11];
    int day, month, year;
    char naturalLanguageDate[50];

    printf("Enter the date in format YYYY-MM-DD: ");
    fgets(dateStr, sizeof(dateStr), stdin);
    dateStr[strcspn(dateStr, "\n")] = 0; // Remove newline character
    
    parseDate(dateStr, &day, &month, &year);
    convertToNaturalLanguage(day, month, year, naturalLanguageDate);
    
    printf("Natural Language Format: %s\n", naturalLanguageDate);
}

// Main function
int main() {
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can convert dates from the YYYY-MM-DD format to a more readable format.\n");
    
    while (1) {
        getUserDateInput();
        
        char continueResponse[10];
        printf("Do you want to convert another date? (yes/no): ");
        fgets(continueResponse, sizeof(continueResponse), stdin);
        continueResponse[strcspn(continueResponse, "\n")] = 0; // Remove newline character
        
        if (strcasecmp(continueResponse, "no") == 0) {
            printf("Thank you for using the converter! Goodbye!\n");
            break;
        }
    }
    
    return 0;
}