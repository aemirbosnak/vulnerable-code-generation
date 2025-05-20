//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
  system("clear");
  int board[20][20] = {{0}};
  int x, y, n, i, j;

  // Game setup
  board[10][10] = 1;
  board[10][11] = 1;
  board[11][10] = 1;
  board[11][11] = 1;

  // Game loop
  while (1) {
    // Calculate next generation
    for (i = 0; i < 20; i++) {
      for (j = 0; j < 20; j++) {
        int neighbors = 0;
        // Check neighbors
        if (board[i - 1][j] == 1) neighbors++;
        if (board[i + 1][j] == 1) neighbors++;
        if (board[i][j - 1] == 1) neighbors++;
        if (board[i][j + 1] == 1) neighbors++;

        // Apply rules
        if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
        if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
      }
    }

    // Print board
    system("clear");
    for (x = 0; x < 20; x++) {
      for (y = 0; y < 20; y++) {
        printf("%d ", board[x][y]);
      }
      printf("\n");
    }

    // Check if game is over
    if (board[10][10] == 0) break;

    // Pause
    system("pause");
  }

  return 0;
}