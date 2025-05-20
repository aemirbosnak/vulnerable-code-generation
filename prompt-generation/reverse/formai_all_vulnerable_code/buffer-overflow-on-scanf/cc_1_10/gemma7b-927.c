//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 3
#define EMPTY_SPACE ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                              {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                              {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE}};

void draw_board() {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      printf("%c ", board[r][c]);
    }
    printf("\n");
  }
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

int main() {
  char current_player = PLAYER_X;
  int game_state = 0;

  // Initialize the board
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      board[r][c] = EMPTY_SPACE;
    }
  }

  // Play the game until someone wins or the board is full
  while (!game_state) {
    // Get the player's move
    int move_row, move_col;
    printf("Enter your move (row, column): ");
    scanf("%d %d", &move_row, &move_col);

    // Validate the move
    if (move_row < 0 || move_row >= BOARD_SIZE || move_col < 0 || move_col >= BOARD_SIZE) {
      printf("Invalid move.\n");
      continue;
    }

    // Place the player's mark on the board
    board[move_row][move_col] = current_player;

    // Check if the player has won or the board is full
    game_state = check_win(current_player) || is_board_full();

    // Switch to the next player
    current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;

    // Draw the board
    draw_board();
  }

  // End the game
  printf("Game over! %c won!", current_player);

  return 0;
}