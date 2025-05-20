//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define BLACK 1
#define WHITE -1
#define EMPTY 0

typedef struct {
  int color;
  int king;
} piece;

typedef struct {
  piece board[BOARD_SIZE][BOARD_SIZE];
} board;

void print_board(board *b) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (b->board[i][j].color == BLACK) {
        printf("B");
      } else if (b->board[i][j].color == WHITE) {
        printf("W");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int is_valid_move(board *b, int x1, int y1, int x2, int y2) {
  if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE ||
      x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
    return 0;
  }

  if (b->board[x1][y1].color == EMPTY) {
    return 0;
  }

  if (b->board[x1][y1].color == b->board[x2][y2].color) {
    return 0;
  }

  if (abs(x2 - x1) != abs(y2 - y1)) {
    return 0;
  }

  if (abs(x2 - x1) == 1) {
    return 1;
  }

  if (abs(x2 - x1) == 2) {
    if (b->board[(x1 + x2) / 2][(y1 + y2) / 2].color != EMPTY) {
      return 1;
    }
  }

  return 0;
}

void make_move(board *b, int x1, int y1, int x2, int y2) {
  b->board[x2][y2].color = b->board[x1][y1].color;
  b->board[x1][y1].color = EMPTY;

  if (abs(x2 - x1) == 2) {
    b->board[(x1 + x2) / 2][(y1 + y2) / 2].color = EMPTY;
  }

  if (y2 == 0 && b->board[x2][y2].color == BLACK) {
    b->board[x2][y2].king = 1;
  } else if (y2 == BOARD_SIZE - 1 && b->board[x2][y2].color == WHITE) {
    b->board[x2][y2].king = 1;
  }
}

int is_game_over(board *b) {
  int black_count = 0;
  int white_count = 0;

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (b->board[i][j].color == BLACK) {
        black_count++;
      } else if (b->board[i][j].color == WHITE) {
        white_count++;
      }
    }
  }

  if (black_count == 0) {
    return WHITE;
  } else if (white_count == 0) {
    return BLACK;
  } else {
    return EMPTY;
  }
}

int main() {
  board b;

  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (i < 3) {
        b.board[i][j].color = WHITE;
      } else if (i > 4) {
        b.board[i][j].color = BLACK;
      } else {
        b.board[i][j].color = EMPTY;
      }

      b.board[i][j].king = 0;
    }
  }

  // Print the initial board
  print_board(&b);

  // Get the player's move
  int x1, y1, x2, y2;
  printf("Enter your move (x1, y1, x2, y2): ");
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

  // Check if the move is valid
  if (!is_valid_move(&b, x1, y1, x2, y2)) {
    printf("Invalid move. Please try again.\n");
    return 1;
  }

  // Make the move
  make_move(&b, x1, y1, x2, y2);

  // Print the updated board
  print_board(&b);

  // Check if the game is over
  int winner = is_game_over(&b);
  if (winner == BLACK) {
    printf("Black wins!\n");
  } else if (winner == WHITE) {
    printf("White wins!\n");
  } else {
    printf("The game is still in progress.\n");
  }

  return 0;
}