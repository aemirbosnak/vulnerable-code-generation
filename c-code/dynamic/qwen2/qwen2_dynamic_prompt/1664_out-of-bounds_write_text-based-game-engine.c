#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 16

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int attackPower;
} Player;

void printPlayer(Player *player) {
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Attack Power: %d\n", player->attackPower);
}

int main() {
    Player player;
    strcpy(player.name, "Hero");
    player.health = 100;
    player.attackPower = 20;

    printf("Welcome to the Game!\n");

    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Attack\n");
        printf("2. Heal\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You attacked the enemy with power %d!\n", player.attackPower);
            // Intentional out-of-bounds write
            player.health -= player.attackPower + 10; // This will overwrite adjacent memory
        } else if (choice == 2) {
            printf("You healed yourself by 10 points!\n");
            player.health += 10;
        } else if (choice == 3) {
            printf("Exiting game...\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }

        printPlayer(&player);
    }

    return 0;
}
