//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible outcomes of an alien invasion.
enum invasion_outcome {
    INVASION_SUCCESS,
    INVASION_FAILURE
};

// Define the factors that affect the probability of an alien invasion.
enum invasion_factor {
    FACTOR_TECHNOLOGY,
    FACTOR_MOTIVATION,
    FACTOR_RESOURCES
};

// Get a random number between 0 and 1.
double get_random_number() {
    return (double)rand() / (double)RAND_MAX;
}

// Calculate the probability of an alien invasion based on the given factors.
double calculate_invasion_probability(double technology, double motivation, double resources) {
    // The probability of an alien invasion is the product of the probabilities of each factor.
    return technology * motivation * resources;
}

// Simulate an alien invasion and return the outcome.
enum invasion_outcome simulate_invasion(double probability) {
    // Get a random number between 0 and 1.
    double random_number = get_random_number();

    // If the random number is less than the probability of invasion, then the invasion is successful.
    if (random_number < probability) {
        return INVASION_SUCCESS;
    } else {
        return INVASION_FAILURE;
    }
}

// Print the results of the simulation.
void print_results(enum invasion_outcome outcome) {
    if (outcome == INVASION_SUCCESS) {
        printf("The alien invasion was successful.\n");
    } else {
        printf("The alien invasion failed.\n");
    }
}

// Get the user's input.
void get_user_input(double *technology, double *motivation, double *resources) {
    printf("Enter the technology level of the aliens (0 to 1): ");
    scanf("%lf", technology);

    printf("Enter the motivation of the aliens (0 to 1): ");
    scanf("%lf", motivation);

    printf("Enter the resources of the aliens (0 to 1): ");
    scanf("%lf", resources);
}

// Main function.
int main() {
    // Initialize the random number generator.
    srand(time(NULL));

    // Get the user's input.
    double technology, motivation, resources;
    get_user_input(&technology, &motivation, &resources);

    // Calculate the probability of an alien invasion.
    double probability = calculate_invasion_probability(technology, motivation, resources);

    // Simulate the alien invasion.
    enum invasion_outcome outcome = simulate_invasion(probability);

    // Print the results of the simulation.
    print_results(outcome);

    return 0;
}