//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card {
    char suit;
    int value;
} card;

card deck[52];

int main() {
    srand(time(0));
    int i;
    int j;
    int player1Score = 0;
    int player2Score = 0;

    for (i = 0; i < 52; i++) {
        deck[i].value = rand() % 13 + 1;
        deck[i].suit = 'c' + (rand() % 4);
    }

    printf("Dealing cards...\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            int k = rand() % 52;
            card tmp = deck[k];
            deck[k] = deck[k + 1];
            deck[k + 1] = tmp;
        }
        printf("%s, %d\n", deck[j].suit, deck[j].value);
        if (deck[j].value == 1) {
            player1Score++;
        } else if (deck[j].value == 2) {
            player2Score++;
        }
    }

    printf("Player 1 score: %d\nPlayer 2 score: %d\n", player1Score, player2Score);
    if (player1Score > player2Score) {
        printf("Player 1 wins!\n");
    } else if (player1Score < player2Score) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}