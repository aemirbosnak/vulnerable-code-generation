//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLANETS 5
#define MAX_ENCOUNTERS 3

typedef struct {
    char name[20];
    char encounter[100];
} Planet;

void initializePlanets(Planet planets[]) {
    // Initialize planets with names and encounters
    snprintf(planets[0].name, sizeof(planets[0].name), "Alpha Centauri");
    snprintf(planets[0].encounter, sizeof(planets[0].encounter), "You found an alien artifact!");

    snprintf(planets[1].name, sizeof(planets[1].name), "Barnard's Star");
    snprintf(planets[1].encounter, sizeof(planets[1].encounter), "A space pirate attacks your ship!");

    snprintf(planets[2].name, sizeof(planets[2].name), "Sirius");
    snprintf(planets[2].encounter, sizeof(planets[2].encounter), "You discover a hidden base!");

    snprintf(planets[3].name, sizeof(planets[3].name), "Proxima Centauri");
    snprintf(planets[3].encounter, sizeof(planets[3].encounter), "An ancient civilization contacts you.");

    snprintf(planets[4].name, sizeof(planets[4].name), "Wolf 359");
    snprintf(planets[4].encounter, sizeof(planets[4].encounter), "You find a damaged spacecraft and must help!");
}

void displayPlanets(Planet planets[]) {
    printf("Available Planets to Explore:\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%d. %s\n", i + 1, planets[i].name);
    }
}

int randomOutcome() {
    return rand() % 3; // 0 = success, 1 = failure, 2 = neutral
}

void planetEncounter(Planet planet) {
    printf("You have landed on %s.\n", planet.name);
    printf("Event: %s\n", planet.encounter);

    int result = randomOutcome();
    switch (result) {
        case 0:
            printf("You successfully complete the mission!\n");
            break;
        case 1:
            printf("Mission failed. You lost equipment!\n");
            break;
        case 2:
            printf("You have a neutral encounter, no effects.\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    Planet planets[NUM_PLANETS];
    initializePlanets(planets);

    while (1) {
        displayPlanets(planets);

        int choice;
        printf("Choose a planet to explore (1-%d), or 0 to quit: ", NUM_PLANETS);
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for playing!\n");
            break;
        } else if (choice < 1 || choice > NUM_PLANETS) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        planetEncounter(planets[choice - 1]);
    }

    return 0;
}