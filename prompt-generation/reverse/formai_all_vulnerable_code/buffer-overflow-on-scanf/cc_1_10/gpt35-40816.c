//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define constants
#define MIN_YEAR 1900
#define MAX_YEAR 2020
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_DAY 1

// Create time travel struct
struct TimeTravel {
    int year;
    int month;
    int day;
};

// Helper function to check if date is valid
bool isValidDate(int year, int month, int day) {
    if (year < MIN_YEAR || year > MAX_YEAR) {
        return false;
    }
    if (month < MIN_MONTH || month > MAX_MONTH) {
        return false;
    }
    if (day < MIN_DAY || day > 31) {
        return false;
    }
    return true;
}

// Helper function to get random date
struct TimeTravel getRandomDate() {
    struct TimeTravel randomDate;
    srand(time(NULL));
    randomDate.year = rand() % (MAX_YEAR - MIN_YEAR + 1) + MIN_YEAR;
    randomDate.month = rand() % (MAX_MONTH - MIN_MONTH + 1) + MIN_MONTH;
    randomDate.day = rand() % 31 + 1;
    return randomDate;
}

int main() {
    // Ask user for input
    int choice = 0;
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Would you like to:\n");
    printf("1. Travel to a specific date\n");
    printf("2. Travel to a random date\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Travel to specific date
    if (choice == 1) {
        int year, month, day;
        printf("Enter the year you would like to travel to: ");
        scanf("%d", &year);
        printf("Enter the month you would like to travel to: ");
        scanf("%d", &month);
        printf("Enter the day you would like to travel to: ");
        scanf("%d", &day);

        if (isValidDate(year, month, day)) {
            printf("You have successfully traveled to %d/%d/%d!\n", month, day, year);
        } else {
            printf("Invalid date entered. Please try again.\n");
        }

    // Travel to random date
    } else if (choice == 2) {
        struct TimeTravel randomDate = getRandomDate();
        printf("You have successfully traveled to %d/%d/%d!\n", randomDate.month, randomDate.day, randomDate.year);
    }

    return 0;
}