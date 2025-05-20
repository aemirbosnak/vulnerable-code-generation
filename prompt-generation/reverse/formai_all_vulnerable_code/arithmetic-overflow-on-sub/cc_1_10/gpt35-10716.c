//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char planetName[50];
    int planetDistance;
    int energyLevel = 100;
    int maxEnergyLevel = 100;

    printf("Welcome to the Procedural Space Adventure game! Let's travel through the galaxy.\n\n");

    while (1) {
        printf("Enter the planet name you want to visit (Type 'quit' to exit the game): ");
        scanf("%s", planetName);

        if (strcmp(planetName, "quit") == 0) {
            printf("\nThanks for playing! Hope you enjoyed the game.\n");
            exit(0);
        }

        printf("Enter the distance from your current position in kms: ");
        scanf("%d", &planetDistance);

        if (planetDistance > energyLevel) {
            printf("Oops! You don't have enough energy to travel to this planet.\n");
            continue;
        }

        printf("\nPreparing for launch...\n");
        energyLevel -= planetDistance;
        printf("You have reached the planet %s. Energy level left: %d\n", planetName, energyLevel);

        if (energyLevel <= maxEnergyLevel/4) {
            printf("Warning! Energy levels are running low!\n");
        }

        // Explore the planet
        printf("\nExploring the planet...\n");
        printf("You found a treasure chest!\n");

        int treasure = rand() % 100;
        printf("You gained %d energy from the treasure chest.\n", treasure);
        energyLevel += treasure;

        if (energyLevel >= maxEnergyLevel) {
            energyLevel = maxEnergyLevel;
            printf("Your energy level is now at maximum capacity!\n");
        }

        // Travel back to space station
        printf("\nGetting ready to travel back to the space station...\n");
        energyLevel -= planetDistance;
        printf("You have arrived at the space station. Energy level left: %d\n", energyLevel);

        if (energyLevel <= maxEnergyLevel/4) {
            printf("Warning! Energy levels are running low!\n");
        }
        printf("\n\n");
    }
    return 0;
}