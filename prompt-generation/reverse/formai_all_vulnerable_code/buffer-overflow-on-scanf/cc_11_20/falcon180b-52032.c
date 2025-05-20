//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10
#define NUM_MONSTERS 5
#define NUM_ITEMS 3

typedef struct {
    char name[20];
    int health;
} monster;

typedef struct {
    char name[20];
    int value;
} item;

int main() {
    srand(time(NULL));

    monster monsters[NUM_MONSTERS];
    item items[NUM_ITEMS];

    for (int i = 0; i < NUM_MONSTERS; i++) {
        monsters[i].health = rand() % 10 + 1;
        sprintf(monsters[i].name, "Monster %d", i + 1);
    }

    for (int i = 0; i < NUM_ITEMS; i++) {
        items[i].value = rand() % 10 + 1;
        sprintf(items[i].name, "Item %d", i + 1);
    }

    printf("Welcome to the Haunted House!\n");
    printf("There are %d rooms, %d monsters, and %d items scattered throughout the house.\n", NUM_ROOMS, NUM_MONSTERS, NUM_ITEMS);
    printf("Your goal is to survive and escape the house.\n");
    printf("Good luck!\n\n");

    int player_health = 10;
    int room = 0;
    int found_item = 0;

    while (player_health > 0 &&!found_item) {
        printf("You are in room %d.\n", room + 1);

        if (room == 4 || room == 7) {
            printf("You found an item!\n");
            found_item = 1;
        }

        int monster_index = rand() % NUM_MONSTERS;
        monster current_monster = monsters[monster_index];

        if (room == current_monster.health) {
            printf("You encountered a monster!\n");
            printf("It has %d health points.\n", current_monster.health);

            if (player_health > current_monster.health) {
                printf("You defeated the monster!\n");
            } else {
                printf("The monster defeated you.\n");
                return 0;
            }
        }

        printf("Do you want to go to the next room? (y/n)\n");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y') {
            room++;
        } else if (choice == 'n') {
            break;
        }
    }

    if (found_item) {
        printf("You found all the items and escaped the house!\n");
    } else {
        printf("You escaped the house, but you didn't find all the items.\n");
    }

    return 0;
}