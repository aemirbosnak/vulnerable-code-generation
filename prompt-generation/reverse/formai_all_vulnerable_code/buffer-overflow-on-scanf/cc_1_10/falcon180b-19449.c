//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateRandomNumber(int *randomNumber);
int calculateAlienInvasionProbability(int population, int technologyLevel, int aggressionLevel);

int main() {
    int population, technologyLevel, aggressionLevel, alienInvasionProbability;
    srand(time(NULL));

    // Get user input
    printf("Enter the population of the planet: ");
    scanf("%d", &population);

    printf("Enter the technology level of the planet (1-10): ");
    scanf("%d", &technologyLevel);

    printf("Enter the aggression level of the aliens (1-10): ");
    scanf("%d", &aggressionLevel);

    // Calculate and display the alien invasion probability
    alienInvasionProbability = calculateAlienInvasionProbability(population, technologyLevel, aggressionLevel);
    printf("The probability of an alien invasion is %d%%\n", alienInvasionProbability);

    return 0;
}

// Generates a random number between 1 and 100
void generateRandomNumber(int *randomNumber) {
    *randomNumber = rand() % 100 + 1;
}

// Calculates the probability of an alien invasion based on population, technology level, and alien aggression
int calculateAlienInvasionProbability(int population, int technologyLevel, int aggressionLevel) {
    int probability = 0;

    // Calculate base probability based on population
    probability += (population / 1000) * 10;

    // Adjust probability based on technology level
    if (technologyLevel > 5) {
        probability += 20;
    } else if (technologyLevel > 2) {
        probability += 10;
    }

    // Adjust probability based on alien aggression level
    if (aggressionLevel > 7) {
        probability -= 30;
    } else if (aggressionLevel > 4) {
        probability -= 10;
    }

    return probability;
}