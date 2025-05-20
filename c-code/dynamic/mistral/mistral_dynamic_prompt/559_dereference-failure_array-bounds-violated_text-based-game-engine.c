#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5

typedef struct Player {
    char name[50];
    int health, attack, defense;
} Player;

Player players[MAX_PLAYERS];

void print_menu() {
    printf("\n\tText-Based Game Engine\n");
    printf("1. Create new player\n");
    printf("2. Start game\n");
    printf("3. Exit\n");
}

void create_player() {
    Player *new_player = &players[MAX_PLAYERS]; // Incorrect indexing

    printf("Enter player name: ");
    scanf("%s", new_player->name);
    new_player->health = 100;
    new_player->attack = 10;
    new_player->defense = 5;
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_player();
                break;
            case 2:
                // game logic here
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
