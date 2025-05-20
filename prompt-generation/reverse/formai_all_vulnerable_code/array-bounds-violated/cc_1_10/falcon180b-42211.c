//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS 8

int deck[NUM_CARDS];
int cards[ROWS][COLS];
int matches = 0;

void initDeck() {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i] = i + 1;
    }
}

void shuffleDeck() {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            cards[i][j] = deck[i * COLS + j];
        }
    }
}

void flipCard(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (cards[row][col] == 0) {
            cards[row][col] = 1;
            matches++;
        } else if (cards[row][col] == 1) {
            cards[row][col] = 0;
            matches--;
        }
    }
}

void checkMatch() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (cards[i][j] == 1) {
                flipCard(i, j);
            }
        }
    }
}

void printBoard() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (cards[i][j] == 1) {
                printf(" %d ", deck[matches]);
            } else {
                printf(" %d ", deck[i * COLS + j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice;
    initDeck();
    shuffleDeck();
    dealCards();

    while (matches < NUM_CARDS) {
        printBoard();
        printf("Turns taken: %d\n", matches);
        printf("Do you want to flip a card? (y/n): ");
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            int row, col;
            printf("Enter the row and column of the card you want to flip (0-3): ");
            scanf("%d %d", &row, &col);
            flipCard(row, col);
        }
    }

    printf("Congratulations! You won in %d turns!\n", matches);

    return 0;
}