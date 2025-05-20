//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Player {
    char name[MAX_NAME_LENGTH];
    int health;
    int experience;
    int inventory[10];
} Player;

Player createPlayer() {
    Player player;
    printf("Enter your name: ");
    scanf("%s", player.name);
    player.health = 100;
    player.experience = 0;
    player.inventory[0] = 0;
    player.inventory[1] = 0;
    player.inventory[2] = 0;
    return player;
}

void displayInventory(Player player) {
    printf("Inventory:\n");
    for (int i = 0; i < 3; i++) {
        if (player.inventory[i] > 0) {
            printf("%d. %s\n", i + 1, player.inventory[i]);
        }
    }
}

void takeInventory(Player player) {
    int itemIndex;
    printf("Enter item index: ");
    scanf("%d", &itemIndex);

    if (itemIndex > 0 && itemIndex <= 3 && player.inventory[itemIndex] > 0) {
        printf("Item taken: %s\n", player.inventory[itemIndex]);
        player.inventory[itemIndex] = 0;
    } else {
        printf("Invalid item index.\n");
    }
}

int main() {
    Player player = createPlayer();

    while (player.health > 0) {
        displayInventory(player);
        takeInventory(player);
    }

    printf("Game over: %s has died.\n", player.name);

    return 0;
}