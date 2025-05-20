//FormAI DATASET v1.0 Category: Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 4
#define COLUMNS 4
#define TOTAL_MOVES 10

void initializeBoard(int board[ROWS][COLUMNS]);
void printBoard(int board[ROWS][COLUMNS], int score);
bool isGameOver(int board[ROWS][COLUMNS]);
bool isValidMove(int board[ROWS][COLUMNS], int row, int col);
void moveTiles(int board[ROWS][COLUMNS], int row, int col, int direction, int* score);

int main() {
    int score = 0;
    int moves = 0;

    int board[ROWS][COLUMNS];
    initializeBoard(board);

    srand(time(NULL));

    while(!isGameOver(board) && moves < TOTAL_MOVES) {
        printBoard(board, score);
        printf("Moves remaining: %d\n", TOTAL_MOVES - moves);

        int row, col;
        printf("Enter row and column of the tile to move: ");
        scanf("%d %d", &row, &col);

        if (isValidMove(board, row, col)) {
            int direction = rand() % 4;
            moveTiles(board, row, col, direction, &score);
            moves++;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    printBoard(board, score);
    printf("Game over. Final score: %d\n", score);

    return 0;
}

void initializeBoard(int board[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = 0;
        }
    }

    // Initialize two random tiles with either 2 or 4
    int count = 0;
    while (count < 2) {
        int row = rand() % ROWS;
        int col = rand() % COLUMNS;

        if (board[row][col] == 0) {
            board[row][col] = (rand() % 2 + 1) * 2;
            count++;
        }
    }
}

void printBoard(int board[ROWS][COLUMNS], int score) {
    system("clear"); // For Linux/Mac users, replace with system("cls") for Windows users
    printf("Score: %d\n", score);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%5d ", board[i][j]); // 5 spaces for better formatting
        }
        printf("\n");
    }
}

bool isGameOver(int board[ROWS][COLUMNS]) {
    // Check for any empty space
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }

    // Check for same adjacent tiles in same row or column
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS - 1; j++) {
            if (board[i][j] == board[i][j+1] || board[j][i] == board[j+1][i]) {
                return false;
            }
        }
    }

    return true; // No valid moves left
}

bool isValidMove(int board[ROWS][COLUMNS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLUMNS) {
        return false;
    }

    if (board[row][col] == 0) {
        return false;
    }

    return true;
}

void moveTiles(int board[ROWS][COLUMNS], int row, int col, int direction, int* score) {
    int newRow = row;
    int newCol = col;

    // Determine new position based on chosen direction
    switch (direction) {
        case 0: // Up
            newRow--;
            break;
        case 1: // Right
            newCol++;
            break;
        case 2: // Down
            newRow++;
            break;
        case 3: // Left
            newCol--;
            break;
    }

    // If new position is out of bounds or have same value, return without doing anything
    if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLUMNS || board[newRow][newCol] == board[row][col]) {
        return;
    }

    // Update board and score
    board[newRow][newCol] = board[row][col];
    board[row][col] = 0;
    *score += board[newRow][newCol];
}