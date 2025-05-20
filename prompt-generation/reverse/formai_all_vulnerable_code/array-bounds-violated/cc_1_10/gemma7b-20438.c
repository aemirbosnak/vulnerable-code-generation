//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

#define WIN_ROW 0
#define WIN_COL 1
#define WIN_DIAG 2

int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                              {0, 0, 0},
                              {0, 0, 0}};

int game_status = 0;

void draw_board() {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      printf("%c ", board[r][c]);
    }
    printf("\n");
  }
}

int check_win(char player) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board[r][0] == player && board[r][1] == player && board[r][2] == player) {
      return WIN_ROW;
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board[0][c] == player && board[1][c] == player && board[2][c] == player) {
      return WIN_COL;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return WIN_DIAG;
  }

  // If all else fails, it's a draw
  return 0;
}

void play_game() {
  // Alternate turns
  char current_player = PLAYER_X;

  // Loop until someone wins or it's a draw
  while (game_status == 0) {
    // Get the player's move
    int move_row, move_col;

    // Place the piece on the board
    board[move_row][move_col] = current_player;

    // Check if the player has won
    if (check_win(current_player) == WIN_ROW || check_win(current_player) == WIN_COL || check_win(current_player) == WIN_DIAG) {
      game_status = 1;
    }

    // If it's not a win, switch to the next player
    current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
  }

  // Draw the board one last time
  draw_board();

  // Announce the winner
  if (game_status == 1) {
    printf("The winner is: %c!", current_player);
  } else {
    printf("It's a draw!");
  }
}

int main() {
  play_game();

  return 0;
}