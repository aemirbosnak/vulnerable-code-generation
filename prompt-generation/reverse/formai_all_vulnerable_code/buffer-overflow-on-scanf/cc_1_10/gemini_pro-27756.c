//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define N 8

char board[N][N];
int moves[200];
int move_count;

void print_board() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int is_valid_move(int x1, int y1, int x2, int y2) {
  if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= N || x2 < 0 || x2 >= N || y2 < 0 || y2 >= N) {
    return 0;
  }
  if (board[x1][y1] == ' ' || board[x2][y2] != ' ') {
    return 0;
  }
  if (x2 - x1 == 1 && (y2 - y1 == 1 || y2 - y1 == -1)) {
    return 1;
  }
  if (x2 - x1 == 2 && (y2 - y1 == 2 || y2 - y1 == -2) && board[(x1 + x2) / 2][(y1 + y2) / 2] == 'O') {
    return 1;
  }
  return 0;
}

int make_move(int x1, int y1, int x2, int y2) {
  if (!is_valid_move(x1, y1, x2, y2)) {
    return 0;
  }
  board[x2][y2] = board[x1][y1];
  board[x1][y1] = ' ';
  if (x2 == 0 || x2 == N - 1) {
    board[x2][y2] = 'O';
  }
  if (abs(x2 - x1) == 2) {
    board[(x1 + x2) / 2][(y1 + y2) / 2] = ' ';
  }
  moves[move_count++] = x1 * N + y1;
  moves[move_count++] = x2 * N + y2;
  return 1;
}

int undo_move() {
  if (move_count == 0) {
    return 0;
  }
  int x2 = moves[--move_count] / N;
  int y2 = moves[move_count--] % N;
  int x1 = moves[--move_count] / N;
  int y1 = moves[move_count--] % N;
  board[x1][y1] = board[x2][y2];
  board[x2][y2] = ' ';
  return 1;
}

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if ((i + j) % 2 == 0) {
        board[i][j] = 'x';
      } else {
        board[i][j] = ' ';
      }
    }
  }

  print_board();

  while (1) {
    int x1, y1, x2, y2;
    printf("Enter move (x1, y1, x2, y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (make_move(x1, y1, x2, y2)) {
      print_board();
    } else {
      printf("Invalid move!\n");
    }
  }

  return 0;
}