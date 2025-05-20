//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to check if a year is a leap year
bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

// Function to increment a date by 1 day
void incrementDate(int* day, int* month, int* year) {
    int daysInMonth;

    if (*month == 2) {
        if (isLeapYear(*year)) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else if (*month == 4 || *month == 6 || *month == 9 || *month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    if (*day < daysInMonth) {
        (*day)++;
    } else {
        *day = 1;
        if (*month < 12) {
            (*month)++;
        } else {
            *month = 1;
            (*year)++;
        }
    }
}

int main() {
    time_t t = time(NULL);
    struct tm now = *localtime(&t);

    int currentDay = now.tm_mday;
    int currentMonth = now.tm_mon + 1;
    int currentYear = now.tm_year + 1900;

    int targetDay;
    int targetMonth;
    int targetYear;

    // Get target date from user
    printf("Enter target date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &targetDay, &targetMonth, &targetYear);

    // Check if target date is in the future
    if (targetYear < currentYear || (targetYear == currentYear && targetMonth < currentMonth ) || (targetYear == currentYear && targetMonth == currentMonth && targetDay <= currentDay)) {
        printf("Cannot travel back in time. Enter a valid future date.\n");
        return 0;
    }

    // Increment current date until it reaches the target date
    printf("\nTraveling through time...\n\n");
    while (currentDay != targetDay || currentMonth != targetMonth || currentYear != targetYear) {
        printf("%02d/%02d/%d\n", currentDay, currentMonth, currentYear);
        incrementDate(&currentDay, &currentMonth, &currentYear);
    }

    printf("%02d/%02d/%d (arrived at target date)\n", currentDay, currentMonth, currentYear);
    return 0;
}