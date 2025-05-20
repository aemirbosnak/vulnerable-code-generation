//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 8

void initDeck(int deck[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            deck[i][j] = i * COLS + j + 1; // 1-based indexing
        }
    }
}

void printDeck(int deck[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", deck[i][j]);
        }
        printf("\n");
    }
}

void shuffleDeck(int deck[][COLS]) {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS - 1; j++) {
            temp = deck[i][j];
            deck[i][j] = deck[i][j + 1];
            deck[i][j + 1] = temp;
        }
    }
}

void flipCard(int deck[][COLS], int row, int col) {
    int card = deck[row][col];
    deck[row][col] = deck[row][col - 1];
    deck[row][col - 1] = card;
}

int checkMatch(int deck[][COLS], int row, int col) {
    int card1 = deck[row][col];
    int card2 = deck[row][col - 1];
    return card1 == card2;
}

int main() {
    int deck[ROWS][COLS];
    initDeck(deck);
    printf("Original deck:\n");
    printDeck(deck);
    shuffleDeck(deck);
    printf("\nShuffled deck:\n");
    printDeck(deck);
    int moves = 0;
    while (moves < TOTAL_CARDS) {
        int row, col;
        printf("\nEnter row and column: ");
        scanf("%d %d", &row, &col);
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("Invalid input.\n");
            continue;
        }
        if (checkMatch(deck, row, col)) {
            moves++;
            printf("Match found!\n");
        } else {
            printf("No match.\n");
            flipCard(deck, row, col);
        }
        printf("\nCurrent deck:\n");
        printDeck(deck);
    }
    printf("\nGame over. You made %d moves.\n", moves);
    return 0;
}