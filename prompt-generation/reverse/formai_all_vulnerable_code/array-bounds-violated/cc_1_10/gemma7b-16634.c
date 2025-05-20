//Gemma-7B DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARDS 52

typedef struct Card {
    int number;
    char suit;
} Card;

Card drawCard(void) {
    Card card;
    card.number = rand() % NUM_CARDS + 1;
    card.suit = 'H' + rand() % 4;
    return card;
}

int main() {
    int i, handSize, won = 0;
    Card hand[5];

    printf("Welcome to the Crazy Card Game!");
    printf("\n");

    // Deal the cards
    for (i = 0; i < handSize; i++) {
        hand[i] = drawCard();
    }

    // Check if the player won
    for (i = 0; i < handSize; i++) {
        if (hand[i].number == 13) {
            won = 1;
        }
    }

    // Show the hand
    printf("Your hand:");
    for (i = 0; i < handSize; i++) {
        printf(" %d of %c", hand[i].number, hand[i].suit);
    }

    // Check if the player won
    if (won) {
        printf("\nCongratulations, you won!");
    } else {
        printf("\nSorry, you lost.");
    }

    return 0;
}