//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 1000
#define MAX_FACTORS 10
#define MAX_DISTANCES 100

int main() {
    int numPlanets;
    int numFactors;
    int numDistances;
    int numAttempts = 0;
    int i, j, k;
    int factors[MAX_FACTORS];
    int distances[MAX_DISTANCES];
    int attempts[MAX_ATTEMPTS];
    int success = 0;
    double probability;
    double sum = 0;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    printf("Please enter the number of planets in the galaxy: ");
    scanf("%d", &numPlanets);

    printf("Please enter the number of factors to consider: ");
    scanf("%d", &numFactors);

    printf("Please enter the number of distances to consider: ");
    scanf("%d", &numDistances);

    srand(time(NULL));

    for (i = 0; i < numPlanets; i++) {
        for (j = 0; j < numFactors; j++) {
            factors[j] = rand() % 101;
        }

        for (k = 0; k < numDistances; k++) {
            distances[k] = rand() % 101;
        }

        for (j = 0; j < numFactors; j++) {
            for (k = 0; k < numDistances; k++) {
                attempts[numAttempts] = (factors[j] * distances[k]) % 101;
                numAttempts++;
            }
        }
    }

    for (i = 0; i < numPlanets; i++) {
        for (j = 0; j < numFactors; j++) {
            for (k = 0; k < numDistances; k++) {
                if (attempts[i * numFactors * numDistances + j * numDistances + k] == 0) {
                    success++;
                }
            }
        }
    }

    probability = ((double)success / (numPlanets * numFactors * numDistances)) * 100;

    printf("The probability of an alien invasion is %.2f%%\n", probability);

    return 0;
}