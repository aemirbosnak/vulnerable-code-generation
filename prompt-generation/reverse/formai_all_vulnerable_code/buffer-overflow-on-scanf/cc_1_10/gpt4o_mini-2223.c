//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // Define the grid size (4x4)
#define PAIRS (SIZE * SIZE) / 2 // Number of pairs

// Function declarations
void initBoard(char board[SIZE][SIZE], char symbols[PAIRS]);
void shuffle(char symbols[PAIRS]);
void printBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]);
int checkMatch(char board[SIZE][SIZE], int firstRow, int firstCol, int secondRow, int secondCol);
int gameLoop(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    char symbols[PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}; // Example symbols
    int gameResult;

    // Initialize random number generator
    srand(time(NULL));

    // Initialize game board with shuffled symbols
    initBoard(board, symbols);

    // Run the game loop until all pairs are found
    gameResult = gameLoop(board);
    if(gameResult) {
        printf("Congratulations, you've matched all pairs!\n");
    } else {
        printf("Game over! Better luck next time.\n");
    }

    return 0;
}

// Function to initialize the game board with shuffled symbols
void initBoard(char board[SIZE][SIZE], char symbols[PAIRS]) {
    shuffle(symbols);
    
    // Fill the board with symbols
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            // Use symbols to fill the board
            board[i][j] = symbols[(i * SIZE + j) % PAIRS];
        }
    }
}

// Function to shuffle symbols randomly
void shuffle(char symbols[PAIRS]) {
    for(int i = PAIRS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = symbols[i];
        symbols[i] = symbols[j];
        symbols[j] = temp;
    }
}

// Function to print the game board
void printBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" * "); // Hidden cell representation
            }
        }
        printf("\n");
    }
}

// Function to check if the selected pair matches
int checkMatch(char board[SIZE][SIZE], int firstRow, int firstCol, int secondRow, int secondCol) {
    return board[firstRow][firstCol] == board[secondRow][secondCol];
}

// Main game loop function
int gameLoop(char board[SIZE][SIZE]) {
    int revealed[SIZE][SIZE] = {0};  // Tracker for revealed cells
    int pairsFound = 0;               // Counter for matched pairs
    int firstRow, firstCol, secondRow, secondCol;

    while (pairsFound < PAIRS) {
        printBoard(board, revealed);

        // First selection
        printf("Select the first cell (row col): ");
        scanf("%d %d", &firstRow, &firstCol);
        revealed[firstRow][firstCol] = 1; // Reveal the selected cell
        printBoard(board, revealed);
        
        // Second selection
        printf("Select the second cell (row col): ");
        scanf("%d %d", &secondRow, &secondCol);
        revealed[secondRow][secondCol] = 1; // Reveal the selected cell
        printBoard(board, revealed);

        // Check for a match
        if (checkMatch(board, firstRow, firstCol, secondRow, secondCol)) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("No match. Try again.\n");
            revealed[firstRow][firstCol] = 0; // Hide the first cell again
            revealed[secondRow][secondCol] = 0; // Hide the second cell again
        }
    }
    return 1; // All pairs found
}