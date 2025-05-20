//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Create a 2D array to store the game board
  int **board = (int **)malloc(5 * sizeof(int *));
  for (int i = 0; i < 5; i++) {
    board[i] = (int *)malloc(5 * sizeof(int));
  }

  // Initialize the board with random values
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      board[i][j] = rand() % 2;
    }
  }

  // Print the initial board
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  // Simulate the game of life
  for (int t = 0; t < 10; t++) {
    // Calculate the number of neighbors for each cell
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        int neighbors = 0;
        if (board[i - 1][j] == 1) neighbors++;
        if (board[i + 1][j] == 1) neighbors++;
        if (board[i][j - 1] == 1) neighbors++;
        if (board[i][j + 1] == 1) neighbors++;
        board[i][j] = (neighbors == 2) || (neighbors == 3);
      }
    }
  }

  // Print the final board
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the board
  for (int i = 0; i < 5; i++) {
    free(board[i]);
  }
  free(board);

  return 0;
}