#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char board[64] = {0};
  char move[10] = "";

  // Initialize the board
  board[0] = 'X';
  board[1] = 'O';
  board[2] = 'X';
  board[3] = 'O';
  board[4] = 'X';

  // Get the player's move
  gets(move);

  // Check if the move is valid
  if (move[0] < 'a' || move[0] > 'h') {
    printf("Invalid move.\n");
    return 1;
  }

  // Check if the move is a win
  if (board[move[0] - 'a'] == 'X' && (board[move[0] - 'a'] - 1) % 3 == 0) {
    printf("You win!\n");
  } else {
    printf("Invalid move.\n");
  }

  return 0;
}
