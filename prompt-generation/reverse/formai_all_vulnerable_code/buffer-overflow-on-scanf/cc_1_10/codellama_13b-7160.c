//Code Llama-13B DATASET v1.0 Category: Time Travel Simulator ; Style: multivariable
/*
 * Time Travel Simulator
 *
 * This program simulates time travel by allowing the user to travel through time
 * and experience different eras.
 *
 * Usage:
 * 1. Enter the year you want to travel to:
 * 2. Press the "Enter" key to start the time machine.
 * 3. The time machine will take you to the selected year.
 * 4. You can use the "back" button to go back to the current year.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
int currentYear;
int selectedYear;

// Function declarations
void printMenu();
void travelToSelectedYear();
void travelBackToCurrentYear();

int main() {
    // Get the current year
    time_t now = time(NULL);
    struct tm *localTime = localtime(&now);
    currentYear = localTime->tm_year + 1900;

    // Print the menu
    printMenu();

    // Get the selected year
    printf("Enter the year you want to travel to: ");
    scanf("%d", &selectedYear);

    // Travel to the selected year
    travelToSelectedYear();

    // Travel back to the current year
    travelBackToCurrentYear();

    return 0;
}

void printMenu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("You are currently in the year %d.\n", currentYear);
    printf("Please select a year to travel to: ");
    printf("1. The year 2000\n");
    printf("2. The year 1990\n");
    printf("3. The year 1980\n");
    printf("4. The year 1970\n");
    printf("5. The year 1960\n");
    printf("6. The year 1950\n");
    printf("7. The year 1940\n");
    printf("8. The year 1930\n");
    printf("9. The year 1920\n");
    printf("10. The year 1910\n");
}

void travelToSelectedYear() {
    // Set the selected year as the current year
    currentYear = selectedYear;

    // Print the current year
    printf("You are now in the year %d.\n", currentYear);
}

void travelBackToCurrentYear() {
    // Set the current year as the selected year
    selectedYear = currentYear;

    // Print the current year
    printf("You are now in the year %d.\n", currentYear);
}