//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

// Memory game board
int board[ROWS][COLS];

// Function to initialize the memory game board
void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }
}

// Function to display the memory game board
void displayBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a pair of tiles is matched
int isMatched(int row1, int col1, int row2, int col2) {
    return board[row1][col1] == board[row2][col2];
}

// Function to check if a tile has been clicked
int isClicked(int row, int col) {
    return board[row][col]!= -1;
}

// Function to check if the game is over
int isGameOver() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to generate a random index for a tile
int getRandomIndex() {
    return (rand() % (COLS * ROWS));
}

// Function to open a tile
void openTile(int row, int col) {
    board[row][col] = 0;
}

// Function to play the memory game
void playGame() {
    initializeBoard();
    int clicked = 0;
    int openTileIndex = getRandomIndex();
    int row, col;
    while (!isGameOver()) {
        displayBoard();
        printf("\nClick on a tile: ");
        scanf("%d %d", &row, &col);
        if (isClicked(row, col)) {
            openTile(row, col);
            clicked++;
        }
        if (isMatched(row, col, row, openTileIndex)) {
            printf("\nCongratulations! You found a pair!\n");
            clicked = 0;
            openTileIndex = getRandomIndex();
        }
    }
    printf("\nGame over! You found %d pairs.\n", clicked);
}

int main() {
    playGame();
    return 0;
}