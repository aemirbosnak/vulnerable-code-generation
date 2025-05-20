//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int getRandomInt(int min, int max);
float probabilityOfInvasion(int alienCount, int bulletCount, int peopleCount);

int main() {
    int alienCount, bulletCount, peopleCount;
    float invasionProbability;

    // seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator\n");
    printf("Please enter the number of aliens, bullets, and people in the area:\n");
    scanf("%d %d %d", &alienCount, &bulletCount, &peopleCount);

    // calculate the invasion probability
    invasionProbability = probabilityOfInvasion(alienCount, bulletCount, peopleCount);

    printf("\nThe probability of an alien invasion is %.2f%%\n", invasionProbability);

    return 0;
}

// helper function to generate a random integer between min and max (inclusive)
int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// function to calculate the probability of an alien invasion
float probabilityOfInvasion(int alienCount, int bulletCount, int peopleCount) {
    int alienSurvivors, bulletCapabilities, invasionStrength;
    float invasionProbability;

    // calculate the number of surviving aliens (50-90% of original count)
    alienSurvivors = alienCount * getRandomInt(50, 90) / 100;

    // calculate the bullet capabilities of the people (40-60% of bullet count)
    bulletCapabilities = bulletCount * getRandomInt(40, 60) / 100;

    // calculate the invasion strength (10-50% of total alien count)
    invasionStrength = alienCount * getRandomInt(10, 50) / 100;

    // calculate the invasion probability based on the above factors
    invasionProbability = (float)invasionStrength / (bulletCapabilities + peopleCount - alienSurvivors) * 100;

    return invasionProbability;
}