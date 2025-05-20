//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int id;
} Planet;

int visitedPlanets[10]; // array to keep track of visited planets
int numVisitedPlanets = 0; // counter for number of visited planets

void generatePlanet(Planet *planet) {
    planet->id = rand() % 100;
    sprintf(planet->name, "Planet %d", planet->id);
    sprintf(planet->description, "Planet %d is a rocky, uninhabitable planet with a toxic atmosphere.", planet->id);
}

void visitPlanet(Planet *planet) {
    printf("You have landed on %s!\n\n", planet->name);
    printf("%s\n\n", planet->description);
    visitedPlanets[numVisitedPlanets++] = planet->id; // add planet to visited list
}

int main() {
    srand(time(NULL)); // seed random number generator with current time
    
    printf("Welcome to Procedural Space Adventure!\n\n");
    
    // generate initial planet to visit
    Planet currentPlanet;
    generatePlanet(&currentPlanet);
    visitPlanet(&currentPlanet);
    
    // main game loop
    while (numVisitedPlanets < 10) {
        printf("What would you like to do next?\n");
        printf("1. Visit another planet\n");
        printf("2. Travel to a random planet\n");
        printf("3. Check your list of visited planets\n");
        printf("4. Quit game\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Enter the planet ID you want to visit:\n");
                int id;
                scanf("%d", &id);
                if (id == currentPlanet.id) {
                    printf("You are already on that planet!\n");
                    break;
                }
                Planet nextPlanet;
                int alreadyVisited = 0;
                for (int i = 0; i < numVisitedPlanets; i++) {
                    if (visitedPlanets[i] == id) {
                        alreadyVisited = 1;
                        break;
                    }
                }
                if (alreadyVisited) {
                    printf("You have already visited that planet!\n");
                    break;
                }
                nextPlanet.id = id;
                sprintf(nextPlanet.name, "Planet %d", nextPlanet.id);
                sprintf(nextPlanet.description, "Planet %d is a barren wasteland with no signs of life.", nextPlanet.id);
                visitPlanet(&nextPlanet);
                currentPlanet = nextPlanet;
                break;
            }
            case 2: {
                Planet nextPlanet;
                generatePlanet(&nextPlanet);
                if (nextPlanet.id == currentPlanet.id) {
                    printf("You have landed on the same planet!\n");
                    break;
                }
                int alreadyVisited = 0;
                for (int i = 0; i < numVisitedPlanets; i++) {
                    if (visitedPlanets[i] == nextPlanet.id) {
                        alreadyVisited = 1;
                        break;
                    }
                }
                if (alreadyVisited) {
                    printf("You have already visited that planet!\n");
                    break;
                }
                visitPlanet(&nextPlanet);
                currentPlanet = nextPlanet;
                break;
            }
            case 3: {
                printf("You have visited the following planets:\n");
                for (int i = 0; i < numVisitedPlanets; i++) {
                    printf("Planet %d\n", visitedPlanets[i]);
                }
                printf("\n");
                break;
            }
            case 4: {
                printf("Thanks for playing Procedural Space Adventure!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice, try again.\n");
            }
        }
    }
    printf("Congratulations, you have visited all 10 planets and won Procedural Space Adventure!\n");
    return 0;
}