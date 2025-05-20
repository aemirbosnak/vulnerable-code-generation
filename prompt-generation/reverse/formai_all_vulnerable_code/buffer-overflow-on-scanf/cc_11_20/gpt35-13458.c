//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define JANUARY 31
#define FEBRUARY 28
#define MARCH 31
#define APRIL 30
#define MAY 31
#define JUNE 30
#define JULY 31
#define AUGUST 31
#define SEPTEMBER 30
#define OCTOBER 31
#define NOVEMBER 30
#define DECEMBER 31

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    int days;
    switch(month) {
        case 1:
            days = JANUARY;
            break;
        case 2:
            if(isLeapYear(year)) {
                days = FEBRUARY + 1;
            } else {
                days = FEBRUARY;
            }
            break;
        case 3:
            days = MARCH;
            break;
        case 4:
            days = APRIL;
            break;
        case 5:
            days = MAY;
            break;
        case 6:
            days = JUNE;
            break;
        case 7:
            days = JULY;
            break;
        case 8:
            days = AUGUST;
            break;
        case 9:
            days = SEPTEMBER;
            break;
        case 10:
            days = OCTOBER;
            break;
        case 11:
            days = NOVEMBER;
            break;
        case 12:
            days = DECEMBER;
            break;
        default:
            days = -1;
            break;
    }
    return days;
}

int main() {

    int day, month, year;

    // Welcome messages for players
    printf("Welcome to the Date Converter Game!\n");
    printf("This is a multiplayer game where two players convert each other's dates.\n");

    // Player 1 enters their date
    printf("Player 1, please enter your date in the format: DD/MM/YYYY: ");
    scanf("%d/%d/%d", &day, &month, &year);

    // Check for valid input
    if(month < 1 || month > 12) {
        printf("Invalid Input! Please enter a month between 1-12.\n");
        return -1;
    } else if(day < 1 || day > getDaysInMonth(month, year)) {
        printf("Invalid Input! Please enter a valid day for the given month and year.\n");
        return -1;
    }

    // Player 1's date is displayed
    printf("Player 1's Date: %d/%d/%d\n", day, month, year);

    // Player 2 enters their date
    printf("Player 2, please enter your date in the format: DD/MM/YYYY: ");
    scanf("%d/%d/%d", &day, &month, &year);

    // Check for valid input
    if(month < 1 || month > 12) {
        printf("Invalid Input! Please enter a month between 1-12.\n");
        return -1;
    } else if(day < 1 || day > getDaysInMonth(month, year)) {
        printf("Invalid Input! Please enter a valid day for the given month and year.\n");
        return -1;
    }

    // Player 2's date is displayed
    printf("Player 2's Date: %d/%d/%d\n", day, month, year);

    // Players convert each other's dates
    printf("Now, Player 1 will convert Player 2's date to American format and vice versa.\n");

    // Player 1 converts Player 2's date to American format
    printf("Player 1, please enter the month for Player 2's date in English: ");
    char monthName[20];
    scanf("%s", monthName);

    // Convert month name to month number
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
    } else {
        printf("Invalid month name!");
        return -1;
    }

    // Check for valid input
    if(month < 1 || month > 12) {
        printf("Invalid Input! Please enter a month between 1-12.\n");
        return -1;
    } else if(day < 1 || day > getDaysInMonth(month, year)) {
        printf("Invalid Input! Please enter a valid day for the given month and year.\n");
        return -1;
    }

    // Player 2's date in American format
    printf("Player 2's Date in American format: %s %d, %d\n", monthName, day, year);

    // Player 2 converts Player 1's date to European format
    printf("Player 2, please enter the month for Player 1's date in English: ");
    scanf("%s", monthName);

    // Convert month name to month number
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
    } else {
        printf("Invalid month name!");
        return -1;
    }

    // Check for valid input
    if(month < 1 || month > 12) {
        printf("Invalid Input! Please enter a month between 1-12.\n");
        return -1;
    } else if(day < 1 || day > getDaysInMonth(month, year)) {
        printf("Invalid Input! Please enter a valid day for the given month and year.\n");
        return -1;
    }

    // Player 1's date in European format
    printf("Player 1's Date in European format: %d %s %d\n", day, monthName, year);

    return 0;
}