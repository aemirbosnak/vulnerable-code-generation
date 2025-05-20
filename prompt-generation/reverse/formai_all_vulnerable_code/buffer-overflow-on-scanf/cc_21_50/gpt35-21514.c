//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include <stdio.h>

// Function to calculate if year is a leap year or not
int isLeapYear(int year) {
    int leap = 0;
    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0) {
            leap = 1;
        }
    }
    return leap;
}

int main() {
    int date, month, year, days;
    char month_str[10];

    // Prompt user to enter the date in natural language
    printf("Enter date in natural language (e.g. December 31, 2021): ");
    scanf("%s %d, %d", month_str, &date, &year);

    // Convert month string to integer
    if (strcmp(month_str, "January") == 0) {
        month = 1;
    } else if (strcmp(month_str, "February") == 0) {
        month = 2;
    } else if (strcmp(month_str, "March") == 0) {
        month = 3;
    } else if (strcmp(month_str, "April") == 0) {
        month = 4;
    } else if (strcmp(month_str, "May") == 0) {
        month = 5;
    } else if (strcmp(month_str, "June") == 0) {
        month = 6;
    } else if (strcmp(month_str, "July") == 0) {
        month = 7;
    } else if (strcmp(month_str, "August") == 0) {
        month = 8;
    } else if (strcmp(month_str, "September") == 0) {
        month = 9;
    } else if (strcmp(month_str, "October") == 0) {
        month = 10;
    } else if (strcmp(month_str, "November") == 0) {
        month = 11;
    } else if (strcmp(month_str, "December") == 0) {
        month = 12;
    } else {
        printf("Invalid month entered!\n");
        return 1;
    }

    // Check if the date entered is valid
    if (date < 1 || date > 31) {
        printf("Invalid date entered!\n");
        return 1;
    }

    // Check if the year entered is valid
    if (year < 1 || year > 9999) {
        printf("Invalid year entered!\n");
        return 1;
    }

    // Check if February has 29 days for a leap year
    if (month == 2 && isLeapYear(year) == 1 && date > 29) {
        printf("Invalid date entered! February of this year has maximum 29 days\n");
        return 1;
    }

    // Check if February has 28 days for a non-leap year
    if (month == 2 && isLeapYear(year) == 0 && date > 28) {
        printf("Invalid date entered! February of this year has maximum 28 days\n");
        return 1;
    }

    // Check if all other months have maximum 31 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && date > 30) {
        printf("Invalid date entered! Maximum %d days for this month\n", 30);
        return 1;
    }

    // Calculate number of days since Jan 1, 1 AD till input date
    days = date; // Add days of the month
    switch (month-1) {
        case 11: days += 30; // Nov
        case 10: days += 31; // Oct
        case 9: days += 30; // Sep
        case 8: days += 31; // Aug
        case 7: days += 31; // Jul
        case 6: days += 30; // Jun
        case 5: days += 31; // May
        case 4: days += 30; // Apr
        case 3: days += 31; // Mar
        case 2: days += isLeapYear(year) == 1 ? 29 : 28; // Feb
        case 1: days += 31; // Jan
    }

    // Print output in natural language
    printf("The date %s %d, %d is %d day(s) after January 1, 1 AD\n", month_str, date, year, days);

    return 0;
}