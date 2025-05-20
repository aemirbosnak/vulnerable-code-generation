//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_ENEMIES 5

typedef struct {
    char name[20];
    int treasure;
    int enemyCount;
} Planet;

typedef struct {
    char name[20];
    int health;
    int damage;
} Enemy;

Planet planets[MAX_PLANETS];
Enemy enemies[MAX_ENEMIES];

void initializePlanets() {
    for (int i = 0; i < MAX_PLANETS; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "Planet %d", i + 1);
        planets[i].treasure = rand() % 100 + 1; // Random treasure between 1 and 100
        planets[i].enemyCount = rand() % (MAX_ENEMIES + 1); // Random enemies up to MAX_ENEMIES
    }
}

void initializeEnemies() {
    const char* enemyNames[] = {"Zorg", "Xel'Naga", "Klonk", "Dread", "Scourge"};
    for (int i = 0; i < MAX_ENEMIES; i++) {
        snprintf(enemies[i].name, sizeof(enemies[i].name), "%s", enemyNames[i]);
        enemies[i].health = rand() % 50 + 50; // Enemy health between 50 and 100
        enemies[i].damage = rand() % 20 + 5; // Enemy damage between 5 and 25
    }
}

void explorePlanet(int planetIndex) {
    printf("You have arrived at %s!\n", planets[planetIndex].name);
    printf("Treasure found: %d\n", planets[planetIndex].treasure);
    printf("Enemies present: %d\n", planets[planetIndex].enemyCount);

    if (planets[planetIndex].enemyCount > 0) {
        printf("Prepare for battle!\n");
        for (int i = 0; i < planets[planetIndex].enemyCount; i++) {
            int enemyIndex = rand() % MAX_ENEMIES;
            printf("Encountered enemy: %s (Health: %d, Damage: %d)\n", enemies[enemyIndex].name, enemies[enemyIndex].health, enemies[enemyIndex].damage);
        }
    } else {
        printf("No enemies here, you can safely collect the treasure!\n");
    }
    printf("You leave %s with a sense of adventure!\n", planets[planetIndex].name);
}

int main() {
    srand(time(NULL)); // Initialize random seed
    int continueExploring = 1;

    initializePlanets();
    initializeEnemies();

    printf("** Welcome to the Space Adventure! **\n");

    while (continueExploring) {
        int selectedPlanet;
        printf("Choose a planet to explore (1-%d) or 0 to Exit: ", MAX_PLANETS);
        scanf("%d", &selectedPlanet);

        if (selectedPlanet == 0) {
            continueExploring = 0;
            printf("Thanks for playing! Until next time, brave explorer!\n");
        } else if (selectedPlanet < 1 || selectedPlanet > MAX_PLANETS) {
            printf("Invalid selection! Please choose a valid planet.\n");
        } else {
            explorePlanet(selectedPlanet - 1); // Adjust index from 1-based to 0-based
        }
    }

    return 0;
}