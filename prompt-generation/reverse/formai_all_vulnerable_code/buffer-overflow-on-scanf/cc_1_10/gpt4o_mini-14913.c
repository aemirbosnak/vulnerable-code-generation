//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int resources;
    int distance; // Distance from the current position
} Planet;

void initializePlanets(Planet *planets) {
    const char *planetNames[] = {"Zypheron", "Galaxia", "Nebulon", "Astropolis", "Ecliptica"};

    for (int i = 0; i < MAX_PLANETS; i++) {
        strcpy(planets[i].name, planetNames[i]);
        planets[i].resources = rand() % 100; // Random resources between 0 and 99
        planets[i].distance = rand() % 1000; // Random distance between 0 and 999
    }
}

void displayPlanets(Planet *planets) {
    printf("Available Planets to Explore:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%d. %s (Distance: %d light-years, Resources: %d)\n", i + 1, planets[i].name,
               planets[i].distance, planets[i].resources);
    }
}

void travelToPlanet(Planet *planet) {
    printf("Traveling to %s... (Distance: %d light-years)\n", planet->name, planet->distance);
    printf("Resources collected: %d\n", planet->resources);
    printf("Thank you for exploring %s, the universe appreciates your courage!\n", planet->name);
}

int main() {
    srand(time(NULL)); // Initialize random number generator
    Planet planets[MAX_PLANETS];

    initializePlanets(planets); // Set up the planets
    int choice;

    while (1) {
        displayPlanets(planets); // Show available planets to the user
        printf("Select a planet to travel to (1-%d) or enter 0 to exit: ", MAX_PLANETS);
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for your journey through the cosmos! Until next time!\n");
            break; // Exit the program
        }
        if (choice < 1 || choice > MAX_PLANETS) {
            printf("Please choose a valid planet number.\n");
            continue; // Ask for input again
        }
        
        travelToPlanet(&planets[choice - 1]); // Travel to the chosen planet
    }

    return 0;
}