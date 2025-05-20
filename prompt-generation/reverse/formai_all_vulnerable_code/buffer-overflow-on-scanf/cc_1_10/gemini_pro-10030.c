//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: active
#include <stdio.h>

#define ROWS 8
#define COLS 8
#define BLACK 1
#define WHITE 2
#define EMPTY 0

int board[ROWS][COLS];

void print_board() {
  printf("  ");
  for (int i = 0; i < COLS; i++) {
    printf("%c ", 'A' + i);
  }
  printf("\n");

  for (int i = 0; i < ROWS; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < COLS; j++) {
      if (board[i][j] == BLACK) {
        printf("B ");
      } else if (board[i][j] == WHITE) {
        printf("W ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

int main() {
  // initialize the board
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if ((i + j) % 2 == 0) {
        board[i][j] = EMPTY;
      } else if (i < 3) {
        board[i][j] = BLACK;
      } else if (i > 4) {
        board[i][j] = WHITE;
      } else {
        board[i][j] = EMPTY;
      }
    }
  }

  // print the board
  print_board();

  // get the player's move
  char input[3];
  printf("Enter your move (e.g. A1): ");
  scanf("%s", input);

  // parse the player's move
  int from_row = input[1] - '1';
  int from_col = input[0] - 'A';
  int to_row = input[3] - '1';
  int to_col = input[2] - 'A';

  // check if the move is valid
  if (board[from_row][from_col] == EMPTY ||
      board[to_row][to_col] != EMPTY ||
      abs(from_row - to_row) != 1 ||
      abs(from_col - to_col) != 1) {
    printf("Invalid move!\n");
    return 1;
  }

  // make the move
  board[from_row][from_col] = EMPTY;
  board[to_row][to_col] = BLACK;

  // print the board
  print_board();

  return 0;
}