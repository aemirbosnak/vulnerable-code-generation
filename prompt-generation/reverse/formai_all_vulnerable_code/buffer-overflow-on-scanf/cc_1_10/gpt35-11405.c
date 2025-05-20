//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int invasionChance, alienType, technologyLevel, defenseLevel;
    // Declare variables to store probability of an invasion, alien type, technology level and defense level
    srand(time(NULL)); // Seed the random number generator with current time

    printf("--------------- Alien Invasion Probability Calculator ---------------\n");

    printf("\nEnter the technology level of human civilization (0 - 100): ");
    scanf("%d", &technologyLevel);

    printf("\nEnter the defense level of human civilization (0 - 100): ");
    scanf("%d", &defenseLevel);

    invasionChance = rand() % 101; // Generate a random number between 0 and 100

    if (invasionChance >= 50) { // Probability of an invasion is 50% or above
        printf("\nWARNING: An alien invasion is highly probable!\n");

        alienType = rand() % 3; // Generate a random number between 0 and 2 to determine alien type

        if (alienType == 0) {
            printf("\nAlien Type: Hostile\n");
        } else if (alienType == 1) {
            printf("\nAlien Type: Neutral\n");
        } else {
            printf("\nAlien Type: Friendly\n");
        }

        if (technologyLevel >= 75 && defenseLevel >= 75) { // High technology and defense levels
            printf("\nHuman civilization is well-prepared for an alien invasion.\n");
            printf("\nAliens are likely to abandon their plan after encountering strong resistance.\n");
        } else if (technologyLevel >= 50 && defenseLevel >= 50) { // Moderate technology and defense levels
            printf("\nHuman civilization has some chance of withstanding an alien invasion.\n");
            printf("\nHowever, humans may suffer significant losses.\n");
        } else { // Low technology and defense levels
            printf("\nHuman civilization is ill-prepared for an alien invasion.\n");
            printf("\nThe outcome of the invasion is likely to be catastrophic for humans.\n");
        }
    } else { // Probability of an invasion is below 50%
        printf("\nAlien invasion is unlikely.\n");
    }

    printf("\n--------------------------------------------------------------------\n");

    return 0;
}