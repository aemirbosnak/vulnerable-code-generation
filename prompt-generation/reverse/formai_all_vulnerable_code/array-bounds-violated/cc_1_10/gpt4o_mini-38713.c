//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4 // Dimension of the board
#define MAX_PAIRED_CARDS (SIZE * SIZE / 2)

typedef struct {
    char symbol;
    int revealed;
} Card;

void initializeBoard(Card board[SIZE][SIZE]) {
    char symbols[MAX_PAIRED_CARDS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (index >= MAX_PAIRED_CARDS) {
                index = 0;
            }
            board[i][j].symbol = symbols[index / 2]; // Pairing the symbols
            board[i][j].revealed = 0; // Every card is initially hidden
            if (index % 2 == 1) {
                index++; // Move to the next symbol after a pair
            } else {
                index++; // Just populate the same symbol
            }
        }
    }

    // Shuffle the board
    for (int i = 0; i < SIZE * SIZE; i++) {
        int r = rand() % (SIZE * SIZE);
        int r2 = rand() % (SIZE * SIZE);
        Card temp = board[i / SIZE][i % SIZE];
        board[i / SIZE][i % SIZE] = board[r2 / SIZE][r2 % SIZE];
        board[r2 / SIZE][r2 % SIZE] = temp;
    }
}

void printBoard(Card board[SIZE][SIZE]) {
    printf("  ");
    for (int j = 0; j < SIZE; j++) {
        printf(" %d ", j);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].revealed) {
                printf(" %c ", board[i][j].symbol);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

int checkWin(Card board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j].revealed) {
                return 0; // Not all cards are revealed
            }
        }
    }
    return 1; // All cards have been revealed
}

int main() {
    Card board[SIZE][SIZE];
    int firstGuessRow, firstGuessCol, secondGuessRow, secondGuessCol;
    int numPairsRevealed = 0;
    srand(time(NULL));
    initializeBoard(board);

    while (numPairsRevealed < MAX_PAIRED_CARDS) {
        printBoard(board);
        printf("Enter the coordinates of the first card (row col): ");
        scanf("%d %d", &firstGuessRow, &firstGuessCol);
        if (board[firstGuessRow][firstGuessCol].revealed) {
            printf("Card already revealed! Try again.\n");
            continue;
        }
        board[firstGuessRow][firstGuessCol].revealed = 1;
        printBoard(board); // Show updated board

        printf("Enter the coordinates of the second card (row col): ");
        scanf("%d %d", &secondGuessRow, &secondGuessCol);
        if (board[secondGuessRow][secondGuessCol].revealed) {
            printf("Card already revealed! Try again.\n");
            board[firstGuessRow][firstGuessCol].revealed = 0;
            continue;
        }
        board[secondGuessRow][secondGuessCol].revealed = 1;
        printBoard(board); // Show updated board

        if (board[firstGuessRow][firstGuessCol].symbol == board[secondGuessRow][secondGuessCol].symbol) {
            printf("It's a match!\n");
            numPairsRevealed++;
        } else {
            printf("Not a match, try again!\n");
            board[firstGuessRow][firstGuessCol].revealed = 0;
            board[secondGuessRow][secondGuessCol].revealed = 0;
        }
    }

    printf("Congratulations! You've matched all pairs!\n");
    return 0;
}