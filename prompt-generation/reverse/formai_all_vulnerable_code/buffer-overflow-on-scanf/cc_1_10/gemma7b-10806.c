//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 64

typedef struct Board {
  int board[MAX_BOARD_SIZE];
  int turn;
  int winner;
} Board;

void initializeBoard(Board *board) {
  board->board[0] = 1;
  board->board[1] = 1;
  board->board[2] = 1;
  board->board[3] = 1;
  board->board[MAX_BOARD_SIZE - 1] = 2;
  board->board[MAX_BOARD_SIZE - 2] = 2;
  board->board[MAX_BOARD_SIZE - 3] = 2;
  board->board[MAX_BOARD_SIZE - 4] = 2;
  board->turn = 0;
  board->winner = 0;
}

int move(Board *board, int from, int to) {
  if (board->board[from] == 0 || board->board[to] != 0) {
    return -1;
  }

  board->board[to] = board->board[from];
  board->board[from] = 0;

  board->turn++;

  if (board->board[to] == 2) {
    board->winner = 1;
  }

  return 0;
}

int main() {
  Board board;
  initializeBoard(&board);

  while (board.winner == 0) {
    int from, to;
    printf("Enter move (from, to): ");
    scanf("%d %d", &from, &to);

    if (move(&board, from, to) == -1) {
      printf("Invalid move.\n");
    }
  }

  printf("Winner: %d\n", board.winner);

  return 0;
}