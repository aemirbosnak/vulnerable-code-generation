//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POPULATION 1000000
#define SIMULATION_RUNS 1000

// Function prototypes
double calculate_invasion_probability(int population, double alien_technology_factor);
void run_simulation(int population);
void display_results(double invasion_probabilities[], int runs);

int main() {
    int population;
    double alien_technology_factor;

    // Getting user input
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the human population (up to %d): ", MAX_POPULATION);
    scanf("%d", &population);

    if (population < 1 || population > MAX_POPULATION) {
        printf("Invalid population size. Please enter a value between 1 and %d.\n", MAX_POPULATION);
        return EXIT_FAILURE;
    }

    printf("Enter the alien technology factor (0.0 - 1.0): ");
    scanf("%lf", &alien_technology_factor);

    if (alien_technology_factor < 0.0 || alien_technology_factor > 1.0) {
        printf("Invalid technology factor. Please enter a value between 0.0 and 1.0.\n");
        return EXIT_FAILURE;
    }

    // Run the simulation
    run_simulation(population + 1);

    return EXIT_SUCCESS;
}

// Function to simulate invasion
double calculate_invasion_probability(int population, double alien_technology_factor) {
    double base_prob = 0.05; // Base probability of invasion
    double tech_modified_prob = base_prob * (1 + alien_technology_factor); // Modify based on alien tech
    return fmin(tech_modified_prob, 1.0); // Limit to a maximum of 1.0
}

// Function to run the simulation and gather probabilities
void run_simulation(int population) {
    double invasion_probabilities[SIMULATION_RUNS];
    for (int run = 0; run < SIMULATION_RUNS; run++) {
        double alien_technology_factor = (double)rand() / (double)(RAND_MAX);
        invasion_probabilities[run] = calculate_invasion_probability(population, alien_technology_factor);
    }
    display_results(invasion_probabilities, SIMULATION_RUNS);
}

// Function to display results
void display_results(double invasion_probabilities[], int runs) {
    double total_probability = 0.0;
    double max_probability = 0.0;
    double min_probability = 1.0;

    printf("\nResults of Invasion Probability Simulation (for %d runs):\n", runs);
    for (int i = 0; i < runs; i++) {
        printf("Run %d: Probability of invasion = %.2lf%%\n", i + 1, invasion_probabilities[i] * 100);
        total_probability += invasion_probabilities[i];

        if (invasion_probabilities[i] > max_probability) {
            max_probability = invasion_probabilities[i];
        }
        if (invasion_probabilities[i] < min_probability) {
            min_probability = invasion_probabilities[i];
        }
    }

    double average_probability = total_probability / runs;
    printf("\nAverage invasion probability: %.2lf%%\n", average_probability * 100);
    printf("Maximum invasion probability: %.2lf%%\n", max_probability * 100);
    printf("Minimum invasion probability: %.2lf%%\n", min_probability * 100);
}