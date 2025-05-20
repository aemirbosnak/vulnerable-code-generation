//Falcon-180B DATASET v1.0 Category: Table Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10
#define INITIAL_BANKROLL 100

typedef struct {
    char name[20];
    int bankroll;
} player_t;

void init_players(player_t players[]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].bankroll = INITIAL_BANKROLL;
    }
}

void deal_card(player_t *player) {
    int card = rand() % 13 + 1;
    printf("%s was dealt card %d\n", player->name, card);
    player->bankroll -= card;
}

int main() {
    srand(time(NULL));

    player_t players[MAX_PLAYERS];
    init_players(players);

    int current_round = 1;
    while (current_round <= MAX_ROUNDS) {
        printf("\nRound %d:\n", current_round);
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].bankroll <= 0) {
                printf("%s has gone bankrupt and is out of the game.\n", players[i].name);
                continue;
            }
            deal_card(&players[i]);
            if (players[i].bankroll <= 0) {
                printf("%s has gone bankrupt and is out of the game.\n", players[i].name);
            }
        }
        current_round++;
    }

    return 0;
}