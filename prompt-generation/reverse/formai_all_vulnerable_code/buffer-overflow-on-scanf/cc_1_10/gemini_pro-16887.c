//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int board[9][9];

int is_valid(int row, int col, int val) {
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == val || board[i][col] == val) {
      return 0;
    }
  }

  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
    for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
      if (board[i][j] == val) {
        return 0;
      }
    }
  }

  return 1;
}

int solve(int row, int col) {
  if (row == 9) {
    return 1;
  }

  if (col == 9) {
    return solve(row + 1, 0);
  }

  if (board[row][col] != 0) {
    return solve(row, col + 1);
  }

  for (int val = 1; val <= 9; val++) {
    if (is_valid(row, col, val)) {
      board[row][col] = val;
      if (solve(row, col + 1)) {
        return 1;
      }
    }
  }

  board[row][col] = 0;
  return 0;
}

void print_board() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  printf("Let's solve this Sudoku puzzle!\n");
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  if (solve(0, 0)) {
    printf("Yay! We found a solution!\n");
    print_board();
  } else {
    printf("Aww, we couldn't solve the puzzle. :( Maybe try again?");
  }

  return 0;
}