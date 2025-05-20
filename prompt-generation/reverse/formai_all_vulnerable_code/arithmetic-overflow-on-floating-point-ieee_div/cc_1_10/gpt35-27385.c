//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int planets, technology, defense;
    float probability;

    printf("Alien Invasion Probability Calculator\n\n");

    // Prompt user for number of planets
    printf("Enter the number of planets in the solar system: ");
    scanf("%d", &planets);

    // Prompt user for technology level
    printf("Enter the technology level of the inhabitants (1-10): ");
    scanf("%d", &technology);

    // Prompt user for defense capabilities
    printf("Enter the defense capabilities of the inhabitants (1-10): ");
    scanf("%d", &defense);

    // Seed the random number generator
    srand(time(NULL));

    // Calculate probability of invasion
    probability = (float)(rand() % 50 + 51) / 100;
    probability *= (float)(rand() % 50 + 51) / 100;
    probability *= (float)(rand() % 50 + 51) / 100;

    // Adjust probability based on factors
    probability /= planets;
    probability *= (float)technology / 10;
    probability /= (float)defense / 10;

    // Print results
    printf("\nBased on the following factors:\n");
    printf("- Number of planets: %d\n", planets);
    printf("- Technology level: %d\n", technology);
    printf("- Defense capabilities: %d\n", defense);
    printf("\nThe likelihood of an alien invasion is %.2f%%\n", probability * 100);

    // Determine if invasion will occur
    bool invasion = probability >= 0.5;

    if (invasion) {
        printf("RUN FOR YOUR LIVES!!!\n");
    } else {
        printf("Looks like you're safe... for now.\n");
    }

    return 0;
}