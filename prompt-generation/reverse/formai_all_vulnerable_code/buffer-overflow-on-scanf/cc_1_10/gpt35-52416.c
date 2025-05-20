//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_NAME_LENGTH 20

typedef struct Planet {
    char name[MAX_NAME_LENGTH];
    int distance;
} Planet;

void generate_planets(Planet planets[]) {
    char names[MAX_PLANETS][MAX_NAME_LENGTH] = { "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto", "Krypton" };

    // initialize random seed
    srand(time(NULL));

    // generate random planet distances
    for (int i = 0; i < MAX_PLANETS; i++) {
        strcpy(planets[i].name, names[i]);
        planets[i].distance = rand() % 100 + 1;
    }
}

void print_planets(Planet planets[]) {
    printf("Available planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%d. %s\tDistance: %d light years\n", i+1, planets[i].name, planets[i].distance);
    }
}

void travel_to_planet(Planet planet) {
    printf("\nTraveling to planet %s...\n", planet.name);
    printf("Arrived at %s.\n\n", planet.name);
}

int main() {
    // generate planets
    Planet planets[MAX_PLANETS];
    generate_planets(planets);

    // print planets
    print_planets(planets);

    // get user choice
    int choice;
    do {
        printf("Enter a number between 1 and %d to choose a planet to travel to (0 to quit): ", MAX_PLANETS);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= MAX_PLANETS) {
            travel_to_planet(planets[choice-1]);
        } else if (choice != 0) {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
    printf("Exiting program...\n");

    return 0;
}