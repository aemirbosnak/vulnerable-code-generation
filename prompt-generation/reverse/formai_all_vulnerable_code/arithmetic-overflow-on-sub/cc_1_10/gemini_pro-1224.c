//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include <stdio.h>

typedef unsigned char uchar;
#define N 9
uchar bd[N][N], ans[N][N], nosol[N][N];

void printb(uchar b[N][N]) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (b[i][j])
        printf("%d ", b[i][j]);
      else
        printf(". ");
    }
    printf("\n");
  }
}

int bvalid(uchar b[N][N]) {
  int i, j, k, l, m, n, x, y, c[N + 1];
  for (i = 0; i < N; i++) {
    for (j = 0; j < N + 1; j++)
      c[j] = 0;
    for (j = 0; j < N; j++) {
      if (b[i][j] == 0)
        continue;
      c[b[i][j]]++;
      if (c[b[i][j]] > 1)
        return 0;
    }
  }
  for (j = 0; j < N; j++) {
    for (i = 0; i < N + 1; i++)
      c[i] = 0;
    for (i = 0; i < N; i++) {
      if (b[i][j] == 0)
        continue;
      c[b[i][j]]++;
      if (c[b[i][j]] > 1)
        return 0;
    }
  }
  for (x = 0; x < N; x += 3) {
    for (y = 0; y < N; y += 3) {
      for (i = 0; i < N + 1; i++)
        c[i] = 0;
      for (i = x; i < x + 3; i++) {
        for (j = y; j < y + 3; j++) {
          if (b[i][j] == 0)
            continue;
          c[b[i][j]]++;
          if (c[b[i][j]] > 1)
            return 0;
        }
      }
    }
  }
  return 1;
}

int bfull(uchar b[N][N]) {
  int i, j;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      if (b[i][j] == 0)
        return 0;
  return 1;
}

int mnext(uchar b[N][N], int i, int j) {
  for (; i < N; i++) {
    for (; j < N; j++) {
      if (b[i][j] == 0)
        return i * N + j;
    }
    j = 0;
  }
  return N * N;
}

int msolve(uchar b[N][N], int i, int j) {
  uchar k;
  int n, vi, vj;
  for (i = i * N + j; i < N * N; i++) {
    k = b[i / N][i % N];
    if (k != 0)
      continue;
    for (n = 1; n <= N; n++) {
      for (vi = i / N; vi < N; vi++) {
        if (vi == i / N && n == k)
          continue;
        if (b[vi][i % N] == n)
          goto nexti;
      }
      for (vj = 0; vj < N; vj++) {
        if (vj == i % N && n == k)
          continue;
        if (b[i / N][vj] == n)
          goto nexti;
      }
      for (vi = i / N / 3 * 3; vi < i / N / 3 * 3 + 3; vi++) {
        for (vj = i % N / 3 * 3; vj < i % N / 3 * 3 + 3; vj++) {
          if (vi == i / N && vj == i % N && n == k)
            continue;
          if (b[vi][vj] == n)
            goto nexti;
        }
      }
      b[i / N][i % N] = n;
      if (msolve(b, i / N, i % N) == 1)
        return 1;
nexti:
      b[i / N][i % N] = 0;
    }
    return 0;
  }
  return 1;
}

int main() {
  int i, j;
  printf("Enter puzzle:\n");
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      bd[i][j] = getchar() - '0';
      ans[i][j] = bd[i][j];
      nosol[i][j] = 0;
    }
  if (bvalid(bd) == 0) {
    printf("Invalid puzzle!\n");
    return 0;
  }
  if (msolve(bd, 0, 0) == 0) {
    printf("No solution!\n");
    return 0;
  }
  printf("Solution:\n");
  printb(bd);
  return 0;
}