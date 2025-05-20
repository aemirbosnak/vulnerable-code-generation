//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: single-threaded
#include <stdio.h>
#include <string.h>

// Function to check if the year is leap year or not
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to get the number of days in a given month and year
int getDaysInMonth(int month, int year) {
    int numDays = 31;
    if (month == 2) {
        if (isLeapYear(year)) {
            numDays = 29;
        } else {
            numDays = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        numDays = 30;
    }
    return numDays;
}

// Function to convert a natural language date string to a numeric date string
void convertDate(char *dateString) {
    int month, day, year;
    char monthString[15], dayString[3], yearString[5];
    sscanf(dateString, "%s %s, %s", monthString, dayString, yearString);
    
    // Convert month string to number
    if (strcmp(monthString, "January") == 0) {
        month = 1;
    } else if (strcmp(monthString, "February") == 0) {
        month = 2;
    } else if (strcmp(monthString, "March") == 0) {
        month = 3;
    } else if (strcmp(monthString, "April") == 0) {
        month = 4;
    } else if (strcmp(monthString, "May") == 0) {
        month = 5;
    } else if (strcmp(monthString, "June") == 0) {
        month = 6;
    } else if (strcmp(monthString, "July") == 0) {
        month = 7;
    } else if (strcmp(monthString, "August") == 0) {
        month = 8;
    } else if (strcmp(monthString, "September") == 0) {
        month = 9;
    } else if (strcmp(monthString, "October") == 0) {
        month = 10;
    } else if (strcmp(monthString, "November") == 0) {
        month = 11;
    } else {
        month = 12;
    }
    
    // Convert day string to number
    day = atoi(dayString);
    
    // Convert year string to number
    year = atoi(yearString);
    
    // Check validity of date
    int numDaysInMonth = getDaysInMonth(month, year);
    if (day > numDaysInMonth) {
        printf("Invalid date: There are only %d days in %s %d\n", numDaysInMonth, monthString, year);
    } else if (year < 1900 || year > 2100) {
        printf("Invalid date: Year must be between 1900 and 2100\n");
    } else {
        printf("%02d/%02d/%d\n", month, day, year);
    }
}

// Main function to run the program
int main() {
    char dateString[20];
    printf("Enter a natural language date (e.g. January 2, 2022): ");
    fgets(dateString, 20, stdin);
    dateString[strcspn(dateString, "\n")] = '\0'; // Remove newline character
    
    convertDate(dateString);
    
    return 0;
}