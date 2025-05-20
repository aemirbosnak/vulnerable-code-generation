#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

typedef struct Player {
    char name[MAX_NAME_LENGTH];
    int health;
    int attack;
} Player;

Player players[MAX_PLAYERS];

void add_player(Player* player, char* name, int health, int attack) {
    strcpy(player->name, name);
    player->health = health;
    player->attack = attack;
}

int main() {
    int num_players = 0;

    printf("Text-Based Battle Arena\n");

    add_player(&players[num_players], "Player1", 100, 20);
    num_players++;

    for (int i = 0; i < num_players; i++) {
        printf("\nPlayer %s has %d health and %d attack\n", players[i].name, players[i].health, players[i].attack);
    }

    for (int i = 0; i < num_players - 1; i++) {
        for (int j = i + 1; j < num_players; j++) {
            players[i].health -= players[j].attack;
            if (players[i].health <= 0) {
                printf("\n%s has been defeated by %s!\n", players[i].name, players[j].name);
                // Dereference failure vulnerability
                printf("Health of defeated player %s after battle: %d\n", players[i].name, players[i].health);
            }
        }
    }

    return 0;
}
