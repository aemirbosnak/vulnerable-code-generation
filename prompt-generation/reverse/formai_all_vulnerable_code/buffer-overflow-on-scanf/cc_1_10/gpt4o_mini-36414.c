//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIMULATIONS 10000

// Function to calculate the probability of invasion
double calculate_invasion_probability(int alien_tech_level, int human_defense_level, int num_simulations) {
    int invasions = 0;

    for (int i = 0; i < num_simulations; i++) {
        // Simple algorithm for determining if invasion is successful
        // If alien tech level is greater than human defense level, invasion is successful
        if (rand() % 100 < (alien_tech_level - human_defense_level + 50)) {
            invasions++;
        }
    }

    return (double) invasions / num_simulations;
}

// Function to display results in a formatted way
void display_results(double probability, int alien_tech_level, int human_defense_level) {
    printf("-------------------------------------------------\n");
    printf("Alien Invasion Probability Calculator\n");
    printf("-------------------------------------------------\n");
    printf("Alien Technology Level: %d\n", alien_tech_level);
    printf("Human Defense Level: %d\n", human_defense_level);
    printf("Calculated Probability of Invasion: %.2f%%\n", probability * 100);
    printf("-------------------------------------------------\n");
}

int main() {
    int alien_tech_level, human_defense_level;
    double invasion_probability;

    // Seed the random number generator for simulation
    srand(time(NULL));

    // User input for alien technology level
    printf("Enter the Alien Technology Level (1 to 100): ");
    if (scanf("%d", &alien_tech_level) != 1 || alien_tech_level < 1 || alien_tech_level > 100) {
        fprintf(stderr, "Invalid input. Please enter a number between 1 and 100.\n");
        return 1;
    }

    // User input for human defense level
    printf("Enter the Human Defense Level (1 to 100): ");
    if (scanf("%d", &human_defense_level) != 1 || human_defense_level < 1 || human_defense_level > 100) {
        fprintf(stderr, "Invalid input. Please enter a number between 1 and 100.\n");
        return 1;
    }

    // Calculate the invasion probability
    invasion_probability = calculate_invasion_probability(alien_tech_level, human_defense_level, MAX_SIMULATIONS);

    // Display the results
    display_results(invasion_probability, alien_tech_level, human_defense_level);

    return 0;
}