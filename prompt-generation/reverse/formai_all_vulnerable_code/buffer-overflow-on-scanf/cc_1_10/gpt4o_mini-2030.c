//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLANETS 8
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    float distance_from_sun; // in million km
    float orbit_speed;       // in km/s
    float diameter;          // in km
} Planet;

void print_planet_info(Planet planet) {
    printf("Planet Information:\n");
    printf("Name: %s\n", planet.name);
    printf("Distance from Sun: %.2f million km\n", planet.distance_from_sun);
    printf("Orbit Speed: %.2f km/s\n", planet.orbit_speed);
    printf("Diameter: %.2f km\n", planet.diameter);
    printf("-----------------------------------------\n");
}

int main() {
    Planet solar_system[MAX_PLANETS] = {
        {"Mercury", 57.91, 47.87, 4879},
        {"Venus", 108.2, 35.02, 12104},
        {"Earth", 149.6, 29.78, 12742},
        {"Mars", 227.9, 24.07, 6779},
        {"Jupiter", 778.5, 13.07, 139820},
        {"Saturn", 1429, 9.69, 116460},
        {"Uranus", 2871, 6.81, 50724},
        {"Neptune", 4497.1, 5.43, 49244}
    };

    int i;
    char choice[NAME_LENGTH];

    printf("Welcome to the Solar System Simulation!\n");
    printf("You can learn about the planets in our solar system.\n");
    printf("Type the name of a planet to learn more about it, or 'exit' to quit.\n");

    while (1) {
        printf("Enter planet name: ");
        scanf("%s", choice);

        // To lowercase for easier comparison
        for (i = 0; choice[i]; i++) {
            choice[i] = tolower(choice[i]);
        }

        if (strcmp(choice, "exit") == 0) {
            printf("Exiting the program. Thank you for exploring the Solar System!\n");
            break;
        }

        int found = 0;
        for (i = 0; i < MAX_PLANETS; i++) {
            if (strcasecmp(choice, solar_system[i].name) == 0) {
                print_planet_info(solar_system[i]);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Planet '%s' not found! Please try again.\n", choice);
        }
    }

    return 0;
}