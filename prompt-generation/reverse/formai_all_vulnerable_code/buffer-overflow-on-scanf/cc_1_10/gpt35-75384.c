//FormAI DATASET v1.0 Category: Sudoku solver ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE];

void displayGrid() {

    printf("-----------------------\n");

    for (int i = 0; i < GRID_SIZE; ++i) {

        for (int j = 0; j < GRID_SIZE; ++j) {

            printf("| ");

            if (grid[i][j] == 0) {
                printf("  ");
            }
            else {
                printf("%d ", grid[i][j]);
            }

            if (j == 8) {
                printf("|\n");

                if (i == 8) {
                    printf("-----------------------\n");
                }
            }
        }
    }
}

bool isRowValid(int row, int num) {

    for (int i = 0; i < GRID_SIZE; ++i) {

        if (grid[row][i] == num) {
            return false;
        }
    }

    return true;
}

bool isColValid(int col, int num) {

    for (int i = 0; i < GRID_SIZE; ++i) {

        if (grid[i][col] == num) {
            return false;
        }
    }

    return true;
}

bool isBoxValid(int row, int col, int num) {

    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;

    for (int i = boxStartRow; i < boxStartRow + 3; ++i) {

        for (int j = boxStartCol; j < boxStartCol + 3; ++j) {

            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool isMoveValid(int row, int col, int num) {

    return isRowValid(row, num) && isColValid(col, num) && isBoxValid(row, col, num);
}

bool findUnassignedCell(int* row, int* col) {

    for (*row = 0; *row < GRID_SIZE; ++*row) {

        for (*col = 0; *col < GRID_SIZE; ++*col) {

            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }

    return false;
}

bool solveSudoku() {

    int row, col;

    if (!findUnassignedCell(&row, &col)) {
        return true;
    }

    for (int num = 1; num <= 9; ++num) {

        if (isMoveValid(row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku()) {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {

    printf("Please input the Sudoku puzzle, line by line:\n");

    for (int i = 0; i < GRID_SIZE; ++i) {

        for (int j = 0; j < GRID_SIZE; ++j) {

            scanf("%d", &grid[i][j]);
        }
    }

    if (solveSudoku()) {
        printf("\nSudoku puzzle solved successfully!\n\n");
        displayGrid();
    }
    else {
        printf("\nSudoku puzzle could not be solved.\n");
    }
    
    return 0;
}