//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define NUM_CARDS 8

typedef struct card {
    int value;
    int isRevealed;
} Card;

void initCards(Card cards[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        cards[i].value = i + 1;
        cards[i].isRevealed = 0;
    }
}

void printCards(Card cards[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        if (cards[i].isRevealed) {
            printf("%d ", cards[i].value);
        } else {
            printf("X ");
        }
    }
    printf("\n");
}

int matchCards(Card card1, Card card2) {
    return card1.value == card2.value;
}

void revealCard(Card *card) {
    card->isRevealed = 1;
}

void hideCard(Card *card) {
    card->isRevealed = 0;
}

int main() {
    srand(time(NULL));

    Card cards[NUM_CARDS];
    initCards(cards);

    int playerScore = 0;
    int numRevealed = 0;
    int numMoves = 0;

    while (numRevealed < SIZE * SIZE) {
        printCards(cards);
        printf("Score: %d\n", playerScore);
        printf("Moves: %d\n", numMoves);

        int row1, col1, row2, col2;
        printf("Enter the coordinates of the first card: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the coordinates of the second card: ");
        scanf("%d %d", &row2, &col2);

        if (row1 >= SIZE || col1 >= SIZE || row2 >= SIZE || col2 >= SIZE) {
            printf("Invalid coordinates.\n");
            continue;
        }

        if (cards[row1 * SIZE + col1].isRevealed || cards[row2 * SIZE + col2].isRevealed) {
            printf("One or both cards are already revealed.\n");
            continue;
        }

        if (matchCards(cards[row1 * SIZE + col1], cards[row2 * SIZE + col2])) {
            revealCard(&cards[row1 * SIZE + col1]);
            revealCard(&cards[row2 * SIZE + col2]);
            playerScore += 10;
            numRevealed += 2;
        } else {
            hideCard(&cards[row1 * SIZE + col1]);
            hideCard(&cards[row2 * SIZE + col2]);
            numMoves++;
        }
    }

    if (numRevealed == SIZE * SIZE) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, you lost.\n");
    }

    return 0;
}