//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes 
void generatePlanet(int size);
void visitPlanet(int size);

int main() {
    srand(time(NULL)); // seed the random number generator

    printf("Welcome to Procedural Space Adventure!\n");

    int numOfPlanets;
    do {
        printf("Enter the number of planets you wish to explore (2-10): ");
        scanf("%d", &numOfPlanets);
    } while (numOfPlanets < 2 || numOfPlanets > 10);

    for (int i = 1; i <= numOfPlanets; i++) {
        printf("Planet %d: \n", i);

        int planetSize = (rand() % 10) + 1; // randomly generated planet size between 1 and 10
        generatePlanet(planetSize); // create the planet

        int choice;
        do {
            printf("What would you like to do on this planet?\n");
            printf("1. Explore\n");
            printf("2. Leave planet\n");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 2);

        if (choice == 1) {
            visitPlanet(planetSize); // visit the planet
        } else {
            printf("You have left planet %d.\n", i);
        }
    }

    printf("Thanks for playing Procedural Space Adventure!\n");

    return 0;
}

// function to generate planet based on size
void generatePlanet(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// function to visit planet
void visitPlanet(int size) {
    printf("Welcome to planet %d!\n", size);
    printf("This planet is uninhabitable.\n");
    printf("There is nothing to do here.\n");
}