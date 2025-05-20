//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int num_simulations; // Number of simulations to run
    int days_to_simulate; // Number of days to simulate
    int invasion_probability; // Probability of alien invasion
    int num_invasions; // Number of invasions that happen
    int i, j; // Loop iterators

    srand(time(NULL)); // Initialize random number generator with current time

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    // Prompt user for input
    printf("How many simulations would you like to run? ");
    scanf("%d", &num_simulations);
    printf("How many days would you like to simulate? ");
    scanf("%d", &days_to_simulate);
    printf("What is the probability of an alien invasion per day (0-100)? ");
    scanf("%d", &invasion_probability);

    // Validate input
    if (num_simulations < 1 || days_to_simulate < 1 || invasion_probability < 0 || invasion_probability > 100) {
        printf("Invalid input. Please try again.\n");
        return 1; // Exit program with error code
    }

    // Run simulations
    for (i = 1, num_invasions = 0; i <= num_simulations; i++) {
        int invasion_count = 0;
        for (j = 1; j <= days_to_simulate; j++) {
            int random_num = rand() % 100 + 1; // Generate random number between 1 and 100
            if (random_num <= invasion_probability) {
                invasion_count++;
            }
        }
        if (invasion_count > 0) {
            printf("Simulation %d: %d invasion(s) occurred.\n", i, invasion_count);
            num_invasions++;
        }
    }

    // Calculate and display results
    double invasion_probability_percent = (double) invasion_probability / 100.0;
    double expected_num_invasions = invasion_probability_percent * days_to_simulate;
    double actual_probability = (double) num_invasions / (double) num_simulations;
    printf("\nAfter running %d simulations, it appears that the actual probability of an alien invasion is %.2lf%%.\n", num_simulations, actual_probability * 100.0);
    printf("Based on the input given, the expected number of invasions over %d days is %.2lf.\n", days_to_simulate, expected_num_invasions);

    return 0; // Exit program with success code
}