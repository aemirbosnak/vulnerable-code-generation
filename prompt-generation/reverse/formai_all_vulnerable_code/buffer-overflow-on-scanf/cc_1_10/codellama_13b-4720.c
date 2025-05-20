//Code Llama-13B DATASET v1.0 Category: Checkers Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROW 8
#define COL 8

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  Position position;
  bool is_king;
} Piece;

typedef struct {
  Piece pieces[ROW][COL];
  bool player1;
  bool player2;
} GameState;

void print_board(GameState *game_state) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      Piece piece = game_state->pieces[i][j];
      if (piece.is_king) {
        printf("K");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

void move_piece(GameState *game_state, int x, int y, int new_x, int new_y) {
  Piece piece = game_state->pieces[x][y];
  game_state->pieces[x][y] = game_state->pieces[new_x][new_y];
  game_state->pieces[new_x][new_y] = piece;
}

bool check_win(GameState *game_state) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      Piece piece = game_state->pieces[i][j];
      if (piece.is_king) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  GameState game_state = {0};
  srand(time(NULL));

  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      game_state.pieces[i][j].is_king = false;
    }
  }

  bool player1 = true;
  while (true) {
    print_board(&game_state);

    if (player1) {
      printf("Player 1's turn\n");
      int x, y, new_x, new_y;
      scanf("%d %d %d %d", &x, &y, &new_x, &new_y);
      move_piece(&game_state, x, y, new_x, new_y);
    } else {
      printf("Player 2's turn\n");
      int x, y, new_x, new_y;
      scanf("%d %d %d %d", &x, &y, &new_x, &new_y);
      move_piece(&game_state, x, y, new_x, new_y);
    }

    if (check_win(&game_state)) {
      printf("Player %d wins\n", player1 ? 1 : 2);
      break;
    }

    player1 = !player1;
  }

  return 0;
}