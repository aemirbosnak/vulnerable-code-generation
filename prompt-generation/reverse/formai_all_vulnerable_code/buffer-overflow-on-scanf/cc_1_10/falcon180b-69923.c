//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 5

typedef struct player {
    char name[20];
    int score;
} Player;

void init_player(Player *player) {
    strcpy(player->name, "Player");
    player->score = 0;
}

void start_game() {
    int num_players;
    printf("Enter the number of players (1-10): ");
    scanf("%d", &num_players);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        init_player(&players[i]);
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", players[i].name);
    }

    int num_rounds;
    printf("Enter the number of rounds (1-5): ");
    scanf("%d", &num_rounds);

    for (int round = 1; round <= num_rounds; round++) {
        printf("Round %d\n", round);
        for (int i = 0; i < num_players; i++) {
            printf("%s's turn\n", players[i].name);
            getchar();
        }
        for (int i = 0; i < num_players; i++) {
            printf("%s's score: %d\n", players[i].name, players[i].score);
        }
    }

    printf("Game over!\n");
}

int main() {
    start_game();
    return 0;
}