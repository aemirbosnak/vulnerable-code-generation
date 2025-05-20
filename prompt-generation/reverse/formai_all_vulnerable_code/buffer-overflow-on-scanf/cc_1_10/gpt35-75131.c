//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Romeo and Juliet
#include <stdio.h>

int sudoku[9][9];

int checkRow(int row, int num) {
  for (int col = 0; col < 9; col++) {
    if (sudoku[row][col] == num) {
      return 0; // not valid
    }
  }
  return 1; // valid
}

int checkColumn(int col, int num) {
  for (int row = 0; row < 9; row++) {
    if (sudoku[row][col] == num) {
      return 0; // not valid
    }
  }
  return 1; // valid
}

int checkBox(int boxStartRow, int boxStartCol, int num) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (sudoku[row + boxStartRow][col + boxStartCol] == num) {
        return 0; // not valid
      }
    }
  }
  return 1; // valid
}

int checkValidity(int row, int col, int num) {
  // Check if number is valid in current row, column and box
  return checkRow(row, num) && checkColumn(col, num) && checkBox(row - row % 3, col - col % 3, num);
}

int solveSudoku() {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (sudoku[row][col] == 0) {
        for (int num = 1; num <= 9; num++) { // Check if num is valid
          if (checkValidity(row, col, num) == 1) {
            sudoku[row][col] = num; // Put num in cell
            if (solveSudoku() == 1) {
              return 1; // Solved!
            } else {
              sudoku[row][col] = 0; // Reset cell
            }
          }
        }
        return 0; // Can't solve
      }
    }
  }
  return 1; // Solved!
}

int main() {
  printf("Alas, sweet sudoku, I shall solve thee!\n");
  
  // Set up sudoku
  printf("Enter sudoku in row-major order (0 for blank cells):\n");
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      scanf("%d", &sudoku[row][col]);
    }
  }
  
  // Solve sudoku
  if (solveSudoku() == 1) {
    printf("Ere be the solution:\n");
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        printf("%d ", sudoku[row][col]);
      }
      printf("\n");
    }
  } else {
    printf("I hae been defeated, I cannot solve this sudoku!\n");
  }
  
  return 0;
}