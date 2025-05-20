//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '},
 {' ', ' ', ' '},
 {' ', ' ', ' '}};

char current_player = 'X';

void initialize_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

int is_board_full() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        return 0;
      }
    }
  }
  return 1;
}

int is_player_won(char player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
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
  initialize_board();

  // Game loop
  while (!is_board_full() && !is_player_won(current_player)) {
    int row, column;
    printf("Enter row and column (1-3): ");
    scanf("%d %d", &row, &column);

    if (board[row][column] == ' ') {
      board[row][column] = current_player;
      current_player = 'O';
    } else {
      printf("Position already taken.\n");
    }
  }

  // Game over
  if (is_player_won(current_player)) {
    printf("Congratulations! %c won!\n", current_player);
  } else {
    printf("It's a draw!\n");
  }

  return 0;
}