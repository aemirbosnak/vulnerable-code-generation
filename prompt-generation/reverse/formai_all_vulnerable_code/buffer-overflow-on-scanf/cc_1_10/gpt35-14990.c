//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALIEN_PROB 0.75 // probability of alien invasion
#define HUMAN_PROP 0.25 // probability of no invasion

int main() {
    int seed, i, interval;
    float random, invProb, noInvProb;
    int invasionCount = 0, noInvasionCount = 0;

    // Get the random seed from the current time
    seed = (int) time(NULL);
    srand(seed);

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    // Get the number of simulations to run
    printf("How many simulations would you like to run? ");
    scanf("%d", &interval);

    // Run the simulation
    for (i = 0; i < interval; i++) {
        random = (float) rand() / RAND_MAX;

        // Determine if an invasion occurred
        if (random <= ALIEN_PROB) {
            invasionCount++;
        } else {
            noInvasionCount++;
        }
    }

    // Calculate the probabilities of invasion and no invasion
    invProb = (float) invasionCount / interval;
    noInvProb = (float) noInvasionCount / interval;

    // Print the results
    printf("\nSimulation results:\n");
    printf("- Probability of Alien Invasion: %.2f\n", invProb);
    printf("- Probability of No Invasion: %.2f\n", noInvProb);

    // Determine the outcome of the simulation
    if (invProb >= HUMAN_PROP) {
        printf("\nWarning! Alien invasion is highly probable. Take necessary precautions!\n");
    } else {
        printf("\nThe probability of an alien invasion is low. No need to worry.\n");
    }

    return 0;
}