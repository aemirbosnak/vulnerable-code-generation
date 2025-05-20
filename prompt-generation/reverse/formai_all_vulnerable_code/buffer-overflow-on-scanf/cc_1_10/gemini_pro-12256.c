//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define BLACK 'B'
#define RED 'R'
#define EMPTY ' '
#define KING 'K'

typedef struct {
  char color;
  char type;
} piece;

typedef struct {
  piece board[BOARD_SIZE][BOARD_SIZE];
} board;

void print_board(board *b) {
  printf("  ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf(" %d", i + 1);
  }
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", b->board[i][j].color ? b->board[i][j].color : EMPTY);
    }
    printf("\n");
  }
}

int main() {
  board b;
  memset(&b, 0, sizeof(board));

  // Set up the initial board position
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (i < 3) {
        b.board[i][j].color = BLACK;
        b.board[i][j].type = EMPTY;
      } else if (i > 4) {
        b.board[i][j].color = RED;
        b.board[i][j].type = EMPTY;
      }
    }
  }

  // Print the initial board position
  print_board(&b);

  // Get the player's move
  int from_row, from_col, to_row, to_col;
  printf("Enter your move (from row, from col, to row, to col): ");
  scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);

  // Make the move
  b.board[to_row][to_col] = b.board[from_row][from_col];
  b.board[from_row][from_col].color = EMPTY;
  b.board[from_row][from_col].type = EMPTY;

  // Print the updated board position
  print_board(&b);

  return 0;
}