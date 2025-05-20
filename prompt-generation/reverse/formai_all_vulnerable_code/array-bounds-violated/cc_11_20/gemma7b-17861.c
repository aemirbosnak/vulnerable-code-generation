//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 4

int main() {
  int numPlayers = 0, i, currentPlayer = 0, board[MAX_Players][MAX_Players] = {0};
  char turn = 'X';

  // Initialize the game board
  for (i = 0; i < MAX_Players; i++) {
    for (int j = 0; j < MAX_Players; j++) {
      board[i][j] = 0;
    }
  }

  // Get the number of players
  printf("Enter the number of players (1-4): ");
  scanf("%d", &numPlayers);

  // Join the game
  for (i = 0; i < numPlayers; i++) {
    board[currentPlayer][currentPlayer] = 1;
    currentPlayer++;
  }

  // Play the game
  while (!board[currentPlayer][currentPlayer] && numPlayers > 1) {
    // Get the move
    int row, column;
    printf("Enter the row (1-3): ");
    scanf("%d", &row);
    printf("Enter the column (1-3): ");
    scanf("%d", &column);

    // Check if the move is valid
    if (board[row][column] != 0) {
      printf("Invalid move.\n");
      continue;
    }

    // Make the move
    board[row][column] = turn;

    // Change the turn
    turn = (turn == 'X') ? 'O' : 'X';

    // Check if the player has won
    if (board[row][column] == turn && board[row][column] == board[row][currentPlayer - 1] && board[row][column] == board[row][currentPlayer - 2]) {
      printf("Player %c has won!\n", turn);
      break;
    }

    // Increment the current player
    currentPlayer++;
  }

  // End the game
  printf("Game over.\n");

  return 0;
}