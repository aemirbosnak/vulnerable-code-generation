//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 8

typedef struct {
    char suit;
    char rank;
} Card;

void shuffle(Card deck[NUM_CARDS]) {
    int i, j;
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int match(Card card1, Card card2) {
    return (card1.rank == card2.rank || card1.suit == card2.suit);
}

void display(Card card) {
    printf("%c%c ", card.rank, card.suit);
}

int main() {
    srand(time(NULL));

    Card deck[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i].suit = 'H' + i % 4;
        deck[i].rank = 'A' + i / 4;
    }

    printf("Shuffling deck...\n");
    shuffle(deck);

    int matches = 0;
    int attempts = 0;

    while (matches < NUM_CARDS) {
        printf("\n");
        for (int i = 0; i < NUM_CARDS; i++) {
            display(deck[i]);
        }

        int choice1, choice2;
        scanf("%d %d", &choice1, &choice2);

        if (choice1 >= 0 && choice1 < NUM_CARDS && choice2 >= 0 && choice2 < NUM_CARDS) {
            if (match(deck[choice1], deck[choice2])) {
                matches++;
            } else {
                attempts++;
            }
        } else {
            printf("Invalid choice.\n");
        }
    }

    printf("\nCongratulations! You matched all %d cards in %d attempts.\n", NUM_CARDS, attempts);

    return 0;
}