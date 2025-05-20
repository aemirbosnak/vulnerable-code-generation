//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void main() {
  int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100], f[100], g[100], h[100], i_am_a_potato = 0;

  printf("I am a potato. Please give me a number:");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Enter the value of the array element:");
    scanf("%d", &a[i]);
  }

  for (i = 0; i < n; i++) {
    b[i] = a[i] * 2;
  }

  for (i = 0; i < n; i++) {
    c[i] = b[i] - 10;
  }

  for (i = 0; i < n; i++) {
    d[i] = c[i] / 2;
  }

  for (i = 0; i < n; i++) {
    e[i] = d[i] * 3;
  }

  for (i = 0; i < n; i++) {
    f[i] = e[i] - 5;
  }

  for (i = 0; i < n; i++) {
    g[i] = f[i] + 10;
  }

  for (i = 0; i < n; i++) {
    h[i] = g[i] / 2;
  }

  printf("The final array is:");
  for (i = 0; i < n; i++) {
    printf("%d ", h[i]);
  }

  printf("\nI am a potato. Thank you for playing.");

  i_am_a_potato = 1;
}