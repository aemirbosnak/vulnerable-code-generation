//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_PLAYERS 5
#define MAX_PLANETS 10
#define MAX_ITEMS 20
#define MAX_ENEMIES 10

typedef struct player {
    char name[20];
    int health;
    int score;
    int inventory[MAX_ITEMS];
} Player;

typedef struct planet {
    char name[20];
    int distance;
    int danger;
    int resources;
} Planet;

typedef struct item {
    char name[20];
    int value;
} Item;

typedef struct enemy {
    char name[20];
    int strength;
} Enemy;

void generatePlanets(Planet planets[], int numPlanets) {
    srand(time(NULL));
    for (int i = 0; i < numPlanets; i++) {
        planets[i].distance = rand() % 100;
        planets[i].danger = rand() % 10;
        planets[i].resources = rand() % 100;
        sprintf(planets[i].name, "Planet %d", i + 1);
    }
}

void generateItems(Item items[], int numItems) {
    srand(time(NULL));
    for (int i = 0; i < numItems; i++) {
        items[i].value = rand() % 100;
        sprintf(items[i].name, "Item %d", i + 1);
    }
}

void generateEnemies(Enemy enemies[], int numEnemies) {
    srand(time(NULL));
    for (int i = 0; i < numEnemies; i++) {
        enemies[i].strength = rand() % 100;
        sprintf(enemies[i].name, "Enemy %d", i + 1);
    }
}

int main() {
    int numPlayers, numPlanets, numItems, numEnemies;
    printf("How many players? ");
    scanf("%d", &numPlayers);
    printf("How many planets? ");
    scanf("%d", &numPlanets);
    printf("How many items? ");
    scanf("%d", &numItems);
    printf("How many enemies? ");
    scanf("%d", &numEnemies);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].health = 100;
        players[i].score = 0;
    }

    Planet planets[MAX_PLANETS];
    generatePlanets(planets, numPlanets);

    Item items[MAX_ITEMS];
    generateItems(items, numItems);

    Enemy enemies[MAX_ENEMIES];
    generateEnemies(enemies, numEnemies);

    return 0;
}