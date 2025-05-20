//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

typedef struct game {
    int table[7][7];
    int currentPlayer;
    int winningScore;
} game;

void initializeGame(game* game) {
    int i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            game->table[i][j] = 0;
        }
    }
    game->currentPlayer = 0;
    game->winningScore = 0;
}

void printTable(game* game) {
    int i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            printf("%2d ", game->table[i][j]);
        }
        printf("\n");
    }
}

int main() {
    game game1;
    initializeGame(&game1);

    printf("Game 1\n");
    printTable(&game1);
    printf("\nPlayer 1's turn:\n");

    int p1, p2;
    scanf("%d%d", &p1, &p2);

    game1.table[p1-1][p2-1] += 10;
    printTable(&game1);

    int winner = 0;
    int score1 = 0, score2 = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (game1.table[i][j] >= game1.winningScore) {
                if (game1.table[i][j] == 0) {
                    winner = 0;
                } else {
                    winner = 1;
                }
                if (winner == 0) {
                    score1 += game1.table[i][j];
                } else {
                    score2 += game1.table[i][j];
                }
            }
        }
    }
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score1 < score2) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}