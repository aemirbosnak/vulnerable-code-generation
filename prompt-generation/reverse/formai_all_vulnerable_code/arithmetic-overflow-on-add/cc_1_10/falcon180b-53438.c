//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 100
#define MAX_ITEMS 100
#define MAX_ENEMIES 100

typedef struct {
    char name[100];
    char description[500];
    int item;
    int enemy;
    int connected[4];
} Room;

typedef struct {
    char name[100];
    int power;
} Item;

typedef struct {
    char name[100];
    int attack;
    int defense;
} Enemy;

int num_rooms = 0;
int num_items = 0;
int num_enemies = 0;

Room rooms[MAX_ROOMS];
Item items[MAX_ITEMS];
Enemy enemies[MAX_ENEMIES];

void generate_room() {
    rooms[num_rooms].name[0] = '\0';
    printf("Enter room name: ");
    scanf("%s", rooms[num_rooms].name);

    rooms[num_rooms].description[0] = '\0';
    printf("Enter room description: ");
    scanf("%[^\n]", rooms[num_rooms].description);

    rooms[num_rooms].item = -1;
    printf("Enter item in room (0 if none): ");
    scanf("%d", &rooms[num_rooms].item);

    rooms[num_rooms].enemy = -1;
    printf("Enter enemy in room (0 if none): ");
    scanf("%d", &rooms[num_rooms].enemy);

    int i, j;
    for (i = 0; i < 4; i++) {
        printf("Enter direction to connect (0-%d): ", num_rooms - 1);
        scanf("%d", &j);
        rooms[num_rooms].connected[i] = j;
    }

    num_rooms++;
}

void generate_item() {
    items[num_items].name[0] = '\0';
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    items[num_items].power = rand() % 100;
    printf("Item power: %d\n", items[num_items].power);

    num_items++;
}

void generate_enemy() {
    enemies[num_enemies].name[0] = '\0';
    printf("Enter enemy name: ");
    scanf("%s", enemies[num_enemies].name);

    enemies[num_enemies].attack = rand() % 100;
    printf("Enemy attack: %d\n", enemies[num_enemies].attack);

    enemies[num_enemies].defense = rand() % 100;
    printf("Enemy defense: %d\n", enemies[num_enemies].defense);

    num_enemies++;
}

int main() {
    srand(time(NULL));

    printf("Enter number of rooms: ");
    scanf("%d", &num_rooms);

    printf("Enter number of items: ");
    scanf("%d", &num_items);

    printf("Enter number of enemies: ");
    scanf("%d", &num_enemies);

    for (int i = 0; i < num_rooms; i++) {
        generate_room();
    }

    for (int i = 0; i < num_items; i++) {
        generate_item();
    }

    for (int i = 0; i < num_enemies; i++) {
        generate_enemy();
    }

    return 0;
}