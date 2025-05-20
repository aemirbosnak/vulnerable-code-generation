//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GRID_SIZE 4
#define TOTAL_PAIRS (GRID_SIZE * GRID_SIZE) / 2

char grid[GRID_SIZE][GRID_SIZE];
char displayGrid[GRID_SIZE][GRID_SIZE];
int matchedPairs = 0;

// Function prototypes
void initializeGrid();
void shuffleAndPopulate();
void display();
void flipCard(int row, int col);
int checkMatch(int row1, int col1, int row2, int col2);
int hasMatched();
void gameLoop();

int main() {
    printf("Welcome to the Memory Game!\n");
    initializeGrid();
    gameLoop();
    return 0;
}

void initializeGrid() {
    shuffleAndPopulate();
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            displayGrid[i][j] = '*'; // Initialize display grid
        }
    }
}

void shuffleAndPopulate() {
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Letters for the grid
    char selectedLetters[TOTAL_PAIRS];

    for (int i = 0; i < TOTAL_PAIRS; i++) {
        selectedLetters[i] = letters[i]; // Select letters for pairs
    }

    // Create pairs
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        grid[i / GRID_SIZE][i % GRID_SIZE] = selectedLetters[i];
        grid[i / GRID_SIZE][i % GRID_SIZE + TOTAL_PAIRS] = selectedLetters[i];
    }

    // Shuffle the grid
    for (int i = TOTAL_PAIRS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        for (int k = 0; k < GRID_SIZE; k++) {
            char temp = grid[k][i % GRID_SIZE];
            grid[k][i % GRID_SIZE] = grid[k][j % GRID_SIZE];
            grid[k][j % GRID_SIZE] = temp;
        }
    }
}

void display() {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", displayGrid[i][j]);
        }
        printf("\n");
    }
}

void flipCard(int row, int col) {
    displayGrid[row][col] = grid[row][col]; // Reveal the card
}

int checkMatch(int row1, int col1, int row2, int col2) {
    // Check if the flipped cards match
    return grid[row1][col1] == grid[row2][col2];
}

int hasMatched() {
    return matchedPairs == TOTAL_PAIRS; // Check if all pairs are matched
}

void gameLoop() {
    srand(time(NULL));
    int firstRow, firstCol, secondRow, secondCol;

    while (!hasMatched()) {
        display();
        printf("Enter coordinates for the first card (row col): ");
        scanf("%d %d", &firstRow, &firstCol);

        flipCard(firstRow, firstCol);
        display();

        printf("Enter coordinates for the second card (row col): ");
        scanf("%d %d", &secondRow, &secondCol);

        flipCard(secondRow, secondCol);
        display();

        if (checkMatch(firstRow, firstCol, secondRow, secondCol)) {
            printf("It's a match!\n");
            matchedPairs++;
        } else {
            printf("Not a match! Try Again.\n");
            displayGrid[firstRow][firstCol] = '*'; // Hide the first card
            displayGrid[secondRow][secondCol] = '*'; // Hide the second card
        }
    }

    printf("Congratulations! You found all pairs!\n");
    display();
}