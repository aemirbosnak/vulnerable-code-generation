//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define MAX_TIME 1000000000 // 1 billion seconds
#define MAX_TIME_TRAVEL 10000000 // 10 million seconds
#define MAX_TIME_DELTA 10000000 // 10 million seconds
#define SPEED_OF_LIGHT 299792458 // m/s

// Time travel function
void time_travel(int* time, int destination) {
    printf("Entering the time machine...\n");
    printf("Setting destination to %d seconds...\n", destination);
    printf("Warping through space-time continuum...\n");
    printf("Arriving at destination...\n");
    *time = destination;
}

// Check if time travel is possible
bool can_travel(int current_time, int destination) {
    if (destination > current_time + MAX_TIME_TRAVEL) {
        printf("Sorry, you cannot travel more than %d seconds into the future!\n", MAX_TIME_TRAVEL);
        return false;
    }
    if (destination < current_time - MAX_TIME_TRAVEL) {
        printf("Sorry, you cannot travel more than %d seconds into the past!\n", MAX_TIME_TRAVEL);
        return false;
    }
    return true;
}

// Main function
int main() {
    int current_time = 0;
    int destination;
    int speed;
    int distance;
    int time_taken;

    // Initialize random seed
    srand(time(0));

    // Start at random time
    current_time = rand() % MAX_TIME;
    printf("You wake up in the year %d...\n", current_time);

    // Main loop
    while (true) {
        // Ask user for destination
        printf("Where do you want to go? (in seconds)\n");
        scanf("%d", &destination);

        // Check if time travel is possible
        if (!can_travel(current_time, destination)) {
            continue;
        }

        // Ask user for speed
        printf("How fast do you want to travel? (in m/s)\n");
        scanf("%d", &speed);

        // Calculate time taken
        distance = abs(destination - current_time);
        time_taken = distance / speed;

        // Travel through time
        time_travel(&current_time, destination);

        // Print results
        printf("You traveled %d seconds into the %s at a speed of %d m/s.\n", time_taken, (destination > current_time)? "future" : "past", speed);
        printf("You arrived in the year %d.\n", current_time);

        // Check for paradoxes
        if (current_time == 0) {
            printf("You created a paradox! The universe is collapsing...\n");
            exit(0);
        }
    }

    return 0;
}