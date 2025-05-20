//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10
#define NUM_ITEMS 20
#define NUM_GHOSTS 5

typedef struct {
    char name[50];
    int value;
} Item;

typedef struct {
    char name[50];
    int health;
    int speed;
} Ghost;

void initRooms(char rooms[NUM_ROOMS][100]) {
    for (int i = 0; i < NUM_ROOMS; i++) {
        sprintf(rooms[i], "Room %d", i + 1);
    }
}

void initItems(Item items[NUM_ITEMS]) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        sprintf(items[i].name, "Item %d", i + 1);
        items[i].value = rand() % 100;
    }
}

void initGhosts(Ghost ghosts[NUM_GHOSTS]) {
    for (int i = 0; i < NUM_GHOSTS; i++) {
        sprintf(ghosts[i].name, "Ghost %d", i + 1);
        ghosts[i].health = rand() % 100;
        ghosts[i].speed = rand() % 10;
    }
}

int main() {
    srand(time(NULL));

    char rooms[NUM_ROOMS][100];
    initRooms(rooms);

    Item items[NUM_ITEMS];
    initItems(items);

    Ghost ghosts[NUM_GHOSTS];
    initGhosts(ghosts);

    int playerHealth = 100;
    int playerSpeed = 5;
    int playerRoom = 1;
    int numItemsCollected = 0;

    while (playerHealth > 0) {
        printf("\nYou are in room %s.\n", rooms[playerRoom]);

        if (numItemsCollected < NUM_ITEMS) {
            printf("There is an item here.\n");
            numItemsCollected++;
        } else {
            printf("There are no more items to collect.\n");
        }

        if (playerSpeed >= ghosts[0].speed) {
            printf("A ghost appears!\n");
            playerHealth -= ghosts[0].health;
        } else {
            printf("You narrowly escape the ghost.\n");
        }

        if (playerHealth <= 0) {
            printf("You have been caught by the ghosts. Game over.\n");
            break;
        }

        printf("Which room do you want to go to? ");
        scanf("%d", &playerRoom);

        if (playerRoom < 1 || playerRoom > NUM_ROOMS) {
            printf("Invalid room number.\n");
        }
    }

    return 0;
}