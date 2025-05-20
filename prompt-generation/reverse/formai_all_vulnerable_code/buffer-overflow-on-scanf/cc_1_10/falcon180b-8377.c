//Falcon-180B DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 3

typedef struct {
    int id;
    char name[20];
    int score;
} player_t;

void init_game(player_t players[]) {
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = i + 1;
        players[i].score = 0;
    }
}

void display_score(player_t players[]) {
    int i;
    printf("Player ID | Player Name | Score\n");
    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("%d | %s | %d\n", players[i].id, players[i].name, players[i].score);
    }
}

void roll_dice(int *dice) {
    *dice = rand() % 6 + 1;
}

int main() {
    player_t players[MAX_PLAYERS];
    int i, j, k, l, m, n, round, dice, max_score;
    char name[20];

    printf("Enter the number of players (1-4): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
    }

    init_game(players);

    for (round = 1; round <= MAX_ROUNDS; round++) {
        for (i = 0; i < n; i++) {
            players[i].score = 0;
        }

        for (j = 0; j < 3; j++) {
            for (i = 0; i < n; i++) {
                roll_dice(&dice);
                players[i].score += dice;
            }

            display_score(players);
        }

        max_score = 0;
        for (i = 0; i < n; i++) {
            if (players[i].score > max_score) {
                max_score = players[i].score;
            }
        }

        printf("Round %d winner: %s with a score of %d\n", round, players[k].name, max_score);
    }

    return 0;
}