#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define NAME_SIZE 20

typedef struct {
    char name[NAME_SIZE];
    int health;
    int armor;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void add_player(char *name) {
    if (num_players >= MAX_PLAYERS) {
        printf("Maximum number of players reached.\n");
        return;
    }

    strcpy(players[num_players].name, name);
    players[num_players].health = 100;
    players[num_players].armor = 0;
    num_players++;
}

int main() {
    char command[100];
    char name[NAME_SIZE];

    printf("Simple Game Engine\n");
    printf("Type 'add' to add a player\n");

    while (1) {
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove newline character

        if (strcmp(command, "add") == 0) {
            printf("Enter player name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; // Remove newline character
            add_player(name);
        }

        // Deliberate null pointer dereference vulnerability in player_stats()
        player_stats(players[-1]);
    }

    return 0;
}

void player_stats(Player *player) {
    printf("Name: %s\nHealth: %d\nArmor: %d\n", player->name, player->health, player->armor);
}
