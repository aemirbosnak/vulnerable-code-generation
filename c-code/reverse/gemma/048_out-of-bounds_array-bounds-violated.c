#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int player = 1;
  int move = 0;

  // Loop until the game is over
  while (!board[move]) {
    // Get the user's move
    printf("Enter your move (1-9): ");
    scanf("%d", &move);

    // Check if the move is valid
    if (move < 1 || move > 9) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Place the player's mark on the board
    board[move] = player;

    // Check if the player has won
    if (board[move] == player && (board[move-1] == player || board[move+1] == player || board[move-2] == player)) {
      printf("You have won!\n");
      break;
    }

    // Next turn
    player = (player == 1) ? 2 : 1;
  }

  // Game over
  if (board[move] == 0) {
    printf("It's a draw.\n");
  }

  return 0;
}
