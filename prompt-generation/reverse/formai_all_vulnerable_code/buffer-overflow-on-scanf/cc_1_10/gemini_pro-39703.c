//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
// 盤面
char board[8][8];
// プレイヤー
char player = 'b';
// 移動の向き
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};
// 盤面を表示
void print_board() {
  printf("  a b c d e f g h\n");
  for (int i = 0; i < 8; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < 8; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
// 入力を受け付ける
void get_input(int *x, int *y) {
  char buf[1024];
  while (1) {
    printf("Input: ");
    scanf("%s", buf);
    if (strlen(buf) != 2 || buf[0] < 'a' || buf[0] > 'h' || buf[1] < '1' || buf[1] > '8') {
      printf("Invalid input\n");
    } else {
      break;
    }
  }
  *x = buf[0] - 'a';
  *y = buf[1] - '1';
}
// 移動できるかをチェック
int can_move(int x, int y) {
  if (x < 0 || x >= 8 || y < 0 || y >= 8) {
    return 0;
  }
  if (player == 'b') {
    return board[y][x] == 'b' || board[y][x] == 'B';
  } else {
    return board[y][x] == 'w' || board[y][x] == 'W';
  }
}
// 移動する
void move(int x, int y) {
  board[y][x] = player;
  if (player == 'b') {
    if (y == 7) {
      board[y][x] = 'B';
    }
  } else {
    if (y == 0) {
      board[y][x] = 'W';
    }
  }
}
// 盤面を初期化する
void init_board() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i < 3) {
        board[i][j] = 'w';
      } else if (i > 4) {
        board[i][j] = 'b';
      } else {
        board[i][j] = ' ';
      }
    }
  }
}
// ゲームループ
void game_loop() {
  while (1) {
    // 盤面を表示
    print_board();
    // 入力を受け付ける
    int x, y;
    get_input(&x, &y);
    // 移動できるかをチェック
    if (!can_move(x, y)) {
      printf("Invalid move\n");
      continue;
    }
    // 移動する
    move(x, y);
    // プレイヤーを切り替える
    player = player == 'b' ? 'w' : 'b';
  }
}
// メイン関数
int main() {
  // 盤面を初期化する
  init_board();
  // ゲームループ
  game_loop();
  return 0;
}