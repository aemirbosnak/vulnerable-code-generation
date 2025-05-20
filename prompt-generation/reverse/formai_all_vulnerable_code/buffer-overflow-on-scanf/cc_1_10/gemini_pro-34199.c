//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define B 1
#define W 2
#define E 0
#define T 3
#define O 4
#define X 5

void print_board(int board[8][8]) {
  printf("┌───┬───┬───┬───┬───┬───┬───┬───┐\n");
  for (int i = 0; i < 8; i++) {
    printf("│ ");
    for (int j = 0; j < 8; j++) {
      switch (board[i][j]) {
        case B:
          printf("B ");
          break;
        case W:
          printf("W ");
          break;
        case E:
          printf("  ");
          break;
        case T:
          printf("T ");
          break;
        case O:
          printf("O ");
          break;
        case X:
          printf("X ");
          break;
      }
    }
    printf("│\n");
    printf("├───┼───┼───┼───┼───┼───┼───┼───┤\n");
  }
  printf("└───┴───┴───┴───┴───┴───┴───┴───┘\n");
}

bool valid_move(int board[8][8], int from_row, int from_col, int to_row, int to_col) {
  if (board[from_row][from_col] == E || board[to_row][to_col] != E) {
    return false;
  }
  if (abs(from_row - to_row) != 1 || abs(from_col - to_col) != 1) {
    return false;
  }
  return true;
}

void make_move(int board[8][8], int from_row, int from_col, int to_row, int to_col) {
  board[to_row][to_col] = board[from_row][from_col];
  board[from_row][from_col] = E;
}

bool check_win(int board[8][8], int player) {
  if (player == B) {
    for (int i = 0; i < 8; i++) {
      if (board[0][i] == B) {
        return true;
      }
    }
  } else if (player == W) {
    for (int i = 0; i < 8; i++) {
      if (board[7][i] == W) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int board[8][8] = {
    {B, E, B, E, B, E, B, E},
    {E, B, E, B, E, B, E, B},
    {B, E, B, E, B, E, B, E},
    {E, E, E, E, E, E, E, E},
    {E, E, E, E, E, E, E, E},
    {E, W, E, W, E, W, E, W},
    {W, E, W, E, W, E, W, E},
    {E, W, E, W, E, W, E, W}
  };
  int player = B;
  int from_row, from_col, to_row, to_col;
  while (true) {
    print_board(board);
    printf("Your turn, player %d:\n", player);
    printf("From row: ");
    scanf("%d", &from_row);
    printf("From col: ");
    scanf("%d", &from_col);
    printf("To row: ");
    scanf("%d", &to_row);
    printf("To col: ");
    scanf("%d", &to_col);
    if (valid_move(board, from_row, from_col, to_row, to_col)) {
      make_move(board, from_row, from_col, to_row, to_col);
      if (check_win(board, player)) {
        printf("Player %d wins!\n", player);
        break;
      }
      player = (player == B) ? W : B;
    } else {
      printf("Invalid move. Try again.\n");
    }
  }
  return 0;
}