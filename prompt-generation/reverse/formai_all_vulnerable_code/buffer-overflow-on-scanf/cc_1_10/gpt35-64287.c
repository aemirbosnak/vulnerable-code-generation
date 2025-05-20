//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define DAYS_IN_YEAR 365
#define DAYS_IN_LYEAR 366

// Function Prototypes
int isLeapYear(int year);
int daysInMonth(int month, int year);
int daysInYearRange(int startYear, int endYear);
int daysInMonthRange(int startMonth, int startYear, int endMonth, int endYear);

// Main Function
int main() {
    // Prompt the user for input
    int startYear, startMonth, startDay, endYear, endMonth, endDay;

    printf("Enter Start Date (YYYY/MM/DD): ");
    scanf("%d/%d/%d", &startYear, &startMonth, &startDay);

    printf("Enter End Date (YYYY/MM/DD): ");
    scanf("%d/%d/%d", &endYear, &endMonth, &endDay);
    
    // Calculate the number of days in the date range
    int daysInYear = daysInYearRange(startYear, endYear);
    int daysInMonth = daysInMonthRange(startMonth, startYear, endMonth, endYear);
    int totalDays = daysInYear + daysInMonth + endDay - startDay;

    // Display the result to the user
    printf("Days between %d/%d/%d and %d/%d/%d: %d\n",
            startYear, startMonth, startDay, endYear, endMonth, endDay, totalDays);

    return 0;
}

// Function to check if a year is a leap year or not
int isLeapYear(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to calculate the number of days in a given month
int daysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        } else {
            return 28;
        }
    } else {
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        } else {
            return 31;
        }
    }
}

// Function to calculate the number of days in a given year range
int daysInYearRange(int startYear, int endYear) {
    int days = 0;
    for (int year = startYear; year <= endYear; year++) {
        if (isLeapYear(year)) {
            days += DAYS_IN_LYEAR;
        } else {
            days += DAYS_IN_YEAR;
        }
    }
    return days;
}

// Function to calculate the number of days in a given month range
int daysInMonthRange(int startMonth, int startYear, int endMonth, int endYear) {
    int days = 0;

    // Iterate through each year in the range
    for (int year = startYear; year <= endYear; year++) {

        // If the current year is the start year, start from the start month
        // Otherwise, start from January
        int monthStart = (year == startYear) ? startMonth : 1;

        // If the current year is the end year, end at the end month
        // Otherwise, end at December
        int monthEnd = (year == endYear) ? endMonth : 12;

        // Iterate through each month in the range for the current year
        for (int month = monthStart; month <= monthEnd; month++) {
            days += daysInMonth(month, year);
        }
    }

    return days;
}