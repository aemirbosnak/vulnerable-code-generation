//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 64
#define MAX_MOVES 12

#define RED 1
#define BLACK 2

typedef struct Move {
  int x, y, color;
} Move;

Move moves[MAX_MOVES];

void makeMove(int x, int y, int color) {
  moves[0].x = x;
  moves[0].y = y;
  moves[0].color = color;
}

int main() {
  int board[BOARD_SIZE] = {0};
  board[1] = RED;
  board[6] = RED;
  board[11] = BLACK;
  board[16] = BLACK;

  int moveCounter = 0;
  int gameOver = 0;

  while (!gameOver) {
    int moveX, moveY;
    printf("Enter move (x, y): ");
    scanf("%d %d", &moveX, &moveY);

    if (moveX < 1 || moveX > BOARD_SIZE || moveY < 1 || moveY > BOARD_SIZE) {
      printf("Invalid move.\n");
      continue;
    }

    if (board[moveX] == 0) {
      printf("Invalid move.\n");
      continue;
    }

    if (board[moveX] == board[moveY]) {
      printf("Invalid move.\n");
      continue;
    }

    makeMove(moveX, moveY, board[moveX]);

    board[moveY] = board[moveX];
    board[moveX] = 0;

    moveCounter++;

    if (moveCounter >= MAX_MOVES) {
      gameOver = 1;
    }

    printf("Move made.\n");
  }

  printf("Game over.\n");

  return 0;
}