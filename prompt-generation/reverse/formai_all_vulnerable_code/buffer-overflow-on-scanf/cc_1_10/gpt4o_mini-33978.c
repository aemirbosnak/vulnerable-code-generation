//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define constants
#define ROWS 4
#define COLS 4
#define TOTAL_CARDS (ROWS * COLS)
#define HIDDEN '*'

// Function Prototypes
void initializeBoard(char board[ROWS][COLS], char symbols[TOTAL_CARDS]);
void displayBoard(char board[ROWS][COLS]);
void shuffleSymbols(char symbols[TOTAL_CARDS]);
int isGameWon(char board[ROWS][COLS], char revealed[ROWS][COLS]);
void playGame(char board[ROWS][COLS], char symbols[TOTAL_CARDS]);

int main() {
    char board[ROWS][COLS];
    char symbols[TOTAL_CARDS] = {
        'A', 'A', 'B', 'B', 
        'C', 'C', 'D', 'D', 
        'E', 'E', 'F', 'F',
        'G', 'G', 'H', 'H'
    };

    // Welcome message
    printf("Welcome to the Memory Game!\n");
    
    // Initialize and shuffle the board
    initializeBoard(board, symbols);
    playGame(board, symbols);
    
    printf("Congratulations, you've matched all pairs!\n");
    return 0;
}

// Initialize the board and shuffle the symbols
void initializeBoard(char board[ROWS][COLS], char symbols[TOTAL_CARDS]) {
    shuffleSymbols(symbols);
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = HIDDEN;
        }
    }
}

// Shuffle symbols randomly
void shuffleSymbols(char symbols[TOTAL_CARDS]) {
    srand(time(NULL));
    for (int i = TOTAL_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = symbols[i];
        symbols[i] = symbols[j];
        symbols[j] = temp;
    }
}

// Display the board
void displayBoard(char board[ROWS][COLS]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if the game is won
int isGameWon(char board[ROWS][COLS], char revealed[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (revealed[i][j] == HIDDEN) {
                return 0; // Game is not yet won
            }
        }
    }
    return 1; // Game is won
}

// Main game function
void playGame(char board[ROWS][COLS], char symbols[TOTAL_CARDS]) {
    char revealed[ROWS][COLS];
    memcpy(revealed, board, sizeof(revealed));
    int x1, y1, x2, y2;
    int pairsFound = 0;

    while (!isGameWon(board, revealed)) {
        displayBoard(revealed);
        printf("Select first card (row and column): ");
        scanf("%d %d", &x1, &y1);
        printf("Select second card (row and column): ");
        scanf("%d %d", &x2, &y2);
        
        if (x1 < 0 || x1 >= ROWS || y1 < 0 || y1 >= COLS || 
            x2 < 0 || x2 >= ROWS || y2 < 0 || y2 >= COLS || 
            (x1 == x2 && y1 == y2) ||
            revealed[x1][y1] != HIDDEN || revealed[x2][y2] != HIDDEN) {
            printf("Invalid selection. Try again.\n");
            continue;
        }

        revealed[x1][y1] = symbols[x1 * COLS + y1];
        revealed[x2][y2] = symbols[x2 * COLS + y2];
        displayBoard(revealed);
        
        if (symbols[x1 * COLS + y1] == symbols[x2 * COLS + y2]) {
            printf("You found a pair!\n");
            pairsFound++;
        } else {
            printf("No match. Try again! \n");
            revealed[x1][y1] = HIDDEN;
            revealed[x2][y2] = HIDDEN;
        }
    }
}