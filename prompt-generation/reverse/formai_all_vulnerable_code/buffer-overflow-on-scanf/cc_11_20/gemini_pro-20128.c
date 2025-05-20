//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 4

int main() {
  int board[N][M];
  int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
  int open[N][M];
  int flips;
  int done;

  srand(time(NULL));

  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      board[i][j] = rand() % 16;
      open[i][j] = 0;
    }
  }

  while (!done) {
    for (i = 0; i < N; i++) {
      for (j = 0; j < M; j++) {
        if (open[i][j]) {
          printf("%2d ", board[i][j]);
        } else {
          printf("XX ");
        }
      }
      printf("\n");
    }

    printf("Enter two coordinates (0-3): ");
    scanf("%d %d", &k, &l);

    if (k >= 0 && k < N && l >= 0 && l < M) {
      open[k][l] = 1;

      for (m = 0; m < N; m++) {
        for (n = 0; n < M; n++) {
          if (open[m][n] && board[k][l] == board[m][n]) {
            open[m][n] = 1;
          }
        }
      }
    }

    flips++;
    done = 1;
    for (o = 0; o < N; o++) {
      for (p = 0; p < M; p++) {
        if (!open[o][p]) {
          done = 0;
        }
      }
    }
  }

  printf("You found all the matches in %d flips!\n", flips);

  return 0;
}