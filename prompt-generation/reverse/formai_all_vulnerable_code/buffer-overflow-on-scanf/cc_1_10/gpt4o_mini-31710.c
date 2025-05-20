//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_SHIPS 3
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int distance;
} Planet;

typedef struct {
    char name[NAME_LENGTH];
    int speed;
    int fuel;
} SpaceShip;

void initializePlanets(Planet planets[]) {
    strcpy(planets[0].name, "Zeta Minor");
    planets[0].distance = rand() % 100 + 50; // Random distance between 50 and 150

    strcpy(planets[1].name, "Alpha Centauri");
    planets[1].distance = rand() % 200 + 150; // Distance between 150 and 350

    strcpy(planets[2].name, "Kappa 4");
    planets[2].distance = rand() % 300 + 100; // Distance between 100 and 400

    strcpy(planets[3].name, "Delta 9");
    planets[3].distance = rand() % 250 + 50; // Distance between 50 and 300

    strcpy(planets[4].name, "Epsilon Eridani");
    planets[4].distance = rand() % 400 + 200; // Distance between 200 and 600
}

void initializeShips(SpaceShip ships[]) {
    strcpy(ships[0].name, "Star Explorer");
    ships[0].speed = rand() % 20 + 30; // Speed between 30 and 50
    ships[0].fuel = 200;

    strcpy(ships[1].name, "Galactic Voyager");
    ships[1].speed = rand() % 25 + 25; // Speed between 25 and 50
    ships[1].fuel = 150;

    strcpy(ships[2].name, "Nebula Cruiser");
    ships[2].speed = rand() % 30 + 20; // Speed between 20 and 50
    ships[2].fuel = 300;
}

void travelToPlanet(SpaceShip* ship, Planet* planet) {
    int travel_time = planet->distance / ship->speed;

    if(ship->fuel <= travel_time * 10) {
        printf("Not enough fuel to reach %s!\n", planet->name);
    } else {
        ship->fuel -= travel_time * 10;
        printf("Traveling to %s, Estimated travel time: %d hours\n", planet->name, travel_time);
        printf("Arrived at %s! Fuel remaining: %d\n", planet->name, ship->fuel);
    }
}

void displayInfo(Planet* planets, SpaceShip* ships) {
    printf("\nAvailable Planets:\n");
    for(int i = 0; i < MAX_PLANETS; i++) {
        printf("Planet %d: %s, Distance: %d light years\n", i + 1, planets[i].name, planets[i].distance);
    }

    printf("\nAvailable Spacecrafts:\n");
    for(int i = 0; i < MAX_SHIPS; i++) {
        printf("Ship %d: %s, Speed: %d light years/hour, Fuel: %d\n", i + 1, ships[i].name, ships[i].speed, ships[i].fuel);
    }
}

int main() {
    srand(time(NULL));
    
    Planet planets[MAX_PLANETS];
    SpaceShip ships[MAX_SHIPS];

    initializePlanets(planets);
    initializeShips(ships);
    
    displayInfo(planets, ships);

    int choice_planet, choice_ship;
    printf("\nSelect a Ship by number (1-%d): ", MAX_SHIPS);
    scanf("%d", &choice_ship);
    
    if(choice_ship < 1 || choice_ship > MAX_SHIPS) {
        printf("Invalid choice of Ship!\n");
        return 1;
    }

    printf("Select a Planet to travel to (1-%d): ", MAX_PLANETS);
    scanf("%d", &choice_planet);
    
    if(choice_planet < 1 || choice_planet > MAX_PLANETS) {
        printf("Invalid choice of Planet!\n");
        return 1;
    }

    travelToPlanet(&ships[choice_ship - 1], &planets[choice_planet - 1]);

    return 0;
}