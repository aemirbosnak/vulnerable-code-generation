//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a given year is a leap year
int isLeapYear(int year) {
    if (year % 4 != 0) {
        return 0;
    } else if (year % 100 != 0) {
        return 1;
    } else if (year % 400 != 0) {
        return 0;
    } else {
        return 1;
    }
}

// Function to get the number of days in a given month
int getDaysInMonth(int month, int year) {
    int daysInMonth;
    switch (month) {
        case 2:
            daysInMonth = isLeapYear(year) ? 29 : 28;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
            break;
    }
    return daysInMonth;
}

// Function to validate a date string entered by the user
int validateDate(char *dateStr) {
    int maxDaysInMonth, day, month, year;

    // Check that the string has the correct length
    if (strlen(dateStr) != 10) {
        return 0;
    }

    // Check that the separators are correct
    if (!((dateStr[2] == '-' && dateStr[5] == '-') || (dateStr[2] == '/' && dateStr[5] == '/'))) {
        return 0;
    }

    // Extract the day, month, and year from the string
    if (sscanf(dateStr, "%d-%d-%d", &day, &month, &year) != 3 &&
        sscanf(dateStr, "%d/%d/%d", &day, &month, &year) != 3) {
        return 0;
    }

    // Check that the year is within a valid range
    if (year < 1900 || year > 9999) {
        return 0;
    }

    // Check that the month is within a valid range
    if (month < 1 || month > 12) {
        return 0;
    }

    // Check that the day is within a valid range for the given month and year
    maxDaysInMonth = getDaysInMonth(month, year);
    if (day < 1 || day > maxDaysInMonth) {
        return 0;
    }

    return 1;
}

// Function to convert a date string to the number of days since 1900-01-01
int dateToDays(char *dateStr) {
    int daysInMonth, day, month, year, days = 0;
    int daysInYear[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    // Extract the day, month, and year from the string
    sscanf(dateStr, "%d-%d-%d", &day, &month, &year);

    // Calculate the number of days from year 1900 to the given year
    for (int y = 1900; y < year; y++) {
        days += isLeapYear(y) ? 366 : 365;
    }

    // Calculate the number of days from January 1st to the start of the given month
    days += daysInYear[month - 1];

    // Add an extra day if it's a leap year and the given month is after February
    if (month > 2 && isLeapYear(year)) {
        days++;
    }

    // Add the number of days in the given month
    days += day - 1;

    return days;
}

// Function to convert the number of days since 1900-01-01 to a date string
char* daysToDate(int days) {
    int daysLeft = days;
    int year = 1900;

    // Calculate the year
    while (daysLeft >= isLeapYear(year) ? 366 : 365) {
        daysLeft -= isLeapYear(year) ? 366 : 365;
        year++;
    }

    // Calculate the month and day
    int month = 1;
    int daysInMonth;
    while (daysLeft >= (daysInMonth = getDaysInMonth(month, year))) {
        daysLeft -= daysInMonth;
        month++;
    }
    int day = daysLeft + 1;

    // Create the date string
    char *dateStr = malloc(11 * sizeof(char));
    sprintf(dateStr, "%04d-%02d-%02d", year, month, day);
    return dateStr;
}

int main() {
    char dateStr[11];

    // Ask the user to enter a date string
    printf("Enter a date in the format YYYY-MM-DD or YYYY/MM/DD: ");
    scanf("%10s", dateStr);

    // Validate the date string
    if (!validateDate(dateStr)) {
        printf("Invalid date!\n");
        return 1;
    }

    // Convert the date string to the number of days since 1900-01-01
    int days = dateToDays(dateStr);

    // Print the number of days since 1900-01-01
    printf("The number of days since 1900-01-01 is: %d\n", days);

    // Convert the number of days since 1900-01-01 to another date string and print it
    printf("The date %d days after 1900-01-01 is: %s\n", days, daysToDate(days));

    return 0;
}