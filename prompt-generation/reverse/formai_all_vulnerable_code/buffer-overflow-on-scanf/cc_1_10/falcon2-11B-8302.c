//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int players[2] = {1, 2};
    int winner = -1;

    int score[2] = {0, 0};

    char name[10][20] = {"Player 1", "Player 2"};

    int rounds = 0;

    while (winner == -1) {
        printf("Round %d:\n", ++rounds);
        for (int i = 0; i < 2; i++) {
            printf("%s's turn.\n", name[players[i]]);
            printf("Choose a card: ");
            scanf("%d", &score[players[i]]);
        }

        int result = compare_scores(score);
        if (result == 0) {
            printf("It's a tie.\n");
            winner = -1;
        } else if (result == 1) {
            printf("%s wins!\n", name[players[result]]);
            winner = players[result];
        } else {
            printf("No winner this round.\n");
        }
    }

    if (winner!= -1) {
        printf("Game over.\n");
        printf("Player %s wins!\n", name[winner]);
    } else {
        printf("Game over.\n");
        printf("It's a tie.\n");
    }

    return 0;
}

int compare_scores(int scores[2]) {
    int max = scores[0];
    int min = scores[1];

    for (int i = 0; i < 2; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }

        if (scores[i] < min) {
            min = scores[i];
        }
    }

    return (max > min)? 1 : -1;
}