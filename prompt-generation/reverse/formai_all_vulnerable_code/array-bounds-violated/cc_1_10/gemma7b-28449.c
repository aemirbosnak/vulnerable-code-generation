//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOARD_SIZE 3
#define EMPTY_SPACE ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] = {{EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                 {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                 {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE}};

char whose_turn = PLAYER_X;

int is_board_full() {
  for (int r = 0; r < MAX_BOARD_SIZE; r++) {
    for (int c = 0; c < MAX_BOARD_SIZE; c++) {
      if (board[r][c] == EMPTY_SPACE) {
        return 0;
      }
    }
  }

  return 1;
}

void place_piece(int row, int column) {
  if (board[row][column] != EMPTY_SPACE) {
    return;
  }

  board[row][column] = whose_turn;
}

int check_win() {
  // Check rows
  for (int r = 0; r < MAX_BOARD_SIZE; r++) {
    if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] != EMPTY_SPACE) {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < MAX_BOARD_SIZE; c++) {
    if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] != EMPTY_SPACE) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != EMPTY_SPACE) {
    return 1;
  }

  // If no one has won, it's a draw
  return 0;
}

int main() {
  // Game loop
  while (!is_board_full() && check_win() == 0) {
    int row, column;

    // Get the player's move
    printf("Enter row and column (1-3): ");
    scanf("%d %d", &row, &column);

    // Place the piece
    place_piece(row, column);

    // Switch turns
    whose_turn = (whose_turn == PLAYER_X) ? PLAYER_O : PLAYER_X;
  }

  // Game over
  if (check_win() == 1) {
    printf("Congratulations! You have won!");
  } else if (is_board_full() == 1) {
    printf("It's a draw!");
  } else {
    printf("An error has occurred.");
  }

  return 0;
}