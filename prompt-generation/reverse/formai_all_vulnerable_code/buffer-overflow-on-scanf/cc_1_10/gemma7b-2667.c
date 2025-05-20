//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 64

void drawBoard(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%c ", board[i][j] ? board[i][j] : '.');
    }
    printf("\n");
  }
}

int main() {
  int board[BOARD_SIZE] = {0};
  int turn = 0;

  // Place the initial pieces
  board[2] = 1;
  board[4] = 1;
  board[5] = 2;
  board[6] = 2;

  // Game loop
  while (!board[BOARD_SIZE - 1] || board[BOARD_SIZE - 2]) {
    // Get the move
    int move = 0;
    printf("Enter your move (e.g. 2-4): ");
    scanf("%d", &move);

    // Validate the move
    if (move < 1 || move > BOARD_SIZE - 1) {
      printf("Invalid move.\n");
      continue;
    }

    // Make the move
    int from = move - 1;
    int to = move - 1;
    board[to] = board[from] * 2;
    board[from] = 0;

    // Change turns
    turn = (turn + 1) % 2;

    // Draw the board
    drawBoard(board, BOARD_SIZE);

    // Check if the game is over
    if (board[BOARD_SIZE - 1] || board[BOARD_SIZE - 2]) {
      printf("Game over!\n");
      break;
    }
  }

  return 0;
}