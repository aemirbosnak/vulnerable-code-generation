//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PLANETS 5
#define MAX_SHIPS 3
#define MAX_COMMANDS 4
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int distance; // Distance from starting point in light years
    int resource_value; // Amount of resources on the planet
} Planet;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int fuel; // Fuel left in the spaceship
    int resources_collected; // Resources collected during the adventure
} Spaceship;

void initialize_planets(Planet planets[]) {
    strcpy(planets[0].name, "Zyphor");
    planets[0].distance = 30;
    planets[0].resource_value = 100;

    strcpy(planets[1].name, "Galoria");
    planets[1].distance = 50;
    planets[1].resource_value = 150;

    strcpy(planets[2].name, "Thranos");
    planets[2].distance = 100;
    planets[2].resource_value = 200;

    strcpy(planets[3].name, "Aurelia");
    planets[3].distance = 75;
    planets[3].resource_value = 180;

    strcpy(planets[4].name, "Nibiru");
    planets[4].distance = 20;
    planets[4].resource_value = 80;
}

void initialize_spaceships(Spaceship ships[]) {
    strcpy(ships[0].name, "Starhawk");
    ships[0].fuel = 100;
    ships[0].resources_collected = 0;

    strcpy(ships[1].name, "Falcon-x");
    ships[1].fuel = 120;
    ships[1].resources_collected = 0;

    strcpy(ships[2].name, "Nova-7");
    ships[2].fuel = 90;
    ships[2].resources_collected = 0;
}

void display_planets(Planet planets[]) {
    printf("Available Planets:\n");
    for(int i = 0; i < MAX_PLANETS; i++) {
        printf("%d. %s - Distance: %d Ly, Resources: %d\n", 
               i + 1, planets[i].name, planets[i].distance, planets[i].resource_value);
    }
}

void display_spaceships(Spaceship ships[]) {
    printf("Available Spaceships:\n");
    for(int i = 0; i < MAX_SHIPS; i++) {
        printf("%d. %s - Fuel: %d, Resources Collected: %d\n", 
               i + 1, ships[i].name, ships[i].fuel, ships[i].resources_collected);
    }
}

void travel_to_planet(Spaceship *ship, Planet *planet) {
    if (ship->fuel >= planet->distance) {
        ship->fuel -= planet->distance;
        ship->resources_collected += planet->resource_value;
        printf("Traveling to %s...\n", planet->name);
        sleep(2);
        printf("You've arrived at %s! Resources collected: %d\n", 
               planet->name, planet->resource_value);
    } else {
        printf("Not enough fuel to reach %s! Fuel required: %d\n", 
               planet->name, planet->distance);
    }
}

void adventure(Planet planets[], Spaceship ships[]) {
    int choice;
    
    display_spaceships(ships);
    printf("Select a spaceship (1-%d): ", MAX_SHIPS);
    scanf("%d", &choice);
    if (choice < 1 || choice > MAX_SHIPS) {
        printf("Invalid choice, terminating adventure.\n");
        return;
    }
    Spaceship *selected_ship = &ships[choice - 1];

    while (1) {
        display_planets(planets);
        printf("Choose your destination planet (1-%d, 0 to exit): ", MAX_PLANETS);
        scanf("%d", &choice);
        if (choice == 0) {
            printf("Ending the adventure. You gathered %d resources!\n", selected_ship->resources_collected);
            break;
        } else if (choice < 1 || choice > MAX_PLANETS) {
            printf("Invalid choice, please select again.\n");
            continue;
        }
        travel_to_planet(selected_ship, &planets[choice - 1]);
    }
}

int main() {
    Planet planets[MAX_PLANETS];
    Spaceship ships[MAX_SHIPS];

    printf("Welcome to the Intergalactic Adventure!\n");
    initialize_planets(planets);
    initialize_spaceships(ships);

    adventure(planets, ships);

    return 0;
}