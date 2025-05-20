//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Define a 2D array to store the game board.
  int **board = malloc(5 * sizeof(int *));
  for (int i = 0; i < 5; i++) {
    board[i] = malloc(5 * sizeof(int));
  }

  // Initialize the game board.
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      board[i][j] = 0;
    }
  }

  // Place the initial cells.
  board[2][2] = 1;
  board[2][3] = 1;
  board[3][2] = 1;
  board[3][3] = 1;

  // Simulate the game of life.
  int generations = 0;
  while (board[2][2] || board[2][3] || board[3][2] || board[3][3]) {
    // Calculate the number of neighbors for each cell.
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        int neighbors = 0;
        if (board[i - 1][j] == 1) neighbors++;
        if (board[i + 1][j] == 1) neighbors++;
        if (board[i][j - 1] == 1) neighbors++;
        if (board[i][j + 1] == 1) neighbors++;
        if (board[i][j] == 1) neighbors--;
        board[i][j] = neighbors > 1 ? 1 : 0;
      }
    }

    // Increment the number of generations.
    generations++;

    // Print the game board.
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        printf("%d ", board[i][j]);
      }
      printf("\n");
    }

    // Free the memory allocated for the game board.
    for (int i = 0; i < 5; i++) {
      free(board[i]);
    }
    free(board);
  }

  // Print the number of generations.
  printf("Number of generations: %d\n", generations);

  return 0;
}