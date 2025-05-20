//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 9

typedef struct {
    char grid[MAX_SIZE][MAX_SIZE];
    int boxes[MAX_SIZE][MAX_SIZE];
    int rows[MAX_SIZE];
    int cols[MAX_SIZE];
    int boxes_size;
    int rows_size;
    int cols_size;
} Sudoku;

void read_sudoku(Sudoku *sudoku) {
    int i, j;
    char ch;

    FILE *file = fopen("sudoku.txt", "r");

    if (file == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }

    for (i = 0; i < MAX_SIZE; i++) {
        fscanf(file, "%c", &ch);
        for (j = 0; j < MAX_SIZE; j++) {
            sudoku->grid[i][j] = tolower(ch);
            ch = fgetc(file);
        }
        fgetc(file); // Skip '\n'
    }
    fclose(file);

    // Set the number of boxes, rows, and columns
    sudoku->boxes_size = MAX_SIZE;
    sudoku->rows_size = MAX_SIZE;
    sudoku->cols_size = MAX_SIZE;

    // Calculate the number of boxes
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            sudoku->boxes[i][j] = 0;
        }
    }

    // Calculate the number of rows
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (sudoku->grid[i][j]!= '.') {
                sudoku->rows[i] = 1;
            } else {
                sudoku->rows[i] = 0;
            }
        }
    }

    // Calculate the number of columns
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (sudoku->grid[j][i]!= '.') {
                sudoku->cols[j] = 1;
            } else {
                sudoku->cols[j] = 0;
            }
        }
    }

    // Calculate the number of boxes
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (sudoku->grid[i][j]!= '.') {
                sudoku->boxes[i / MAX_SIZE][j / MAX_SIZE] = 1;
            } else {
                sudoku->boxes[i / MAX_SIZE][j / MAX_SIZE] = 0;
            }
        }
    }
}

int is_valid(Sudoku *sudoku, int row, int col, int num) {
    // Check row
    for (int i = 0; i < sudoku->rows_size; i++) {
        if (sudoku->grid[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (int i = 0; i < sudoku->cols_size; i++) {
        if (sudoku->grid[i][col] == num) {
            return 0;
        }
    }

    // Check box
    int box_x = row / MAX_SIZE;
    int box_y = col / MAX_SIZE;
    for (int i = box_x * MAX_SIZE; i < box_x * MAX_SIZE + MAX_SIZE; i++) {
        for (int j = box_y * MAX_SIZE; j < box_y * MAX_SIZE + MAX_SIZE; j++) {
            if (sudoku->grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

void solve_sudoku(Sudoku *sudoku) {
    int i, j;
    int num;
    int stack_index = 0;

    // Check if the puzzle is already solved
    for (i = 0; i < sudoku->rows_size; i++) {
        for (j = 0; j < sudoku->cols_size; j++) {
            if (sudoku->grid[i][j] == '.') {
                return;
            }
        }
    }

    // Backtrack through the grid to find the solution
    while (stack_index < sudoku->rows_size * sudoku->cols_size * sudoku->boxes_size) {
        num = -1;
        for (i = 0; i < sudoku->rows_size; i++) {
            for (j = 0; j < sudoku->cols_size; j++) {
                for (int k = 1; k <= 9; k++) {
                    if (is_valid(sudoku, i, j, k) && (num == -1 || is_valid(sudoku, i, j, num))) {
                        num = k;
                        break;
                    }
                }
            }
        }
        if (num == -1) {
            printf("No solution exists!\n");
            return;
        }
        sudoku->grid[stack_index / sudoku->cols_size][stack_index % sudoku->cols_size] = num + '0';
        stack_index++;
    }

    // Print the solution
    printf("Solution:\n");
    for (i = 0; i < sudoku->rows_size; i++) {
        for (j = 0; j < sudoku->cols_size; j++) {
            printf("%c", sudoku->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Sudoku sudoku;
    read_sudoku(&sudoku);
    solve_sudoku(&sudoku);
    return 0;
}