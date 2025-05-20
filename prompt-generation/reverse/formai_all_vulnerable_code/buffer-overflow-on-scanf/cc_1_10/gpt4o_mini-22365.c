//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLANETS 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float distance_from_sun; // in millions of kilometers
    float size; // in kilometers
    float orbital_period; // in Earth days
} Planet;

void initializePlanets(Planet* planets) {
    strcpy(planets[0].name, "Mercury");
    planets[0].distance_from_sun = 57.91;
    planets[0].size = 4879;
    planets[0].orbital_period = 88;

    strcpy(planets[1].name, "Venus");
    planets[1].distance_from_sun = 108.2;
    planets[1].size = 12104;
    planets[1].orbital_period = 225;

    strcpy(planets[2].name, "Earth");
    planets[2].distance_from_sun = 149.6;
    planets[2].size = 12742;
    planets[2].orbital_period = 365;

    strcpy(planets[3].name, "Mars");
    planets[3].distance_from_sun = 227.9;
    planets[3].size = 6779;
    planets[3].orbital_period = 687;

    strcpy(planets[4].name, "Jupiter");
    planets[4].distance_from_sun = 778.6;
    planets[4].size = 139822;
    planets[4].orbital_period = 4331;

    strcpy(planets[5].name, "Saturn");
    planets[5].distance_from_sun = 1433.5;
    planets[5].size = 116464;
    planets[5].orbital_period = 10747;

    strcpy(planets[6].name, "Uranus");
    planets[6].distance_from_sun = 2872.5;
    planets[6].size = 50724;
    planets[6].orbital_period = 30688;

    strcpy(planets[7].name, "Neptune");
    planets[7].distance_from_sun = 4495.1;
    planets[7].size = 49244;
    planets[7].orbital_period = 60182;
}

void printPlanet(const Planet* planet) {
    printf("Name: %s\n", planet->name);
    printf("Distance from Sun: %.2f million km\n", planet->distance_from_sun);
    printf("Size: %.2f km\n", planet->size);
    printf("Orbital Period: %.2f days\n\n", planet->orbital_period);
}

void listPlanets(const Planet* planets, int number_of_planets) {
    printf("Planets in the Solar System:\n");
    for (int i = 0; i < number_of_planets; i++) {
        printf("%d. %s\n", i + 1, planets[i].name);
    }
}

int main() {
    Planet planets[MAX_PLANETS];
    initializePlanets(planets);

    int choice = 0;
    while (1) {
        printf("Enter the planet number to get more information (1 to %d), or 0 to exit: ", MAX_PLANETS);
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice > 0 && choice <= MAX_PLANETS) {
            printPlanet(&planets[choice - 1]);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Exiting the Solar System simulation. Goodbye!\n");
    return 0;
}