//FormAI DATASET v1.0 Category: Sudoku solver ; Style: active
#include <stdio.h>

#define SIZE 9

int sudoku[SIZE][SIZE];

void printSudoku() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int isRowValid(int row, int number) {
    for (int i = 0; i < SIZE; i++) {
        if (sudoku[row][i] == number) {
            return 0;
        }
    }
    return 1;
}

int isColumnValid(int column, int number) {
    for (int i = 0; i < SIZE; i++) {
        if (sudoku[i][column] == number) {
            return 0;
        }
    }
    return 1;
}

int isBoxValid(int row, int column, int number) {
    int boxRow = row - row % 3;
    int boxColumn = column - column % 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxColumn; j < boxColumn + 3; j++) {
            if (sudoku[i][j] == number) {
                return 0;
            }
        }
    }
    return 1;
}

int isCellValid(int row, int column, int number) {
    return isRowValid(row, number) && isColumnValid(column, number) && isBoxValid(row, column, number);
}

int solveSudoku(int row, int column) {
    if (row == SIZE) {
        return 1;
    }
    if (sudoku[row][column]) {
        if (column == SIZE - 1) {
            return solveSudoku(row + 1, 0);
        } else {
            return solveSudoku(row, column + 1);
        }
    }
    for (int i = 1; i <= SIZE; i++) {
        if (isCellValid(row, column, i)) {
            sudoku[row][column] = i;
            if (column == SIZE - 1) {
                if (solveSudoku(row + 1, 0)) {
                    return 1;
                }
            } else {
                if (solveSudoku(row, column + 1)) {
                    return 1;
                }
            }
            sudoku[row][column] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Enter sudoku grid values (Use 0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
    printf("Solving sudoku...\n");
    if (solveSudoku(0, 0)) {
        printf("Sudoku solved:\n");
        printSudoku();
    } else {
        printf("Unable to solve sudoku.\n");
    }
    return 0;
}