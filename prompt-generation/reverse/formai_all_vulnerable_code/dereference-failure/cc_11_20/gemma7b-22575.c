//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define ALIVE 1
#define DEAD 0

int main() {
  int **board = NULL;
  int i, j, x, y;
  int seed = time(NULL);
  srand(seed);

  board = malloc(HEIGHT * sizeof(int *) * WIDTH);
  for (i = 0; i < HEIGHT; i++) {
    board[i] = malloc(WIDTH * sizeof(int));
  }

  // Initial game board
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      board[i][j] = ALIVE;
    }
  }

  // Simulate life
  for (x = 0; x < 10; x++) {
    for (y = 0; y < 10; y++) {
      int neighbors = 0;
      // Check neighbors
      for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
          if (board[i][j] == ALIVE && i != 0 && j != 0) {
            neighbors++;
          }
        }
      }

      // Rule of Life
      if (board[x][y] == ALIVE && neighbors < 2) {
        board[x][y] = DEAD;
      } else if (board[x][y] == ALIVE && neighbors > 3) {
        board[x][y] = DEAD;
      } else if (board[x][y] == DEAD && neighbors == 3) {
        board[x][y] = ALIVE;
      }
    }
  }

  // Print the final board
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  free(board);
  return 0;
}