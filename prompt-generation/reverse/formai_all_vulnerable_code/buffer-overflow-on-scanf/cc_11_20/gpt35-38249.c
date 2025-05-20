//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: random
#include <stdio.h>
#include <string.h>

// Function to check if the given year is a leap year or not
int isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to convert month name to month number
int getMonthNumber(char *month) {
    if (strcmp(month, "January") == 0 || strcmp(month, "january") == 0) {
        return 1;
    } else if (strcmp(month, "February") == 0 || strcmp(month, "february") == 0) {
        return 2;
    } else if (strcmp(month, "March") == 0 || strcmp(month, "march") == 0) {
        return 3;
    } else if (strcmp(month, "April") == 0 || strcmp(month, "april") == 0) {
        return 4;
    } else if (strcmp(month, "May") == 0 || strcmp(month, "may") == 0) {
        return 5;
    } else if (strcmp(month, "June") == 0 || strcmp(month, "june") == 0) {
        return 6;
    } else if (strcmp(month, "July") == 0 || strcmp(month, "july") == 0) {
        return 7;
    } else if (strcmp(month, "August") == 0 || strcmp(month, "august") == 0) {
        return 8;
    } else if (strcmp(month, "September") == 0 || strcmp(month, "september") == 0) {
        return 9;
    } else if (strcmp(month, "October") == 0 || strcmp(month, "october") == 0) {
        return 10;
    } else if (strcmp(month, "November") == 0 || strcmp(month, "november") == 0) {
        return 11;
    } else if (strcmp(month, "December") == 0 || strcmp(month, "december") == 0) {
        return 12;
    } else {
        return -1;
    }
}

// Main function
int main() {
    int day, year;
    char month[10];

    // Get date from user
    printf("Enter date in natural language (Format: Month Day Year): ");
    scanf("%s %d %d", month, &day, &year);

    // Convert month name to month number
    int monthNumber = getMonthNumber(month);

    // Validate date
    if (monthNumber == -1 || day < 1 || day > 31 || year < 1) {
        printf("Invalid Date!");
    } else if ((monthNumber == 4 || monthNumber == 6 || monthNumber == 9 || monthNumber == 11) && day > 30) {
        printf("Invalid Date!");
    } else if (monthNumber == 2 && day > 29) {
        printf("Invalid Date!");
    } else if (monthNumber == 2 && day == 29 && !isLeapYear(year)) {
        printf("Invalid Date!");
    } else {
        // Determine the number of days elapsed since 1st January
        int daysElapsed = 0;
        for (int i = 1; i < monthNumber; i++) {
            if (i == 2) {
                if (isLeapYear(year)) {
                    daysElapsed += 29;
                } else {
                    daysElapsed += 28;
                }
            } else if (i == 4 || i == 6 || i == 9 || i == 11) {
                daysElapsed += 30;
            } else {
                daysElapsed += 31;
            }
        }
        daysElapsed += day - 1;

        // Determine the day of the week
        int dayOfWeek = (daysElapsed + 5) % 7;

        // Print the date in ISO format
        printf("ISO Date: %04d-%02d-%02d\n", year, monthNumber, day);

        // Print the day of the week
        switch (dayOfWeek) {
            case 0:
                printf("Day of the Week: Saturday\n");
                break;
            case 1:
                printf("Day of the Week: Sunday\n");
                break;
            case 2:
                printf("Day of the Week: Monday\n");
                break;
            case 3:
                printf("Day of the Week: Tuesday\n");
                break;
            case 4:
                printf("Day of the Week: Wednesday\n");
                break;
            case 5:
                printf("Day of the Week: Thursday\n");
                break;
            case 6:
                printf("Day of the Week: Friday\n");
                break;
        }
    }

    return 0;
}