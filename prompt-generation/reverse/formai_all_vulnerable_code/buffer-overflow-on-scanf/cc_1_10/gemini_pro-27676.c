//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 9

int board[N][N];
int rows[N][N] = {0};
int cols[N][N] = {0};
int sqrs[N][N] = {0};

int sqr(int row, int col) {
  return (row / 3) * 3 + (col / 3);
}

void print() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int solve(int row, int col) {
  if (row == N) {
    print();
    return 1;
  }

  if (board[row][col] != 0) {
    return solve(row + (col + 1) / N, (col + 1) % N);
  }

  for (int i = 0; i < N; i++) {
    if (rows[row][i] || cols[col][i] || sqrs[sqr(row, col)][i]) {
      continue;
    }

    board[row][col] = i + 1;
    rows[row][i] = cols[col][i] = sqrs[sqr(row, col)][i] = 1;
    if (solve(row + (col + 1) / N, (col + 1) % N)) {
      return 1;
    }
    board[row][col] = 0;
    rows[row][i] = cols[col][i] = sqrs[sqr(row, col)][i] = 0;
  }

  return 0;
}

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] != 0) {
        rows[i][board[i][j] - 1] = cols[j][board[i][j] - 1] = sqrs[sqr(i, j)][board[i][j] - 1] = 1;
      }
    }
  }

  solve(0, 0);

  return 0;
}