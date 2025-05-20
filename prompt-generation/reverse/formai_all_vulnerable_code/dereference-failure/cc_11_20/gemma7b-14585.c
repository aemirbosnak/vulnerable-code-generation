//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int main() {
  int **board = NULL;
  board = (int **)malloc(MAX_SIZE * sizeof(int *));
  for (int i = 0; i < MAX_SIZE; i++) {
    board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
  }

  // Initialize the board
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      board[i][j] = 0;
    }
  }

  // Place some seeds
  board[2][2] = 1;
  board[3][3] = 1;
  board[4][4] = 1;

  // Simulate life
  for (int t = 0; t < 20; t++) {
    for (int i = 0; i < MAX_SIZE; i++) {
      for (int j = 0; j < MAX_SIZE; j++) {
        int neighbors = 0;
        if (board[i-1][j] == 1) neighbors++;
        if (board[i+1][j] == 1) neighbors++;
        if (board[i][j-1] == 1) neighbors++;
        if (board[i][j+1] == 1) neighbors++;

        if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
        if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) board[i][j] = 0;
      }
    }
  }

  // Print the final board
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < MAX_SIZE; i++) {
    free(board[i]);
  }
  free(board);

  return 0;
}