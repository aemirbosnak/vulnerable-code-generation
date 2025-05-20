//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int i, n, key, a[1000], b[1000], c[1000], d[1000], e[1000], f[1000], g[1000], h[1000], i_a, i_b, i_c, pos, flag = 0;
  char str[1000];
  FILE *fp;

  fp = fopen("secret.txt", "r");
  fscanf(fp, "%d", &n);
  fclose(fp);

  for (i = 0; i < n; i++) {
    a[i] = rand() % 1000;
  }

  for (i = 0; i < n; i++) {
    b[i] = a[i] + 10;
  }

  for (i = 0; i < n; i++) {
    c[i] = b[i] - 20;
  }

  for (i = 0; i < n; i++) {
    d[i] = c[i] * 3;
  }

  for (i = 0; i < n; i++) {
    e[i] = d[i] / 4;
  }

  for (i = 0; i < n; i++) {
    f[i] = e[i] % 5;
  }

  for (i = 0; i < n; i++) {
    g[i] = f[i] + 6;
  }

  for (i = 0; i < n; i++) {
    h[i] = g[i] - 7;
  }

  for (i = 0; i < n; i++) {
    i_a = h[i] / 8;
    i_b = h[i] % 8;
    pos = i_a * 8 + i_b;
    str[pos] = 'a' + i;
  }

  str[n] = '\0';

  printf("%s", str);
  return 0;
}