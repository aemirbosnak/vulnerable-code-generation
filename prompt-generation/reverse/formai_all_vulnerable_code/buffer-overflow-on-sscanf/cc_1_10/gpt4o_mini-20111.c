//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BUFFER_SIZE 256
#define DAYS_IN_YEAR 365
#define MONTHS_IN_YEAR 12

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return (year % 400 == 0);
        }
        return 1;
    }
    return 0;
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

// Function to convert a date string to its equivalent days since epoch
long convertDateToDays(char *dateString) {
    int day, month, year;
    // Parsing the input date format: DD-MM-YYYY
    sscanf(dateString, "%d-%d-%d", &day, &month, &year);
    
    long totalDays = 0;

    // Adding the days of complete years
    for (int i = 1970; i < year; i++) {
        totalDays += isLeapYear(i) ? DAYS_IN_YEAR + 1 : DAYS_IN_YEAR;
    }

    // Adding the days for the months of the current year
    for (int i = 1; i < month; i++) {
        totalDays += getDaysInMonth(i, year);
    }
    
    // Adding the days in the current month
    totalDays += day;

    return totalDays;
}

// Function to convert days since epoch back to date string
void convertDaysToDate(long totalDays, char *dateString) {
    int year = 1970;
    int month = 1;
    int day;

    // Determine year
    while (totalDays >= (isLeapYear(year) ? (DAYS_IN_YEAR + 1) : DAYS_IN_YEAR)) {
        totalDays -= (isLeapYear(year) ? (DAYS_IN_YEAR + 1) : DAYS_IN_YEAR);
        year++;
    }

    // Determine month and day
    while (totalDays > 0) {
        int daysInMonth = getDaysInMonth(month, year);
        if (totalDays >= daysInMonth) {
            totalDays -= daysInMonth;
            month++;
        } else {
            day = totalDays;
            totalDays = 0;
        }
    }

    // Format the date string as DD-MM-YYYY
    sprintf(dateString, "%02d-%02d-%d", day, month, year);
}

// Main function to demonstrate the conversion system
int main() {
    char inputDate[BUFFER_SIZE];
    char outputDate[BUFFER_SIZE];
    long totalDays;

    printf("Enter a date (DD-MM-YYYY): ");
    fgets(inputDate, BUFFER_SIZE, stdin);
    inputDate[strcspn(inputDate, "\n")] = 0;  // Removing the newline character
   
    // Convert input date to days since epoch
    totalDays = convertDateToDays(inputDate);
    printf("Total days since epoch: %ld\n", totalDays);

    // Convert days back to date string
    convertDaysToDate(totalDays, outputDate);
    printf("Converted back, the date is: %s\n", outputDate);

    return 0;
}