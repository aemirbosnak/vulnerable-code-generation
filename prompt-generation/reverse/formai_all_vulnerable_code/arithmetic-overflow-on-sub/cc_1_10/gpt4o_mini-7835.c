//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 20
#define MAX_SHIPS 5
#define MAX_PLANETS 10

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int power;
    int armor;
} Weapon;

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int durability;
    int cargo_capacity;
} Ship;

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int resources;
    int danger_level;
} Planet;

void initializeShips(Ship ships[]) {
    strcpy(ships[0].name, "Cyberhawk");
    ships[0].durability = 100;
    ships[0].cargo_capacity = 500;

    strcpy(ships[1].name, "Iron Comet");
    ships[1].durability = 120;
    ships[1].cargo_capacity = 600;
    
    strcpy(ships[2].name, "Neon Phantom");
    ships[2].durability = 80;
    ships[2].cargo_capacity = 300;

    strcpy(ships[3].name, "Galactic Voyager");
    ships[3].durability = 150;
    ships[3].cargo_capacity = 700;

    strcpy(ships[4].name, "Starlight Raider");
    ships[4].durability = 90;
    ships[4].cargo_capacity = 400;
}

void initializeWeapons(Weapon weapons[]) {
    strcpy(weapons[0].name, "Plasma Blaster");
    weapons[0].power = 50;
    weapons[0].armor = 10;

    strcpy(weapons[1].name, "Laser Cannon");
    weapons[1].power = 70;
    weapons[1].armor = 15;

    strcpy(weapons[2].name, "Ion Torpedo");
    weapons[2].power = 100;
    weapons[2].armor = 30;
}

void initializePlanets(Planet planets[]) {
    strcpy(planets[0].name, "Neon City");
    planets[0].resources = 200;
    planets[0].danger_level = 1;

    strcpy(planets[1].name, "Asteroid Belt");
    planets[1].resources = 150;
    planets[1].danger_level = 3;

    strcpy(planets[2].name, "Dark Zone");
    planets[2].resources = 50;
    planets[2].danger_level = 5;

    strcpy(planets[3].name, "Robotic Utopia");
    planets[3].resources = 250;
    planets[3].danger_level = 2;

    strcpy(planets[4].name, "Quantum Realm");
    planets[4].resources = 100;
    planets[4].danger_level = 4;
}

void travelToPlanet(Ship* ship, Planet* planet) {
    printf("Travelling to %s...\n", planet->name);
    if(ship->durability > planet->danger_level * 10) {
        printf("Safe journey to %s! Resources found: %d.\n", planet->name, planet->resources);
    } else {
        printf("Warning! Potentially dangerous journey suspected to %s. Take precautions!\n", planet->name);
    }
}

void generateRandomEvent() {
    int event = rand() % 3;
    switch(event) {
        case 0:
            printf("You encountered space pirates! Prepare for battle!\n");
            break;
        case 1:
            printf("An asteroid shower is approaching! Evasive maneuvers needed!\n");
            break;
        case 2:
            printf("You found a derelict ship with unknown technology!\n");
            break;
    }
}

void displayShipInfo(Ship* ship) {
    printf("Ship Name: %s\n", ship->name);
    printf("Durability: %d\n", ship->durability);
    printf("Cargo Capacity: %d\n", ship->cargo_capacity);
}

int main() {
    srand(time(NULL));

    Ship ships[MAX_SHIPS];
    Weapon weapons[MAX_ITEMS];
    Planet planets[MAX_PLANETS];

    initializeShips(ships);
    initializeWeapons(weapons);
    initializePlanets(planets);

    int choice;
    printf("Welcome to the Cyberpunk Space Adventure!\n");
    printf("Choose your ship:\n");
    for (int i = 0; i < MAX_SHIPS; i++) {
        printf("%d. %s (Durability: %d, Cargo: %d)\n", i + 1, ships[i].name, ships[i].durability, ships[i].cargo_capacity);
    }
    
    scanf("%d", &choice);
    Ship selected_ship = ships[choice - 1];

    int planet_choice;
    printf("Choose your destination:\n");
    for (int j = 0; j < 5; j++) {
        printf("%d. %s (Resources: %d, Danger Level: %d)\n", j + 1, planets[j].name, planets[j].resources, planets[j].danger_level);
    }

    scanf("%d", &planet_choice);
    travelToPlanet(&selected_ship, &planets[planet_choice - 1]);

    generateRandomEvent();
    
    displayShipInfo(&selected_ship);

    return 0;
}