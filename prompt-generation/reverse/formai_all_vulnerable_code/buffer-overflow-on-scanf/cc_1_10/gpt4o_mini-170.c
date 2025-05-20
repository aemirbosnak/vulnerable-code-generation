//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_SHIPS 5
#define MAX_RESOURCES 50

typedef struct {
    char name[20];
    int resources;
} Planet;

typedef struct {
    char name[20];
    int fuel;
    int capacity;
} Spaceship;

void initialize_planets(Planet planets[], int num_planets) {
    const char *planet_names[] = {"Zerlon", "Gorath", "Veltrax", "Jupiter", "Xandar", "Nimrath", "Zyphor", "Aerith", "Cestus", "Thalor"};
    srand(time(0));

    for(int i = 0; i < num_planets; i++) {
        strcpy(planets[i].name, planet_names[i]);
        planets[i].resources = rand() % MAX_RESOURCES;
    }
}

void initialize_spaceships(Spaceship ships[], int num_ships) {
    const char *ship_names[] = {"Falcon", "Starlight", "Nebula", "Quantum", "Pulsar"};
    
    for(int i = 0; i < num_ships; i++) {
        strcpy(ships[i].name, ship_names[i]);
        ships[i].fuel = rand() % 100 + 50; // Start with 50 to 149 fuel
        ships[i].capacity = rand() % 30 + 20; // Capacity between 20 and 49
    }
}

void display_planets(Planet planets[], int num_planets) {
    printf("Planets in the galaxy:\n");
    for(int i = 0; i < num_planets; i++) {
        printf("Planet: %s | Resources: %d\n", planets[i].name, planets[i].resources);
    }
}

void display_ships(Spaceship ships[], int num_ships) {
    printf("Available Spaceships:\n");
    for(int i = 0; i < num_ships; i++) {
        printf("Ship: %s | Fuel: %d | Capacity: %d\n", ships[i].name, ships[i].fuel, ships[i].capacity);
    }
}

int collect_resources(Planet *planet, int amount) {
    if (planet->resources < amount) {
        amount = planet->resources; // Take only what is available
    }
    planet->resources -= amount; // Deduct resources from planet
    return amount; // Total collected
}

void travel(Spaceship *ship, Planet *planet) {
    if (ship->fuel <= 0) {
        printf("You cannot travel! The ship has run out of fuel.\n");
        return;
    }
    
    ship->fuel -= 10; // Deduct fuel cost for travel
    int collected = collect_resources(planet, ship->capacity);
    printf("Traveling to planet %s...\n", planet->name);
    printf("Collected %d resources from %s.\n", collected, planet->name);
}

int main() {
    Planet planets[MAX_PLANETS];
    Spaceship ships[MAX_SHIPS];

    initialize_planets(planets, MAX_PLANETS);
    initialize_spaceships(ships, MAX_SHIPS);

    int choice, ship_index, planet_index;

    while (1) {
        printf("\nWelcome to the Galactic Exploration Console!\n");
        printf("1. View Planets\n");
        printf("2. View Spaceships\n");
        printf("3. Travel to a Planet\n");
        printf("4. Exit\n");
        printf("Please choose an action: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_planets(planets, MAX_PLANETS);
                break;
            case 2:
                display_ships(ships, MAX_SHIPS);
                break;
            case 3:
                printf("Select a ship (0-%d): ", MAX_SHIPS - 1);
                scanf("%d", &ship_index);
                if (ship_index < 0 || ship_index >= MAX_SHIPS) {
                    printf("Invalid ship selection.\n");
                    break;
                }
                printf("Select a planet (0-%d): ", MAX_PLANETS - 1);
                scanf("%d", &planet_index);
                if (planet_index < 0 || planet_index >= MAX_PLANETS) {
                    printf("Invalid planet selection.\n");
                    break;
                }
                travel(&ships[ship_index], &planets[planet_index]);
                break;
            case 4:
                printf("Exiting the Galactic Exploration Console.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}