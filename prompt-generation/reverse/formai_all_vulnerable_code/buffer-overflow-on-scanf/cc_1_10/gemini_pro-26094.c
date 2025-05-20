//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
#include <stdio.h>

#define SIZE 9

int grid[SIZE][SIZE];
int solved;

void print_grid() {
  int i, j;
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int is_valid(int row, int col, int num) {
  int i, j;

  for (i = 0; i < SIZE; i++) {
    if (grid[row][i] == num) {
      return 0;
    }
  }

  for (j = 0; j < SIZE; j++) {
    if (grid[j][col] == num) {
      return 0;
    }
  }

  int box_row = row / 3;
  int box_col = col / 3;

  for (i = box_row * 3; i < box_row * 3 + 3; i++) {
    for (j = box_col * 3; j < box_col * 3 + 3; j++) {
      if (grid[i][j] == num) {
        return 0;
      }
    }
  }

  return 1;
}

void solve(int row, int col) {
  if (row == SIZE) {
    solved = 1;
    return;
  }

  if (col == SIZE) {
    solve(row + 1, 0);
    return;
  }

  if (grid[row][col] != 0) {
    solve(row, col + 1);
    return;
  }

  int i;
  for (i = 1; i <= SIZE; i++) {
    if (is_valid(row, col, i)) {
      grid[row][col] = i;
      solve(row, col + 1);
      if (solved) {
        return;
      }
      grid[row][col] = 0;
    }
  }
}

int main() {
  int i, j;

  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  solve(0, 0);

  if (solved) {
    print_grid();
  } else {
    printf("No solution\n");
  }

  return 0;
}