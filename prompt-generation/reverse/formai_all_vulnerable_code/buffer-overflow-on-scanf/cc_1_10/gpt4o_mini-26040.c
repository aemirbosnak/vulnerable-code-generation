//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_SHIPS 5
#define MAX_ENEMIES 3

typedef struct {
    char name[30];
    int fuel;
    int armor;
    int firepower;
} SpaceShip;

typedef struct {
    char name[30];
    int distance;
    int resources;
} Planet;

void initializePlanet(Planet *planet, const char *name, int distance, int resources) {
    snprintf(planet->name, sizeof(planet->name), "%s", name);
    planet->distance = distance;
    planet->resources = resources;
}

void initializeShip(SpaceShip *ship, const char *name, int fuel, int armor, int firepower) {
    snprintf(ship->name, sizeof(ship->name), "%s", name);
    ship->fuel = fuel;
    ship->armor = armor;
    ship->firepower = firepower;
}

void printSpaceshipStatus(SpaceShip *ship) {
    printf("Ship: %s\n", ship->name);
    printf("Fuel: %d\n", ship->fuel);
    printf("Armor: %d\n", ship->armor);
    printf("Firepower: %d\n", ship->firepower);
}

void planetDetails(Planet *planet) {
    printf("Exploring Planet: %s\n", planet->name);
    printf("Distance from your location: %dkm\n", planet->distance);
    printf("Resources available: %d\n", planet->resources);
}

void encounterEnemies(SpaceShip *ship) {
    printf("WARNING: Enemies detected!\n");
    for (int i = 0; i < MAX_ENEMIES; i++) {
        int enemyPower = rand() % 5 + 1;
        printf("Enemy Ship %d with firepower %d approaching!\n", i + 1, enemyPower);
        if (ship->firepower > enemyPower) {
            printf("You have defeated Enemies!\n");
        } else {
            ship->armor -= enemyPower;
            printf("You received damage! Remaining Armor: %d\n", ship->armor);
            if (ship->armor <= 0) {
                printf("Your ship has been destroyed! GAME OVER.\n");
                exit(0);
            }
        }
    }
}

void travelToPlanet(SpaceShip *ship, Planet *planet) {
    if (ship->fuel < planet->distance) {
        printf("INSUFFICIENT FUEL to travel to %s!\n", planet->name);
    } else {
        ship->fuel -= planet->distance;
        printf("Traveling to %s...\n", planet->name);
        planetDetails(planet);
        encounterEnemies(ship);
    }
}

int main() {
    srand(time(NULL));
    
    SpaceShip ships[MAX_SHIPS];
    Planet planets[MAX_PLANETS];

    initializeShip(&ships[0], "Star Blazer", 100, 30, 25);
    initializeShip(&ships[1], "Cosmic Voyager", 80, 40, 35);
    initializeShip(&ships[2], "Galactic Hunter", 90, 25, 30);
    initializeShip(&ships[3], "Nebula Explorer", 75, 20, 20);
    initializeShip(&ships[4], "Astro Defender", 60, 35, 40);

    initializePlanet(&planets[0], "Zircon-9", 50, 200);
    initializePlanet(&planets[1], "Xenthar Prime", 70, 150);
    initializePlanet(&planets[2], "Vulcanus", 100, 300);
    initializePlanet(&planets[3], "Varlox", 60, 220);
    initializePlanet(&planets[4], "Echo-3", 80, 180);
    initializePlanet(&planets[5], "Neutron Valley", 90, 210);
    initializePlanet(&planets[6], "Inferno", 110, 230);
    initializePlanet(&planets[7], "Crystalia", 120, 240);
    initializePlanet(&planets[8], "Phantom-4", 40, 160);
    initializePlanet(&planets[9], "Stardust Bay", 30, 170);

    printf("***** WELCOME TO THE SPACE ADVENTURE GAME *****\n");
    printf("Choose your spaceship:\n");
    for (int i = 0; i < MAX_SHIPS; i++) {
        printf("%d. %s\n", i + 1, ships[i].name);
    }

    int choice;
    printf("Select your ship (1-%d): ", MAX_SHIPS);
    scanf("%d", &choice);
    
    if (choice < 1 || choice > MAX_SHIPS) {
        printf("Invalid choice! Try again.\n");
        return 1;
    }
    
    SpaceShip selectedShip = ships[choice - 1];
    printf("\nYou have selected %s.\n", selectedShip.name);

    while (1) {
        int planetChoice;
        printf("Available Planets to explore:\n");
        for (int i = 0; i < MAX_PLANETS; i++) {
            printf("%d. %s (Distance: %dkm)\n", i + 1, planets[i].name, planets[i].distance);
        }

        printf("Choose a planet to travel to (1-%d): ", MAX_PLANETS);
        scanf("%d", &planetChoice);

        if (planetChoice < 1 || planetChoice > MAX_PLANETS) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        travelToPlanet(&selectedShip, &planets[planetChoice - 1]);
    }

    return 0;
}