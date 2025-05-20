//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_NUMBERS 75
#define MAX_CARDS 5
#define MAX_ROUNDS 10

typedef struct {
    int id;
    char name[20];
    int card[MAX_CARDS][5];
    int score;
} Player;

void init_card(int card[MAX_CARDS][5]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        for (int j = 0; j < 5; j++) {
            card[i][j] = rand() % MAX_NUMBERS + 1;
        }
    }
}

void print_card(int card[MAX_CARDS][5]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int compare_card(int card1[MAX_CARDS][5], int card2[MAX_CARDS][5]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        for (int j = 0; j < 5; j++) {
            if (card1[i][j]!= card2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void play_round(Player players[MAX_PLAYERS], int round) {
    printf("Round %d:\n", round + 1);
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d's card:\n", players[i].id);
        print_card(players[i].card);
    }
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int num_players;

    printf("Enter number of players (1-10): ");
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].id = i + 1;
        init_card(players[i].card);
    }

    int round = 1;
    while (round <= MAX_ROUNDS) {
        play_round(players, round);
        round++;
    }

    return 0;
}