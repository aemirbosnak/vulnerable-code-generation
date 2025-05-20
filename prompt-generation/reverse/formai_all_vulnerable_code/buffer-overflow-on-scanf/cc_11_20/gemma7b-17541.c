//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
  int board[MAX][MAX] = {0};
  int x, y, i, j, n, m;

  printf("Enter number of rows: ");
  scanf("%d", &n);

  printf("Enter number of columns: ");
  scanf("%d", &m);

  printf("Enter number of iterations: ");
  scanf("%d", &i);

  for (x = 0; x < n; x++) {
    for (y = 0; y < m; y++) {
      board[x][y] = rand() % 2;
    }
  }

  for (j = 0; j < i; j++) {
    for (x = 0; x < n; x++) {
      for (y = 0; y < m; y++) {
        if (board[x][y] == 1) {
          board[x][y] = 2;
          if (x > 0 && board[x - 1][y] == 1) {
            board[x - 1][y] = 2;
          }
          if (x < n - 1 && board[x + 1][y] == 1) {
            board[x + 1][y] = 2;
          }
          if (y > 0 && board[x][y - 1] == 1) {
            board[x][y - 1] = 2;
          }
          if (y < m - 1 && board[x][y + 1] == 1) {
            board[x][y + 1] = 2;
          }
        }
      }
    }
  }

  for (x = 0; x < n; x++) {
    for (y = 0; y < m; y++) {
      if (board[x][y] == 2) {
        printf("(%d, %d) is wet\n", x, y);
      }
    }
  }

  return 0;
}