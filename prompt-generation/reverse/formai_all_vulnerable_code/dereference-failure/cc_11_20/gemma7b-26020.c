//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a game of life board
  int **board = malloc(HEIGHT * sizeof(int *));
  for (int i = 0; i < HEIGHT; i++) {
    board[i] = malloc(WIDTH * sizeof(int));
  }

  // Initialize the board
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      board[y][x] = rand() % 2;
    }
  }

  // Simulate life
  for (int t = 0; t < 100; t++) {
    // Calculate the number of neighbors for each cell
    for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
        int neighbors = 0;
        for (int dy = -1; dy <= 1; dy++) {
          for (int dx = -1; dx <= 1; dx++) {
            if (x + dx >= 0 && x + dx < WIDTH && y + dy >= 0 && y + dy < HEIGHT) {
              neighbors++;
            }
          }
        }

        // Apply the rules of life
        if (board[y][x] == 1 && neighbors < 2) {
          board[y][x] = 0;
        } else if (board[y][x] == 0 && neighbors == 3) {
          board[y][x] = 1;
        }
      }
    }

    // Print the board
    for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
        printf("%d ", board[y][x]);
      }
      printf("\n");
    }
  }

  // Free the memory allocated for the board
  for (int i = 0; i < HEIGHT; i++) {
    free(board[i]);
  }
  free(board);

  return 0;
}