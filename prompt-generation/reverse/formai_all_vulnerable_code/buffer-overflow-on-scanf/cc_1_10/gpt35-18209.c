//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLANET_COUNT 5

typedef struct {
    char name[20];
    int distance;
    int resources;
} Planet;

int main() {
    Planet planets[PLANET_COUNT] = {
        {"Earth", 0, 100},
        {"Mars", 10, 50},
        {"Jupiter", 60, 200},
        {"Saturn", 80, 150},
        {"Uranus", 100, 75}
    };

    int currentPlanet = 0;
    int resources = 100;
    int fuel = 100;
    srand(time(NULL));
    printf("-----------------------\n");
    printf("Welcome to Procedural Space Adventure!\n");
    printf("-----------------------\n");
    printf("You are on planet %s\n", planets[currentPlanet].name);
    printf("You have %d resources and %d fuel\n", resources, fuel);

    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Travel to another planet\n");
        printf("2. Collect resources\n");
        printf("3. Refuel spaceship\n");
        printf("4. Quit game\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (fuel <= 0) {
                    printf("You do not have enough fuel to travel\n");
                    break;
                }
                int planetIndex = rand() % PLANET_COUNT;
                if (planetIndex == currentPlanet) {
                    printf("You are already on planet %s!\n", planets[currentPlanet].name);
                    break;
                }
                int distance = abs(planets[planetIndex].distance - planets[currentPlanet].distance);
                printf("Travelling to planet %s (%d distance)...\n", planets[planetIndex].name, distance);
                fuel -= distance;
                currentPlanet = planetIndex;
                printf("You have arrived at planet %s!\n", planets[currentPlanet].name);
                printf("You have %d fuel left\n", fuel);
                break;

            case 2:
                if (planets[currentPlanet].resources <= 0) {
                    printf("There are no more resources on planet %s\n", planets[currentPlanet].name);
                    break;
                }
                int collectedResources = rand() % planets[currentPlanet].resources + 1;
                planets[currentPlanet].resources -= collectedResources;
                resources += collectedResources;
                printf("You have collected %d resources from planet %s\n", collectedResources, planets[currentPlanet].name);
                printf("You now have %d resources\n", resources);
                break;

            case 3:
                printf("Refuelling spaceship...\n");
                int refuelAmount = rand() % 20 + 1;
                fuel += refuelAmount;
                printf("You have refuelled for %d fuel\n", refuelAmount);
                printf("You now have %d fuel\n", fuel);
                break;

            case 4:
                printf("Thank you for playing Procedural Space Adventure!\n");
                exit(0);

            default:
                printf("Invalid input\n");
                break;
        }

        // Check if player has won
        if (resources >= 500) {
            printf("Congratulations, you have won Procedural Space Adventure!\n");
            exit(0);
        }

    }
    return 0;
}