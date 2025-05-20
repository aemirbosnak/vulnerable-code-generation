//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void explorePlanet();
int navigateSpace();
void engageWarpDrive();

int main() {
    int choice;

    // seed random number generator
    srand(time(0));

    printf("Welcome to the Procedural Space Adventure!\n\n");

    // loop until player chooses to quit
    do {
        printf("What would you like to do?\n");
        printf("1. Explore a planet\n");
        printf("2. Navigate through space\n");
        printf("3. Engage the warp drive (fast travel)\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                explorePlanet();
                break;
            case 2:
                navigateSpace();
                break;
            case 3:
                engageWarpDrive();
                break;
            case 4:
                printf("Thanks for playing! Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n\n");
                break;          
        }
    } while (choice != 4);

    return 0;
}

void explorePlanet() {
    // randomly choose a planet to explore
    int planetNum = rand() % 10 + 1;

    printf("Exploring planet %d...\n", planetNum);

    // simulate exploring the planet
    printf("You find a native species on the planet.\n");
    printf("You make contact with the species and exchange cultural information.\n");
    printf("You also discover a rare element on the planet that could be valuable.\n");

    printf("\n");
}

int navigateSpace() {
    // randomly generate a number between 1 and 100 to determine success rate
    int successRate = rand() % 100 + 1;

    if (successRate > 50) {
        printf("Navigation successful!\n");
        return 1;
    } else {
        printf("Navigation failed. You are unable to find a safe path through space.\n");
        return 0;
    }
}

void engageWarpDrive() {
    int success = navigateSpace();

    if (success) {
        printf("Engaging warp drive...\n");
        printf("You arrive at your destination in record time.\n\n");
    } else {
        printf("Warp drive malfunctioned. You are stranded in space.\n\n");
    }
}