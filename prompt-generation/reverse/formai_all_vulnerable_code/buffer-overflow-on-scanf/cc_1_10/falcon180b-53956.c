//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_civilizations, num_communicating_civilizations, num_hostile_civilizations, num_planets_attacked;
    float probability;
    char choice;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Let's calculate the probability of an alien invasion happening.\n");

    // Initialize random seed
    srand(time(NULL));

    // Get number of civilizations in the universe
    do {
        printf("Enter the estimated number of civilizations in the universe: ");
        scanf("%d", &num_civilizations);
    } while (num_civilizations <= 0);

    // Calculate number of communicating civilizations
    num_communicating_civilizations = num_civilizations * 0.1;

    // Calculate number of hostile civilizations
    num_hostile_civilizations = num_communicating_civilizations * 0.01;

    // Calculate number of planets attacked
    num_planets_attacked = num_hostile_civilizations * 10;

    // Calculate probability of an alien invasion happening
    probability = ((float)num_planets_attacked / (float)num_civilizations) * 100;

    // Print results
    printf("\nResults:\n");
    printf("Number of civilizations in the universe: %d\n", num_civilizations);
    printf("Number of communicating civilizations: %d\n", num_communicating_civilizations);
    printf("Number of hostile civilizations: %d\n", num_hostile_civilizations);
    printf("Number of planets attacked: %d\n", num_planets_attacked);
    printf("Probability of an alien invasion happening: %.2f%%\n", probability);

    printf("\nDo you want to calculate the probability again? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Thank you for using the Alien Invasion Probability Calculator!\n");
        return 0;
    }
}