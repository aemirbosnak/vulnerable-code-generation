//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_MONSTERS 10
#define MAX_ITEMS 10

typedef struct {
    int x, y;
} Vector2D;

typedef struct {
    char symbol;
    int color;
} Cell;

typedef struct {
    Vector2D position;
    int health;
    int attack;
    int defense;
} Creature;

typedef struct {
    Vector2D position;
    int value;
} Item;

Cell* generateMap();
void printMap(Cell* map);
void generateItems(Item* items);
void generateMonsters(Creature* monsters);

int main() {
    srand(time(0));

    Cell* map = generateMap();
    printMap(map);

    Item* items = malloc(sizeof(Item) * MAX_ITEMS);
    generateItems(items);

    Creature* monsters = malloc(sizeof(Creature) * MAX_MONSTERS);
    generateMonsters(monsters);

    return 0;
}

Cell* generateMap() {
    Cell* map = malloc(sizeof(Cell) * MAP_WIDTH * MAP_HEIGHT);

    for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
        map[i].symbol = rand() % 2? '#' : '.';
        map[i].color = rand() % 8;
    }

    return map;
}

void printMap(Cell* map) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[y * MAP_WIDTH + x].symbol);
        }
        printf("\n");
    }
}

void generateItems(Item* items) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].position.x = rand() % MAP_WIDTH;
        items[i].position.y = rand() % MAP_HEIGHT;
        items[i].value = rand() % 100;
    }
}

void generateMonsters(Creature* monsters) {
    for (int i = 0; i < MAX_MONSTERS; i++) {
        monsters[i].position.x = rand() % MAP_WIDTH;
        monsters[i].position.y = rand() % MAP_HEIGHT;
        monsters[i].health = rand() % 100;
        monsters[i].attack = rand() % 100;
        monsters[i].defense = rand() % 100;
    }
}