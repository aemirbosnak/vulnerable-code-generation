//Code Llama-13B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: funny
// Unique C Rogue-like Game with Procedural Generation example program in a funny style

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define constants
#define WIDTH 80
#define HEIGHT 25
#define MAX_ROOMS 20
#define MAX_OBJECTS 5
#define MAX_MONSTERS 5
#define MAX_ITEMS 5

// Define structures
typedef struct {
    int x, y;
    char type;
} object;

typedef struct {
    int x, y;
    char type;
    int health;
    int damage;
} monster;

typedef struct {
    int x, y;
    char type;
    int weight;
    int value;
} item;

typedef struct {
    object objects[MAX_OBJECTS];
    monster monsters[MAX_MONSTERS];
    item items[MAX_ITEMS];
} room;

// Define functions
void initialize_objects(object objects[], int n) {
    for (int i = 0; i < n; i++) {
        objects[i].x = rand() % WIDTH;
        objects[i].y = rand() % HEIGHT;
        objects[i].type = 'A' + rand() % 26;
    }
}

void initialize_monsters(monster monsters[], int n) {
    for (int i = 0; i < n; i++) {
        monsters[i].x = rand() % WIDTH;
        monsters[i].y = rand() % HEIGHT;
        monsters[i].type = 'A' + rand() % 26;
        monsters[i].health = 10 + rand() % 10;
        monsters[i].damage = 1 + rand() % 5;
    }
}

void initialize_items(item items[], int n) {
    for (int i = 0; i < n; i++) {
        items[i].x = rand() % WIDTH;
        items[i].y = rand() % HEIGHT;
        items[i].type = 'A' + rand() % 26;
        items[i].weight = 1 + rand() % 5;
        items[i].value = 10 + rand() % 10;
    }
}

void generate_room(room *room) {
    int n_objects = rand() % MAX_OBJECTS + 1;
    int n_monsters = rand() % MAX_MONSTERS + 1;
    int n_items = rand() % MAX_ITEMS + 1;

    initialize_objects(room->objects, n_objects);
    initialize_monsters(room->monsters, n_monsters);
    initialize_items(room->items, n_items);
}

void display_room(room *room) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            char c = ' ';

            if (room->objects[i].x == j && room->objects[i].y == i) {
                c = room->objects[i].type;
            } else if (room->monsters[i].x == j && room->monsters[i].y == i) {
                c = room->monsters[i].type;
            } else if (room->items[i].x == j && room->items[i].y == i) {
                c = room->items[i].type;
            }

            printf("%c", c);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    room rooms[MAX_ROOMS];

    for (int i = 0; i < MAX_ROOMS; i++) {
        generate_room(&rooms[i]);
        display_room(&rooms[i]);
    }

    return 0;
}