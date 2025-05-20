//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8
#define RED 1
#define GREEN 2
#define EMPTY 0

void print_board(int board[][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] == RED) {
        printf(" R ");
      } else if (board[i][j] == GREEN) {
        printf(" G ");
      } else {
        printf(" . ");
      }
    }
    printf("\n");
  }
}

int valid_move(int board[][SIZE], int from_row, int from_col, int to_row, int to_col) {
  if (from_row < 0 || from_row >= SIZE || from_col < 0 || from_col >= SIZE) {
    return 0;
  }
  if (to_row < 0 || to_row >= SIZE || to_col < 0 || to_col >= SIZE) {
    return 0;
  }
  if (board[from_row][from_col] == EMPTY) {
    return 0;
  }
  if (board[to_row][to_col] != EMPTY) {
    return 0;
  }
  if (abs(from_row - to_row) != 1 || abs(from_col - to_col) != 1) {
    return 0;
  }
  return 1;
}

int main() {
  int board[SIZE][SIZE];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if ((i + j) % 2 == 1) {
        if (i < 3) {
          board[i][j] = GREEN;
        } else if (i > 4) {
          board[i][j] = RED;
        } else {
          board[i][j] = EMPTY;
        }
      } else {
        board[i][j] = EMPTY;
      }
    }
  }

  int turn = RED;

  while (1) {
    print_board(board);

    if (turn == RED) {
      printf("Red's turn:\n");
    } else {
      printf("Green's turn:\n");
    }

    int from_row, from_col, to_row, to_col;
    scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);

    if (!valid_move(board, from_row, from_col, to_row, to_col)) {
      printf("Invalid move\n");
      continue;
    }

    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = EMPTY;

    turn = 3 - turn;
  }

  return 0;
}