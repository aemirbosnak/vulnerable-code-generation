//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generatePlanet(char planet[]);
void travel(char currentPlanet[]);
void visitMarket();
void mineResources();

int main() {
    srand(time(NULL)); // Seed the random number generator

    char currentPlanet[20];
    generatePlanet(currentPlanet); // Generate the starting planet

    int choice;

    printf("Welcome to the space adventure game!\n");
    printf("You are currently on planet %s.\n\n", currentPlanet);

    while(1) {
        printf("What would you like to do?\n");
        printf("1) Travel to another planet\n");
        printf("2) Visit the market\n");
        printf("3) Mine resources\n");
        printf("4) Quit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                travel(currentPlanet);
                break;
            case 2:
                visitMarket();
                break;
            case 3:
                mineResources();
                break;
            case 4:
                printf("Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}

// Function to generate a random planet name
void generatePlanet(char planet[]) {
    char planets[][20] = {"Earth", "Mars", "Venus", "Jupiter", "Saturn", "Neptune", "Uranus"};
    int numPlanets = 7;

    int index = rand() % numPlanets;
    sprintf(planet, "%s", planets[index]);
}

// Function to travel to new planet
void travel(char currentPlanet[]) {
    char newPlanet[20];

    printf("\nTraveling to new planet...\n");

    generatePlanet(newPlanet); // Generate a new planet name
    while(strcmp(currentPlanet, newPlanet) == 0) {
        generatePlanet(newPlanet);
    }

    printf("You have arrived on planet %s!\n\n", newPlanet);

    sprintf(currentPlanet, "%s", newPlanet); // Update the current planet
}

// Function to visit the market
void visitMarket() {
    printf("\nYou are visiting the market...\n");

    // Code to implement the market goes here

    printf("You finished your visit to the market!\n\n");
}

// Function to mine resources
void mineResources() {
    printf("\nYou are mining resources...\n");

    // Code to implement the mining process goes here

    printf("You finished mining resources!\n\n");
}