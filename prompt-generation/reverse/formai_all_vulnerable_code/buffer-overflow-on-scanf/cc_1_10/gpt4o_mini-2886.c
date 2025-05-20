//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GRID_SIZE 4 // 4x4 grid
#define TOTAL_PAIRS (GRID_SIZE * GRID_SIZE) / 2

typedef struct {
    char visible;
    char value;
} Cell;

// Function to initialize the game board
void initializeBoard(Cell board[GRID_SIZE][GRID_SIZE]) {
    char values[TOTAL_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;
    // Fill the board with pairs of values
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (index < TOTAL_PAIRS) {
                board[i][j].value = values[index / 2]; // Pairing values
                board[i][j].visible = 0; // Initially hidden
                index++;
            }
        }
    }

    // Shuffle the board
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int r1 = rand() % GRID_SIZE;
            int r2 = rand() % GRID_SIZE;
            // Swap values
            char temp = board[i][j].value;
            board[i][j].value = board[r1][r2].value;
            board[r1][r2].value = temp;
        }
    }
}

// Function to display the board
void displayBoard(Cell board[GRID_SIZE][GRID_SIZE]) {
    printf("Memory Game Board:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (board[i][j].visible) {
                printf("[%c] ", board[i][j].value);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

// Function to check if the selected cells match
int checkMatch(Cell board[GRID_SIZE][GRID_SIZE], int x1, int y1, int x2, int y2) {
    return board[x1][y1].value == board[x2][y2].value;
}

// Function to play the game
void playGame() {
    Cell board[GRID_SIZE][GRID_SIZE];
    int pairsFound = 0;
    int totalPairs = TOTAL_PAIRS;
    int x1, y1, x2, y2;
    
    initializeBoard(board);
    
    while (pairsFound < totalPairs) {
        displayBoard(board);
        printf("Enter coordinates for the first card (row column): ");
        scanf("%d %d", &x1, &y1);
        
        // Validate input
        if (x1 < 0 || x1 >= GRID_SIZE || y1 < 0 || y1 >= GRID_SIZE || board[x1][y1].visible) {
            printf("Invalid selection or card already revealed. Try again.\n");
            continue;
        }
        
        board[x1][y1].visible = 1; // Reveal the first card
        displayBoard(board);
        
        printf("Enter coordinates for the second card (row column): ");
        scanf("%d %d", &x2, &y2);

        // Validate input
        if (x2 < 0 || x2 >= GRID_SIZE || y2 < 0 || y2 >= GRID_SIZE || (x2 == x1 && y2 == y1) || board[x2][y2].visible) {
            printf("Invalid selection or card already revealed. Try again.\n");
            board[x1][y1].visible = 0; // Hide the first card again
            continue;
        }
        
        board[x2][y2].visible = 1; // Reveal the second card
        displayBoard(board);
        
        // Check for match
        if (checkMatch(board, x1, y1, x2, y2)) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match. Try again.\n");
            // Hide both cards again
            board[x1][y1].visible = 0;
            board[x2][y2].visible = 0;
        }
    }
    
    printf("Congratulations! You've found all pairs!\n");
}

// Main function to set the random seed and start the game
int main() {
    srand(time(0)); // Seed the random number generator
    playGame();
    return 0;
}