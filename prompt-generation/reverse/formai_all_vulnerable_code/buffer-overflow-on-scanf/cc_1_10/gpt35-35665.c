//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the date information
struct Date {
    int day;
    int month;
    int year;
};

// Function to check if a year is a leap year or not
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

// Function to calculate the number of days in a month
int getDaysInMonth(int month, int year) {
    int daysInMonth;

    switch (month) {
        case 2:
            if (isLeapYear(year)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
            break;
    }

    return daysInMonth;
}

// Function to convert a date string to a Date structure
struct Date getDateFromString(char *dateString) {
    // Create a new Date structure
    struct Date date;

    // Extract the day, month, and year from the date string
    char *dayString = strtok(dateString, "/");
    char *monthString = strtok(NULL, "/");
    char *yearString = strtok(NULL, "/");
    date.day = atoi(dayString);
    date.month = atoi(monthString);
    date.year = atoi(yearString);

    return date;
}

// Function to convert a Date structure to a string
char *getStringFromDate(struct Date date) {
    // Create a new string
    char *dateString = malloc(sizeof(char) * 100);

    // Format the date string using sprintf
    sprintf(dateString, "%d/%d/%d", date.day, date.month, date.year);

    return dateString;
}

// Function to add days to a date
struct Date addDaysToDate(struct Date date, int daysToAdd) {
    // Loop through and add the days while adjusting the month and year as necessary
    while (daysToAdd > 0) {
        int daysInMonth = getDaysInMonth(date.month, date.year);
        if (date.day + daysToAdd > daysInMonth) {
            daysToAdd -= (daysInMonth - date.day + 1);
            date.day = 1;
            if (date.month == 12) {
                date.month = 1;
                date.year++;
            } else {
                date.month++;
            }
        } else {
            date.day += daysToAdd;
            daysToAdd = 0;
        }
    }

    return date;
}

// Main function
int main() {
    // Prompt the user to enter a date
    printf("Enter a date (dd/mm/yyyy format): ");
    char dateString[100];
    fgets(dateString, 100, stdin);
    dateString[strcspn(dateString, "\n")] = '\0';

    // Convert the date string to a Date structure
    struct Date date = getDateFromString(dateString);

    // Prompt the user to enter the number of days to add
    printf("Enter the number of days to add: ");
    int daysToAdd;
    scanf("%d", &daysToAdd);

    // Add the days to the date
    date = addDaysToDate(date, daysToAdd);

    // Convert the date back to a string and print it
    char *newDateString = getStringFromDate(date);
    printf("The new date is: %s\n", newDateString);

    // Free memory from the newDateString variable
    free(newDateString);

    return 0;
}