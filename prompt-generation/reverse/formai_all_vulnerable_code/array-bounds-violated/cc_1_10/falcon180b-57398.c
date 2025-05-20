//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5
#define NUM_ITEMS 10
#define NUM_GHOSTS 3

typedef struct {
    char name[50];
    int value;
} Item;

typedef struct {
    char name[50];
    int health;
    int attack;
} Ghost;

void initItems(Item items[NUM_ITEMS]) {
    int i;
    for (i = 0; i < NUM_ITEMS; i++) {
        sprintf(items[i].name, "Item %d", i + 1);
        items[i].value = rand() % 100;
    }
}

void initGhosts(Ghost ghosts[NUM_GHOSTS]) {
    int i;
    for (i = 0; i < NUM_GHOSTS; i++) {
        sprintf(ghosts[i].name, "Ghost %d", i + 1);
        ghosts[i].health = rand() % 50 + 1;
        ghosts[i].attack = rand() % 10 + 1;
    }
}

void printItem(Item item) {
    printf("You found %s! It's worth %d points.\n", item.name, item.value);
}

void encounterGhost(Ghost ghost) {
    int playerHealth = rand() % 100 + 1;
    int ghostAttack = ghost.attack;

    if (playerHealth > ghostAttack) {
        printf("You defeated the %s! Gain %d health.\n", ghost.name, ghostAttack);
    } else {
        printf("The %s defeated you! Lose %d health.\n", ghost.name, ghostAttack - playerHealth);
    }
}

int main() {
    srand(time(NULL));

    Item items[NUM_ITEMS];
    initItems(items);

    Ghost ghosts[NUM_GHOSTS];
    initGhosts(ghosts);

    int playerHealth = 100;
    int totalItems = 0;
    int totalGhosts = 0;

    int room = 1;
    while (room <= NUM_ROOMS && totalItems < NUM_ITEMS) {
        int itemFound = rand() % 2;
        if (itemFound == 1) {
            printItem(items[totalItems]);
            totalItems++;
        }

        int ghostEncounter = rand() % 2;
        if (ghostEncounter == 1) {
            encounterGhost(ghosts[totalGhosts]);
            totalGhosts++;
        }

        room++;
    }

    if (totalItems == NUM_ITEMS) {
        printf("Congratulations! You found all the items and defeated all the ghosts.\n");
    } else {
        printf("Sorry, you didn't find all the items.\n");
    }

    return 0;
}