//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: standalone
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPACE ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                              {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                              {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE}};

int move_available(int row, int col) {
  return board[row][col] == EMPTY_SPACE;
}

int place_move(int row, int col, char player) {
  if (!move_available(row, col)) {
    return -1;
  }
  board[row][col] = player;
  return 0;
}

int is_board_full() {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      if (board[r][c] == EMPTY_SPACE) {
        return 0;
      }
    }
  }
  return 1;
}

int has_player_won(char player) {
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
  char current_player = PLAYER_X;
  int game_state = 0;

  // Initialize the board
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      board[r][c] = EMPTY_SPACE;
    }
  }

  // Game loop
  while (!game_state) {
    // Get the move from the player
    int row, col;
    printf("Enter row (1-3): ");
    scanf("%d", &row);

    printf("Enter column (1-3): ");
    scanf("%d", &col);

    // Place the move
    int move_result = place_move(row, col, current_player);

    // Check if the move was successful
    if (move_result == -1) {
      printf("Invalid move.\n");
    } else {
      // Check if the player has won
      if (has_player_won(current_player)) {
        game_state = 1;
        printf("Congratulations! You won!\n");
      } else if (is_board_full()) {
        game_state = 1;
        printf("It's a draw!\n");
      } else {
        // Switch to the next player
        current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
      }
    }
  }

  return 0;
}