//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define EMPTY_SLOT -1

int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SLOT, EMPTY_SLOT, EMPTY_SLOT},
                              {EMPTY_SLOT, EMPTY_SLOT, EMPTY_SLOT},
                              {EMPTY_SLOT, EMPTY_SLOT, EMPTY_SLOT}};

int is_board_full() {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      if (board[r][c] == EMPTY_SLOT) {
        return 0;
      }
    }
  }
  return 1;
}

int has_player_won(int player) {
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

  return 0;
}

int main() {
  int current_player = 1;
  int game_status = 0;

  // Initialize the board
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      board[r][c] = EMPTY_SLOT;
    }
  }

  // Play the game until someone wins or the board is full
  while (!game_status) {
    int move_row, move_col;

    // Get the player's move
    printf("Enter row: ");
    scanf("%d", &move_row);

    printf("Enter column: ");
    scanf("%d", &move_col);

    // Validate the move
    if (board[move_row][move_col] != EMPTY_SLOT) {
      printf("Invalid move.\n");
      continue;
    }

    // Make the move
    board[move_row][move_col] = current_player;

    // Check if the player has won or the board is full
    game_status = has_player_won(current_player) || is_board_full();

    // Switch the current player
    current_player = (current_player == 1) ? 2 : 1;
  }

  // Print the winner or draw
  if (game_status) {
    printf("Congratulations! Player %d won!\n", current_player);
  } else {
    printf("It's a draw!\n");
  }

  return 0;
}