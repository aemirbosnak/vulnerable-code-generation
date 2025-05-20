//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIALS 10000
#define MAX_ALIENS 1000
#define MAX_YEARS 1000
#define PROBABILITY_THRESHOLD 0.05

int main() {
    int numTrials;
    int numAliens;
    int numYears;
    double probability;
    int i;

    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of trials you would like to run (between 1 and %d): ", MAX_TRIALS);
    scanf("%d", &numTrials);

    printf("Please enter the maximum number of aliens that could invade Earth (between 1 and %d): ", MAX_ALIENS);
    scanf("%d", &numAliens);

    printf("Please enter the maximum number of years from now that an alien invasion could occur (between 1 and %d): ", MAX_YEARS);
    scanf("%d", &numYears);

    double totalProbability = 0;

    for (i = 0; i < numTrials; i++) {
        int numInvasions = 0;

        int year = rand() % numYears + 1;
        int numAliensThisYear = rand() % numAliens + 1;

        printf("Simulating trial %d...\n", i + 1);
        printf("In the year %d, %d aliens invade Earth.\n", year, numAliensThisYear);

        if (numAliensThisYear > 0) {
            numInvasions++;
        }

        totalProbability += numInvasions / numTrials;
    }

    probability = totalProbability;

    if (probability >= PROBABILITY_THRESHOLD) {
        printf("\nWARNING: There is a %.2f%% chance of an alien invasion within the next %d years!\n", probability * 100, numYears);
    } else {
        printf("\nGood news! There is only a %.2f%% chance of an alien invasion within the next %d years.\n", probability * 100, numYears);
    }

    return 0;
}