//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 50
#define MAX_ENEMIES 50
#define MAX_ITEMS 50

typedef struct {
    char name[50];
    int x, y;
    int health;
} Planet;

typedef struct {
    char name[50];
    int x, y;
    int health;
    int attack;
} Enemy;

typedef struct {
    char name[50];
    int x, y;
    int value;
} Item;

void generatePlanets(Planet planets[], int numPlanets) {
    for (int i = 0; i < numPlanets; i++) {
        planets[i].x = rand() % 1000;
        planets[i].y = rand() % 1000;
        planets[i].health = rand() % 100;
        sprintf(planets[i].name, "Planet %d", i + 1);
    }
}

void generateEnemies(Enemy enemies[], int numEnemies) {
    for (int i = 0; i < numEnemies; i++) {
        enemies[i].x = rand() % 1000;
        enemies[i].y = rand() % 1000;
        enemies[i].health = rand() % 100;
        enemies[i].attack = rand() % 50;
        sprintf(enemies[i].name, "Enemy %d", i + 1);
    }
}

void generateItems(Item items[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        items[i].x = rand() % 1000;
        items[i].y = rand() % 1000;
        items[i].value = rand() % 100;
        sprintf(items[i].name, "Item %d", i + 1);
    }
}

int main() {
    srand(time(NULL));

    Planet planets[MAX_PLANETS];
    Enemy enemies[MAX_ENEMIES];
    Item items[MAX_ITEMS];

    int numPlanets, numEnemies, numItems;
    scanf("%d %d %d", &numPlanets, &numEnemies, &numItems);

    generatePlanets(planets, numPlanets);
    generateEnemies(enemies, numEnemies);
    generateItems(items, numItems);

    // TODO: Implement space adventure game logic

    return 0;
}