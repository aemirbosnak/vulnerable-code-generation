//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Define constants for time travel simulation
#define START_YEAR 2019
#define END_YEAR 2077
#define TRAVEL_SPEED 3 // Years per minute

// Define function to calculate the current year based on minutes passed
int calculateYear(int minutes) {
    return ((minutes * TRAVEL_SPEED) / 60) + START_YEAR;
}

int main() {
    // Declare variables for time travel simulation
    int currentYear = START_YEAR;
    int minutesPassed = 0;
    bool isTravelling = false;

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Time Travel Simulator!\n");
    printf("This simulator allows you to travel through time from %d to %d.\n\n", START_YEAR, END_YEAR);

    // Main program loop
    while (currentYear < END_YEAR) {
        // Check if the user wants to travel in time
        if (!isTravelling) {
            printf("Current year: %d.\n", currentYear);
            printf("Would you like to travel in time? (y/n)\n");
            
            // Get user input
            char input;
            scanf("%c", &input);
            
            // Check if the user wants to travel in time
            if (input == 'y') {
                printf("How many minutes would you like to travel?\n");

                // Get user input
                int travelTime;
                scanf("%d", &travelTime);

                isTravelling = true;
                minutesPassed = travelTime;
            } else {
                // Update the current year based on time passed
                currentYear = calculateYear(minutesPassed);
                minutesPassed = 0;
            }
        } else {
            // Simulate time travel
            printf("Travelling in time...\n");
            int travelTime = rand() % 100;
            minutesPassed += travelTime;
            printf("You travelled %d minutes.\n", travelTime);

            // Update the current year based on time passed
            currentYear = calculateYear(minutesPassed);

            // Check if the user has arrived at the destination year
            if (currentYear >= END_YEAR) {
                printf("You have arrived in year %d.\n", currentYear);
                isTravelling = false;
            }
        }
    }

    // End of program
    printf("Thank you for using the Time Travel Simulator!\n");

    return 0;
}