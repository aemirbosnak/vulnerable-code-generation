//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the RNG with current time

    int year; // The year we'll be time-traveling to
    printf("Enter a year to travel to: ");
    scanf("%d", &year);

    // Calculate the time difference in seconds
    time_t now = time(NULL);
    time_t target = mktime(&(struct tm){0, 0, 0, 1, 0, year - 1900, 0, 0, 0});
    double diff = difftime(target, now);

    if (diff < 0) {
        printf("Error: You can't travel back in time!\n");
        return 1;
    }

    printf("Preparing to travel to year %d...\n", year);
    printf("Time difference: %g seconds\n", diff);

    while (diff >= 1) {
        // Randomly generate a message
        int r = rand() % 3;
        switch (r) {
            case 0:
                printf("Analyzing the spacetime continuum...\n");
                break;
            case 1:
                printf("Warming up the flux capacitor...\n");
                break;
            case 2:
                printf("Engaging warp engines...\n");
                break;
        }

        // Wait for a random amount of time (between 1 and 3 seconds)
        int wait_time = rand() % 3 + 1;
        sleep(wait_time);

        // Update the remaining time difference
        diff -= wait_time;

        // Output the remaining time difference
        printf("Time until arrival: %g seconds\n", diff);
    }

    printf("Arrived in year %d! Welcome to the future (or past).\n", year);

    return 0;
}