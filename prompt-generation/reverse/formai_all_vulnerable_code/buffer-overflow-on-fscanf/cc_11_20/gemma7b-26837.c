//Gemma-7B DATASET v1.0 Category: Data mining ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

int main() {
  int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
  char a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE], d[MAX_SIZE], e[MAX_SIZE], f[MAX_SIZE], g[MAX_SIZE], h[MAX_SIZE];
  FILE *fp;
  fp = fopen("data.txt", "r");
  fscanf(fp, "%s", a);
  fclose(fp);

  for (i = 0; a[i] != '\0'; i++) {
    if (a[i] >= 'a' && a[i] <= 'z') {
      b[i] = a[i] - 32;
    } else {
      b[i] = a[i];
    }
  }

  for (i = 0; b[i] != '\0'; i++) {
    if (b[i] >= 'A' && b[i] <= 'Z') {
      c[i] = b[i] + 32;
    } else {
      c[i] = b[i];
    }
  }

  for (i = 0; c[i] != '\0'; i++) {
    if (c[i] >= 'a' && c[i] <= 'z') {
      d[i] = c[i] - 32;
    } else {
      d[i] = c[i];
    }
  }

  for (i = 0; d[i] != '\0'; i++) {
    if (d[i] >= 'A' && d[i] <= 'Z') {
      e[i] = d[i] + 32;
    } else {
      e[i] = d[i];
    }
  }

  for (i = 0; e[i] != '\0'; i++) {
    if (e[i] >= 'a' && e[i] <= 'z') {
      f[i] = e[i] - 32;
    } else {
      f[i] = e[i];
    }
  }

  for (i = 0; f[i] != '\0'; i++) {
    printf("%c ", f[i]);
  }

  return 0;
}