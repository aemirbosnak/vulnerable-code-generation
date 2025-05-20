//FormAI DATASET v1.0 Category: Sudoku solver ; Style: excited
#include <stdio.h>

// function to print the Sudoku grid
void printGrid(int grid[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// function to check if the current number is valid
int isSafe(int grid[9][9], int row, int col, int num) {
  // checking for the same number in the same row
  for (int i = 0; i < 9; i++) {
    if (grid[row][i] == num) {
      return 0;
    }
  }
  
  // checking for the same number in the same column
  for (int i = 0; i < 9; i++) {
    if (grid[i][col] == num) {
      return 0;
    }
  }
  
  // checking for the same number in the same 3x3 square
  int startRow = row - row % 3;
  int startCol = col - col % 3;
  
  for (int i = startRow; i < startRow + 3; i++) {
    for (int j = startCol; j < startCol + 3; j++) {
      if (grid[i][j] == num) {
        return 0;
      }
    }
  }
  
  // if the number is safe, return 1
  return 1;
}

// function to solve the Sudoku grid
int solveSudoku(int grid[9][9]) {
  int row, col;
  
  // if there are no empty cells remaining, the grid is solved
  if (!findEmptyCell(grid, &row, &col)) {
    return 1;
  }
  
  // trying out different numbers in the empty cells
  for (int i = 1; i <= 9; i++) {
    if (isSafe(grid, row, col, i)) {
      grid[row][col] = i;
      
      if (solveSudoku(grid)) {
        return 1;
      }
      
      grid[row][col] = 0; // backtrack
    }
  }
  
  return 0;
}

// function to find the next empty cell
int findEmptyCell(int grid[9][9], int *row, int *col) {
  for (*row = 0; *row < 9; (*row)++) {
    for (*col = 0; *col < 9; (*col)++) {
      if (grid[*row][*col] == 0) {
        return 1; // empty cell found
      }
    }
  }
  
  return 0; // no empty cells remaining
}

// main function
int main() {
  int grid[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0}};
  
  // taking input from the user
  printf("Enter the Sudoku grid:\n");
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &grid[i][j]);
    }
  }
  
  // solving the Sudoku grid
  if (solveSudoku(grid)) {
    printf("\nSudoku solved successfully!\n");
    printGrid(grid);
  } else {
    printf("\nSorry, the Sudoku grid cannot be solved.\n");
  }
  
  return 0;
}