//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1; // Leap year
            }
            return 0; // Not a leap year
        }
        return 1; // Leap year
    }
    return 0; // Not a leap year
}

// Function to convert Gregorian date to Julian date
void gregorianToJulian(int day, int month, int year, int *jDay, int *jMonth, int *jYear) {
    *jYear = year;
    *jMonth = month;
    *jDay = day;

    // Adjust for the Gregorian to Julian conversion
    if (year > 1582 || (year == 1582 && (month > 10 || (month == 10 && day > 15)))) {
        *jDay += 10; // Julian shift for days
    }

    // Handle month adjustments for Julian calendar
    if (*jMonth > 2) {
        (*jMonth)--;
    } else {
        (*jMonth) += 10; // Adjust month for Julian calendar
        (*jYear)--;
    }
}

// Function to convert Julian date to Gregorian date
void julianToGregorian(int jDay, int jMonth, int jYear, int *gDay, int *gMonth, int *gYear) {
    *gYear = jYear;
    *gMonth = jMonth;
    *gDay = jDay;

    // Adjust for Julian to Gregorian conversion
    if (jYear > 1582 || (jYear == 1582 && (jMonth > 10 || (jMonth == 10 && jDay > 15)))) {
        *gDay -= 10; // Revert Julian shift for days
    }

    // Handle month adjustments for Gregorian calendar
    if (*gMonth < 3) {
        (*gMonth) += 12; // Adjust month for Gregorian calendar
        (*gYear)--;
    }
}

// Function to display the menu and get user input
void displayMenu() {
    printf("Welcome to the Date Converter!\n");
    printf("1. Convert Gregorian Date to Julian Date\n");
    printf("2. Convert Julian Date to Gregorian Date\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    int option;
    int day, month, year;
    int convertedDay, convertedMonth, convertedYear;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        if (option == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        switch (option) {
            case 1:
                printf("Enter Gregorian Date (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                gregorianToJulian(day, month, year, &convertedDay, &convertedMonth, &convertedYear);
                printf("Julian Date: %d %d %d\n", convertedDay, convertedMonth, convertedYear);
                break;

            case 2:
                printf("Enter Julian Date (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                julianToGregorian(day, month, year, &convertedDay, &convertedMonth, &convertedYear);
                printf("Gregorian Date: %d %d %d\n", convertedDay, convertedMonth, convertedYear);
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}