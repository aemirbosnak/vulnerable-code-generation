//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define NUM_PIECES 6
#define WHITE 0
#define BLACK 1
#define PAWN 0
#define KNIGHT 1
#define BISHOP 2
#define ROOK 3
#define QUEEN 4
#define KING 5

typedef struct {
  int x;
  int y;
  int color;
  int type;
} piece;

typedef struct {
  piece board[BOARD_SIZE][BOARD_SIZE];
  int turn;
} game;

int check_move(game *g, piece *p, int x, int y) {
  if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
    return 0;
  }

  if (g->board[x][y].color == p->color) {
    return 0;
  }

  switch (p->type) {
    case PAWN:
      if (p->color == WHITE) {
        if (p->x == 1 && x == 3) {
          return 1;
        } else if (x == p->x + 1) {
          return 1;
        }
      } else {
        if (p->x == 6 && x == 4) {
          return 1;
        } else if (x == p->x - 1) {
          return 1;
        }
      }
      break;
    case KNIGHT:
      if ((abs(p->x - x) == 1 && abs(p->y - y) == 2) || (abs(p->x - x) == 2 && abs(p->y - y) == 1)) {
        return 1;
      }
      break;
    case BISHOP:
      if (abs(p->x - x) == abs(p->y - y)) {
        return 1;
      }
      break;
    case ROOK:
      if (p->x == x || p->y == y) {
        return 1;
      }
      break;
    case QUEEN:
      if (p->x == x || p->y == y || abs(p->x - x) == abs(p->y - y)) {
        return 1;
      }
      break;
    case KING:
      if (abs(p->x - x) <= 1 && abs(p->y - y) <= 1) {
        return 1;
      }
      break;
  }

  return 0;
}

int main() {
  game g;
  memset(&g, 0, sizeof(g));

  g.board[0][0].color = WHITE;
  g.board[0][0].type = ROOK;
  g.board[0][1].color = WHITE;
  g.board[0][1].type = KNIGHT;
  g.board[0][2].color = WHITE;
  g.board[0][2].type = BISHOP;
  g.board[0][3].color = WHITE;
  g.board[0][3].type = QUEEN;
  g.board[0][4].color = WHITE;
  g.board[0][4].type = KING;
  g.board[0][5].color = WHITE;
  g.board[0][5].type = BISHOP;
  g.board[0][6].color = WHITE;
  g.board[0][6].type = KNIGHT;
  g.board[0][7].color = WHITE;
  g.board[0][7].type = ROOK;

  g.board[1][0].color = WHITE;
  g.board[1][1].color = WHITE;
  g.board[1][2].color = WHITE;
  g.board[1][3].color = WHITE;
  g.board[1][4].color = WHITE;
  g.board[1][5].color = WHITE;
  g.board[1][6].color = WHITE;
  g.board[1][7].color = WHITE;

  g.board[6][0].color = BLACK;
  g.board[6][1].color = BLACK;
  g.board[6][2].color = BLACK;
  g.board[6][3].color = BLACK;
  g.board[6][4].color = BLACK;
  g.board[6][5].color = BLACK;
  g.board[6][6].color = BLACK;
  g.board[6][7].color = BLACK;

  g.board[7][0].color = BLACK;
  g.board[7][1].color = BLACK;
  g.board[7][2].color = BLACK;
  g.board[7][3].color = BLACK;
  g.board[7][4].color = BLACK;
  g.board[7][5].color = BLACK;
  g.board[7][6].color = BLACK;
  g.board[7][7].color = BLACK;

  g.turn = WHITE;

  while (1) {
    int x, y, x2, y2;

    printf("Your move: ");
    scanf("%d %d %d %d", &x, &y, &x2, &y2);

    piece *p = &g.board[x][y];

    if (p->color != g.turn) {
      printf("It's not your turn!\n");
      continue;
    }

    if (!check_move(&g, p, x2, y2)) {
      printf("Invalid move!\n");
      continue;
    }

    g.board[x2][y2] = *p;
    g.board[x][y].color = 0;
    g.board[x][y].type = 0;

    g.turn = !g.turn;
  }

  return 0;
}