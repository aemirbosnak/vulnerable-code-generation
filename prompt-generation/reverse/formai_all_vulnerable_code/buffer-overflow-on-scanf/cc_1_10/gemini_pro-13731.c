//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUDOKU_SIZE 9

typedef struct {
    int value;
    int possibilities;
    int visited;
} cell_t;

typedef struct {
    cell_t cells[SUDOKU_SIZE][SUDOKU_SIZE];
} sudoku_t;

int is_valid_move(sudoku_t *sudoku, int row, int col, int value) {
    int i, j;

    // check row
    for (i = 0; i < SUDOKU_SIZE; i++) {
        if (sudoku->cells[row][i].value == value) {
            return 0;
        }
    }

    // check column
    for (i = 0; i < SUDOKU_SIZE; i++) {
        if (sudoku->cells[i][col].value == value) {
            return 0;
        }
    }

    // check box
    int box_row = row / 3;
    int box_col = col / 3;
    for (i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (sudoku->cells[i][j].value == value) {
                return 0;
            }
        }
    }

    return 1;
}

void solve_sudoku(sudoku_t *sudoku) {
    int row, col, value;

    // find the first empty cell
    for (row = 0; row < SUDOKU_SIZE; row++) {
        for (col = 0; col < SUDOKU_SIZE; col++) {
            if (sudoku->cells[row][col].value == 0) {
                goto found_empty_cell;
            }
        }
    }

    // no empty cells found, the sudoku is solved
    return;

found_empty_cell:

    // try all possible values for the empty cell
    for (value = 1; value <= SUDOKU_SIZE; value++) {
        if (is_valid_move(sudoku, row, col, value)) {
            // set the cell value and mark it as visited
            sudoku->cells[row][col].value = value;
            sudoku->cells[row][col].visited = 1;

            // recursively solve the rest of the sudoku
            solve_sudoku(sudoku);

            // if the sudoku is not solved, reset the cell value and mark it as unvisited
            if (!sudoku->cells[row][col].visited) {
                sudoku->cells[row][col].value = 0;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    sudoku_t sudoku;
    int i, j;

    // read the sudoku puzzle from the command line
    for (i = 0; i < SUDOKU_SIZE; i++) {
        for (j = 0; j < SUDOKU_SIZE; j++) {
            scanf("%d", &sudoku.cells[i][j].value);
        }
    }

    // solve the sudoku puzzle
    solve_sudoku(&sudoku);

    // print the solved sudoku puzzle
    for (i = 0; i < SUDOKU_SIZE; i++) {
        for (j = 0; j < SUDOKU_SIZE; j++) {
            printf("%d ", sudoku.cells[i][j].value);
        }
        printf("\n");
    }

    return 0;
}