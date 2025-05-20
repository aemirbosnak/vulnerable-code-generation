//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for the game
#define MAX_PLANETS 5
#define MAX_SPACESHIPS 5
#define MAX_ACTIONS 5

// Structure to represent a spaceship
typedef struct {
    char name[20];
    int fuel;
    int shields;
    int attackPower;
} Spaceship;

// Structure to represent a planet
typedef struct {
    char name[30];
    char resource[30];
} Planet;

typedef struct {
    char* name;
    void (*action)(Spaceship*);
} Action;

// Function prototypes
void explore(Spaceship *ship);
void attack(Spaceship *ship);
void refuel(Spaceship *ship);
void displayStatus(Spaceship *ship);
void gameLoop(Spaceship *ship);

// Function to initialize spaceship
void initializeSpaceship(Spaceship *ship, const char *name) {
    strcpy(ship->name, name);
    ship->fuel = 100;
    ship->shields = 50;
    ship->attackPower = 20;
}

// Main function
int main() {
    Spaceship playerShip;
    initializeSpaceship(&playerShip, "Star Voyager");
    gameLoop(&playerShip);
    return 0;
}

// Function to display the spaceship status
void displayStatus(Spaceship *ship) {
    printf("\n--- Ship Status ---\n");
    printf("Name: %s\n", ship->name);
    printf("Fuel: %d\n", ship->fuel);
    printf("Shields: %d\n", ship->shields);
    printf("Attack Power: %d\n", ship->attackPower);
    printf("--------------------\n");
}

// Function to explore a random planet
void explore(Spaceship *ship) {
    if (ship->fuel <= 0) {
        printf("Not enough fuel to explore!\n");
        return;
    }

    ship->fuel -= 10;
    
    const char *planets[MAX_PLANETS] = {
        "Zyphoria - Rich in Crystals",
        "Pytronis - High Energy Source",
        "Quexar - Abundant Water",
        "Novacron - Ancient Technology",
        "Xelthar - Mysterious Anomalies"
    };

    int index = rand() % MAX_PLANETS;
    printf("Exploring planet: %s\n", planets[index]);
}

// Function to attack another spaceship
void attack(Spaceship *ship) {
    if (ship->fuel <= 0) {
        printf("Not enough fuel to attack!\n");
        return;
    }

    ship->fuel -= 15;
    printf("%s attacks with power %d!\n", ship->name, ship->attackPower);
}

// Function to refuel the spaceship
void refuel(Spaceship *ship) {
    if (ship->fuel >= 100) {
        printf("Fuel is already at maximum!\n");
        return;
    }

    printf("Refueling...\n");
    ship->fuel = 100;
}

// Game loop
void gameLoop(Spaceship *ship) {
    srand(time(NULL)); // Seed for random number generation
    int choice;

    while (1) {
        displayStatus(ship);
        printf("\nChoose an action:\n");
        printf("1. Explore\n");
        printf("2. Attack\n");
        printf("3. Refuel\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
          case 1:
              explore(ship);
              break;
          case 2:
              attack(ship);
              break;
          case 3:
              refuel(ship);
              break;
          case 4:
              printf("Quitting the game. Safe travels!\n");
              exit(0);
              break;
          default:
              printf("Invalid choice. Please try again.\n");
        }
    }
}