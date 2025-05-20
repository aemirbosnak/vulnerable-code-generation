#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int board[6][6] = {{0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0}};

  int player = 1;
  int move = 0;

  while (!board[move / 6][move % 6]) {
    printf("Enter your move (x, y): ");
    scanf("%d", &move);

    if (move < 0 || move >= 36) {
      printf("Invalid move. Please try again.\n");
      continue;
    }
  }

  board[move / 6][move % 6] = player;

  if (player == 1) {
    printf("You won!");
  } else {
    printf("You lost.");
  }

  return 0;
}
