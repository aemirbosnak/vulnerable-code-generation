//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

#define EMPTY_SPACE ' '

typedef struct GameBoard {
  char board[BOARD_SIZE][BOARD_SIZE];
  char current_player;
  int game_status;
} GameBoard;

void initialize_board(GameBoard *board) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      board->board[r][c] = EMPTY_SPACE;
    }
  }

  board->current_player = PLAYER_X;
  board->game_status = 0;
}

void place_piece(GameBoard *board, int row, int column) {
  if (board->board[row][column] != EMPTY_SPACE) {
    return;
  }

  board->board[row][column] = board->current_player;
  board->current_player = (board->current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

int check_win(GameBoard *board) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board->board[r][0] == board->board[r][1] && board->board[r][0] == board->board[r][2] && board->board[r][0] != EMPTY_SPACE) {
      return board->board[r][0] - PLAYER_X;
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board->board[0][c] == board->board[1][c] && board->board[0][c] == board->board[2][c] && board->board[0][c] != EMPTY_SPACE) {
      return board->board[0][c] - PLAYER_X;
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != EMPTY_SPACE) {
    return board->board[0][0] - PLAYER_X;
  }

  // If all spaces are filled and there is no winner, the game is a draw
  return 2;
}

int main() {
  GameBoard board;
  initialize_board(&board);

  // Game loop
  while (board.game_status == 0) {
    int row, column;
    printf("Enter row (1-3): ");
    scanf("%d", &row);

    printf("Enter column (1-3): ");
    scanf("%d", &column);

    place_piece(&board, row, column);

    int winner = check_win(&board);

    if (winner != 0) {
      printf("Winner: Player %c!\n", winner + PLAYER_X);
      board.game_status = 1;
    } else {
      board.current_player = (board.current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
  }

  return 0;
}