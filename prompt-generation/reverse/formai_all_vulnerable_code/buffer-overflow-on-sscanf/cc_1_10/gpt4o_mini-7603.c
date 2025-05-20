//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_STRING 100
#define DATE_FORMAT_LENGTH 20

// Function to convert month from string to number
int monthStringToNumber(const char *month) {
    const char *months[] = {"January", "February", "March", "April", "May",
                            "June", "July", "August", "September",
                            "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1; // Return month number (1-12)
        }
    }
    return -1; // Invalid month
}

// Function to check if the year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
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

// Function to convert a natural language date to standard date format
int convertNaturalDate(const char *naturalDate, char *standardDate) {
    const char *delimiter = " "; 
    char month[20], day[3], year[5];
    
    // Parse the input date
    if (sscanf(naturalDate, "%s %s %s", month, day, year) != 3) {
        return -1; // Error parsing date
    }
    
    int monthNum = monthStringToNumber(month);
    if (monthNum == -1) {
        return -1; // Invalid month
    }
    
    int dayNum = atoi(day);
    int yearNum = atoi(year);
    
    // Validate day
    if (dayNum < 1 || dayNum > getDaysInMonth(monthNum, yearNum)) {
        return -1; // Invalid day
    }

    // Create standard date format YYYY-MM-DD
    sprintf(standardDate, "%04d-%02d-%02d", yearNum, monthNum, dayNum);
    return 0; // Success
}

// Function to calculate the difference between two dates in days
int dateDifference(const char *startDate, const char *endDate) {
    struct tm tmStart = {0}, tmEnd = {0};

    strptime(startDate, "%Y-%m-%d", &tmStart);
    strptime(endDate, "%Y-%m-%d", &tmEnd);

    time_t timeStart = mktime(&tmStart);
    time_t timeEnd = mktime(&tmEnd);

    return difftime(timeEnd, timeStart) / (60 * 60 * 24);
}

int main() {
    char naturalDate[MAX_DATE_STRING];
    char standardDate[DATE_FORMAT_LENGTH];

    printf("Enter a date in natural language format (e.g., \"March 15 2023\"): ");
    fgets(naturalDate, MAX_DATE_STRING, stdin);
    naturalDate[strcspn(naturalDate, "\n")] = 0; // Remove trailing newline

    if (convertNaturalDate(naturalDate, standardDate) != 0) {
        printf("Error: Invalid date format or date doesn't exist!\n");
        return 1;
    }

    printf("Standard date format: %s\n", standardDate);

    // Example end date for difference calculation
    char endDate[DATE_FORMAT_LENGTH] = "2023-12-31";
    int daysDiff = dateDifference(standardDate, endDate);
    printf("Days between %s and %s: %d days\n", standardDate, endDate, daysDiff);

    return 0;
}