//FormAI DATASET v1.0 Category: Sudoku solver ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#define N 9

int grid[N][N];

int findEmpty(int *row, int *col) {
  for (*row = 0; *row < N; (*row)++) {
    for (*col = 0; *col < N; (*col)++) {
      if (grid[*row][*col] == 0) {
        return 1; 
      }
    }
  }
  return 0; 
}

int isValid(int row, int col, int num) {
  int i, j;
  for (i = 0; i < N; i++) {
    if (grid[row][i] == num) {
      return 0;
    }
    if (grid[i][col] == num) {
      return 0;
    }
  }
  int boxRow = row - row % 3;
  int boxCol = col - col % 3;
  for (i = boxRow; i < boxRow + 3; i++) {
    for (j = boxCol; j < boxCol + 3; j++) {
      if (grid[i][j] == num) {
        return 0;
      }
    }
  }
  return 1;
}

int solveSudoku() {
  int row, col;
  if (!findEmpty(&row, &col)) {
    return 1;
  }
  int i;
  for (i = 1; i <= 9; i++) {
    if (isValid(row, col, i)) {
      grid[row][col] = i; 
      if (solveSudoku()) {
        return 1; 
      }
      grid[row][col] = 0; 
    }
  }
  return 0;
}

void printSudoku() {
  int i,j;
  printf("\n-------------\n");
  for(i=0;i<9;i++) {
    printf("| ");
    for(j=0;j<9;j++) {
      printf("%d ", grid[i][j]);
      if ((j+1) % 3 == 0) printf("| ");
    }
    printf("\n");
    if ((i+1) % 3 == 0) printf("-------------\n");
  }
}

int main() {
  int i,j;
  printf("Enter the Sudoku puzzle (use 0 to indicate empty cells):\n");
  for(i=0;i<9;i++) {
    printf("Row %d: ",i+1);
    for(j=0;j<9;j++) {
      scanf("%d",&grid[i][j]);
    }
  }
  if(solveSudoku()) {
    printf("\nSudoku Solution:\n");
    printSudoku();
  } else {
    printf("\nNo solution found.\n");
  }
  return 0;
}