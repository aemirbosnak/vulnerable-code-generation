//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of time periods
#define NUM_PERIODS 10

// Define the probability of each time period
double probabilities[NUM_PERIODS] = {
    0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1
};

// Generate a random time period
int generate_time_period() {
    double r = (double)rand() / RAND_MAX;
    double cumulative_probability = 0.0;
    for (int i = 0; i < NUM_PERIODS; i++) {
        cumulative_probability += probabilities[i];
        if (r <= cumulative_probability) {
            return i;
        }
    }
    return -1;  // Should never reach here
}

// Simulate time travel
void simulate_time_travel(int num_simulations) {
    // Initialize the results
    int results[NUM_PERIODS] = {0};

    // Run the simulations
    for (int i = 0; i < num_simulations; i++) {
        int time_period = generate_time_period();
        results[time_period]++;
    }

    // Print the results
    printf("Time Period\tProbability\tCount\n");
    for (int i = 0; i < NUM_PERIODS; i++) {
        printf("%d\t\t%f\t%d\n", i, probabilities[i], results[i]);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Simulate time travel
    simulate_time_travel(1000000);

    return 0;
}