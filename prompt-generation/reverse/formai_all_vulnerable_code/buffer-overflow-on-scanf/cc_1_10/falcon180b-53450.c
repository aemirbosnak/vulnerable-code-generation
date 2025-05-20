//Falcon-180B DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 10

typedef struct Player {
    char name[20];
    int score;
    int wins;
    int losses;
    int ties;
} Player;

void init_player(Player* player) {
    strcpy(player->name, "");
    player->score = 0;
    player->wins = 0;
    player->losses = 0;
    player->ties = 0;
}

void print_player(Player player) {
    printf("Name: %s\n", player.name);
    printf("Score: %d\n", player.score);
    printf("Wins: %d\n", player.wins);
    printf("Losses: %d\n", player.losses);
    printf("Ties: %d\n", player.ties);
}

int main() {
    int num_players;
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        init_player(&players[i]);
    }

    int num_rounds;
    printf("Enter number of rounds: ");
    scanf("%d", &num_rounds);

    for (int i = 0; i < num_rounds; i++) {
        for (int j = 0; j < num_players; j++) {
            printf("Player %d's score for round %d: ", j + 1, i + 1);
            scanf("%d", &players[j].score);
        }

        for (int j = 0; j < num_players; j++) {
            players[j].wins = 0;
            players[j].losses = 0;
            players[j].ties = 0;
        }

        for (int j = 0; j < num_players - 1; j++) {
            for (int k = j + 1; k < num_players; k++) {
                if (players[j].score > players[k].score) {
                    players[j].wins++;
                    players[k].losses++;
                } else if (players[j].score < players[k].score) {
                    players[j].losses++;
                    players[k].wins++;
                } else {
                    players[j].ties++;
                    players[k].ties++;
                }
            }
        }
    }

    printf("\nFinal scores:\n");
    for (int i = 0; i < num_players; i++) {
        print_player(players[i]);
    }

    return 0;
}