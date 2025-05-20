//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

typedef struct {
    int num;
    char called;
} bingo_card;

typedef struct {
    int id;
    char *name;
    bingo_card cards[MAX_CARDS];
} player;

int main() {
    srand(time(0));
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        for (int j = 0; j < MAX_CARDS; j++) {
            players[i].cards[j].num = rand() % 75 + 1;
            players[i].cards[j].called = 0;
        }
    }

    int current_ball = 0;
    while (current_ball < 75) {
        printf("Current ball: %d\n", current_ball + 1);
        for (int i = 0; i < num_players; i++) {
            for (int j = 0; j < MAX_CARDS; j++) {
                if (players[i].cards[j].num == current_ball + 1 &&!players[i].cards[j].called) {
                    players[i].cards[j].called = 1;
                    printf("%s got a bingo!\n", players[i].name);
                }
            }
        }
        current_ball++;
    }

    return 0;
}