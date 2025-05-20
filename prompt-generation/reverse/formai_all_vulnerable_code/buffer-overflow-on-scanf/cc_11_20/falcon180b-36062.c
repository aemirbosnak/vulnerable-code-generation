//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10
#define NUM_ITEMS 5
#define NUM_ENEMIES 3

struct room {
    char name[50];
    int has_item;
    int has_enemy;
};

struct item {
    char name[50];
    int value;
};

struct enemy {
    char name[50];
    int strength;
};

int main() {
    srand(time(0));
    struct room rooms[NUM_ROOMS];
    struct item items[NUM_ITEMS];
    struct enemy enemies[NUM_ENEMIES];

    // Initialize rooms
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].has_item = rand() % 2;
        rooms[i].has_enemy = rand() % 2;
        sprintf(rooms[i].name, "Room %d", i + 1);
    }

    // Initialize items
    for (int i = 0; i < NUM_ITEMS; i++) {
        items[i].value = rand() % 100;
        sprintf(items[i].name, "Item %d", i + 1);
    }

    // Initialize enemies
    for (int i = 0; i < NUM_ENEMIES; i++) {
        enemies[i].strength = rand() % 50 + 1;
        sprintf(enemies[i].name, "Enemy %d", i + 1);
    }

    int player_strength = 100;
    int player_items = 0;
    int player_room = 0;

    while (player_strength > 0) {
        printf("\nYou are in Room %s.\n", rooms[player_room].name);

        if (rooms[player_room].has_item) {
            printf("You found an item: %s (value: %d)\n", items[player_items].name, items[player_items].value);
            player_items++;
        }

        if (rooms[player_room].has_enemy) {
            printf("You encountered an enemy: %s (strength: %d)\n", enemies[rand() % NUM_ENEMIES].name, enemies[rand() % NUM_ENEMIES].strength);
            if (enemies[rand() % NUM_ENEMIES].strength > player_strength) {
                printf("You died.\n");
                return 0;
            } else {
                player_strength -= enemies[rand() % NUM_ENEMIES].strength;
            }
        }

        printf("What do you want to do? ");
        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case'm':
                if (player_room > 0) {
                    player_room--;
                } else {
                    printf("You can't go back any further.\n");
                }
                break;
            case 'M':
                if (player_room < NUM_ROOMS - 1) {
                    player_room++;
                } else {
                    printf("You reached the end.\n");
                }
                break;
            case 'q':
                printf("You quit the game.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}