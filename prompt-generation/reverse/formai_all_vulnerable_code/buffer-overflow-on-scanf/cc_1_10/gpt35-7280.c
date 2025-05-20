//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// define the boundaries of time-travel
#define MIN_YEAR 1000
#define MAX_YEAR 3000

// function to check if a year is leap year
bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

// function to generate a random year within the boundaries
int generateRandomYear() {
    int yearRange = MAX_YEAR - MIN_YEAR;
    int randomYear = rand() % yearRange + MIN_YEAR;
    return randomYear;
}

// function to travel to a specific year
void travelToYear(int year) {
    printf("You have time-traveled to the year %d.\n", year);
    if (isLeapYear(year)) {
        printf("This is a leap year.\n");
    } else {
        printf("This is not a leap year.\n");
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator with current time

    printf("Welcome to the time travel simulator!\n");
    printf("Enter 'y' to travel to a random year or 'n' to exit.\n");

    char input;
    scanf("%c", &input);

    while (input == 'y') {
        int randomYear = generateRandomYear();
        travelToYear(randomYear);

        printf("Enter 'y' to travel to another year or 'n' to exit.\n");
        scanf(" %c", &input);
    }

    printf("Thank you for using the time travel simulator!\n");

    return 0;
}