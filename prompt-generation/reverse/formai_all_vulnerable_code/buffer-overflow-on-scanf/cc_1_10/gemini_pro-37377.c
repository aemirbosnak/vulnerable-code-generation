//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3
#define PLAYERS 2

char board[BOARD_SIZE][BOARD_SIZE];
int current_player;

bool is_valid_move(int row, int col) {
  return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
}

void make_move(int row, int col, char player) {
  board[row][col] = player;
}

bool is_winner(char player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
      return true;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }

  return false;
}

bool is_tied() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Set the current player to 1
  current_player = 1;

  // Play the game
  while (true) {
    // Get the player's move
    int row, col;
    printf("Player %d, enter your move (row, col): ", current_player);
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    if (!is_valid_move(row, col)) {
      printf("Invalid move. Try again.\n");
      continue;
    }

    // Make the move
    make_move(row, col, current_player == 1 ? 'X' : 'O');

    // Print the board
    print_board();

    // Check if the player has won
    if (is_winner(current_player == 1 ? 'X' : 'O')) {
      printf("Player %d wins!\n", current_player);
      break;
    }

    // Check if the game is tied
    if (is_tied()) {
      printf("Tie game!\n");
      break;
    }

    // Switch the current player
    current_player = current_player == 1 ? 2 : 1;
  }

  return 0;
}