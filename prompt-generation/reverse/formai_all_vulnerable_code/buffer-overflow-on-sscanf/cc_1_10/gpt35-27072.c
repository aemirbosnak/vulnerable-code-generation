//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// function to check leap year
bool isLeapYear(int year) {
    // if year is divisible by 4
    if (year % 4 == 0) {
        // if it's not divisible by 100
        if (year % 100 != 0) {
            return true;
        }
        // if it's divisible by 100 but also by 400
        else if (year % 400 == 0) {
            return true;
        }
    }
    // if none of the above conditions met, not a leap year
    return false;
}

// function to calculate days in a month
int daysInMonth(int month, int year) {
    int days;

    // check for February
    if (month == 2) {
        if (isLeapYear(year)) {
            days = 29;
        } else {
            days = 28;
        }
    } 
    // check for months with 31 days
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        days = 31;
    }
    // all other months have 30 days
    else {
        days = 30;
    }

    return days;
}

// function to convert a date to total number of days
int dateToDays(int day, int month, int year) {
    int i;
    int days = 0;

    // calculate days from previous years
    for (i = 1; i < year; i++) {
        if (isLeapYear(i)) {
            days += 366;
        } else {
            days += 365;
        }
    }

    // calculate days from previous months
    for (i = 1; i < month; i++) {
        days += daysInMonth(i, year);
    }

    // add days for current month
    days += day;

    return days;
}

// function to convert total number of days to a date
void daysToDate(int days, int *day, int *month, int *year) {
    int i;

    // calculate year
    for (i = 1; days > 365; i++) {
        if (isLeapYear(i)) {
            days -= 366;
        } else {
            days -= 365;
        }
    }
    *year = i;

    // calculate month
    for (i = 1; days > daysInMonth(i, *year); i++) {
        days -= daysInMonth(i, *year);
    }
    *month = i;

    // calculate day
    *day = days;
}

// main function to run the program
int main() {
    int day, month, year;
    char input[20], monthName[20];
    bool validInput = false;

    // prompt user to enter date in natural language
    printf("Enter date in natural language (e.g. January 1st 2001):\n");
    fgets(input, 20, stdin);

    // check for valid input
    if (sscanf(input, "%s %d %d", monthName, &day, &year) == 3) {
        // convert month name to number
        if (strcmp(monthName, "January") == 0) {
            month = 1;
        } else if (strcmp(monthName, "February") == 0) {
            month = 2;
        } else if (strcmp(monthName, "March") == 0) {
            month = 3;
        } else if (strcmp(monthName, "April") == 0) {
            month = 4;
        } else if (strcmp(monthName, "May") == 0) {
            month = 5;
        } else if (strcmp(monthName, "June") == 0) {
            month = 6;
        } else if (strcmp(monthName, "July") == 0) {
            month = 7;
        } else if (strcmp(monthName, "August") == 0) {
            month = 8;
        } else if (strcmp(monthName, "September") == 0) {
            month = 9;
        } else if (strcmp(monthName, "October") == 0) {
            month = 10;
        } else if (strcmp(monthName, "November") == 0) {
            month = 11;
        } else if (strcmp(monthName, "December") == 0) {
            month = 12;
        } else {
            printf("Invalid input. Please enter date in the format: Month day year\n");
            return 1;
        }

        // check for valid day and year
        if (day < 1 || day > daysInMonth(month, year) || year < 1) {
            printf("Invalid input. Please enter a valid date.\n");
        } else {
            validInput = true;
        }
    } else {
        printf("Invalid input. Please enter date in the format: Month day year\n");
        return 1;
    }

    // convert date to total number of days and print
    if (validInput) {
        int totalDays = dateToDays(day, month, year);
        printf("Total number of days from 1st January 1 AD: %d\n", totalDays);

        // convert total number of days back to a date and print
        int newDay, newMonth, newYear;
        daysToDate(totalDays, &newDay, &newMonth, &newYear);
        printf("The date is: %d %s %d\n", newDay, monthName, newYear);
    }

    return 0;
}