//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4  // Size of the grid (4x4)
#define TOTAL_PAIRS (SIZE * SIZE) / 2

char grid[SIZE][SIZE];
char displayGrid[SIZE][SIZE];
int available[SIZE * SIZE];
char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

void initializeGrid();
void shuffleSymbols();
void displayCurrentGrid();
int isMatch(int first, int second);
int checkForWin();
void playGame();

int main() {
    srand(time(NULL));  // Seed for random number generation
    printf("Welcome to the Exciting Memory Game!\n");
    printf("Try to match all the pairs of symbols in the grid!\n\n");
    playGame();
    return 0;
}

void initializeGrid() {
    memset(grid, '_', sizeof(grid));  // Initialize grid with empty spaces
    memset(displayGrid, '_', sizeof(displayGrid));  // Display grid with empty symbols
    for (int i = 0; i < SIZE * SIZE; i++) {
        available[i] = 1;  // Mark all positions as available
    }
}

void shuffleSymbols() {
    int symbolsIndex = 0;
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        grid[symbolsIndex / SIZE][symbolsIndex % SIZE] = symbols[i];
        grid[symbolsIndex / SIZE][symbolsIndex % SIZE + TOTAL_PAIRS] = symbols[i];
        symbolsIndex += 2;  // Fill two positions with the same symbol
    }
    
    // Shuffle the grid
    for (int i = 0; i < SIZE * SIZE; i++) {
        int r = rand() % (SIZE * SIZE);
        char temp = grid[i / SIZE][i % SIZE];
        grid[i / SIZE][i % SIZE] = grid[r / SIZE][r % SIZE];
        grid[r / SIZE][r % SIZE] = temp;
    }
}

void displayCurrentGrid() {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", displayGrid[i][j]);
        }
        printf("\n");
    }
}

int isMatch(int first, int second) {
    return grid[first / SIZE][first % SIZE] == grid[second / SIZE][second % SIZE];
}

int checkForWin() {
    for (int i = 0; i < SIZE * SIZE; i++) {
        if (available[i]) {
            return 0;  // Game not yet won
        }
    }
    return 1;  // All pairs found!
}

void playGame() {
    initializeGrid();
    shuffleSymbols();
    
    int moves = 0;
    
    while (1) {
        displayCurrentGrid();
        int first, second;
        
        printf("Choose your first position (0-15): ");
        scanf("%d", &first);
        displayGrid[first / SIZE][first % SIZE] = grid[first / SIZE][first % SIZE];
        displayCurrentGrid();
        
        printf("Choose your second position (0-15): ");
        scanf("%d", &second);
        displayGrid[second / SIZE][second % SIZE] = grid[second / SIZE][second % SIZE];
        
        if (isMatch(first, second)) {
            printf("It's a match! You found: %c\n", grid[first / SIZE][first % SIZE]);
            available[first] = 0;
            available[second] = 0;
        } else {
            printf("Sorry, not a match!\n");
            // Hide the symbols after a brief pause
            sleep(2);
            displayGrid[first / SIZE][first % SIZE] = '_';
            displayGrid[second / SIZE][second % SIZE] = '_';
        }
        
        moves++;
        
        if (checkForWin()) {
            printf("Congratulations! You've matched all pairs in %d moves!\n", moves);
            break;
        }
    }
}