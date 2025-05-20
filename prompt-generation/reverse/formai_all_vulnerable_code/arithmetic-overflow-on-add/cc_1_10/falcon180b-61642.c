//Falcon-180B DATASET v1.0 Category: Poker Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define NUM_HANDS 7

typedef struct {
    int card1;
    int card2;
} hand_t;

void initDeck(int deck[DECK_SIZE]) {
    int i;
    for (i = 0; i < DECK_SIZE; i++) {
        deck[i] = i + 1;
    }
}

void shuffleDeck(int deck[DECK_SIZE]) {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCard(int deck[DECK_SIZE], int hand[NUM_HANDS]) {
    int card = deck[0];
    deck[0] = deck[DECK_SIZE - 1];
    deck[DECK_SIZE - 1] = card;
    hand[0] = card;
}

int evaluateHand(hand_t hand) {
    int value = 0;
    if (hand.card1 == 11 || hand.card1 == 12 || hand.card1 == 13) {
        value += 10;
    } else {
        value += hand.card1;
    }
    if (hand.card2 == 11 || hand.card2 == 12 || hand.card2 == 13) {
        value += 10;
    } else {
        value += hand.card2;
    }
    return value;
}

int main() {
    int deck[DECK_SIZE];
    initDeck(deck);
    shuffleDeck(deck);

    int hands[NUM_HANDS];
    int i;
    for (i = 0; i < NUM_HANDS; i++) {
        dealCard(deck, hands);
    }

    int highestValue = 0;
    for (i = 0; i < NUM_HANDS; i++) {
        int value = evaluateHand((hand_t) {hands[i], hands[i + 1]});
        if (value > highestValue) {
            highestValue = value;
        }
    }

    printf("Highest hand value: %d\n", highestValue);

    return 0;
}