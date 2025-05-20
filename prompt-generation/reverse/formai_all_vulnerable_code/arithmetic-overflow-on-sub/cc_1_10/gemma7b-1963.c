//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

int main() {
  int x1 = WIDTH / 2;
  int y1 = HEIGHT - 1;
  int x2 = WIDTH / 2;
  int y2 = 0;

  char board[HEIGHT][WIDTH] = {0};

  board[y1][x1] = 'A';
  board[y2][x2] = 'B';

  int score1 = 0;
  int score2 = 0;

  clock_t start, end;
  double time_taken;

  start = clock();

  while (1) {
    int move = rand() % 2;

    if (move == 0) {
      y2--;
    } else {
      y2++;
    }

    if (board[y2][x2] == 'A') {
      score1++;
      board[y1][x1] = 'O';
      x1 = WIDTH / 2;
      y1 = HEIGHT - 1;
    } else if (board[y2][x2] == 'B') {
      score2++;
      board[y2][x2] = 'O';
      x2 = WIDTH / 2;
      y2 = 0;
    }

    board[y1][x1] = 'A';
    board[y2][x2] = 'B';

    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken: %.2f seconds\n", time_taken);

    if (score1 == 5) {
      printf("Player 1 wins!\n");
      break;
    } else if (score2 == 5) {
      printf("Player 2 wins!\n");
      break;
    }
  }

  return 0;
}