#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int board[36] = {0};
  int player1 = 1, player2 = 2, currentPlayer = player1;
  int move, x, y;

  for (int round = 0; round < 6; round++) {
    printf("Enter move (x, y): ");
    scanf("%d %d", &x, &y);

    if (x < 0 || x >= 6 || y < 0 || y >= 6) {
      printf("Invalid move.\n");
      continue;
    }

    if (board[x * 6 + y] != 0) {
      printf("Move already made.\n");
      continue;
    }

    board[x * 6 + y] = currentPlayer;
    currentPlayer = (currentPlayer == player1) ? player2 : player1;
  }

  printf("Game over! Winner: %d\n", board[0] == player1 ? player1 : player2);

  return 0;
}
