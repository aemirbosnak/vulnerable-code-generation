//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Initialize random number generator

    // Create a deck of cards
    int deck[52] = {0};
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 4; j++) {
            deck[i * 13 + j] = 1;
        }
    }

    // Shuffle the deck
    int swap;
    for (int i = 0; i < 52; i++) {
        swap = rand() % i + 1;
        deck[swap] = deck[i];
    }

    // Deal 5 cards to player 1
    int player1[5] = {0};
    for (int i = 0; i < 5; i++) {
        player1[i] = deck[i];
        deck[i] = 0;
    }

    // Deal 5 cards to player 2
    int player2[5] = {0};
    for (int i = 0; i < 5; i++) {
        player2[i] = deck[i];
        deck[i] = 0;
    }

    // Print player 1's hand
    printf("Player 1's hand: ");
    for (int i = 0; i < 5; i++) {
        if (player1[i] == 1) {
            printf("%d of %s\n", i + 1, "Clubs");
        } else if (player1[i] == 2) {
            printf("%d of %s\n", i + 1, "Diamonds");
        } else if (player1[i] == 3) {
            printf("%d of %s\n", i + 1, "Hearts");
        } else if (player1[i] == 4) {
            printf("%d of %s\n", i + 1, "Spades");
        }
    }

    // Print player 2's hand
    printf("\nPlayer 2's hand: ");
    for (int i = 0; i < 5; i++) {
        if (player2[i] == 1) {
            printf("%d of %s\n", i + 1, "Clubs");
        } else if (player2[i] == 2) {
            printf("%d of %s\n", i + 1, "Diamonds");
        } else if (player2[i] == 3) {
            printf("%d of %s\n", i + 1, "Hearts");
        } else if (player2[i] == 4) {
            printf("%d of %s\n", i + 1, "Spades");
        }
    }

    // Compare player 1's and player 2's hands
    int player1_score = 0;
    int player2_score = 0;
    for (int i = 0; i < 5; i++) {
        if (player1[i] > player2[i]) {
            player1_score++;
        } else if (player1[i] < player2[i]) {
            player2_score++;
        }
    }

    // Determine the winner
    if (player1_score > player2_score) {
        printf("Player 1 wins!\n");
    } else if (player1_score < player2_score) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}