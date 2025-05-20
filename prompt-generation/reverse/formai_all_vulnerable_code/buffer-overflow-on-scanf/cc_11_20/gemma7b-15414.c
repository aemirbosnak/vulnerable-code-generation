//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define EMPTY_SLOT 0
#define PLAYER_X 1
#define PLAYER_O 2

int main() {
  int board[BOARD_SIZE][BOARD_SIZE] = { { EMPTY_SLOT, EMPTY_SLOT, EMPTY_SLOT },
    { EMPTY_SLOT, EMPTY_SLOT, EMPTY_SLOT },
    { EMPTY_SLOT, EMPTY_SLOT, EMPTY_SLOT } };

  int current_player = PLAYER_X;
  int game_won = 0;

  // Game loop
  while (!game_won) {
    // Get the player's move
    int move_row, move_col;
    printf("Enter your move (row, column): ");
    scanf("%d %d", &move_row, &move_col);

    // Validate the move
    if (move_row < 0 || move_row >= BOARD_SIZE) {
      printf("Invalid move. Please try again.\n");
      continue;
    }
    if (move_col < 0 || move_col >= BOARD_SIZE) {
      printf("Invalid move. Please try again.\n");
      continue;
    }
    if (board[move_row][move_col] != EMPTY_SLOT) {
      printf("That slot is already taken. Please try again.\n");
      continue;
    }

    // Make the move
    board[move_row][move_col] = current_player;

    // Check if the player has won
    game_won = check_win(board, current_player);

    // Switch to the next player
    current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
  }

  // Game over
  printf("Game over! The winner is: ");
  printf((game_won == PLAYER_X) ? "Player X" : "Player O");

  return 0;
}

int check_win(int **board, int player) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board[r][0] == player && board[r][1] == player && board[r][2] == player) {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board[0][c] == player && board[1][c] == player && board[2][c] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }

  // No win
  return 0;
}