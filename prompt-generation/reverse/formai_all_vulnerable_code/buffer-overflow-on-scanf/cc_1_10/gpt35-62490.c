//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

void print_sudoku(int matrix[9][9]) {
  printf(" -----------------------\n");
  for (int i = 0; i < 9; i++) {
    printf("| ");
    for (int j = 0; j < 9; j++) {
      printf("%d ", matrix[i][j]);
      if ((j+1) % 3 == 0) printf("| ");
    }
    printf("\n");
    if ((i+1) % 3 == 0) printf(" -----------------------\n");
  }
}

int solve_sudoku(int matrix[9][9], int row, int col) {
  if (row == 9) return 1;
  if (col == 9) return solve_sudoku(matrix, row+1, 0);
  if (matrix[row][col] != 0) return solve_sudoku(matrix, row, col+1);

  for (int num = 1; num <= 9; num++) {
    int can_place = 1;
    for (int i = 0; i < 9; i++) {
      if (matrix[row][i] == num || matrix[i][col] == num ||
          matrix[3*(row/3)+i/3][3*(col/3)+i%3] == num) {
        can_place = 0;
        break;
      }
    }
    if (!can_place) continue;
    matrix[row][col] = num;
    if (solve_sudoku(matrix, row, col+1)) return 1;
    matrix[row][col] = 0;
  }
  return 0;
}

void fill_sudoku(int matrix[9][9]) {
  printf("Enter the sudoku matrix (0 for empty cells):\n");
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

int main() {
  int matrix[9][9];
  fill_sudoku(matrix);
  if (solve_sudoku(matrix, 0, 0)) {
    printf("The solved sudoku is:\n");
    print_sudoku(matrix);
  }
  else {
    printf("This sudoku cannot be solved.\n");
  }
  return 0;
}