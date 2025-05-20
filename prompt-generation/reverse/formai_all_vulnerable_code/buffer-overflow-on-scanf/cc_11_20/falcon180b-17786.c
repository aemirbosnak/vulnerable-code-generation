//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 20
#define MAX_ENEMIES 30

typedef struct {
    char *name;
    char *description;
    int items[MAX_ITEMS];
    int enemies[MAX_ENEMIES];
} Room;

typedef struct {
    char *name;
    char *description;
} Item;

typedef struct {
    char *name;
    int health;
    int attack;
} Enemy;

int main() {
    srand(time(NULL));

    Room rooms[MAX_ROOMS];
    Item items[MAX_ITEMS];
    Enemy enemies[MAX_ENEMIES];

    int num_rooms = 0;
    int num_items = 0;
    int num_enemies = 0;

    Room *start_room = &rooms[num_rooms++];
    start_room->name = "Start Room";
    start_room->description = "You are in the start room. There is a door to the east.";
    start_room->items[0] = num_items;
    items[num_items++] = (Item){.name = "Key",.description = "A rusty old key." };

    Room *end_room = &rooms[num_rooms++];
    end_room->name = "End Room";
    end_room->description = "You have reached the end of the adventure! Congratulations!";

    Enemy *goblin = &enemies[num_enemies++];
    goblin->name = "Goblin";
    goblin->health = 10;
    goblin->attack = 5;

    int player_health = 20;
    int player_attack = 10;

    int current_room = 0;

    while (current_room!= num_rooms - 1) {
        printf("You are in room %s.\n", rooms[current_room].description);

        if (rooms[current_room].items[0]!= -1) {
            printf("There is an item here.\n");
        }

        if (player_health <= 0) {
            printf("You have died.\n");
            return 1;
        }

        int choice;
        printf("What do you want to do?\n");
        printf("1. Go east\n");
        printf("2. Attack\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (current_room < num_rooms - 1 && rooms[current_room + 1].name!= NULL) {
                current_room++;
            } else {
                printf("There is no door to the east.\n");
            }
            break;

        case 2:
            if (rooms[current_room].enemies[0]!= -1) {
                int enemy_index = rooms[current_room].enemies[0];
                Enemy *enemy = &enemies[enemy_index];

                int damage = player_attack - enemy->health;

                if (damage > 0) {
                    printf("You killed the %s!\n", enemy->name);
                    rooms[current_room].enemies[0] = -1;
                } else if (damage == 0) {
                    printf("You hit the %s, but it doesn't seem to be affected.\n", enemy->name);
                } else {
                    printf("The %s hit you! You lost %d health.\n", enemy->name, damage);
                    player_health -= damage;
                }
            } else {
                printf("There is no enemy here.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
        }
    }

    printf("Congratulations! You have completed the adventure!\n");

    return 0;
}