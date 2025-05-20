//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include <stdio.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int check_winner() {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0];
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return board[0][j];
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0];
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2];
  }

  return 0;
}

int main() {
  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Print the initial board
  print_board();

  // Get the player's move
  int player_row, player_col;
  printf("Enter your move (row, column): ");
  scanf("%d %d", &player_row, &player_col);

  // Place the player's move on the board
  board[player_row][player_col] = 'X';

  // Print the updated board
  print_board();

  // Check if the player has won
  int winner = check_winner();
  if (winner == 'X') {
    printf("You win!\n");
  } else if (winner == 'O') {
    printf("You lose!\n");
  } else {
    printf("The game is a draw.\n");
  }

  return 0;
}