//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPOT '-'

int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT},
                              {EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT},
                              {EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT}};

int is_board_full() {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      if (board[r][c] == EMPTY_SPOT) {
        return 0;
      }
    }
  }
  return 1;
}

int check_win(char player) {
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

void place_move(char player, int row, int col) {
  if (board[row][col] != EMPTY_SPOT) {
    return;
  }

  board[row][col] = player;
}

int main() {
  char current_player = PLAYER_X;

  // Game loop
  while (!is_board_full() && !check_win(current_player)) {
    int row, col;

    // Get the move from the user
    printf("Enter row (1-3): ");
    scanf("%d", &row);

    printf("Enter column (1-3): ");
    scanf("%d", &col);

    // Place the move
    place_move(current_player, row, col);

    // Switch the player
    current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
  }

  // Check if the game has ended
  if (check_win(current_player) == 1) {
    printf("Winner: %c!\n", current_player);
  } else {
    printf("It's a draw.\n");
  }

  return 0;
}