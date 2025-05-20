//Falcon-180B DATASET v1.0 Category: Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 3
#define MAX_BETS 5

typedef struct {
    char name[20];
    int bet;
} Player;

void init_player(Player* player) {
    player->bet = 0;
    printf("Enter your name: ");
    scanf("%s", player->name);
}

void init_game(Player* players, int num_players) {
    srand(time(NULL));
    for (int i = 0; i < num_players; i++) {
        init_player(&players[i]);
    }
}

int roll_dice() {
    return rand() % 6 + 1;
}

int play_round(Player* players, int num_players, int* winner) {
    printf("Round %d:\n", 1);
    for (int i = 0; i < num_players; i++) {
        printf("%s rolls the dice...\n", players[i].name);
        int dice = roll_dice();
        printf("%s rolled a %d!\n", players[i].name, dice);
        if (dice > *winner) {
            *winner = dice;
        }
    }
    return *winner;
}

void play_game(Player* players, int num_players) {
    int winner = 0;
    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\nRound %d:\n", round);
        winner = play_round(players, num_players, &winner);
        printf("The winner of round %d is %s with %d!\n\n", round, players[winner - 1].name, winner);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players;

    printf("Welcome to CyberDice!\n");
    printf("How many players will be playing? (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    init_game(players, num_players);
    play_game(players, num_players);

    return 0;
}