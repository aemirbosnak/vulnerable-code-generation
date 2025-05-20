//Gemma-7B DATASET v1.0 Category: Data mining ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

main() {
  int i, j, k, l, n, m, a[100], b[100], c[100], d[100], e[100], f[100];

  printf("Enter the number of elements:");
  scanf("%d", &n);

  printf("Enter the elements:");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (i = 0; i < n; i++) {
    b[i] = a[i] * 2;
  }

  for (i = 0; i < n; i++) {
    c[i] = a[i] + 10;
  }

  for (i = 0; i < n; i++) {
    d[i] = a[i] - 5;
  }

  for (i = 0; i < n; i++) {
    e[i] = a[i] % 3;
  }

  for (i = 0; i < n; i++) {
    f[i] = a[i] / 4;
  }

  printf("The doubled elements are:");
  for (i = 0; i < n; i++) {
    printf("%d ", b[i]);
  }

  printf("\nThe elements increased by 10 are:");
  for (i = 0; i < n; i++) {
    printf("%d ", c[i]);
  }

  printf("\nThe elements decreased by 5 are:");
  for (i = 0; i < n; i++) {
    printf("%d ", d[i]);
  }

  printf("\nThe elements modulo 3 are:");
  for (i = 0; i < n; i++) {
    printf("%d ", e[i]);
  }

  printf("\nThe elements divided by 4 are:");
  for (i = 0; i < n; i++) {
    printf("%d ", f[i]);
  }

  return 0;
}