//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX 25

int main() {
  int **board = (int **)malloc(MAX * sizeof(int *));
  for (int i = 0; i < MAX; i++) {
    board[i] = (int *)malloc(MAX * sizeof(int));
  }

  // Initialize the board
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      board[i][j] = 0;
    }
  }

  // Game of Life rules
  board[1][1] = 1;
  board[2][2] = 1;
  board[2][3] = 1;
  board[3][2] = 1;
  board[3][3] = 1;

  // Simulate the game
  int generations = 0;
  while ( generations < 10) {
    // Calculate the next generation
    for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < MAX; j++) {
        int num_neighbors = 0;
        for (int x = -1; x <= 1; x++) {
          for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) continue;
            if (board[i + x][j + y] == 1) num_neighbors++;
          }
        }
        if (num_neighbors == 2) board[i][j] = 1;
        else board[i][j] = 0;
      }
    }

    // Print the board
    for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < MAX; j++) {
        printf("%d ", board[i][j]);
      }
      printf("\n");
    }

     generations++;
  }

  // Free the memory
  for (int i = 0; i < MAX; i++) {
    free(board[i]);
  }
  free(board);

  return 0;
}