//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 9
#define ROWS SIZE
#define COLUMNS SIZE
#define BOXES SIZE

#define EMPTY 0

typedef struct {
  int grid[ROWS][COLUMNS];
  int solved;
} Sudoku;

/* Function to print the Sudoku grid */
void print_sudoku(Sudoku *sudoku) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      if (sudoku->grid[i][j] == EMPTY) {
        printf("  ");
      } else {
        printf("%d ", sudoku->grid[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");
}

/* Function to check if a number is present in a row */
int check_row(Sudoku *sudoku, int row, int number) {
  for (int i = 0; i < ROWS; i++) {
    if (sudoku->grid[row][i] == number) {
      return 1;
    }
  }
  return 0;
}

/* Function to check if a number is present in a column */
int check_column(Sudoku *sudoku, int column, int number) {
  for (int i = 0; i < ROWS; i++) {
    if (sudoku->grid[i][column] == number) {
      return 1;
    }
  }
  return 0;
}

/* Function to check if a number is present in a box */
int check_box(Sudoku *sudoku, int row, int column, int number) {
  int box_row = row / 3;
  int box_column = column / 3;
  for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
    for (int j = box_column * 3; j < box_column * 3 + 3; j++) {
      if (sudoku->grid[i][j] == number) {
        return 1;
      }
    }
  }
  return 0;
}

/* Function to check if a number is safe to place in a cell */
int is_safe(Sudoku *sudoku, int row, int column, int number) {
  return !check_row(sudoku, row, number) && !check_column(sudoku, column, number) && !check_box(sudoku, row, column, number);
}

/* Recursively solves the Sudoku puzzle */
int solve_sudoku(Sudoku *sudoku, int row, int column) {
  if (row == ROWS) {
    sudoku->solved = 1;
    return 1;
  }

  if (column == COLUMNS) {
    return solve_sudoku(sudoku, row + 1, 0);
  }

  if (sudoku->grid[row][column] != EMPTY) {
    return solve_sudoku(sudoku, row, column + 1);
  }

  for (int number = 1; number <= SIZE; number++) {
    if (is_safe(sudoku, row, column, number)) {
      sudoku->grid[row][column] = number;
      if (solve_sudoku(sudoku, row, column + 1)) {
        return 1;
      }
    }
  }

  sudoku->grid[row][column] = EMPTY;
  return 0;
}

/* Function to read a Sudoku puzzle from a file */
int read_sudoku(Sudoku *sudoku, char* filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return 0;
  }

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      fscanf(fp, "%d ", &sudoku->grid[i][j]);
    }
  }

  fclose(fp);
  return 1;
}

/* Main function */
int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  Sudoku sudoku;
  sudoku.solved = 0;

  if (!read_sudoku(&sudoku, argv[1])) {
    printf("Error reading Sudoku puzzle from file.\n");
    return 1;
  }

  printf("Original Sudoku puzzle:\n");
  print_sudoku(&sudoku);

  if (!solve_sudoku(&sudoku, 0, 0)) {
    printf("No solution found.\n");
  } else {
    printf("Solved Sudoku puzzle:\n");
    print_sudoku(&sudoku);
  }

  return 0;
}