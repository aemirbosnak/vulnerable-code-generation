//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to convert month in words to month number
int monthToNumber(const char *month) {
    if (strcasecmp(month, "January") == 0) return 1;
    else if (strcasecmp(month, "February") == 0) return 2;
    else if (strcasecmp(month, "March") == 0) return 3;
    else if (strcasecmp(month, "April") == 0) return 4;
    else if (strcasecmp(month, "May") == 0) return 5;
    else if (strcasecmp(month, "June") == 0) return 6;
    else if (strcasecmp(month, "July") == 0) return 7;
    else if (strcasecmp(month, "August") == 0) return 8;
    else if (strcasecmp(month, "September") == 0) return 9;
    else if (strcasecmp(month, "October") == 0) return 10;
    else if (strcasecmp(month, "November") == 0) return 11;
    else if (strcasecmp(month, "December") == 0) return 12;
    
    return -1; // Invalid month
}

// Function to get the current date
void getCurrentDate() {
    time_t rawtime;
    struct tm *timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    printf("\nCurrent Date: %s", asctime(timeinfo));
}

// Function to validate if the date entered by the user is correct
int isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) return 0; // Invalid month
    if (day < 1 || day > 31) return 0; // Invalid day

    // Check for month-specific day limits
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return 0;
    if (month == 2) {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { // Leap Year
            if (day > 29) return 0;
        } else { // Not a leap year
            if (day > 28) return 0;
        }
    }
    
    return 1; // Valid date
}

// Function to convert a natural language date string to a formatted date
void convertNaturalDate(const char *dateStr) {
    char month[20];
    int day, year;
    
    // Format to extract day, month and year
    if (sscanf(dateStr, "%d %s %d", &day, month, &year) != 3) {
        printf("Invalid date format. Please use 'day Month year' format.\n");
        return;
    }
    
    int monthNumber = monthToNumber(month);
    
    if (monthNumber == -1) {
        printf("Invalid month name: %s\n", month);
        return;
    }

    // Check if the entered date is valid
    if (!isValidDate(day, monthNumber, year)) {
        printf("The date %d %s %d is invalid.\n", day, month, year);
        return;
    }
    
    printf("Formatted Date: %04d-%02d-%02d\n", year, monthNumber, day);
}

int main() {
    char dateStr[50];
    
    getCurrentDate();
    
    printf("\nEnter a date in 'day Month year' format (e.g., '12 October 2023'):\n");
    fgets(dateStr, sizeof(dateStr), stdin);

    // Remove newline character from input
    dateStr[strcspn(dateStr, "\n")] = 0;

    convertNaturalDate(dateStr);
    
    return 0;
}