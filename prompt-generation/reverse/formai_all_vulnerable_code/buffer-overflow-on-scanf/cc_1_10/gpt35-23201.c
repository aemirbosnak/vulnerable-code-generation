//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: unmistakable
#include <stdio.h>
#include <stdbool.h>

void travel(int x, int y) {
    printf("Travelling to (%d,%d)\n", x, y);
}

void engageThrusters() {
    printf("Engaging thrusters...\n");
}

void navigateToPlanet() {
    printf("Navigating to planet...\n");
}

void collectResource() {
    printf("Collecting resource...\n");
}

void displayPlanetInfo(int planetNumber) {
    printf("Displaying planet info for planet %d...\n", planetNumber);
}

int main() {
    int currentPlanet = 0;
    bool gameOver = false;
    char userChoice;

    printf("Welcome to the Procedural Space Adventure game!\n");
    printf("You have just crash-landed on a planet in a distant galaxy.\n");
    printf("Your goal is to gather resources and find a way back home.\n");

    while (!gameOver) {
        printf("\nYou are currently on planet %d.\n", currentPlanet);
        printf("What would you like to do?\n");
        printf("a. Travel to a different planet\n");
        printf("b. Collect resources from current planet\n");
        printf("c. Display info about current planet\n");
        printf("d. Quit game\n");

        scanf(" %c", &userChoice);

        switch (userChoice) {
            case 'a':
                printf("\nWhich planet would you like to travel to? (Enter x y coordinates)\n");
                int x, y;
                scanf("%d %d", &x, &y);
                travel(x, y);
                engageThrusters();
                navigateToPlanet();
                currentPlanet++;
                break;
            case 'b':
                collectResource();
                printf("Resource collected!\n");
                break;
            case 'c':
                displayPlanetInfo(currentPlanet);
                break;
            case 'd':
                printf("Goodbye!\n");
                gameOver = true;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}