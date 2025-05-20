//FormAI DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 80
#define GENERATIONS 50
#define LIVE '*'
#define DEAD ' '

void initBoard(char board[ROWS][COLS], float density);
void printBoard(char board[ROWS][COLS]);
int countNeighbors(char board[ROWS][COLS], int row, int col);
void updateBoard(char board[ROWS][COLS]);

int main(void) {
    char board[ROWS][COLS];
    float density;

    srand(time(NULL)); // Random seed based on current time

    printf("Enter starting density (0.0 - 1.0): ");
    scanf("%f", &density);

    initBoard(board, density);
    printBoard(board);

    for (int i = 0; i < GENERATIONS; i++) {
        updateBoard(board);
        printBoard(board);
    }

    return 0;
}

void initBoard(char board[ROWS][COLS], float density) {
    int numCells = ROWS * COLS;
    int numLiveCells = (int)(numCells * density);

    // Populate board with empty cells
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = DEAD;
        }
    }

    // Randomly add live cells
    for (int k = 0; k < numLiveCells; k++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;

        if (board[row][col] == DEAD) {
            board[row][col] = LIVE;
        } else {
            k--;
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            putchar(board[i][j]);
        }
        putchar('\n');
    }
    printf("Press enter to continue...");
    getchar();
    system("cls"); // Clear screen for next generation
}

int countNeighbors(char board[ROWS][COLS], int row, int col) {
    int count = 0;

    // Check neighboring cells
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue; // Ignore current cell
            }

            int newRow = row + i;
            int newCol = col + j;

            // Wrap around if out of bounds
            if (newRow < 0) {
                newRow = ROWS - 1;
            } else if (newRow >= ROWS) {
                newRow = 0;
            }
            if (newCol < 0) {
                newCol = COLS - 1;
            } else if (newCol >= COLS) {
                newCol = 0;
            }

            if (board[newRow][newCol] == LIVE) {
                count++;
            }
        }
    }

    return count;
}

void updateBoard(char board[ROWS][COLS]) {
    char newBoard[ROWS][COLS];

    // Copy board to newBoard
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            newBoard[i][j] = board[i][j];
        }
    }

    // Update newBoard based on original board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(board, i, j);

            if (board[i][j] == LIVE) {
                if (neighbors == 2 || neighbors == 3) { // Cell survives
                    newBoard[i][j] = LIVE;
                } else { // Cell dies from overpopulation/underpopulation
                    newBoard[i][j] = DEAD;
                }
            } else if (board[i][j] == DEAD) {
                if (neighbors == 3) { // Cell is born
                    newBoard[i][j] = LIVE;
                }
            }
        }
    }

    // Copy newBoard back to board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}