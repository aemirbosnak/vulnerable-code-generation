//FormAI DATASET v1.0 Category: Sudoku solver ; Style: surprised
#include <stdio.h>

int grid[9][9];  // sudoku puzzle grid

void printGrid() {  // prints the current state of the puzzle
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int findEmpty(int* row, int* col) {  // helper function to find empty cells
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int isValid(int row, int col, int num) {  // checks if a num is valid in a cell
    int i, j;
    for (i = 0; i < 9; i++) {  // check row and col
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
    int rowStart = (row / 3) * 3;  // check subgrid
    int colStart = (col / 3) * 3;
    for (i = rowStart; i < rowStart + 3; i++) {
        for (j = colStart; j < colStart + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve() {  // solves the puzzle using backtracking
    int row, col;
    if (!findEmpty(&row, &col)) {
        return 1;  // solved
    }
    for (int num = 1; num <= 9; num++) {
        if (isValid(row, col, num)) {
            grid[row][col] = num;
            if (solve()) {
                return 1;  // solved
            }
            grid[row][col] = 0;  // backtrack
        }
    }
    return 0;  // unsolvable
}

int main() {
    printf("Welcome to the Sudoku solver!\n");
    printf("Please enter the numbers in the puzzle one by one:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    printf("Solving...\n");
    if (solve()) {
        printf("Puzzle solved!\n");
        printGrid();
    } else {
        printf("Puzzle is unsolvable.\n");
    }
    return 0;
}