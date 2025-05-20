//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SUDOKU_SIZE 9
#define SUDOKU_BOX_SIZE 3

bool is_valid_sudoku(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE]) {
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    bool row[SUDOKU_SIZE] = {false};
    bool col[SUDOKU_SIZE] = {false};
    bool box[SUDOKU_SIZE] = {false};

    for (int j = 0; j < SUDOKU_SIZE; j++) {
      if (sudoku[i][j] < 1 || sudoku[i][j] > SUDOKU_SIZE) {
        return false;
      }

      if (row[sudoku[i][j] - 1]) {
        return false;
      } else {
        row[sudoku[i][j] - 1] = true;
      }

      if (col[sudoku[j][i] - 1]) {
        return false;
      } else {
        col[sudoku[j][i] - 1] = true;
      }

      int box_row = i / SUDOKU_BOX_SIZE;
      int box_col = j / SUDOKU_BOX_SIZE;
      int box_index = box_row * SUDOKU_BOX_SIZE + box_col;

      if (box[sudoku[i][j] - 1]) {
        return false;
      } else {
        box[sudoku[i][j] - 1] = true;
      }
    }
  }
  return true;
}

bool solve_sudoku(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE]) {
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++) {
      if (sudoku[i][j] == 0) {
        for (int k = 1; k <= SUDOKU_SIZE; k++) {
          sudoku[i][j] = k;
          if (is_valid_sudoku(sudoku)) {
            if (solve_sudoku(sudoku)) {
              return true;
            }
          }
          sudoku[i][j] = 0;
        }
        return false;
      }
    }
  }
  return true;
}

int main() {
  int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];

  printf("Enter the sudoku puzzle (0 for empty cells):\n");
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++) {
      scanf("%d", &sudoku[i][j]);
    }
  }

  if (is_valid_sudoku(sudoku)) {
    if (solve_sudoku(sudoku)) {
      printf("Solved sudoku:\n");
      for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
          printf("%d ", sudoku[i][j]);
        }
        printf("\n");
      }
    } else {
      printf("No solution found.\n");
    }
  } else {
    printf("Invalid sudoku puzzle.\n");
  }

  return 0;
}