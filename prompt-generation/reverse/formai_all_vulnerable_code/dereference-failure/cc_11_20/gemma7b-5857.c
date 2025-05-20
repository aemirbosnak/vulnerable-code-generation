//Gemma-7B DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
  int player_1_wins = 0;
  int player_2_wins = 0;
  int current_player = 1;
  int board[6][6] = {{0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}};

  // Game Loop
  while (player_1_wins == 0 && player_2_wins == 0) {
    // Get the player's move
    int move_row, move_col;
    printf("Enter your move (row, column): ");
    scanf("%d %d", &move_row, &move_col);

    // Check if the move is valid
    if (move_row < 0 || move_row >= 6) {
      printf("Invalid move. Please try again.\n");
      continue;
    }
    if (move_col < 0 || move_col >= 6) {
      printf("Invalid move. Please try again.\n");
      continue;
    }
    if (board[move_row][move_col] != 0) {
      printf("Invalid move. That space has already been taken.\n");
      continue;
    }

    // Place the player's piece on the board
    board[move_row][move_col] = current_player;

    // Check if the player has won
    if (check_win(board, current_player) == 1) {
      player_1_wins++;
      if (current_player == 1) {
        printf("You have won!\n");
      } else {
        printf("Player 1 has won.\n");
      }
    } else {
      // Switch to the next player
      current_player = (current_player == 1) ? 2 : 1;
    }
  }

  // End of Game Loop

  // Print the final score
  printf("Final Score:\n");
  printf("Player 1: %d\n", player_1_wins);
  printf("Player 2: %d\n", player_2_wins);

  return 0;
}

int check_win(int **board, int player) {
  // Check rows
  for (int r = 0; r < 6; r++) {
    for (int c = 0; c < 6; c++) {
      if (board[r][c] == player && board[r][c] == board[r][c+1] && board[r][c] == board[r][c+2] && board[r][c] == board[r][c+3] && board[r][c] == board[r][c+4]) {
        return 1;
      }
    }
  }

  // Check columns
  for (int c = 0; c < 6; c++) {
    for (int r = 0; r < 6; r++) {
      if (board[r][c] == player && board[r+1][c] == player && board[r+2][c] == player && board[r+3][c] == player && board[r+4][c] == player) {
        return 1;
      }
    }
  }

  // Check diagonals
  for (int d = 0; d < 6; d++) {
    for (int r = 0; r < 6; r++) {
      for (int c = 0; c < 6; c++) {
        if (board[r][c] == player && board[r+1][c+1] == player && board[r+2][c+2] == player && board[r+3][c+3] == player && board[r+4][c+4] == player) {
          return 1;
        }
      }
    }
  }

  // If no winner, return 0
  return 0;
}