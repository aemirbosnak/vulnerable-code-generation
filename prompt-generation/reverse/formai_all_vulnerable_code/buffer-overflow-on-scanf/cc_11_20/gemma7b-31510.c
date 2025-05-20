//Gemma-7B DATASET v1.0 Category: Data mining ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
  int i, j, k, l, n, m, a[1000], b[1000], c[1000];
  char str[1000];

  printf("Enter the number of elements:");
  scanf("%d", &n);

  printf("Enter the elements:");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  printf("Enter the query:");
  scanf("%s", str);

  for (i = 0; str[i] != '\0'; i++) {
    switch (str[i]) {
      case 'a':
        for (j = 0; j < n; j++) {
          if (a[j] % 2 == 0) {
            b[j] = a[j] * 2;
          } else {
            b[j] = a[j] + 1;
          }
        }
        break;
      case 'b':
        for (j = 0; j < n; j++) {
          c[j] = a[j] - 1;
        }
        break;
      case 'c':
        for (j = 0; j < n; j++) {
          if (a[j] % 2 == 0) {
            c[j] = a[j] * 2;
          } else {
            c[j] = a[j] + 1;
          }
        }
        break;
    }
  }

  printf("The results are:");
  for (i = 0; i < n; i++) {
    printf("%d ", b[i]);
  }
  printf("\n");
  for (i = 0; i < n; i++) {
    printf("%d ", c[i]);
  }
}