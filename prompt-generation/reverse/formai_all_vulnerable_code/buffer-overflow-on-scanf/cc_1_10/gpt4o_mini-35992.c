//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define SIZE 4 // 4x4 board
#define TOTAL_PAIRS (SIZE * SIZE) / 2
#define EMPTY ' '
// Temporary symbols for multi-pair representation
const char symbols[TOTAL_PAIRS] = {'!', '@', '#', '$', '%', '^', '&', '*'};

void initializeBoard(char board[SIZE][SIZE], char display[SIZE][SIZE]) {
    // Fill the display board with pairs
    char chosenSymbols[TOTAL_PAIRS * 2];
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        chosenSymbols[i * 2] = symbols[i];
        chosenSymbols[i * 2 + 1] = symbols[i];
    }

    // Shuffle the symbols
    for (int i = TOTAL_PAIRS * 2 - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = chosenSymbols[i];
        chosenSymbols[i] = chosenSymbols[j];
        chosenSymbols[j] = temp;
    }

    // Initialize the board with chosen symbols
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = chosenSymbols[i * SIZE + j];
            display[i][j] = EMPTY;
        }
    }
}

void printBoard(char display[SIZE][SIZE]) {
    printf("\nBoard:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", display[i][j]);
        }
        printf("\n");
    }
}

int revealSymbol(char board[SIZE][SIZE], char display[SIZE][SIZE], int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || display[x][y] != EMPTY) {
        return 0; // Invalid move
    }
    display[x][y] = board[x][y];
    return 1; // Valid move
}

int checkMatch(char display[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    return display[x1][y1] == display[x2][y2];
}

int main() {
    char board[SIZE][SIZE], display[SIZE][SIZE];
    int moves = 0, foundPairs = 0;
    int x1, y1, x2, y2;

    srand(time(NULL));
    initializeBoard(board, display);

    while (foundPairs < TOTAL_PAIRS) {
        printBoard(display);
        printf("Enter coordinates of first cell (row col): ");
        scanf("%d %d", &x1, &y1);
        
        if (!revealSymbol(board, display, x1, y1)) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        printBoard(display);
        printf("Enter coordinates of second cell (row col): ");
        scanf("%d %d", &x2, &y2);
        
        if (!revealSymbol(board, display, x2, y2)) {
            printf("Invalid move! Try again.\n");
            display[x1][y1] = EMPTY; // Hide first revealed symbol
            continue;
        }

        moves++;
        if (checkMatch(display, x1, y1, x2, y2)) {
            printf("Match found!\n");
            foundPairs++;
        } else {
            printf("No match! Hiding symbols...\n");
            sleep(2); // Pause for user to see before hiding
            display[x1][y1] = EMPTY; // Hide first symbol
            display[x2][y2] = EMPTY; // Hide second symbol
        }
    }

    printf("Congratulations! You found all pairs in %d moves!\n", moves);
    return 0;
}