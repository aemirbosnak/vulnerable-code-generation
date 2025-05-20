//Falcon-180B DATASET v1.0 Category: Poker Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_HANDS 7
#define NUM_PLAYERS 2

typedef struct {
    char suit;
    int value;
} Card;

void shuffleDeck(Card deck[]) {
    int i, j;
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCard(Card deck[], Card hand[], int *numCards) {
    Card card = deck[*numCards];
    *numCards += 1;
    hand[*numCards - 1] = card;
}

int compareHands(Card hand1[], Card hand2[]) {
    int i;
    for (i = 0; i < NUM_HANDS; i++) {
        if (hand1[i].value > hand2[i].value) {
            return 1;
        } else if (hand1[i].value < hand2[i].value) {
            return -1;
        }
    }
    return 0;
}

void printHand(Card hand[]) {
    int i;
    for (i = 0; i < NUM_HANDS; i++) {
        printf("%c%d ", hand[i].suit, hand[i].value);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Card deck[NUM_CARDS];
    Card hand1[NUM_HANDS];
    Card hand2[NUM_HANDS];
    int numCards = 0;
    int i;

    // Initialize deck
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i].suit = '2' + (i / 13);
        deck[i].value = i % 13 + 1;
    }

    // Shuffle deck
    shuffleDeck(deck);

    // Deal cards
    for (i = 0; i < NUM_HANDS; i++) {
        dealCard(deck, hand1, &numCards);
        dealCard(deck, hand2, &numCards);
    }

    // Print hands
    printf("Player 1's hand:\n");
    printHand(hand1);
    printf("Player 2's hand:\n");
    printHand(hand2);

    // Compare hands
    int winner = compareHands(hand1, hand2);
    if (winner == 1) {
        printf("Player 1 wins!\n");
    } else if (winner == -1) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}