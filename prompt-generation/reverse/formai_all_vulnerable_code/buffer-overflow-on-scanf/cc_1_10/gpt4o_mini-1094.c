//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_SOLDIERS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int role;  // 0: Pilot, 1: Engineer, 2: Medic
} Soldier;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hasEnemyBase;  // 1 if there's an enemy base
} Planet;

typedef struct {
    Planet planets[MAX_PLANETS];
    int planetCount;
} Galaxy;

void initializeGalaxy(Galaxy *galaxy);
void explorePlanet(Soldier *soldier, Galaxy *galaxy, int planetIndex);
void encounterEnemy(Soldier *soldier);
void healSoldier(Soldier *soldier);
void repairShip(Soldier *soldier);
void showStatus(Soldier *soldier);

int main() {
    srand(time(NULL));  // Seed random number generator
    Galaxy galaxy;
    Soldier soldiers[MAX_SOLDIERS];
    int soldierCount = 0;

    printf("Welcome to the Intergalactic Space Adventure!\n");
    printf("----------------------------------------------\n");

    // Initialize the galaxy with planets
    initializeGalaxy(&galaxy);

    // Create some soldiers
    printf("Enter the number of soldiers (Max %d): ", MAX_SOLDIERS);
    scanf("%d", &soldierCount);
    soldierCount = (soldierCount > MAX_SOLDIERS) ? MAX_SOLDIERS : soldierCount;

    for (int i = 0; i < soldierCount; i++) {
        printf("Enter name for soldier %d: ", i + 1);
        scanf("%s", soldiers[i].name);
        soldiers[i].role = rand() % 3;  // Randomly assign a role
    }

    // Explore the galaxy
    for (int i = 0; i < galaxy.planetCount; i++) {
        printf("\n** Exploring Planet: %s **\n", galaxy.planets[i].name);
        for (int j = 0; j < soldierCount; j++) {
            explorePlanet(&soldiers[j], &galaxy, i);
        }
    }

    return 0;
}

void initializeGalaxy(Galaxy *galaxy) {
    strcpy(galaxy->planets[0].name, "Zerthar");
    galaxy->planets[0].hasEnemyBase = rand() % 2;
    strcpy(galaxy->planets[1].name, "Plutonia");
    galaxy->planets[1].hasEnemyBase = rand() % 2;
    strcpy(galaxy->planets[2].name, "Nebulum");
    galaxy->planets[2].hasEnemyBase = rand() % 2;
    strcpy(galaxy->planets[3].name, "Qyxos");
    galaxy->planets[3].hasEnemyBase = rand() % 2;
    strcpy(galaxy->planets[4].name, "Xenora");
    galaxy->planets[4].hasEnemyBase = rand() % 2;

    galaxy->planetCount = MAX_PLANETS; 
}

void explorePlanet(Soldier *soldier, Galaxy *galaxy, int planetIndex) {
    printf("%s is exploring...\n", soldier->name);
    if (galaxy->planets[planetIndex].hasEnemyBase) {
        encounterEnemy(soldier);
    } else {
        printf("%s found resources on %s!\n", soldier->name, galaxy->planets[planetIndex].name);
    }
}

void encounterEnemy(Soldier *soldier) {
    printf("Oh no! %s encountered an enemy base!\n", soldier->name);
    
    int action = rand() % 3;  // Random action: 0: Attack, 1: Heal, 2: Repair
    switch (action) {
        case 0:
            printf("%s is attacking the enemy!\n", soldier->name);
            break;
        case 1:
            healSoldier(soldier);
            break;
        case 2:
            repairShip(soldier);
            break;
    }
    showStatus(soldier);
}

void healSoldier(Soldier *soldier) {
    printf("%s is healing...\n", soldier->name);
}

void repairShip(Soldier *soldier) {
    printf("%s is repairing the spaceship...\n", soldier->name);
}

void showStatus(Soldier *soldier) {
    printf("Status of %s (Role: %s) updated following the encounter!\n", soldier->name,
        (soldier->role == 0) ? "Pilot" : (soldier->role == 1) ? "Engineer" : "Medic");
}