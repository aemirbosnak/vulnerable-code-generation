//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENERATIONS 100

int main() {
  int **board;
  int board_size = 5;
  int generation = 0;
  int seed = time(NULL);
  srand(seed);

  // Allocate memory for the board
  board = (int **)malloc(board_size * sizeof(int *));
  for (int i = 0; i < board_size; i++) {
    board[i] = (int *)malloc(board_size * sizeof(int));
  }

  // Initialize the board
  for (int i = 0; i < board_size; i++) {
    for (int j = 0; j < board_size; j++) {
      board[i][j] = rand() % 2;
    }
  }

  // Simulate game of life for a number of generations
  while (generation < MAX_GENERATIONS) {
    generation++;

    // Calculate the number of neighbors for each cell
    for (int i = 0; i < board_size; i++) {
      for (int j = 0; j < board_size; j++) {
        int neighbors = 0;
        for (int x = -1; x <= 1; x++) {
          for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) continue;
            if (board[i + x][j + y] == 1) neighbors++;
          }
        }

        // Update the cell's state based on the number of neighbors
        if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
        if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
      }
    }

    // Print the board
    for (int i = 0; i < board_size; i++) {
      for (int j = 0; j < board_size; j++) {
        printf("%d ", board[i][j]);
      }
      printf("\n");
    }

    // Pause the game
    printf("Press any key to continue...");
    getchar();
  }

  // Free the memory allocated for the board
  for (int i = 0; i < board_size; i++) {
    for (int j = 0; j < board_size; j++) {
      free(board[i][j]);
    }
    free(board[i]);
  }

  free(board);

  return 0;
}