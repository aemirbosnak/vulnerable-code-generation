//FormAI DATASET v1.0 Category: Checkers Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

char board[ROWS][COLS];
char player = 'W';

void init_board() {
  int i, j;

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      if ((i + j) % 2 == 0) {
        if (i < 3) {
          board[i][j] = 'B';
        } else if (i > 4) {
          board[i][j] = 'W';
        } else {
          board[i][j] = ' ';
        }
      }
    }
  }
}

void print_board() {
  int i, j;

  printf("  ");
  for (i = 0; i < COLS; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");

  for (i = 0; i < ROWS; i++) {
    printf("%d ", i + 1);
    for (j = 0; j < COLS; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int move_piece(int from_row, int from_col, int to_row, int to_col) {
  if (board[to_row][to_col] != ' ') {
    printf("Invalid move.\n");
    return 0;
  }

  if (player == 'B' && to_row >= from_row) {
    printf("Invalid move.\n");
    return 0;
  }

  if (player == 'W' && to_row <= from_row) {
    printf("Invalid move.\n");
    return 0;
  }

  if (abs(from_row - to_row) == 1 && abs(from_col - to_col) == 1) {
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = ' ';
  } else if (abs(from_row - to_row) == 2 && abs(from_col - to_col) == 2) {
    int jumped_row = (from_row + to_row) / 2;
    int jumped_col = (from_col + to_col) / 2;

    if (board[jumped_row][jumped_col] == ' ') {
      printf("Invalid move.\n");
      return 0;
    }

    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = ' ';
    board[jumped_row][jumped_col] = ' ';
  } else {
    printf("Invalid move.\n");
    return 0;
  }

  if (player == 'W' && to_row == 0) {
    board[to_row][to_col] = 'W';
  } else if (player == 'B' && to_row == ROWS - 1) {
    board[to_row][to_col] = 'B';
  }

  return 1;
}

int main() {
  int from_row, from_col, to_row, to_col;

  init_board();
  print_board();

  while (1) {
    printf("%c's turn.\n", player);

    printf("Enter row and column to move from: ");
    scanf("%d %d", &from_row, &from_col);
    printf("Enter row and column to move to: ");
    scanf("%d %d", &to_row, &to_col);

    if (move_piece(from_row - 1, from_col - 1, to_row - 1, to_col - 1)) {
      print_board();

      if (player == 'W') {
        player = 'B';
      } else {
        player = 'W';
      }
    }
  }

  return 0;
}