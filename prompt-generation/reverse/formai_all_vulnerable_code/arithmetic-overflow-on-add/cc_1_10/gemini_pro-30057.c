//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of time travelers
#define MAX_TRAVELERS 10

// Define the maximum number of time periods
#define MAX_PERIODS 10

// Define the time travel simulator struct
typedef struct {
    int id;
    int period;
    time_t timestamp;
} time_traveler;

// Create an array of time travelers
time_traveler travelers[MAX_TRAVELERS];

// Create an array of time periods
int periods[MAX_PERIODS];

// Initialize the time travel simulator
void init_simulator() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the time travelers
    for (int i = 0; i < MAX_TRAVELERS; i++) {
        travelers[i].id = i;
        travelers[i].period = rand() % MAX_PERIODS;
        travelers[i].timestamp = time(NULL);
    }

    // Initialize the time periods
    for (int i = 0; i < MAX_PERIODS; i++) {
        periods[i] = rand() % 100;
    }
}

// Run the time travel simulator
void run_simulator() {
    // Loop forever
    while (1) {
        // Get the current time
        time_t current_time = time(NULL);

        // Check if any time travelers have arrived
        for (int i = 0; i < MAX_TRAVELERS; i++) {
            if (travelers[i].timestamp + periods[travelers[i].period] <= current_time) {
                // Print the time traveler's arrival message
                printf("Time traveler %d has arrived from period %d!\n", travelers[i].id, travelers[i].period);

                // Update the time traveler's timestamp
                travelers[i].timestamp = current_time;
            }
        }
    }
}

// Main function
int main() {
    // Initialize the time travel simulator
    init_simulator();

    // Run the time travel simulator
    run_simulator();

    return 0;
}