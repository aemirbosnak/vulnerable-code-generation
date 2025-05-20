//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: cheerful
#include<stdio.h>
#include<string.h>

// Function to check if given year is a leap year or not
int isLeapYear(int year) {
    if(year % 100 == 0) {
        if(year % 400 == 0) {
            return 1;
        }
    } else if(year % 4 == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int day, year, month;
    char monthName[20];

    // Taking user inputs
    printf("Enter date in Natural Language (example: 11th October 2022): ");
    scanf("%d%s%d", &day, monthName, &year);

    // Converting month name to month number
    if(strcmp(monthName, "January") == 0) {
        month = 1;
    } else if(strcmp(monthName, "February") == 0) {
        month = 2;
    } else if(strcmp(monthName, "March") == 0) {
        month = 3;
    } else if(strcmp(monthName, "April") == 0) {
        month = 4;
    } else if(strcmp(monthName, "May") == 0) {
        month = 5;
    } else if(strcmp(monthName, "June") == 0) {
        month = 6;
    } else if(strcmp(monthName, "July") == 0) {
        month = 7;
    } else if(strcmp(monthName, "August") == 0) {
        month = 8;
    } else if(strcmp(monthName, "September") == 0) {
        month = 9;
    } else if(strcmp(monthName, "October") == 0) {
        month = 10;
    } else if(strcmp(monthName, "November") == 0) {
        month = 11;
    } else if(strcmp(monthName, "December") == 0) {
        month = 12;
    }

    // Checking if the date is valid
    int daysInMonth;
    if(month == 2) {
        if(isLeapYear(year)) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else if(month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    if(day > daysInMonth) {
        printf("Invalid date\n");
        return 1;
    }

    // Outputting the date in numerical format
    printf("The date in numerical format is: %d/%d/%d\n", day, month, year);

    return 0;
}