//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define months and their corresponding number of days
const char* MONTHS[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const int DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Function to check if a given year is a leap year
bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

// Function to convert a given date into days
int convertToDate(int day, int month, int year) {
    int leapYears = (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    int daysInYears = (year - 1) * 365 + leapYears;
    int daysInMonths = 0;
    for (int i = 0; i < month - 1; i++) {
        daysInMonths += DAYS_IN_MONTH[i];
        if (i == 1 && isLeapYear(year)) {
            daysInMonths++;
        }
    }
    return daysInYears + daysInMonths + day;
}

// Function to convert a given number of days into a date
void convertToDayMonthYear(int days, int* dayPtr, int* monthPtr, int* yearPtr) {
    int leapYears = days / 1461;
    int daysInYears = (days % 1461) * 4 + 1;
    int daysInMonths = 0;
    int month = 0;
    int daysInMonth = 0;
    bool foundMonth = false;
    for (int i = 0; i < 12; i++) {
        int daysInMonth = DAYS_IN_MONTH[i];
        if (i == 1 && isLeapYear(leapYears * 4 + 1)) {
            daysInMonth++;
        }
        if (daysInYears + daysInMonths + daysInMonth <= days) {
            daysInMonths += daysInMonth;
            month++;
        } else {
            foundMonth = true;
            break;
        }
    }
    if (!foundMonth) {
        printf("Invalid number of days!\n");
        exit(1);
    }
    int day = days - (daysInYears + daysInMonths - daysInMonth);
    *dayPtr = day + 1;
    *monthPtr = month + 1;
    *yearPtr = leapYears * 4 + 1;
}

int main() {
    char dateStr[11];
    printf("Enter date in the format DD/MM/YYYY: ");
    scanf("%s", dateStr);

    // Split date into day, month, and year
    char* dayStr = strtok(dateStr, "/");
    char* monthStr = strtok(NULL, "/");
    char* yearStr = strtok(NULL, "/");
    int day = atoi(dayStr);
    int month = atoi(monthStr);
    int year = atoi(yearStr);

    // Convert date to number of days
    int days = convertToDate(day, month, year);
    printf("Days since January 1st, 0001: %d\n", days);

    // Convert number of days to date
    int newDay, newMonth, newYear;
    convertToDayMonthYear(days, &newDay, &newMonth, &newYear);
    printf("Date: %d %s %d\n", newDay, MONTHS[newMonth - 1], newYear);

    return 0;
}