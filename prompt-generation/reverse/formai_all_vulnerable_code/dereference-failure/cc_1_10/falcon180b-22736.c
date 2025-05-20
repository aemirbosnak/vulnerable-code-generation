//Falcon-180B DATASET v1.0 Category: Poker Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 2

typedef struct {
    char *name;
    int hand[NUM_CARDS];
} Player;

void shuffle(int deck[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCard(int deck[], int *top, int card) {
    deck[*top] = card;
    (*top)++;
}

int compareHands(int hand1[], int hand2[]) {
    for (int i = 0; i < NUM_CARDS; i++) {
        if (hand1[i] > hand2[i]) {
            return 1;
        } else if (hand1[i] < hand2[i]) {
            return -1;
        }
    }
    return 0;
}

int main() {
    int deck[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i + 1;
    }
    shuffle(deck, NUM_CARDS);

    int top = 0;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_CARDS; j++) {
            dealCard(deck, &top, deck[top]);
        }
    }

    Player players[NUM_PLAYERS];
    players[0].name = "Player 1";
    players[1].name = "Player 2";

    printf("Player 1's hand:\n");
    for (int i = 0; i < NUM_CARDS; i++) {
        printf("%d ", players[0].hand[i]);
    }
    printf("\n");

    printf("Player 2's hand:\n");
    for (int i = 0; i < NUM_CARDS; i++) {
        printf("%d ", players[1].hand[i]);
    }
    printf("\n");

    int winner = 0;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (compareHands(players[i].hand, players[(i + 1) % NUM_PLAYERS].hand) == 1) {
            winner = i;
            break;
        }
    }

    if (winner == 0) {
        printf("Tie!\n");
    } else {
        printf("Player %d wins!\n", winner + 1);
    }

    return 0;
}