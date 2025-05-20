//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5
#define NUM_ITEMS 10
#define NUM_ENEMIES 5

typedef struct {
    char name[50];
    char description[200];
    int value;
} Item;

typedef struct {
    char name[50];
    char description[200];
    int attack;
    int defense;
} Enemy;

void generateItems() {
    Item items[NUM_ITEMS];
    int i;

    for (i = 0; i < NUM_ITEMS; i++) {
        items[i].name[0] = '\0';
        items[i].description[0] = '\0';
        items[i].value = rand() % 100;

        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", items[i].name);

        printf("Enter the description of item %d: ", i + 1);
        scanf("%[^\n]", items[i].description);
    }
}

void generateEnemies() {
    Enemy enemies[NUM_ENEMIES];
    int i;

    for (i = 0; i < NUM_ENEMIES; i++) {
        enemies[i].name[0] = '\0';
        enemies[i].description[0] = '\0';
        enemies[i].attack = rand() % 100;
        enemies[i].defense = rand() % 100;

        printf("Enter the name of enemy %d: ", i + 1);
        scanf("%s", enemies[i].name);

        printf("Enter the description of enemy %d: ", i + 1);
        scanf("%[^\n]", enemies[i].description);
    }
}

void generateRooms() {
    char rooms[NUM_ROOMS][200];
    int i;

    for (i = 0; i < NUM_ROOMS; i++) {
        rooms[i][0] = '\0';

        printf("Enter the description of room %d: ", i + 1);
        scanf("%[^\n]", rooms[i]);
    }
}

int main() {
    srand(time(NULL));

    generateItems();
    generateEnemies();
    generateRooms();

    return 0;
}