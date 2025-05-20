//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Allocate memory for a 2D array
  int **board = malloc(5 * sizeof(int *));
  for (int i = 0; i < 5; i++) {
    board[i] = malloc(5 * sizeof(int));
  }

  // Initialize the board
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      board[i][j] = 0;
    }
  }

  // Seed the random number generator
  srand(time(NULL));

  // Randomly assign some cells to be alive
  for (int i = 0; i < 10; i++) {
    board[rand() % 5][rand() % 5] = 1;
  }

  // Simulate the game of life
  for (int t = 0; t < 10; t++) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        int num_alive = 0;
        // Check the neighbors
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (board[i + dx][j + dy] == 1) {
              num_alive++;
            }
          }
        }
        // Apply the rules of life
        if (board[i][j] == 1 && num_alive < 2) {
          board[i][j] = 0;
        } else if (board[i][j] == 0 && num_alive == 3) {
          board[i][j] = 1;
        }
      }
    }

    // Print the board
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        printf("%d ", board[i][j]);
      }
      printf("\n");
    }
  }

  // Free the memory
  for (int i = 0; i < 5; i++) {
    free(board[i]);
  }
  free(board);

  return 0;
}