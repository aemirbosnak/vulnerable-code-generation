//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    int distance;
} Planet;

void travelToPlanet(Planet planets[]);
void displayPlanetList(Planet planets[]);

int main() {
    Planet planets[MAX_PLANETS] = {
        {"Earth", 0},
        {"Mars", 225},
        {"Jupiter", 587},
        {"Saturn", 934},
        {"Uranus", 1792},
        {"Neptune", 2791},
        {"Pluto", 3675},
        {"Alpha Centauri", 413000},
        {"Andromeda", 2530000},
        {"Zeta Reticuli", 39000000}
    };
    srand(time(NULL));
    printf("Welcome to the Space Adventure Game!\n");
    printf("You are currently on planet Earth.\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Travel to another planet\n");
        printf("2. Display list of planets\n");
        printf("3. Quit game\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                travelToPlanet(planets);
                break;
            case 2:
                displayPlanetList(planets);
                break;
            case 3:
                printf("\nThanks for playing the Space Adventure Game!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}

void travelToPlanet(Planet planets[]) {
    int currentPlanetIndex = 0;
    for (int i = 0; i < MAX_PLANETS; i++) {
        if (strcmp(planets[i].name, "Earth") == 0) {
            currentPlanetIndex = i;
            break;
        }
    }
    int choice;
    while (1) {
        printf("\nChoose a planet to travel to:\n");
        for (int i = 0; i < MAX_PLANETS; i++) {
            if (i != currentPlanetIndex) {
                printf("%d. %s (%d light years away)\n", i + 1, planets[i].name, planets[i].distance);
            }
        }
        printf("%d. Cancel\n", MAX_PLANETS + 1);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= MAX_PLANETS) {
            int destinationPlanetIndex = choice - 1;
            printf("\nTraveling to %s...\n", planets[destinationPlanetIndex].name);
            int totalDistance = planets[destinationPlanetIndex].distance - planets[currentPlanetIndex].distance;
            int travelTime = (totalDistance * (rand() % 5 + 1)) / 100;
            printf("Estimated travel time: %d years\n", travelTime);
            printf("Arrived at %s!\n", planets[destinationPlanetIndex].name);
            break;
        } else if (choice == MAX_PLANETS + 1) {
            printf("\nCanceled travel.\n");
            break;
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }
}

void displayPlanetList(Planet planets[]) {
    printf("\nList of planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%s (%d light years away)\n", planets[i].name, planets[i].distance);
    }
}