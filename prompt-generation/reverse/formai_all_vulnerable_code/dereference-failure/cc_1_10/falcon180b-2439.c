//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9
#define MAX_ROWS 9
#define MAX_COLS 9
#define MAX_VAL 9

typedef struct {
    int size;
    int rows;
    int cols;
    int **board;
} Sudoku;

Sudoku *create_sudoku(int size) {
    Sudoku *sudoku = (Sudoku *) malloc(sizeof(Sudoku));
    if (sudoku == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    sudoku->size = size;
    sudoku->rows = size * size;
    sudoku->cols = size;
    sudoku->board = (int **) malloc(sizeof(int *) * sudoku->rows);

    for (int i = 0; i < sudoku->rows; i++) {
        sudoku->board[i] = (int *) malloc(sizeof(int) * sudoku->cols);
    }

    return sudoku;
}

void destroy_sudoku(Sudoku *sudoku) {
    for (int i = 0; i < sudoku->rows; i++) {
        free(sudoku->board[i]);
    }
    free(sudoku->board);
    free(sudoku);
}

void print_sudoku(Sudoku *sudoku) {
    for (int i = 0; i < sudoku->rows; i++) {
        for (int j = 0; j < sudoku->cols; j++) {
            printf("%d ", sudoku->board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(Sudoku *sudoku, int row, int col, int val) {
    int start_row = row - row % sudoku->size;
    int start_col = col - col % sudoku->size;

    for (int i = 0; i < sudoku->size; i++) {
        for (int j = 0; j < sudoku->size; j++) {
            if (sudoku->board[start_row + i][start_col + j] == val ||
                sudoku->board[start_row + i][start_col + j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int is_solved(Sudoku *sudoku) {
    for (int i = 0; i < sudoku->rows; i++) {
        for (int j = 0; j < sudoku->cols; j++) {
            if (sudoku->board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int size = 9;
    Sudoku *sudoku = create_sudoku(size);

    for (int i = 0; i < sudoku->rows; i++) {
        for (int j = 0; j < sudoku->cols; j++) {
            sudoku->board[i][j] = rand() % MAX_VAL + 1;
        }
    }

    print_sudoku(sudoku);

    while (!is_solved(sudoku)) {
        int row = rand() % sudoku->rows;
        int col = rand() % sudoku->cols;

        if (sudoku->board[row][col] == 0) {
            for (int val = 1; val <= MAX_VAL; val++) {
                if (is_valid_move(sudoku, row, col, val)) {
                    sudoku->board[row][col] = val;
                    break;
                }
            }
        }

        print_sudoku(sudoku);
    }

    destroy_sudoku(sudoku);

    return 0;
}