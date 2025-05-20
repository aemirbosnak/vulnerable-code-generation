//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawBoard(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%c ", board[i][j] ? 'O' : '.');
    }
    printf("\n");
  }
}

int main() {
  int size = 5;
  int **board = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    board[i] = (int *)malloc(size * sizeof(int));
  }

  // Seed the random number generator
  srand(time(NULL));

  // Initialize the board
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      board[i][j] = rand() % 2;
    }
  }

  // Draw the board
  drawBoard(board, size);

  // Game loop
  int generation = 0;
  while (1) {
    // Calculate the next generation
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        int neighbours = 0;
        for (int x = -1; x <= 1; x++) {
          for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) continue;
            if (board[i + x][j + y] == 'O') neighbours++;
          }
        }
        if (board[i][j] == 'O' && neighbours < 2) board[i][j] = '.';
        else if (board[i][j] == '.' && neighbours == 3) board[i][j] = 'O';
      }
    }

    // Draw the board
    drawBoard(board, size);

    // Increment the generation
    generation++;

    // Check if the game is over
    if (generation > 10) break;
  }

  // Free the memory
  for (int i = 0; i < size; i++) {
    free(board[i]);
  }
  free(board);

  return 0;
}