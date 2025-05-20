//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 10
#define MAX_NUM 9

// Function to check if a number is valid in a given row
int isValidInRow(int sudoku[MAX_SIZE][MAX_SIZE], int row, int num) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        if (sudoku[row][i] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a number is valid in a given column
int isValidInCol(int sudoku[MAX_SIZE][MAX_SIZE], int col, int num) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        if (sudoku[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a number is valid in a given 3x3 box
int isValidInBox(int sudoku[MAX_SIZE][MAX_SIZE], int row, int col, int num) {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if ((i >= row && i < row + 3) && (j >= col && j < col + 3) && sudoku[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku puzzle
int solveSudoku(int sudoku[MAX_SIZE][MAX_SIZE]) {
    int i, j, row, col, num, count = 0;
    while (count < MAX_SIZE * MAX_SIZE) {
        row = rand() % MAX_SIZE;
        col = rand() % MAX_SIZE;
        if (sudoku[row][col] == 0) {
            for (num = 1; num <= MAX_NUM; num++) {
                if (isValidInRow(sudoku, row, num) && isValidInCol(sudoku, col, num) && isValidInBox(sudoku, row - row % 3, col - col % 3, num)) {
                    sudoku[row][col] = num;
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}

// Function to print the Sudoku puzzle
void printSudoku(int sudoku[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    srand(time(NULL));
    int sudoku[MAX_SIZE][MAX_SIZE];
    memset(sudoku, 0, sizeof(sudoku));
    int size = 0;
    while (size < MAX_SIZE) {
        printf("Enter the size of the Sudoku puzzle (between %d and %d): ", 1, MAX_SIZE);
        scanf("%d", &size);
    }
    int count = solveSudoku(sudoku);
    printf("Solved Sudoku puzzle:\n");
    printSudoku(sudoku);
    printf("Number of randomly generated numbers: %d\n", count);
    return 0;
}