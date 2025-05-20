//FormAI DATASET v1.0 Category: Sudoku solver ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define N 9

int board[N][N];

void print_board() {
  printf("-------------------\n");
  for (int i = 0; i < N; i++) {
    printf("| ");
    for (int j = 0; j < N; j++) {
      printf("%d ", board[i][j]);
      if (j % 3 == 2) {
        printf("| ");
      }
    }
    printf("\n");
    if (i % 3 == 2) {
      printf("-------------------\n");
    }
  }
}

int is_safe(int row, int col, int num) {
  for (int i = 0; i < N; i++) {
    if (board[row][i] == num || board[i][col] == num) {
      return 0;
    }
  }
  int r = row - row % 3;
  int c = col - col % 3;
  for (int i = r; i < r + 3; i++) {
    for (int j = c; j < c + 3; j++) {
      if (board[i][j] == num) {
        return 0;
      }
    }
  }
  return 1;
}

int solve() {
  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      if (board[row][col] == 0) {
        for (int num = 1; num <= N; num++) {
          if (is_safe(row, col, num)) {
            board[row][col] = num;
            if (solve()) {
              return 1;
            }
            board[row][col] = 0;
          }
        }
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  printf("Enter the Sudoku board:\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  printf("\nInitial Sudoku board:\n");
  print_board();
  if (solve()) {
    printf("\nSolution:\n");
    print_board();
  } else {
    printf("\nInvalid board!\n");
  }
  return 0;
}