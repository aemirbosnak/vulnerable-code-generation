//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 4
#define MAX_CARDS (SIZE * SIZE)

void initializeBoard(char board[SIZE][SIZE], char symbols[MAX_CARDS]) {
    int idx = 0;
    // Fill the board with symbols
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '*';  // using '*' as the hidden card symbol
        }
    }
}

void shuffleSymbols(char symbols[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        symbols[i] = 'A' + (i / 2); // Create pairs of letters A, B, C, ...
    }
    // Shuffle the symbols
    for (int i = MAX_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = symbols[i];
        symbols[i] = symbols[j];
        symbols[j] = temp;
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool checkMatch(char board[SIZE][SIZE], char symbols[MAX_CARDS], int pos1, int pos2) {
    int row1 = pos1 / SIZE;
    int col1 = pos1 % SIZE;
    int row2 = pos2 / SIZE;
    int col2 = pos2 % SIZE;

    return symbols[pos1] == symbols[pos2];
}

bool isGameOver(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '*') {
                return false; // Found at least one unmatched card
            }
        }
    }
    return true; // All cards matched
}

int main() {
    char board[SIZE][SIZE];
    char symbols[MAX_CARDS];
    int attempts = 0;
    int firstPick = -1, secondPick = -1;

    srand(time(NULL));
    initializeBoard(board, symbols);
    shuffleSymbols(symbols);

    while (!isGameOver(board)) {
        printBoard(board);
        printf("Select first card (0-%d): ", MAX_CARDS - 1);
        scanf("%d", &firstPick);
        if (firstPick < 0 || firstPick >= MAX_CARDS) {
            printf("Invalid Selection. Try again.\n");
            continue;
        }
        
        int row1 = firstPick / SIZE;
        int col1 = firstPick % SIZE;

        if (board[row1][col1] != '*') {
            printf("Card already revealed! Try again.\n");
            continue;
        }
        
        // Reveal the first card
        board[row1][col1] = symbols[firstPick]; 
        printBoard(board);

        printf("Select second card (0-%d): ", MAX_CARDS - 1);
        scanf("%d", &secondPick);
        if (secondPick < 0 || secondPick >= MAX_CARDS) {
            printf("Invalid Selection. Try again.\n");
            board[row1][col1] = '*'; // Hide the first card
            continue;
        }

        int row2 = secondPick / SIZE;
        int col2 = secondPick % SIZE;

        if (board[row2][col2] != '*') {
            printf("Card already revealed! Try again.\n");
            board[row1][col1] = '*'; // Hide the first card
            continue;
        }
        
        // Reveal the second card
        board[row2][col2] = symbols[secondPick]; 
        printBoard(board);

        attempts++;

        if (checkMatch(board, symbols, firstPick, secondPick)) {
            printf("Match found!\n");
        } else {
            printf("Not a match. Try again.\n");
            // Hide cards if no match
            board[row1][col1] = '*';
            board[row2][col2] = '*'; 
        }

        printf("Total attempts: %d\n", attempts);
    }

    printf("Congratulations! You've matched all cards in %d attempts.\n", attempts);
    return 0;
}