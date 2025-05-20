//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 10
#define NUM_ATTEMPTS 5

typedef struct {
    int value;
    int matched;
} Card;

void initDeck(Card *deck) {
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i].value = i + 1;
        deck[i].matched = 0;
    }
}

void shuffleDeck(Card *deck) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void displayDeck(Card *deck) {
    for (int i = 0; i < NUM_CARDS; i++) {
        printf("%d ", deck[i].value);
    }
    printf("\n");
}

int isMatch(Card *deck, int choice1, int choice2) {
    if (deck[choice1 - 1].value == deck[choice2 - 1].value) {
        return 1;
    }
    return 0;
}

int main() {
    Card deck[NUM_CARDS];
    initDeck(deck);
    shuffleDeck(deck);

    int attempts = 0;
    while (attempts < NUM_ATTEMPTS) {
        displayDeck(deck);
        int choice1, choice2;
        printf("Enter two card choices: ");
        scanf("%d %d", &choice1, &choice2);

        if (isMatch(deck, choice1, choice2)) {
            printf("Match found!\n");
            deck[choice1 - 1].matched = 1;
            deck[choice2 - 1].matched = 1;
            attempts++;
        } else {
            printf("No match found.\n");
            deck[choice1 - 1].matched = 0;
            deck[choice2 - 1].matched = 0;
        }
    }

    printf("Game over.\n");
    for (int i = 0; i < NUM_CARDS; i++) {
        if (!deck[i].matched) {
            printf("%d ", deck[i].value);
        }
    }
    printf("\n");

    return 0;
}