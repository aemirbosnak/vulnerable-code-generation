//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 1000
#define MAX_TIME_TRAVEL_DURATION 10

// Function to simulate time travel
void time_travel(int duration) {
    printf("Time travel initiated. Destination: %d seconds in the future.\n", duration);
    sleep(duration);
    printf("Time travel complete.\n");
}

int main() {
    int num_time_travels, duration;
    char repeat;

    // Seed random number generator with current time
    srand(time(NULL));

    // Get number of time travels from user
    printf("How many time travels do you want to simulate? ");
    scanf("%d", &num_time_travels);

    // Simulate time travels
    for (int i = 0; i < num_time_travels; i++) {
        // Get time travel duration from user
        printf("Enter time travel duration (in seconds): ");
        scanf("%d", &duration);

        // Check if duration is valid
        if (duration <= 0 || duration > MAX_TIME_TRAVEL_DURATION) {
            printf("Invalid duration.\n");
            continue;
        }

        // Simulate time travel
        time_travel(duration);

        // Ask user if they want to repeat the simulation
        printf("Do you want to simulate another time travel? (y/n) ");
        scanf(" %c", &repeat);
        if (repeat!= 'y') {
            break;
        }
    }

    return 0;
}