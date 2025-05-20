#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define NAME_LENGTH 50

typedef struct Player {
    char name[NAME_LENGTH];
    int health;
    int armor;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void add_player() {
    Player new_player;
    printf("Enter player name: ");
    fgets(new_player.name, NAME_LENGTH, stdin);
    players[num_players] = new_player;
    num_players++;
}

void game_loop() {
    int i, input;

    printf("\nGame On!\n");

    for (i = 0; i < num_players; i++) {
        printf("\nPlayer %s\n", players[i].name);
        printf("Health: %d, Armor: %d\n", players[i].health, players[i].armor);
    }

    printf("\nChoose a player (0 to %d): ", num_players - 1);
    scanf("%d", &input);

    // Out of bounds read vulnerability occurs here.
    printf("Player's secret level: %c\n", players[input].name[NAME_LENGTH + 1]);
}

int main() {
    int choice;

    printf("Text-Based Game Engine\n");
    printf("1. Add Player\n2. Start Game\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            while (num_players < MAX_PLAYERS) {
                add_player();
            }
            break;
        case 2:
            game_loop();
            break;
        default:
            printf("Invalid option.");
    }

    return 0;
}
