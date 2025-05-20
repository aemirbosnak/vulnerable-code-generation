//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initialize variables
    double alien_strength, defense_intelligence, invasion_probability;
    int alien_technology, defense_technology, num_of_simulations;

    // Set seed for random number generator
    srand(time(NULL));

    // Prompt user for input
    printf("Enter alien strength (0 to 1): ");
    scanf("%lf", &alien_strength);

    printf("Enter alien technology level (1 to 10): ");
    scanf("%d", &alien_technology);

    printf("Enter defense intelligence level (1 to 10): ");
    scanf("%lf", &defense_intelligence);

    printf("Enter defense technology level (1 to 10): ");
    scanf("%d", &defense_technology);

    printf("Enter number of simulations: ");
    scanf("%d", &num_of_simulations);

    // Calculate invasion probability using Monte Carlo simulation
    int num_of_successes = 0;
    for (int i = 0; i < num_of_simulations; i++) {
        double alien_power = alien_strength * alien_technology;
        double defense_power = defense_intelligence * defense_technology;
        double prob_of_success = (alien_power / (alien_power + defense_power));

        double random_num = (double) rand() / RAND_MAX;

        if (random_num <= prob_of_success) {
            num_of_successes++;
        }
    }
    invasion_probability = ((double) num_of_successes / num_of_simulations) * 100;

    // Print results
    printf("\nAlien strength: %.2lf\nAlien technology: %d\nDefense intelligence: %.2lf\nDefense technology: %d\nNum of simulations: %d\n\n", alien_strength, alien_technology, defense_intelligence, defense_technology, num_of_simulations);
    printf("Probability of invasion success: %.2lf%%\n", invasion_probability);

    return 0;
}