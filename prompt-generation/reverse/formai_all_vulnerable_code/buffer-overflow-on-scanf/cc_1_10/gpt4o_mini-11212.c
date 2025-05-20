//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // 4x4 Grid
#define TOTAL_PAIRS (SIZE * SIZE) / 2

void initializeGrid(char grid[SIZE][SIZE], char displayGrid[SIZE][SIZE]);
void shuffleCards(char grid[SIZE][SIZE]);
void printGrid(char displayGrid[SIZE][SIZE]);
bool makeMove(char grid[SIZE][SIZE], char displayGrid[SIZE][SIZE]);
bool checkForMatch(char grid[SIZE][SIZE], char firstCard, char secondCard);
bool isGameOver(char displayGrid[SIZE][SIZE]);
void playGame();

int main() {
    srand(time(NULL)); // Seed for random number generation
    playGame();
    return 0;
}

void playGame() {
    char grid[SIZE][SIZE], displayGrid[SIZE][SIZE];
    initializeGrid(grid, displayGrid);
    
    shuffleCards(grid);
    
    while (!isGameOver(displayGrid)) {
        printGrid(displayGrid);
        if (!makeMove(grid, displayGrid)) {
            printf("Try again!\n");
        }
    }
    printGrid(displayGrid);
    printf("Congratulations! You've matched all pairs!\n");
}

void initializeGrid(char grid[SIZE][SIZE], char displayGrid[SIZE][SIZE]) {
    char card = 'A';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = (i * SIZE + j) < TOTAL_PAIRS ? card : 'X'; // Fill half with pairs
            if ((i * SIZE + j) % 2 == 1) card++; // Increment card for pairs
            displayGrid[i][j] = '*'; // Initial display state
        }
    }
}

void shuffleCards(char grid[SIZE][SIZE]) {
    for (int i = SIZE * SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap the cards
        char temp = grid[i / SIZE][i % SIZE];
        grid[i / SIZE][i % SIZE] = grid[j / SIZE][j % SIZE];
        grid[j / SIZE][j % SIZE] = temp;
    }
}

void printGrid(char displayGrid[SIZE][SIZE]) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", displayGrid[i][j]);
        }
        printf("\n");
    }
}

bool makeMove(char grid[SIZE][SIZE], char displayGrid[SIZE][SIZE]) {
    int x1, y1, x2, y2;
    printf("Enter coordinates of first card (row and column): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter coordinates of second card (row and column): ");
    scanf("%d %d", &x2, &y2);

    // Adjust for indexing (1-4 to 0-3)
    x1--; y1--; x2--; y2--;

    // Check validity of the moves
    if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || 
        x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE || 
        (x1 == x2 && y1 == y2) ||
        displayGrid[x1][y1] != '*' || displayGrid[x2][y2] != '*') {
        printf("Invalid move! Please try again.\n");
        return false;
    }

    // Reveal the chosen cards
    displayGrid[x1][y1] = grid[x1][y1];
    displayGrid[x2][y2] = grid[x2][y2];
    
    printGrid(displayGrid);
    
    // Check for a match
    bool matched = checkForMatch(grid, grid[x1][y1], grid[x2][y2]);
    if (!matched) {
        printf("No match found!\n");
        displayGrid[x1][y1] = '*';
        displayGrid[x2][y2] = '*';
    } else {
        printf("It's a match!\n");
    }
    return true;
}

bool checkForMatch(char grid[SIZE][SIZE], char firstCard, char secondCard) {
    return firstCard == secondCard;
}

bool isGameOver(char displayGrid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (displayGrid[i][j] == '*') {
                return false; // At least one card is still faced down
            }
        }
    }
    return true; // All cards matched
}