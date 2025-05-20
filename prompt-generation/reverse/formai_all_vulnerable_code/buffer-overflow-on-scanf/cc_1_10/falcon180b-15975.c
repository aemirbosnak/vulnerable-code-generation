//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL_YEAR 2050
#define MIN_TIME_TRAVEL_YEAR 2010

// Function to check if a given year is valid for time travel
int isValidTimeTravelYear(int year) {
    if (year < MIN_TIME_TRAVEL_YEAR || year > MAX_TIME_TRAVEL_YEAR) {
        printf("Invalid time travel year.\n");
        return 0;
    }
    return 1;
}

// Function to simulate time travel
void timeTravel(int year) {
    printf("Time traveling to %d...\n", year);
    sleep(1);
    printf("Arrived in %d.\n", year);
    sleep(1);
}

// Main function
int main() {
    int year;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Loop until the user decides to quit
    while (1) {
        // Prompt the user for a year to travel to
        printf("Enter a year to time travel to (between %d and %d): ", MIN_TIME_TRAVEL_YEAR, MAX_TIME_TRAVEL_YEAR);
        scanf("%d", &year);

        // Check if the year is valid for time travel
        if (isValidTimeTravelYear(year)) {
            // Simulate time travel
            timeTravel(year);
        } else {
            // Invalid year, try again
            printf("\n");
        }

        // Check if the user wants to quit
        printf("Press enter to time travel again or type 'quit' to exit.\n");
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
    }

    return 0;
}