//Code Llama-13B DATASET v1.0 Category: Sudoku solver ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SUDOKU_SIZE 9
#define MAX_CANDIDATES 9

typedef struct {
  int row;
  int col;
  int value;
} Cell;

typedef struct {
  int size;
  int** board;
  int* candidates;
} Sudoku;

void init_sudoku(Sudoku* sudoku, int size) {
  sudoku->size = size;
  sudoku->board = (int**)malloc(sizeof(int*) * size);
  sudoku->candidates = (int*)malloc(sizeof(int) * size * size);

  for (int i = 0; i < size; i++) {
    sudoku->board[i] = (int*)malloc(sizeof(int) * size);
    for (int j = 0; j < size; j++) {
      sudoku->board[i][j] = 0;
      sudoku->candidates[i * size + j] = MAX_CANDIDATES;
    }
  }
}

void free_sudoku(Sudoku* sudoku) {
  for (int i = 0; i < sudoku->size; i++) {
    free(sudoku->board[i]);
  }
  free(sudoku->board);
  free(sudoku->candidates);
}

void print_sudoku(Sudoku* sudoku) {
  for (int i = 0; i < sudoku->size; i++) {
    for (int j = 0; j < sudoku->size; j++) {
      printf("%d ", sudoku->board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void generate_candidates(Sudoku* sudoku) {
  for (int i = 0; i < sudoku->size; i++) {
    for (int j = 0; j < sudoku->size; j++) {
      for (int k = 1; k <= sudoku->size; k++) {
        sudoku->candidates[i * sudoku->size + j] |= (1 << k);
      }
    }
  }
}

void eliminate_candidates(Sudoku* sudoku, int row, int col, int value) {
  sudoku->candidates[row * sudoku->size + col] &= ~(1 << value);

  for (int i = 0; i < sudoku->size; i++) {
    if (i != row) {
      sudoku->candidates[i * sudoku->size + col] &= ~(1 << value);
    }
    if (i != col) {
      sudoku->candidates[row * sudoku->size + i] &= ~(1 << value);
    }
  }

  int box_row = row - (row % (sudoku->size / 3));
  int box_col = col - (col % (sudoku->size / 3));

  for (int i = box_row; i < box_row + sudoku->size / 3; i++) {
    for (int j = box_col; j < box_col + sudoku->size / 3; j++) {
      if (i != row && j != col) {
        sudoku->candidates[i * sudoku->size + j] &= ~(1 << value);
      }
    }
  }
}

void solve_sudoku(Sudoku* sudoku) {
  for (int i = 0; i < sudoku->size; i++) {
    for (int j = 0; j < sudoku->size; j++) {
      if (sudoku->board[i][j] == 0) {
        int candidates = sudoku->candidates[i * sudoku->size + j];
        for (int k = 1; k <= sudoku->size; k++) {
          if (candidates & (1 << k)) {
            sudoku->board[i][j] = k;
            eliminate_candidates(sudoku, i, j, k);
            solve_sudoku(sudoku);
            sudoku->board[i][j] = 0;
          }
        }
        return;
      }
    }
  }
}

int main() {
  Sudoku sudoku;
  init_sudoku(&sudoku, MAX_SUDOKU_SIZE);

  generate_candidates(&sudoku);
  solve_sudoku(&sudoku);

  print_sudoku(&sudoku);

  free_sudoku(&sudoku);

  return 0;
}