//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void drawBoard(int **board, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%c ", board[r][c] ? 'O' : '.');
    }
    printf("\n");
  }
}

int main() {
  int size = MAX_SIZE;
  int **board = (int **)malloc(size * sizeof(int *));
  for (int r = 0; r < size; r++) {
    board[r] = (int *)malloc(size * sizeof(int));
  }

  // Initial board setup
  board[1][1] = board[2][2] = board[3][3] = 1;

  // Paranoid game loop
  int round = 0;
  while (1) {
    round++;
    drawBoard(board, size);

    // Check for any living cells that need to die
    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        if (board[r][c] && (board[r-1][c] == 0 || board[r+1][c] == 0 || board[r][c-1] == 0 || board[r][c+1] == 0)) {
          board[r][c] = 0;
        }
      }
    }

    // Check if any dead cells should be brought back to life
    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        if (board[r][c] == 0 && (board[r-1][c] == 1 || board[r+1][c] == 1 || board[r][c-1] == 1 || board[r][c+1] == 1)) {
          board[r][c] = 1;
        }
      }
    }

    // Print round number
    printf("Round: %d\n", round);

    // Check if the game is over
    if (board[size-1][size-1] == 1) {
      break;
    }
  }

  drawBoard(board, size);

  return 0;
}