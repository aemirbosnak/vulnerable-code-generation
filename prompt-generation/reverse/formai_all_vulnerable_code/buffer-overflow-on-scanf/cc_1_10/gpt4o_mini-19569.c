//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4  // Define a 4x4 grid (16 cells)
#define PAIRS (SIZE * SIZE / 2)

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void fillBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE], bool revealed[SIZE][SIZE]);
bool checkMatch(char board[SIZE][SIZE], int x1, int y1, int x2, int y2);
bool allPairsRevealed(bool revealed[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    bool revealed[SIZE][SIZE] = { false };  // Tracking revealed cells
    int x1, y1, x2, y2;                     // Coordinates of the selections
    int turns = 0;                          // Count turns
    bool gameOn = true;                     // Game status

    initializeBoard(board);
    fillBoard(board);

    // Game loop
    while (gameOn) {
        displayBoard(board, revealed);
        
        printf("Turn %d! Choose first card (row col): ", turns + 1);
        scanf("%d %d", &x1, &y1);
        
        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || revealed[x1][y1]) {
            printf("Invalid choice! Try again.\n");
            continue;
        }
        
        revealed[x1][y1] = true; // Reveal the first card
        displayBoard(board, revealed);
        
        printf("Choose second card (row col): ");
        scanf("%d %d", &x2, &y2);
        
        if (x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE || (x2 == x1 && y2 == y1) || revealed[x2][y2]) {
            printf("Invalid choice! Try again.\n");
            revealed[x1][y1] = false; // Hide the first card again
            continue;
        }
        
        revealed[x2][y2] = true; // Reveal the second card
        displayBoard(board, revealed);
        
        turns++;
        if (checkMatch(board, x1, y1, x2, y2)) {
            printf("It's a match!\n");
        } else {
            printf("Not a match. Try again!\n");
            revealed[x1][y1] = false; // Hide the first card again
            revealed[x2][y2] = false; // Hide the second card again
        }
        
        // Check for game over
        if (allPairsRevealed(revealed)) {
            printf("Congratulations! You've matched all pairs in %d turns!\n", turns);
            gameOn = false; // End game
        }
    }

    return 0;
}

// Initializes the game's grid
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Fills the board with pairs of numbers
void fillBoard(char board[SIZE][SIZE]) {
    int numbers[PAIRS];
    for (int i = 0; i < PAIRS; i++) {
        numbers[i] = i + '1'; // Fill pairs with numbers from '1' to '8'
    }
    
    // Shuffle the numbers
    for (int i = 0; i < PAIRS; i++) {
        int r = rand() % PAIRS;
        int temp = numbers[i];
        numbers[i] = numbers[r];
        numbers[r] = temp;
    }

    // Place numbers in the grid
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = numbers[index % PAIRS];
            index++;
        }
    }
}

// Displays the board state
void displayBoard(char board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("\nBoard:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]); // Show revealed card
            } else {
                printf("* "); // Hide unrevealed card
            }
        }
        printf("\n");
    }
}

// Checks if two selected cards match
bool checkMatch(char board[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    return (board[x1][y1] == board[x2][y2]);
}

// Check if all pairs are revealed
bool allPairsRevealed(bool revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) {
                return false; // Found an unrevealed card
            }
        }
    }
    return true; // All pairs revealed
}