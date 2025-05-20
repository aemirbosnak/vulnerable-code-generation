//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS 8

typedef struct {
    char value;
    int isRevealed;
} Card;

void initDeck(Card deck[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i].value = '2' + (char) (i / 2);
        deck[i].isRevealed = 0;
    }
}

void printDeck(Card deck[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        if (deck[i].isRevealed) {
            printf(" %c ", deck[i].value);
        } else {
            printf(" X ");
        }
    }
    printf("\n");
}

int revealCard(Card deck[NUM_CARDS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS &&!deck[row * COLS + col].isRevealed) {
        deck[row * COLS + col].isRevealed = 1;
        return 1;
    }
    return 0;
}

int checkMatch(Card deck[NUM_CARDS], int row1, int col1, int row2, int col2) {
    if (row1!= row2 || col1!= col2) {
        return 0;
    }
    return deck[row1 * COLS + col1].value == deck[row2 * COLS + col2].value;
}

int main() {
    Card deck[NUM_CARDS];
    initDeck(deck);
    int gameWon = 0;

    srand(time(0));
    int numMoves = 0;

    while (!gameWon) {
        printDeck(deck);
        int row, col;
        scanf("%d %d", &row, &col);
        if (revealCard(deck, row, col)) {
            numMoves++;
            if (numMoves == 1) {
                printf("You have %d moves left.\n", NUM_CARDS - 2);
            }
            if (checkMatch(deck, row, col, row, col)) {
                printf("Match!\n");
            } else {
                printf("Mismatch.\n");
            }
        } else {
            printf("Invalid move.\n");
        }
        if (numMoves == NUM_CARDS - 2) {
            gameWon = 1;
            printf("You win!\n");
        }
    }

    return 0;
}