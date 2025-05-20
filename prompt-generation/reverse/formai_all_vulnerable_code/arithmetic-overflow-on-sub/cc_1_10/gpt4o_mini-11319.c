//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SHIPS 10
#define MAX_PLANETS 5
#define NAME_LENGTH 30
#define SPACE 100

typedef struct {
    char name[NAME_LENGTH];
    int distance; // Distance from home base
    int ore_supply; // Ore available on the planet
} Planet;

typedef struct {
    char name[NAME_LENGTH];
    int fuel; // Current fuel
    int ore_collected;
} Ship;

Planet planets[MAX_PLANETS];
Ship ships[MAX_SHIPS];
int total_planets = 0, total_ships = 0, player_ship_index = -1;

void initialize_planets() {
    strcpy(planets[0].name, "Zorgon");
    planets[0].distance = 20;
    planets[0].ore_supply = 100;

    strcpy(planets[1].name, "Xenon");
    planets[1].distance = 40;
    planets[1].ore_supply = 200;

    strcpy(planets[2].name, "Tralnor");
    planets[2].distance = 70;
    planets[2].ore_supply = 150;

    strcpy(planets[3].name, "Naboo");
    planets[3].distance = 85;
    planets[3].ore_supply = 120;

    strcpy(planets[4].name, "Qorath");
    planets[4].distance = 30;
    planets[4].ore_supply = 300;

    total_planets = 5;
}

void create_ship() {
    if (total_ships >= MAX_SHIPS) {
        printf("Maximum number of ships already created.\n");
        return;
    }
    
    Ship new_ship;
    printf("Enter ship name: ");
    scanf("%s", new_ship.name);
    new_ship.fuel = SPACE; // Start with full fuel
    new_ship.ore_collected = 0;

    ships[total_ships++] = new_ship;
    player_ship_index = total_ships - 1; // Assign the new ship as the player's ship
    printf("Ship '%s' created successfully!\n", new_ship.name);
}

void display_planets() {
    printf("Available Planets:\n");
    for (int i = 0; i < total_planets; i++) {
        printf("%d. %s (Distance: %d, Ore Supply: %d)\n", i + 1, planets[i].name,
               planets[i].distance, planets[i].ore_supply);
    }
}

void display_ships() {
    printf("Current Ships:\n");
    for (int i = 0; i < total_ships; i++) {
        printf("%d. %s (Fuel: %d, Ore Collected: %d)\n", i + 1, ships[i].name,
               ships[i].fuel, ships[i].ore_collected);
    }
}

void travel_to_planet(int planet_index) {
    if (planet_index < 0 || planet_index >= total_planets) {
        printf("Invalid planet selection.\n");
        return;
    }

    int fuel_needed = planets[planet_index].distance;
    if (ships[player_ship_index].fuel < fuel_needed) {
        printf("Not enough fuel to travel to %s.\n", planets[planet_index].name);
        return;
    }

    ships[player_ship_index].fuel -= fuel_needed; // Deduct fuel
    printf("Traveling to %s...\n", planets[planet_index].name);
    printf("Arrived at %s. Collecting ore...\n", planets[planet_index].name);
    
    ships[player_ship_index].ore_collected += planets[planet_index].ore_supply;
    planets[planet_index].ore_supply = 0; // Ore is now collected
    printf("Collected all ore from %s. Current ore: %d\n", planets[planet_index].name, 
           ships[player_ship_index].ore_collected);
}

int main() {
    srand(time(NULL)); // Initialize random seed
    initialize_planets(); // Initialize planet data
    int option;

    do {
        printf("\n=== Space Adventure ===\n");
        printf("1. Create Ship\n2. Display Ships\n3. Display Planets\n");
        printf("4. Travel to a Planet\n5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                create_ship();
                break;
            case 2:
                display_ships();
                break;
            case 3:
                display_planets();
                break;
            case 4:
                if (player_ship_index == -1) {
                    printf("You need to create a ship first!\n");
                } else {
                    display_planets();
                    printf("Select planet index to travel: ");
                    int planet_index;
                    scanf("%d", &planet_index);
                    travel_to_planet(planet_index - 1);
                }
                break;
            case 5:
                printf("Exiting the game. Safe travels!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}