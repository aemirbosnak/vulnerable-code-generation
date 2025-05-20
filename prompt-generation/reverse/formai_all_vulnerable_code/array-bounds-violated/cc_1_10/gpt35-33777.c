//FormAI DATASET v1.0 Category: Poker Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    char suit;
} Card;

int main() {
    // Initialize deck of cards
    Card deck[52];
    int index = 0;
    for (int value = 2; value <= 14; value++) {
        for (char suit = 'H'; suit <= 'S'; suit++) {
            Card card = {value, suit};
            deck[index] = card;
            index++;
        }
    }

    // Shuffle the deck
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Deal the cards
    Card player1[2];
    Card player2[2];
    player1[0] = deck[0];
    player2[0] = deck[1];
    player1[1] = deck[2];
    player2[1] = deck[3];

    // Print out the hands
    printf("Player 1's hand: %d%c %d%c\n", player1[0].value, player1[0].suit, player1[1].value, player1[1].suit);
    printf("Player 2's hand: %d%c %d%c\n", player2[0].value, player2[0].suit, player2[1].value, player2[1].suit);

    // Find the winner
    int player1sum = player1[0].value + player1[1].value;
    int player2sum = player2[0].value + player2[1].value;
    if (player1sum > player2sum) {
        printf("Player 1 wins!\n");
    } else if (player2sum > player1sum) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}