//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: beginner-friendly
#include <stdio.h>

// function to check if the player is alive
int isPlayerAlive(int healthPoints) {
    if (healthPoints > 0) {
        return 1; // player is alive
    } else {
        return 0; // player is dead
    }
}

int main() {
    int healthPoints = 100;
    int fuelLevel = 1000;
    int currentPlanet = 1;
    int isSelected = 0;
    int playerChoice;

    printf("Welcome to Procedural Space Adventure!\n");

    while (isPlayerAlive(healthPoints)) {
        printf("\n\n~~~You are currently on Planet %d~~~\n", currentPlanet);
        printf("You have %d health points and %d fuel.\n", healthPoints, fuelLevel);
        printf("Where would you like to go next?\n");
        printf("1. Planet %d-1\n", currentPlanet);
        printf("2. Planet %d-2\n", currentPlanet);
        printf("3. Planet %d-3\n", currentPlanet);
        printf("4. Refuel\n");
        printf("5. Quit\n");

        isSelected = 0;

        // get user's input and validate
        while (!isSelected) {
            scanf("%d", &playerChoice);
            switch (playerChoice) {
                case 1:
                    isSelected = 1;
                    currentPlanet = currentPlanet * 10 + 1;
                    printf("Traveling to Planet %d...\n", currentPlanet);
                    break;
                case 2:
                    isSelected = 1;
                    currentPlanet = currentPlanet * 10 + 2;
                    printf("Traveling to Planet %d...\n", currentPlanet);
                    break;
                case 3:
                    isSelected = 1;
                    currentPlanet = currentPlanet * 10 + 3;
                    printf("Traveling to Planet %d...\n", currentPlanet);
                    break;
                case 4:
                    isSelected = 1;
                    fuelLevel = 1000;
                    printf("Refueling...\n");
                    break;
                case 5:
                    isSelected = 1;
                    printf("Quitting game...\n");
                    return 0;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        }

        // consume fuel
        fuelLevel -= 100;

        // check if the player has run out of fuel
        if (fuelLevel <= 0) {
            healthPoints = 0;
            printf("You ran out of fuel and died in the cold vacuum of space...\n");
            break;
        } else {
            // update the player's health points
            healthPoints -= 10;

            if (healthPoints <= 0) {
                printf("You died on Planet %d...\n", currentPlanet);
                break;
            }
        }
    }

    printf("Thank you for playing Procedural Space Adventure!\n");

    return 0;
}