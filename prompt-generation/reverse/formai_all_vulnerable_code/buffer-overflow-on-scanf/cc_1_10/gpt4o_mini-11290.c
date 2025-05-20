//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SITUATIONS 100

typedef struct {
    char description[256];
    float probability; // Probability on a scale of 0.0 to 1.0
} Situation;

int numberOfSituations = 0;
Situation situations[MAX_SITUATIONS];

void addSituation(const char *description, float probability) {
    if (numberOfSituations >= MAX_SITUATIONS) {
        printf("Maximum number of situations reached.\n");
        return;
    }
    snprintf(situations[numberOfSituations].description, sizeof(situations[numberOfSituations].description), "%s", description);
    situations[numberOfSituations].probability = probability;
    numberOfSituations++;
}

float calculateInvasionProbability() {
    float totalProbability = 0.0;
    for (int i = 0; i < numberOfSituations; i++) {
        totalProbability += situations[i].probability;
    }
    return totalProbability / numberOfSituations; // Return average probability
}

void simulateInvasion() {
    float invasionChance = (rand() % 100) / 100.0; // Random float between 0.0 and 1.0
    float currentProbability = calculateInvasionProbability();
    
    printf("Simulated Invasion Chance: %.2f\n", invasionChance);
    printf("Calculated Invasion Probability: %.2f\n", currentProbability);
    
    if (invasionChance < currentProbability) {
        printf("ALIENS HAVE INVADED! Prepare for battle!\n");
    } else {
        printf("No alien invasion today! You're safe for now.\n");
    }
}

void printSituations() {
    printf("\nList of Possible Situations Leading to Alien Invasion:\n");
    for (int i = 0; i < numberOfSituations; i++) {
        printf("%d. %s - Probability: %.2f\n", i + 1, situations[i].description, situations[i].probability);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Adding sample situations
    addSituation("Aliens are already here secretly observing us.", 0.7);
    addSituation("Government officials have been abducted.", 0.5);
    addSituation("Mysterious lights appear in the sky at night.", 0.6);
    addSituation("High rates of unexplained disappearances.", 0.4);
    addSituation("Strange signals are being intercepted from space.", 0.8);
    
    printSituations();

    // Simulate invasion
    simulateInvasion();
    
    // Additional simulation for the user
    char continueSimulation;
    do {
        printf("Do you want to simulate another invasion? (y/n): ");
        scanf(" %c", &continueSimulation);
        if (continueSimulation == 'y') {
            simulateInvasion();
        }
    } while (continueSimulation == 'y');

    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}