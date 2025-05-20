//Falcon-180B DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5
#define MAX_BETS 100

typedef struct {
    char name[20];
    int money;
} Player;

void init_player(Player* player) {
    sprintf(player->name, "Player %d", player->money = rand() % MAX_BETS + 1);
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int num_players = 0;
    int money_pool = 0;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        init_player(&players[i]);
        num_players++;
        money_pool += players[i].money;
    }

    printf("Welcome to the game!\n");
    printf("There are %d players with a total of %d chips.\n", num_players, money_pool);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        int bets[MAX_PLAYERS];
        memset(bets, 0, sizeof(bets));

        printf("Round %d\n", round);
        for (int i = 0; i < num_players; i++) {
            printf("Player %s, how much do you bet? ", players[i].name);
            scanf("%d", &bets[i]);
            money_pool -= bets[i];
        }

        int highest_bet = 0;
        int highest_bet_player = 0;

        for (int i = 0; i < num_players; i++) {
            if (bets[i] > highest_bet) {
                highest_bet = bets[i];
                highest_bet_player = i;
            }
        }

        if (highest_bet == 0) {
            printf("No one bet, the pot goes to the last player.\n");
            players[num_players - 1].money += money_pool;
        } else {
            printf("Player %s wins with a bet of %d!\n", players[highest_bet_player].name, highest_bet);
            players[highest_bet_player].money += money_pool;
        }
    }

    return 0;
}