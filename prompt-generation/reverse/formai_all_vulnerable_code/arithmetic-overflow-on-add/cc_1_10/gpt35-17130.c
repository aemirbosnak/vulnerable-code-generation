//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 10

// Function declarations
bool playerMove(int board[][COLS], int row, int col, int move);
void enemyMove(int board[][COLS], int row, int col, int move);

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize board
    int board[ROWS][COLS] = {0};

    // Initialize player position
    int playerRow = ROWS - 1;
    int playerCol = COLS / 2;

    // Game loop
    while (true) {
        // Clear screen
        system("clear");

        // Print board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++)
                printf("%c ", board[i][j] ? '*' : ' ');
            printf("\n");
        }

        // Ask for player move
        int move;
        printf("Enter move (left = -1, right = 1, shoot = 0): ");
        scanf("%d", &move);

        // Player move
        if (playerMove(board, playerRow, playerCol, move))
            return 0;

        // Enemy move
        enemyMove(board, playerRow, playerCol, rand() % 3 - 1);
    }

    return 0;
}

bool playerMove(int board[][COLS], int row, int col, int move) {
    // Update player position
    col += move;

    // Check if player reached the enemy line
    if (row == 0) {
        printf("You win!\n");
        return true;
    }

    // Check if player is out of bounds
    if (col < 0 || col >= COLS) {
        col -= move;
        return false;
    }

    // Update player position on the board
    board[row][col] = 1;
    board[row + 1][col - move] = 0;

    // Check if player was hit
    if (board[row][col] && row != ROWS - 1) {
        printf("You lose!\n");
        return true;
    }

    // Player did not win or lose yet
    return false;
}

void enemyMove(int board[][COLS], int row, int col, int move) {
    // Check if enemy reached the player line
    if (row == ROWS - 1) {
        printf("You lose!\n");
        exit(0);
    }

    // Update enemy position
    row--;

    // Check if enemy is out of bounds
    if (col + move < 0 || col + move >= COLS) {
        move = -move;
    }

    // Update enemy position on the board
    board[row][col] = 0;
    board[row][col + move] = 1;
}