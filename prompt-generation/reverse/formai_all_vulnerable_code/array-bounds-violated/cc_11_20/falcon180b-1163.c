//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 10
#define MAX_ENEMIES 10
#define MAX_PLAYERS 1

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
    int items[MAX_ITEMS];
    int num_items;
} Player;

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
} Enemy;

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
    int items[MAX_ITEMS];
    int num_items;
} Room;

int main() {
    srand(time(NULL));
    Player player;
    Enemy enemies[MAX_ENEMIES];
    Room rooms[MAX_ROOMS];

    player.health = 100;
    player.attack = 10;
    player.defense = 10;

    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].health = rand() % 50 + 1;
        enemies[i].attack = rand() % 20 + 1;
        enemies[i].defense = rand() % 20 + 1;
    }

    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].health = rand() % 50 + 1;
        rooms[i].attack = rand() % 20 + 1;
        rooms[i].defense = rand() % 20 + 1;
        rooms[i].num_items = rand() % MAX_ITEMS + 1;
        for (int j = 0; j < rooms[i].num_items; j++) {
            rooms[i].items[j] = rand() % 10 + 1;
        }
    }

    int choice;
    int room_index = 0;
    int enemy_index = 0;

    while (1) {
        printf("You are in room %d.\n", room_index + 1);
        printf("You have %d health, %d attack, and %d defense.\n", player.health, player.attack, player.defense);
        printf("You have the following items:\n");
        for (int i = 0; i < player.num_items; i++) {
            printf("%d ", player.items[i]);
        }
        printf("\n");

        printf("What would you like to do?\n");
        printf("1. Move to another room\n");
        printf("2. Attack an enemy\n");
        printf("3. Use an item\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            room_index = (room_index + 1) % MAX_ROOMS;
            break;
        case 2:
            enemy_index = (enemy_index + 1) % MAX_ENEMIES;
            if (player.attack > enemies[enemy_index].defense) {
                enemies[enemy_index].health -= player.attack;
            } else {
                player.health -= enemies[enemy_index].attack;
            }
            break;
        case 3:
            printf("Which item would you like to use?\n");
            scanf("%d", &choice);
            player.items[choice - 1]--;
            player.health += 10;
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}