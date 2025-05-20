//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_HEALTH 100
#define MAX_FUEL 100
#define MAX_ENEMIES 5
#define MAX_PLANETS 10
#define MAX_RESOURCES 3

// Define structs
typedef struct {
    char name[20];
    int health;
    int fuel;
    int resources[MAX_RESOURCES];
} Spaceship;

typedef struct {
    char name[20];
    int enemyHealth;
    int resources[MAX_RESOURCES];
} Enemy;

typedef struct {
    char name[20];
    int resourceValue[MAX_RESOURCES];
} Planet;

// Declare functions
void initializeSpaceship(Spaceship *ship);
void initializeEnemies(Enemy enemies[], int numEnemies);
void initializePlanets(Planet planets[], int numPlanets);
void printSpaceshipStatus(Spaceship *ship);
void printEnemyStatus(Enemy *enemy);
void printPlanetStatus(Planet *planet);
void travelToPlanet(Spaceship *ship, Planet *planet);
void encounterEnemy(Spaceship *ship, Enemy *enemy);
void collectResources(Spaceship *ship, Planet *planet);
void tradeResources(Spaceship *ship, Planet *planet);
void endGame(Spaceship *ship);

int main() {
    srand(time(NULL)); // Seed random number generator

    Spaceship ship;
    initializeSpaceship(&ship); // Initialize spaceship
    
    Planet planets[MAX_PLANETS];
    initializePlanets(planets, MAX_PLANETS); // Initialize planets
    
    Enemy enemies[MAX_ENEMIES];
    initializeEnemies(enemies, MAX_ENEMIES); // Initialize enemies
    
    int choice;
    while (ship.health > 0 && ship.fuel > 0) { // Game loop
        printf("What would you like to do?\n");
        printf("1. Travel to another planet\n");
        printf("2. Encounter an enemy\n");
        printf("3. Collect resources from current planet\n");
        printf("4. Trade resources with current planet\n");
        printf("5. End game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                srand(time(NULL)); // Reseed random number generator for travel
                Planet destination = planets[rand() % MAX_PLANETS];
                travelToPlanet(&ship, &destination);
                break;
            case 2:
                if (rand() % 2 == 0) { // 50% chance of encountering enemy
                    Enemy enemy = enemies[rand() % MAX_ENEMIES];
                    encounterEnemy(&ship, &enemy);
                } else {
                    printf("No enemy encountered.\n");
                }
                break;
            case 3:
                collectResources(&ship, &planets[0]); // Only one planet
                break;
            case 4:
                tradeResources(&ship, &planets[0]); // Only one planet
                break;
            case 5:
                endGame(&ship);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }

        printf("\n");
        printSpaceshipStatus(&ship);
        printf("\n");
    }

    endGame(&ship); // Game over
    return 0;
}

void initializeSpaceship(Spaceship *ship) {
    printf("Initializing spaceship...\n");
    printf("What would you like to name your spaceship?: ");
    scanf("%s", ship->name);
    ship->health = MAX_HEALTH;
    ship->fuel = MAX_FUEL;
    for (int i = 0; i < MAX_RESOURCES; i++) {
        ship->resources[i] = 0;
    }
    printf("Spaceship initialized.\n");
    printSpaceshipStatus(ship);
}

void initializeEnemies(Enemy enemies[], int numEnemies) {
    printf("Initializing enemies...\n");
    for (int i = 0; i < numEnemies; i++) {
        sprintf(enemies[i].name, "Enemy #%d", i+1);
        enemies[i].enemyHealth = rand() % MAX_HEALTH;
        for (int j = 0; j < MAX_RESOURCES; j++) {
            enemies[i].resources[j] = rand() % 10;
        }
        printf("Enemy #%d: Health = %d, Resources = [", i+1, enemies[i].enemyHealth);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%d", enemies[i].resources[j]);
            if (j < MAX_RESOURCES - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
    printf("Enemies initialized.\n");
}

void initializePlanets(Planet planets[], int numPlanets) {
    printf("Initializing planets...\n");
    for (int i = 0; i < numPlanets; i++) {
        sprintf(planets[i].name, "Planet #%d", i+1);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            planets[i].resourceValue[j] = rand() % 10 + 1; // Resources have value between 1 and 10
        }
        printf("Planet #%d: Resource Value = [", i+1);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%d", planets[i].resourceValue[j]);
            if (j < MAX_RESOURCES - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
    printf("Planets initialized.\n");
}

void printSpaceshipStatus(Spaceship *ship) {
    printf("%s - Health: %d / %d, Fuel: %d / %d, Resources: [", ship->name, ship->health, MAX_HEALTH, ship->fuel, MAX_FUEL);
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("%d", ship->resources[i]);
        if (i < MAX_RESOURCES - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void printEnemyStatus(Enemy *enemy) {
    printf("%s - Health: %d / %d, Resources: [", enemy->name, enemy->enemyHealth, MAX_HEALTH);
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("%d", enemy->resources[i]);
        if (i < MAX_RESOURCES - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void printPlanetStatus(Planet *planet) {
    printf("%s - Resource Value: [", planet->name);
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("%d", planet->resourceValue[i]);
        if (i < MAX_RESOURCES - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void travelToPlanet(Spaceship *ship, Planet *planet) {
    int fuelCost = rand() % 10 + 1; // Fuel cost between 1 and 10
    if (ship->fuel >= fuelCost) {
        printf("Traveling to %s...\n", planet->name);
        ship->fuel -= fuelCost;
        printPlanetStatus(planet);
    } else {
        printf("Not enough fuel to travel to %s!\n", planet->name);
    }
}

void encounterEnemy(Spaceship *ship, Enemy *enemy) {
    printf("Encountering enemy %s...\n", enemy->name);
    printEnemyStatus(enemy);
    while (ship->health > 0 && enemy->enemyHealth > 0) {
        int shipAttack = rand() % 10 + 1; // Ship attack between 1 and 10
        int enemyAttack = rand() % 10 + 1; // Enemy attack between 1 and 10
        printf("%s took %d damage!\n", ship->name, enemyAttack);
        ship->health -= enemyAttack;
        printf("%s took %d damage!\n", enemy->name, shipAttack);
        enemy->enemyHealth -= shipAttack;
    }
    if (ship->health <= 0) {
        printf("%s was defeated! Game over.\n", ship->name);
    } else {
        printf("Enemy %s was defeated! Collecting resources...\n", enemy->name);
        for (int i = 0; i < MAX_RESOURCES; i++) {
            ship->resources[i] += enemy->resources[i];
        }
    }
}

void collectResources(Spaceship *ship, Planet *planet) {
    printf("Collecting resources from %s...\n", planet->name);
    for (int i = 0; i < MAX_RESOURCES; i++) {
        ship->resources[i] += planet->resourceValue[i];
    }
}

void tradeResources(Spaceship *ship, Planet *planet) {
    printf("Trading resources at %s...\n", planet->name);
    for (int i = 0; i < MAX_RESOURCES; i++) {
        int tradeQuantity;
        printf("How many units of resource %d do you want to trade?: ", i+1);
        scanf("%d", &tradeQuantity);
        if (tradeQuantity <= ship->resources[i]) {
            int tradeValue = tradeQuantity * planet->resourceValue[i];
            ship->resources[i] -= tradeQuantity;
            ship->fuel += tradeValue; // Trade value converted to fuel
            printf("Traded %d units of resource %d for %d fuel.\n", tradeQuantity, i+1, tradeValue);
        } else {
            printf("Not enough resource %d!\n", i+1);
        }
    }
}

void endGame(Spaceship *ship) {
    printf("Game over.\n");
    printf("%s - Final Status: Health: %d / %d, Fuel: %d / %d, Resources: [", ship->name, ship->health, MAX_HEALTH, ship->fuel, MAX_FUEL);
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("%d", ship->resources[i]);
        if (i < MAX_RESOURCES - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}