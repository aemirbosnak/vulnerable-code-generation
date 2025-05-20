#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  char player = 'X';
  int move = 0;

  for (int round = 0; round < 9; round++) {
    printf("Enter your move (1-9): ");
    scanf("%d", &move);

    if (board[move - 1] != 0) {
      printf("Invalid move.\n");
      continue;
    }

    board[move - 1] = player;
    player = 'O' == player ? 'X' : 'O';
  }

  printf("Game over! The winner is: %c", board[0] == board[1] && board[0] == board[2] ? board[0] : board[3] == board[4] && board[3] == board[5] ? board[3] : board[6] == board[7] && board[6] == board[8] ? board[6] : 'N');

  return 0;
}
