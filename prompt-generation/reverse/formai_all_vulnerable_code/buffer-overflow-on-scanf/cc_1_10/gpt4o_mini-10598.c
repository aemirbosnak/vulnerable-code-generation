//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SAMPLES 10000

// Function to generate random probabilities
double generate_random_probability() {
    return (double)rand() / (double)RAND_MAX;
}

// Function to simulate an alien invasion event
int simulate_invasion_event(double invasion_probability) {
    double random_value = generate_random_probability();
    return random_value < invasion_probability ? 1 : 0; // 1 for invasion, 0 for no invasion
}

// Function to calculate the probability of an alien invasion
double calculate_invasion_probability(double invasion_rate, int num_samples) {
    int invasion_count = 0;

    // Simulate the invasion events
    for (int i = 0; i < num_samples; i++) {
        invasion_count += simulate_invasion_event(invasion_rate);
    }

    // Return the probability based on the simulation results
    return (double)invasion_count / num_samples;
}

// Function to print simulation results
void print_simulation_results(double invasion_rate, double probability) {
    printf("Invasion Rate: %.2f\n", invasion_rate);
    printf("Simulated Alien Invasion Probability: %.4f\n", probability);
}

int main() {
    double invasion_rate;
    int num_samples;

    // Seed the random number generator
    srand(time(NULL));

    // User input for invasion rate and number of samples
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the alien invasion rate (0.0 - 1.0): ");
    scanf("%lf", &invasion_rate);

    // Validate invasion rate
    while (invasion_rate < 0.0 || invasion_rate > 1.0) {
        printf("Invalid input. Please enter a value between 0.0 and 1.0: ");
        scanf("%lf", &invasion_rate);
    }

    printf("Please input the number of simulation samples (up to %d): ", MAX_SAMPLES);
    scanf("%d", &num_samples);

    // Validate number of samples
    while (num_samples <= 0 || num_samples > MAX_SAMPLES) {
        printf("Invalid input. Please enter a positive integer up to %d: ", MAX_SAMPLES);
        scanf("%d", &num_samples);
    }

    // Calculate the probability of invasion
    double invasion_probability = calculate_invasion_probability(invasion_rate, num_samples);

    // Print the results
    print_simulation_results(invasion_rate, invasion_probability);

    // Additional suggestions for the user
    printf("\nConsider adjusting the alien invasion rate or increasing the sample size for a more detailed simulation.\n");

    return 0;
}