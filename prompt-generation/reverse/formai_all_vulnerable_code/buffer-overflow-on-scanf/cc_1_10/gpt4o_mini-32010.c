//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_PATH_LENGTH 256

typedef struct {
    char name[50];
    char type[20];
    float distance; // Distance from the spaceship in light years
} Planet;

typedef struct {
    char shipName[50];
    int fuel;
    int speed; // speed in light years per year
    int currentIndex; // index in planets array being explored
} Spaceship;

void initializePlanets(Planet planets[MAX_PLANETS]) {
    strcpy(planets[0].name, "Zypher");
    strcpy(planets[0].type, "Gas Giant");
    planets[0].distance = 4.2;

    strcpy(planets[1].name, "Lunaris");
    strcpy(planets[1].type, "Rocky");
    planets[1].distance = 1.5;

    strcpy(planets[2].name, "AquaTerra");
    strcpy(planets[2].type, "Oceanic");
    planets[2].distance = 3.1;

    strcpy(planets[3].name, "Infernis");
    strcpy(planets[3].type, "Volcanic");
    planets[3].distance = 2.8;

    strcpy(planets[4].name, "Cryos");
    strcpy(planets[4].type, "Ice");
    planets[4].distance = 5.0;

    strcpy(planets[5].name, "Dune");
    strcpy(planets[5].type, "Desert");
    planets[5].distance = 3.5;

    strcpy(planets[6].name, "Elysium");
    strcpy(planets[6].type, "Garden");
    planets[6].distance = 6.7;

    strcpy(planets[7].name, "Melodia");
    strcpy(planets[7].type, "Harmonic");
    planets[7].distance = 7.4;

    strcpy(planets[8].name, "Oblivion");
    strcpy(planets[8].type, "Black Hole");
    planets[8].distance = 8.1;

    strcpy(planets[9].name, "Nova");
    strcpy(planets[9].type, "Star");
    planets[9].distance = 10.3;
}

void initializeSpaceship(Spaceship *ship, const char* name, int fuel, int speed) {
    strcpy(ship->shipName, name);
    ship->fuel = fuel;
    ship->speed = speed;
    ship->currentIndex = 0;
}

void explorePlanet(Spaceship *ship, Planet *planet) {
    if (ship->fuel <= 0) {
        printf("Not enough fuel to explore further!\n");
        return;
    }

    ship->fuel -= (int)(planet->distance / ship->speed);
    if (ship->fuel < 0) {
        printf("Insufficient fuel after expense!\n");
        ship->fuel = 0;
        return;
    }
    
    printf("Exploring %s (%s): Distance = %.2f light years\n", planet->name, planet->type, planet->distance);
    printf("Remaining Fuel: %d\n", ship->fuel);
}

void printStatus(const Spaceship *ship) {
    printf("Spaceship: %s | Fuel: %d | Speed: %d light years/year\n", ship->shipName, ship->fuel, ship->speed);
}

void travelToNextPlanet(Spaceship *ship, Planet planets[MAX_PLANETS]) {
    if (ship->currentIndex >= MAX_PLANETS) {
        printf("All planets explored!\n");
        return;
    }

    explorePlanet(ship, &planets[ship->currentIndex]);
    ship->currentIndex++;
}

int main() {
    srand(time(NULL));
    
    Planet planets[MAX_PLANETS];
    initializePlanets(planets);
    
    Spaceship ship;
    initializeSpaceship(&ship, "Star Voyager", 100, rand() % 10 + 1);
    
    printStatus(&ship);
    
    while (ship.currentIndex < MAX_PLANETS) {
        char choice;
        printf("Ready to travel to the next planet? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'y') {
            travelToNextPlanet(&ship, planets);
        } else {
            printf("Mission aborted. Returning to base.\n");
            break;
        }
    }

    if (ship.fuel > 0) {
        printf("Mission accomplished. Returning to base with %d fuel remaining.\n", ship.fuel);
    } else {
        printf("Fuel exhausted. Emergency landing required!\n");
    }

    return 0;
}