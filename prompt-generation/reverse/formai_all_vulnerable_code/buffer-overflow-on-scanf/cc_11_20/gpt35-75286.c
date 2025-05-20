//FormAI DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
  int n, i, j, k;

  printf("Enter the number of rows: ");
  scanf("%d", &n);

  // pattern 1
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  // pattern 2
  for (i = n; i >= 1; i--) {
    for (j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  // pattern 3
  for (i = 1; i <= n; i++) {
    for (j = n; j >= i; j--) {
      printf("* ");
    }
    printf("\n");
  }

  // pattern 4
  for (i = 1; i <= n; i++) {
    for (j = n; j >= i; j--) {
      printf(" ");
    }
    for (k = 1; k <= i; k++) {
      printf("* ");
    }
    printf("\n");
  }

  // pattern 5
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      printf("%d ", j);
    }
    printf("\n");
  }

  // pattern 6
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      printf("%c ", j+64);
    }
    printf("\n");
  }

  return 0;
}