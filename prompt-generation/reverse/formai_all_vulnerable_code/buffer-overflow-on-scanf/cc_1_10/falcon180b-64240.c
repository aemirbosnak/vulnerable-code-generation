//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_ENEMIES 20
#define MAX_ITEMS 30

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
    int speed;
} Planet;

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
    int speed;
} Enemy;

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
    int speed;
} Item;

void generatePlanets(Planet planets[], int numPlanets) {
    for (int i = 0; i < numPlanets; i++) {
        sprintf(planets[i].name, "Planet %d", i + 1);
        planets[i].health = rand() % 100 + 1;
        planets[i].attack = rand() % 100 + 1;
        planets[i].defense = rand() % 100 + 1;
        planets[i].speed = rand() % 100 + 1;
    }
}

void generateEnemies(Enemy enemies[], int numEnemies) {
    for (int i = 0; i < numEnemies; i++) {
        sprintf(enemies[i].name, "Enemy %d", i + 1);
        enemies[i].health = rand() % 100 + 1;
        enemies[i].attack = rand() % 100 + 1;
        enemies[i].defense = rand() % 100 + 1;
        enemies[i].speed = rand() % 100 + 1;
    }
}

void generateItems(Item items[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        sprintf(items[i].name, "Item %d", i + 1);
        items[i].health = rand() % 100 + 1;
        items[i].attack = rand() % 100 + 1;
        items[i].defense = rand() % 100 + 1;
        items[i].speed = rand() % 100 + 1;
    }
}

int main() {
    srand(time(NULL));

    Planet planets[MAX_PLANETS];
    Enemy enemies[MAX_ENEMIES];
    Item items[MAX_ITEMS];

    int numPlanets, numEnemies, numItems;

    printf("Enter number of planets: ");
    scanf("%d", &numPlanets);

    printf("Enter number of enemies: ");
    scanf("%d", &numEnemies);

    printf("Enter number of items: ");
    scanf("%d", &numItems);

    generatePlanets(planets, numPlanets);
    generateEnemies(enemies, numEnemies);
    generateItems(items, numItems);

    return 0;
}