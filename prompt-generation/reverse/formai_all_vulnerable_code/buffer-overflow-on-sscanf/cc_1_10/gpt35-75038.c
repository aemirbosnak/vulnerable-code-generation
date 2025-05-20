//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert the given month string to its corresponding integer value
int monthToInt(char *month) {
    char *months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    int i;
    for (i = 0; i < 12; i++) {
        if (strcmp(months[i], month) == 0) {
            return i + 1;
        }
    }
    return -1;  // Return -1 if month string is invalid
}

// Function to check if the given year is a leap year or not
int isLeapYear(int year) {
    if (year % 4 != 0) {
        return 0;
    }
    else if (year % 100 != 0) {
        return 1;
    }
    else if (year % 400 != 0) {
        return 0;
    }
    else {
        return 1;
    }
}

// Function to get the number of days in a given month of a given year
int getNumDays(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    else {
        return days[month - 1];
    }
}

int main() {
    char input[50];
    printf("Enter a date in natural language format (e.g. January 1st, 2000): ");
    fgets(input, sizeof(input), stdin);  // Get user input

    char month[10];
    int day, year;
    sscanf(input, "%s %d%c %d", month, &day, &input[strlen(input) - 2], &year);  // Parse user input

    int monthNum = monthToInt(month);  // Convert month string to integer value

    if (monthNum == -1) {
        printf("Invalid month string.\n");
        return 1;
    }

    if (day < 1 || day > getNumDays(monthNum, year)) {  // Check if day value is valid
        printf("Invalid day value.\n");
        return 1;
    }

    printf("Date in standard format: %d-%02d-%02d\n", year, monthNum, day);  // Print date in standard format
    return 0;
}