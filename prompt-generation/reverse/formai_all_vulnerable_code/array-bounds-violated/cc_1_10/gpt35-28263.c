//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check whether a given year is a leap year
int isLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    } else if (year % 100 == 0) {
        return 0;
    } else if (year % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to calculate the number of days in a given year
int daysInYear(int year) {
    if (isLeapYear(year)) {
        return 366;
    } else {
        return 365;
    }
}

// Function to calculate the number of days in a given month and year
int daysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

// Function to convert a date in the format "dd/mm/yyyy" to the format "day month year"
void convertDate(char date[]) {
    // Retrieve the day, month, and year from the input string
    char dayStr[3], monthStr[3], yearStr[5];
    strncpy(dayStr, date, 2);
    dayStr[2] = '\0';
    strncpy(monthStr, date + 3, 2);
    monthStr[2] = '\0';
    strncpy(yearStr, date + 6, 4);
    yearStr[4] = '\0';
    int day = atoi(dayStr);
    int month = atoi(monthStr);
    int year = atoi(yearStr);
    
    // Check for invalid inputs
    if (day < 1 || day > daysInMonth(month, year) || month < 1 || month > 12 || year < 1) {
        printf("Invalid date input.\n");
        return;
    }
    
    // Create arrays of month names and day suffixes
    char* monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char* daySuffixes[] = {"th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th", "th", "st"};
    
    // Calculate the day of the year
    int dayOfYear = day;
    for (int i = 1; i < month; i++) {
        dayOfYear += daysInMonth(i, year);
    }
    
    // Format and print the output string
    char output[50];
    sprintf(output, "%d%s %s %d", day, daySuffixes[day], monthNames[month - 1], year);
    printf("%s\n", output);
}

int main() {
    // Prompt the user for a date in the format "dd/mm/yyyy"
    printf("Enter a date (dd/mm/yyyy): ");
    char input[50];
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character from input string
    
    // Convert the date and print the result
    convertDate(input);
    
    return 0;
}