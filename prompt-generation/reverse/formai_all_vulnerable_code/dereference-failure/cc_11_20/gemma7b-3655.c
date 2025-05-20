//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 20

int main() {
  int **board = (int **)malloc(DIM * sizeof(int *));
  for (int i = 0; i < DIM; i++) {
    board[i] = (int *)malloc(DIM * sizeof(int));
  }

  // Initialize the board
  for (int i = 0; i < DIM; i++) {
    for (int j = 0; j < DIM; j++) {
      board[i][j] = 0;
    }
  }

  // Seed the random number generator
  srand(time(NULL));

  // Place some random cells alive
  for (int i = 0; i < 10; i++) {
    board[rand() % DIM][rand() % DIM] = 1;
  }

  // Play the game of life
  int generation = 0;
  while (1) {
    // Calculate the next generation
    for (int i = 0; i < DIM; i++) {
      for (int j = 0; j < DIM; j++) {
        int num_alive = 0;
        for (int r = -1; r <= 1; r++) {
          for (int c = -1; c <= 1; c++) {
            if (board[i + r][j + c] == 1) {
              num_alive++;
            }
          }
        }
        if (board[i][j] == 1 && num_alive < 2) {
          board[i][j] = 0;
        } else if (board[i][j] == 0 && num_alive == 3) {
          board[i][j] = 1;
        }
      }
    }

    // Increment the generation
    generation++;

    // Print the board
    for (int i = 0; i < DIM; i++) {
      for (int j = 0; j < DIM; j++) {
        printf("%d ", board[i][j]);
      }
      printf("\n");
    }

    // Check if the game is over
    if (generation >= 10) {
      break;
    }
  }

  // Free the memory
  for (int i = 0; i < DIM; i++) {
    free(board[i]);
  }
  free(board);

  return 0;
}