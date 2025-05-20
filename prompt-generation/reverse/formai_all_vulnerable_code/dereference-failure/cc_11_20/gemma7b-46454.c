//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Cryptic
#include <stdlib.h>
#include <time.h>

int main() {
  int **board = NULL;
  int board_size = 0;

  board_size = 20;
  board = malloc(board_size * sizeof(int *));
  for (int i = 0; i < board_size; i++) {
    board[i] = malloc(board_size * sizeof(int));
  }

  // Seed the random number generator
  srand(time(NULL));

  // Initialize the board
  for (int i = 0; i < board_size; i++) {
    for (int j = 0; j < board_size; j++) {
      board[i][j] = rand() % 2;
    }
  }

  // Play the game
  for (int t = 0; t < 100; t++) {
    for (int i = 0; i < board_size; i++) {
      for (int j = 0; j < board_size; j++) {
        int neighbors = 0;
        for (int r = -1; r <= 1; r++) {
          for (int c = -1; c <= 1; c++) {
            if (r == 0 && c == 0) continue;
            if (board[i + r][j + c] == 1) neighbors++;
          }
        }

        if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
        else if (board[i][j] == 0 && neighbors == 2) board[i][j] = 1;
      }
    }

    // Print the board
    for (int i = 0; i < board_size; i++) {
      for (int j = 0; j < board_size; j++) {
        printf("%d ", board[i][j]);
      }
      printf("\n");
    }

    // Sleep for a while
    sleep(1);
  }

  // Free the memory
  for (int i = 0; i < board_size; i++) {
    for (int j = 0; j < board_size; j++) {
      free(board[i][j]);
    }
    free(board[i]);
  }
  free(board);

  return 0;
}