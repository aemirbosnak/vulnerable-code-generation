//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to Time Travel Simulator!\n\n");
    printf("Choose a year to travel to (between 1800 and 2100): ");
    int year;
    scanf("%d", &year);

    if (year < 1800 || year > 2100) {
        printf("\nInvalid year. Please choose a year between 1800 and 2100.\n");
        return 0;
    }

    printf("\nTraveling to year %d...\n\n", year);
    printf("Initializing time circuits...\n");
    printf("Flux capacitor online...\n");
    printf("Time circuits ON...\n");

    srand(time(NULL)); // seed the random number generator with the current time

    int currentYear = 2021;
    int timeTravelDuration = year - currentYear;

    printf("Time travel duration: %d year(s).\n\n", timeTravelDuration);

    if (timeTravelDuration < 0) {
        printf("Sorry, time travel to the past is not yet possible. Please choose a future year.\n");
        return 0;
    }

    printf("Preparing for time jump...\n\n");

    for (int i = 5; i > 0; i--) {
        printf("%d...\n", i);
        sleep(1); // pause for 1 second
    }

    printf("\nTime jump successful!\n\n");

    int randomNumber = rand() % 100 + 1; // generate a random number between 1 and 100

    if (randomNumber <= 25) {
        printf("Warning: temporal anomaly detected!\n");
        printf("Please wait while we stabilize the timeline...\n\n");
        sleep(3); // pause for 3 seconds

        printf("Timeline stabilized. Everything appears to be back to normal.\n\n");
    }

    printf("Welcome to year %d!\n\n", year);

    if (year > 2021) {
        printf("Wow, you made it to the future! Here are some predictions for the year %d:\n\n", year);

        printf("1. Flying cars will be a common sight.\n");
        printf("2. Everyone will have a robot assistant.\n");
        printf("3. Virtual reality will be as common as smartphones.\n");
    } else {
        printf("Looks like you traveled back in time. Here are some historical events that will happen soon:\n\n");

        if (year >= 1861 && year <= 1865) {
            printf("1. The American Civil War is raging.\n");
        }

        if (year >= 1914 && year <= 1918) {
            printf("2. World War I is being fought.\n");
        }

        if (year >= 1939 && year <= 1945) {
            printf("3. World War II is being fought.\n");
        }
    }

    printf("\nThanks for using Time Travel Simulator!\n");

    return 0;
}