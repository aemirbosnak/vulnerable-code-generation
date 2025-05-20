//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 100

void initializeBoard(int board[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = 0; // Initialize all cells as dead
        }
    }
}

void printBoard(int board[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("\033[H\033[J"); // Clear the console
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 1) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int countNeighbors(int board[MAX_SIZE][MAX_SIZE], int rows, int cols, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int ni = x + i, nj = y + j;
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                count += board[ni][nj];
            }
        }
    }
    return count;
}

void nextGeneration(int board[MAX_SIZE][MAX_SIZE], int nextBoard[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = countNeighbors(board, rows, cols, i, j);
            if (board[i][j] == 1) { // Living cell
                if (neighbors < 2 || neighbors > 3) {
                    nextBoard[i][j] = 0; // Cell dies
                } else {
                    nextBoard[i][j] = 1; // Cell lives
                }
            } else { // Dead cell
                if (neighbors == 3) {
                    nextBoard[i][j] = 1; // Cell becomes alive
                } else {
                    nextBoard[i][j] = 0; // Remains dead
                }
            }
        }
    }
}

void loadBoardFromFile(int board[MAX_SIZE][MAX_SIZE], int *rows, int *cols, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fscanf(file, "%d %d", rows, cols);
    initializeBoard(board, *rows, *cols);
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(file, "%d", &board[i][j]);
        }
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    int board[MAX_SIZE][MAX_SIZE];
    int nextBoard[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    // Get board size & initial state from file or default
    if (argc > 1) {
        loadBoardFromFile(board, &rows, &cols, argv[1]);
    } else {
        printf("Enter number of rows and columns: ");
        scanf("%d %d", &rows, &cols);
        initializeBoard(board, rows, cols);
        printf("Enter initial board state (1 for alive, 0 for dead):\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                scanf("%d", &board[i][j]);
            }
        }
    }

    while (1) {
        printBoard(board, rows, cols);
        nextGeneration(board, nextBoard, rows, cols);
        memcpy(board, nextBoard, sizeof(board[0][0]) * rows * cols);
        usleep(300000); // Sleep for 300 milliseconds to slow down the output
    }

    return 0;
}