//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10
#define NUM_ITEMS 5
#define NUM_ENEMIES 3

typedef struct {
    int x, y;
} Point;

typedef struct {
    char name[50];
    Point location;
} Room;

typedef struct {
    char name[50];
    Point location;
} Item;

typedef struct {
    char name[50];
    Point location;
} Enemy;

Room rooms[NUM_ROOMS];
Item items[NUM_ITEMS];
Enemy enemies[NUM_ENEMIES];

void generateMaze(int seed) {
    srand(seed);

    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].location.x = rand() % 20 + 1;
        rooms[i].location.y = rand() % 20 + 1;
    }

    for (int i = 0; i < NUM_ITEMS; i++) {
        items[i].location.x = rand() % 20 + 1;
        items[i].location.y = rand() % 20 + 1;
    }

    for (int i = 0; i < NUM_ENEMIES; i++) {
        enemies[i].location.x = rand() % 20 + 1;
        enemies[i].location.y = rand() % 20 + 1;
    }
}

void printMaze() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        printf("Room %d: %s\n", i + 1, rooms[i].name);
    }

    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("Item %d: %s\n", i + 1, items[i].name);
    }

    for (int i = 0; i < NUM_ENEMIES; i++) {
        printf("Enemy %d: %s\n", i + 1, enemies[i].name);
    }
}

int main() {
    int seed;

    printf("Enter a seed for the random number generator: ");
    scanf("%d", &seed);

    generateMaze(seed);
    printMaze();

    return 0;
}