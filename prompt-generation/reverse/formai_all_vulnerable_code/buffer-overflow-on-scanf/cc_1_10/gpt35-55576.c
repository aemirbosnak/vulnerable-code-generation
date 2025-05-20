//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int getRandomNumber(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min) + min);
}

// Struct to represent a planet
typedef struct Planet {
    char name[20];
    int distance;
    int resources;
    int inhabitants;
} Planet;

// Function to print the details of a planet
void printPlanetDetails(Planet planet) {
    printf("\nPlanet details:\n");
    printf("Name: %s\n", planet.name);
    printf("Distance from Earth: %d light years\n", planet.distance);
    printf("Resources available: %d\n", planet.resources);
    printf("Inhabitants: %d\n", planet.inhabitants);
}

// Main function
int main() {
    // List of planets
    Planet planets[] = {
        {"Alderaan", 300, 700, 120000000},
        {"Tatooine", 70, 400, 5000000},
        {"Coruscant", 900, 1200, 1000000000},
        {"Naboo", 500, 1000, 150000000},
        {"Hoth", 200, 300, 0},
        {"Endor", 400, 600, 20000000},
        {"Dagobah", 100, 200, 0},
        {"Bespin", 600, 800, 5000000},
        {"Kashyyyk", 800, 900, 3500000},
        {"Geonosis", 1000, 1100, 10000000}
    };
    int numPlanets = sizeof(planets) / sizeof(Planet);

    // Player details
    char playerName[20];
    printf("Enter your name: ");
    fgets(playerName, 20, stdin);

    // Randomly select a starting planet
    int startingPlanetIndex = getRandomNumber(0, numPlanets);
    Planet currentPlanet = planets[startingPlanetIndex];
    printf("\nWelcome, %s! You are starting on planet %s.\n", playerName, currentPlanet.name);
    printPlanetDetails(currentPlanet);

    // Main game loop
    int gameOver = 0;
    while (!gameOver) {
        // Prompt player for their next move
        char choice;
        printf("\nWhat do you want to do next? (a) Move to a new planet, (b) Gather resources, (c) Talk to inhabitants, (q) Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a': {
                // Randomly select a new planet to move to
                int newPlanetIndex = getRandomNumber(0, numPlanets);
                while (newPlanetIndex == startingPlanetIndex) {
                    newPlanetIndex = getRandomNumber(0, numPlanets);
                }
                Planet newPlanet = planets[newPlanetIndex];
                printf("\nYou have moved to planet %s.\n", newPlanet.name);
                printPlanetDetails(newPlanet);
                currentPlanet = newPlanet;
                break;
            }
            case 'b': {
                // Check if there are any resources on the current planet
                if (currentPlanet.resources == 0) {
                    printf("\nThere are no resources available on this planet.\n");
                } else {
                    // Randomly generate the amount of resources the player is able to gather
                    int maxResources = (currentPlanet.resources < 100) ? currentPlanet.resources : 100;
                    int gatheredResources = getRandomNumber(1, maxResources);
                    printf("\nYou have gathered %d resources from planet %s.\n", gatheredResources, currentPlanet.name);
                    currentPlanet.resources -= gatheredResources;
                }
                break;
            }
            case 'c': {
                // Check if there are any inhabitants on the current planet
                if (currentPlanet.inhabitants == 0) {
                    printf("\nThere are no inhabitants on this planet.\n");
                } else {
                    // Randomly generate a response from the inhabitants
                    char *responses[] = {"Hello!", "Greetings, traveler.", "What brings you to our planet?"};
                    int numResponses = sizeof(responses) / sizeof(char*);
                    int responseIndex = getRandomNumber(0, numResponses);
                    printf("\nInhabitant: %s\n", responses[responseIndex]);
                }
                break;
            }
            case 'q': {
                printf("\nThanks for playing, %s!\n", playerName);
                gameOver = 1;
                break;
            }
            default: {
                printf("\nInvalid choice. Please choose again.\n");
                break;
            }
        }
    }

    return 0;
}