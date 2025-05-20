//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 32

typedef struct player {
    char name[MAX_NAME_LENGTH];
    int score;
} player;

void print_players(player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void get_player_input(player *player) {
    printf("%s, enter your move: ", player->name);
    scanf("%s", player->name);
}

int main() {
    int num_players;
    player players[MAX_PLAYERS];

    printf("How many players are playing? (1-%d) ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    while (1) {
        for (int i = 0; i < num_players; i++) {
            get_player_input(&players[i]);

            // Check if the player has won
            if (strcmp(players[i].name, "quit") == 0) {
                printf("%s has quit the game.\n", players[i].name);
                return 0;
            } else if (players[i].score >= 100) {
                printf("%s has won the game!\n", players[i].name);
                return 0;
            }
        }

        print_players(players, num_players);
    }

    return 0;
}