//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_civilizations, num_planets, num_invasions, num_simulations, i, j;
    double probability;
    char choice;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    // Get number of civilizations from user
    printf("Enter the number of civilizations in the universe: ");
    scanf("%d", &num_civilizations);

    // Get number of planets from user
    printf("Enter the number of planets in the universe: ");
    scanf("%d", &num_planets);

    // Get number of invasions from user
    printf("Enter the number of invasions to simulate: ");
    scanf("%d", &num_invasions);

    // Get number of simulations from user
    printf("Enter the number of simulations to run: ");
    scanf("%d", &num_simulations);

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Run the simulations
    for (i = 0; i < num_simulations; i++) {
        int num_invaded_planets = 0;

        // Simulate each invasion
        for (j = 0; j < num_invasions; j++) {
            int planet_index = rand() % num_planets;

            if (planet_index < num_civilizations) {
                // The planet is already inhabited by a civilization
                continue;
            }

            // The planet is uninhabited, so it is invaded
            num_invaded_planets++;
        }

        // Calculate the probability of invasion
        probability = (double) num_invaded_planets / num_invasions;

        // Print the results
        printf("Simulation %d: %.2f%% of planets were invaded.\n", i + 1, probability * 100);
    }

    // Ask the user if they want to run the program again
    printf("Do you want to run another simulation? (y/n): ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'y':
        case 'Y':
            main();
            break;
        default:
            printf("Exiting program...\n");
            break;
    }

    return 0;
}