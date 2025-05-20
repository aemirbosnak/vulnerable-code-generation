//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int current_player;
  int game_status;
} Board;

Board *init_board() {
  Board *board = malloc(sizeof(Board));
  board->board = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
  board->current_player = 1;
  board->game_status = 0;
  return board;
}

void play_move(Board *board, int row, int col) {
  if (board->board[row][col] == 0 && board->game_status == 0) {
    board->board[row][col] = board->current_player;
    board->current_player = (board->current_player == 1) ? 2 : 1;
  }
}

int check_win(Board *board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    // Check rows
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board->board[i][j] == board->board[i][0] && board->board[i][j] != 0) {
        return board->board[i][j];
      }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board->board[0][j] == board->board[1][j] && board->board[0][j] == board->board[2][j] && board->board[0][j] != 0) {
        return board->board[0][j];
      }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
      return board->board[0][0];
    }
  }

  return 0;
}

void game_loop(Board *board) {
  // Game continues until there is a winner or a draw
  while (board->game_status == 0) {
    // Get the player's move
    int row, col;
    printf("Enter your move (row, column): ");
    scanf("%d %d", &row, &col);

    // Play the move
    play_move(board, row, col);

    // Check if there is a winner
    if (check_win(board) != 0) {
      board->game_status = 1;
      printf("Congratulations! You won!");
    }
  }

  // Draw the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board->board[i][j]);
    }
    printf("\n");
  }

  // Game over
  printf("Thank you for playing! Goodbye!");
}

int main() {
  Board *board = init_board();
  game_loop(board);

  return 0;
}