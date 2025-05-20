//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define SIZE 4      // Define the grid size for the game
#define TOTAL_CARDS (SIZE * SIZE / 2) // Total unique pairs

// Function prototypes
void initializeBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]);
void shuffleCards(char cards[TOTAL_CARDS]);
void printBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]);
bool isValidMove(int x, int y);
void revealCard(char board[SIZE][SIZE], int revealed[SIZE][SIZE], int x, int y);
bool checkMatch(char board[SIZE][SIZE], int revealed[SIZE][SIZE], int x1, int y1, int x2, int y2);

// Main function
int main() {
    char board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0};
    char cards[TOTAL_CARDS] = {'A', 'A', 'B', 'B', 
                                'C', 'C', 'D', 'D', 
                                'E', 'E', 'F', 'F', 
                                'G', 'G', 'H', 'H'};
    int turns = 0;
    int pairs_found = 0;

    srand(time(NULL)); // Seed for random number generation
    shuffleCards(cards); // Shuffle the cards before creating the board

    // Initialize the board
    int cardIndex = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = cards[cardIndex++];
        }
    }

    // Main game loop
    while (pairs_found < TOTAL_CARDS) {
        printBoard(board, revealed);
        
        int x1, y1, x2, y2;
        printf("Select first card (row and column): ");
        scanf("%d %d", &x1, &y1);
        if (!isValidMove(x1, y1) || revealed[x1][y1]) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        revealCard(board, revealed, x1, y1);
        printBoard(board, revealed);

        printf("Select second card (row and column): ");
        scanf("%d %d", &x2, &y2);
        if (!isValidMove(x2, y2) || revealed[x2][y2] || (x1 == x2 && y1 == y2)) {
            printf("Invalid move! Try again.\n");
            revealed[x1][y1] = 0; // Hide the first card if the second move is invalid
            continue;
        }

        revealCard(board, revealed, x2, y2);
        printBoard(board, revealed);
        
        if (checkMatch(board, revealed, x1, y1, x2, y2)) {
            printf("It's a match!\n");
            pairs_found++;
        } else {
            printf("Not a match. Try again.\n");
            revealed[x1][y1] = 0; // Hide cards again if not a match
            revealed[x2][y2] = 0;
        }
        turns++;
    }

    printf("Congratulations! You've found all pairs in %d turns!\n", turns);
    return 0;
}

// Initialize the game board (hidden state)
void initializeBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' '; // Empty card
            revealed[i][j] = 0; // Not revealed
        }
    }
}

// Shuffle the cards randomly
void shuffleCards(char cards[TOTAL_CARDS]) {
    for (int i = TOTAL_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp; 
    }
}

// Print current state of the board
void printBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\nCurrent board:\n  ");
    for (int j = 0; j < SIZE; j++) printf(" %d ", j);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

// Check if the move is valid
bool isValidMove(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

// Reveal a card
void revealCard(char board[SIZE][SIZE], int revealed[SIZE][SIZE], int x, int y) {
    revealed[x][y] = 1; // Mark as revealed
}

// Check for a match
bool checkMatch(char board[SIZE][SIZE], int revealed[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}