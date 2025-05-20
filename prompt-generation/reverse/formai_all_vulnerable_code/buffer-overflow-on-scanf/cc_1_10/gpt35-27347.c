//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function prototypes */
float estimateAlienProbability(int, int);
int generateRandomInt(int);

int main() {
    
    int numGalaxies = 0;
    int numCivilizations = 0;

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    /* Get number of galaxies from user */
    while (numGalaxies <= 0) {
        printf("Please enter the number of galaxies in the universe: ");
        scanf("%d", &numGalaxies);
    }

    /* Get number of potential civilizations per galaxy from user */
    while (numCivilizations <= 0) {
        printf("Please enter the estimated number of potential civilizations per galaxy: ");
        scanf("%d", &numCivilizations);
    }

    /* Calculate estimated probability of alien invasion */
    float alienProbability = estimateAlienProbability(numGalaxies, numCivilizations);

    printf("\nBased on our calculations, the probability of an alien invasion is %f percent.\n", alienProbability);

    return 0;
}

float estimateAlienProbability(int numGalaxies, int numCivilizations) {

    /* Set random seed */
    srand(time(NULL));

    /* Generate random integer to represent technological sophistication of aliens */
    int techLevel = generateRandomInt(10);

    /* Generate random integer to represent belligerence of aliens */
    int belligerence = generateRandomInt(10);

    /* Generate random integer to represent closeness of aliens to Earth */
    int proximity = generateRandomInt(10);

    /* Calculate probability based on inputs and random values */
    float probability = (float)(numGalaxies * numCivilizations * techLevel * belligerence) / (10 * 10 * 10 * proximity);

    return probability;
}

int generateRandomInt(int max) {

    int randomNum = rand() % max + 1;

    return randomNum;
}