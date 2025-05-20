//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_ALIENS 100
#define MAX_ITEMS 50

typedef struct planet {
    char name[50];
    int population;
    int resources;
} Planet;

typedef struct alien {
    char name[50];
    int health;
    int strength;
} Alien;

typedef struct item {
    char name[50];
    int value;
    int weight;
} Item;

void generatePlanets(Planet planets[], int numPlanets) {
    srand(time(NULL));
    for (int i = 0; i < numPlanets; i++) {
        sprintf(planets[i].name, "Planet %d", i + 1);
        planets[i].population = rand() % 1000 + 1;
        planets[i].resources = rand() % 1000 + 1;
    }
}

void generateAliens(Alien aliens[], int numAliens) {
    srand(time(NULL));
    for (int i = 0; i < numAliens; i++) {
        sprintf(aliens[i].name, "Alien %d", i + 1);
        aliens[i].health = rand() % 100 + 1;
        aliens[i].strength = rand() % 100 + 1;
    }
}

void generateItems(Item items[], int numItems) {
    srand(time(NULL));
    for (int i = 0; i < numItems; i++) {
        sprintf(items[i].name, "Item %d", i + 1);
        items[i].value = rand() % 1000 + 1;
        items[i].weight = rand() % 100 + 1;
    }
}

int main() {
    Planet planets[MAX_PLANETS];
    Alien aliens[MAX_ALIENS];
    Item items[MAX_ITEMS];

    int numPlanets, numAliens, numItems;

    printf("Enter the number of planets: ");
    scanf("%d", &numPlanets);

    printf("Enter the number of aliens: ");
    scanf("%d", &numAliens);

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    generatePlanets(planets, numPlanets);
    generateAliens(aliens, numAliens);
    generateItems(items, numItems);

    return 0;
}