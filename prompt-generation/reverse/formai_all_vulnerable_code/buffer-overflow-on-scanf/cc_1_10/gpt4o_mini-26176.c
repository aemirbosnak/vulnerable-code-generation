//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_SIMULATIONS 10000

typedef struct {
    double probability;
    int numInvaders;
    int numEncounters;
} AlienInvasion;

double calculateProbability(double invaders, double encounters) {
    return (invaders / encounters) * 100.0;
}

void simulateInvasion(AlienInvasion* invasion) {
    int successfulEncounters = 0;

    for (int i = 0; i < NUM_SIMULATIONS; i++) {
        // Simulating each encounter based on probability threshold
        double encounterOutcome = (double)rand() / RAND_MAX;

        if (encounterOutcome < invasion->probability / 100.0) {
            successfulEncounters++;
        }
    }

    printf("Simulating Alien Invasion with %.2f%% Probability\n", invasion->probability);
    printf("Total Successful Encounters: %d out of %d\n", successfulEncounters, NUM_SIMULATIONS);
}

void initializeInvasion(AlienInvasion* invasion) {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    printf("Enter the number of alien invaders: ");
    scanf("%d", &invasion->numInvaders);
    
    printf("Enter the number of encounters with humans: ");
    scanf("%d", &invasion->numEncounters);

    // Calculate the probability of a successful alien invasion
    invasion->probability = calculateProbability(invasion->numInvaders, invasion->numEncounters);
}

void playWithParameters(AlienInvasion* invasion) {
    printf("Let's play with the invader scenarios!\n");

    while (1) {
        printf("\n1. Increase number of invaders\n");
        printf("2. Increase number of encounters\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int increase;
            printf("Enter the number of invaders to add: ");
            scanf("%d", &increase);
            invasion->numInvaders += increase;
        } else if (choice == 2) {
            int increase;
            printf("Enter the number of encounters to add: ");
            scanf("%d", &increase);
            invasion->numEncounters += increase;
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice! Please choose again.\n");
            continue;
        }

        invasion->probability = calculateProbability(invasion->numInvaders, invasion->numEncounters);
        simulateInvasion(invasion);
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed
    AlienInvasion invasion;

    initializeInvasion(&invasion);
    simulateInvasion(&invasion);
    playWithParameters(&invasion);

    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}