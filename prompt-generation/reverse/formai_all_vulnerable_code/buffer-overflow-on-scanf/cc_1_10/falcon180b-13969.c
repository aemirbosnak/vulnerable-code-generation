//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numPlanets;
    double numInhabitedPlanets;
    double numPlanetsWithAdvancedCivilizations;
    double numPlanetsWithHostileIntentions;
    double probabilityOfInvasion;
    int i;

    srand(time(NULL));

    // Ask user for number of planets to simulate
    printf("How many planets do you want to simulate? ");
    scanf("%d", &numPlanets);

    // Initialize variables
    numInhabitedPlanets = 0;
    numPlanetsWithAdvancedCivilizations = 0;
    numPlanetsWithHostileIntentions = 0;

    // Simulate each planet
    for (i = 0; i < numPlanets; i++) {
        // Determine if planet is inhabited
        if (rand() % 2 == 0) {
            numInhabitedPlanets++;

            // Determine if civilization is advanced
            if (rand() % 2 == 0) {
                numPlanetsWithAdvancedCivilizations++;

                // Determine if civilization has hostile intentions
                if (rand() % 2 == 0) {
                    numPlanetsWithHostileIntentions++;
                }
            }
        }
    }

    // Calculate probability of invasion
    probabilityOfInvasion = ((double)numPlanetsWithHostileIntentions / numInhabitedPlanets) * 100;

    // Output results
    printf("Out of %d simulated planets:\n", numPlanets);
    printf("%d were inhabited.\n", numInhabitedPlanets);
    printf("%d had advanced civilizations.\n", numPlanetsWithAdvancedCivilizations);
    printf("%d had hostile intentions.\n", numPlanetsWithHostileIntentions);
    printf("The probability of an alien invasion is %.2f%%\n", probabilityOfInvasion);

    return 0;
}