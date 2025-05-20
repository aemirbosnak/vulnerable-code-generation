//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_SHIPS 3
#define PLANET_NAME_LENGTH 20

typedef struct {
    char name[PLANET_NAME_LENGTH];
    int distance; // distance from current position
    int resources; // amount of resources available
} Planet;

typedef struct {
    char name[PLANET_NAME_LENGTH];
    int fuel; // units of fuel remaining
    int cargo; // current cargo capacity
} Spaceship;

void initialize_planets(Planet planets[]) {
    strcpy(planets[0].name, "Zypher");
    planets[0].distance = 10;
    planets[0].resources = 50;

    strcpy(planets[1].name, "Aethera");
    planets[1].distance = 30;
    planets[1].resources = 75;

    strcpy(planets[2].name, "Nexis");
    planets[2].distance = 40;
    planets[2].resources = 100;

    strcpy(planets[3].name, "Orionis");
    planets[3].distance = 25;
    planets[3].resources = 60;

    strcpy(planets[4].name, "Atlaris");
    planets[4].distance = 35;
    planets[4].resources = 80;

    printf("Planets initialized. Ready for exploration!\n");
}

void initialize_ships(Spaceship ships[]) {
    strcpy(ships[0].name, "Falcon");
    ships[0].fuel = 100;
    ships[0].cargo = 0;

    strcpy(ships[1].name, "Nebula");
    ships[1].fuel = 100;
    ships[1].cargo = 0;

    strcpy(ships[2].name, "Starlight");
    ships[2].fuel = 100;
    ships[2].cargo = 0;

    printf("Spaceships ready for launch!\n");
}

void travel_to_planet(Spaceship *ship, Planet *planet) {
    if (ship->fuel < planet->distance) {
        printf("Not enough fuel to reach %s. Please refuel.\n", planet->name);
        return;
    }
    
    ship->fuel -= planet->distance;
    ship->cargo += planet->resources;
    planet->resources = 0; // resources collected

    printf("Travelling to %s...\n", planet->name);
    printf("Arrived at %s. Resources collected: %d.\n", planet->name, ship->cargo);
}

void display_status(Spaceship *ship) {
    printf("Spaceship: %s\n", ship->name);
    printf("Fuel remaining: %d\n", ship->fuel);
    printf("Cargo capacity: %d\n", ship->cargo);
}

int main() {
    Planet planets[MAX_PLANETS];
    Spaceship ships[MAX_SHIPS];

    // Initialization
    initialize_planets(planets);
    initialize_ships(ships);

    int choice, ship_index = 0;

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Display spaceship status\n");
        printf("2. Travel to a planet\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_status(&ships[ship_index]);
                break;

            case 2:
                printf("Choose a planet to travel to:\n");
                for (int i = 0; i < MAX_PLANETS; i++) {
                    printf("%d. %s (Distance: %d, Resources: %d)\n", i + 1, planets[i].name, planets[i].distance, planets[i].resources);
                }
                printf("Enter planet number: ");
                int planet_choice;
                scanf("%d", &planet_choice);
                
                if (planet_choice < 1 || planet_choice > MAX_PLANETS) {
                    printf("Invalid planet selection. Please try again.\n");
                } else {
                    travel_to_planet(&ships[ship_index], &planets[planet_choice - 1]);
                }
                break;

            case 3:
                printf("Exiting. Safe travels, space explorer!\n");
                exit(0);

            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
}