//GEMINI-pro DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define the game board
int board[3][3] = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
};

// Define the current player
int current_player = 1;

// Define the winner
int winner = 0;

// Declare the main function
int main() {
  // Welcome the player
  printf("Welcome to Tic-Tac-Toe!\n");

  // While the game is not over
  while (winner == 0) {
    // Print the game board
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == 0) {
          printf(" ");
        } else if (board[i][j] == 1) {
          printf("X");
        } else if (board[i][j] == 2) {
          printf("O");
        }
      }
      printf("\n");
    }

    // Get the player's move
    int row, col;
    printf("Player %d, enter your move (row, col): ", current_player);
    scanf("%d %d", &row, &col);

    // Place the player's move on the game board
    board[row][col] = current_player;

    // Check for a winner
    winner = check_winner(board);

    // Switch the current player
    if (current_player == 1) {
      current_player = 2;
    } else {
      current_player = 1;
    }
  }

  // Print the winner
  if (winner == 1) {
    printf("Player 1 wins!\n");
  } else if (winner == 2) {
    printf("Player 2 wins!\n");
  } else {
    printf("Tie!\n");
  }

  // Return 0
  return 0;
}

// Check for a winner
int check_winner(int board[3][3]) {
  // Check for a winner in the rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0];
    }
  }

  // Check for a winner in the columns
  for (int j = 0; j < 3; j++) {
    if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return board[0][j];
    }
  }

  // Check for a winner in the diagonals
  if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0];
  }
  if (board[2][0] != 0 && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
    return board[2][0];
  }

  // No winner yet
  return 0;
}