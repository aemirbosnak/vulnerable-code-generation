//FormAI DATASET v1.0 Category: Pattern printing ; Style: detailed
// A unique C pattern printing example program

#include<stdio.h>

int main() {
  int rows, i, j, k;

  printf("Enter number of rows:");
  scanf("%d", &rows);

  // Pattern 1
  printf("\nPattern 1:\n");
  for (i = 1; i <= rows; i++) {
    for (j = 1; j <= i; j++) {
      printf("%d ", i);
    }
    printf("\n");
  }

  // Pattern 2
  printf("\nPattern 2:\n");
  for (i = 1; i <= rows; i++) {
    for (j = rows; j >= i; j--) {
      printf("* ");
    }
    printf("\n");
  }

  // Pattern 3
  printf("\nPattern 3:\n");
  for (i = 1; i <= rows; i++) {
    for (j = rows; j >= i; j--) {
      printf("  ");
    }
    for (k = 1; k <= i; k++) {
      printf("* ");
    }
    printf("\n");
  }

  // Pattern 4
  printf("\nPattern 4:\n");
  for (i = 1; i <= rows; i++) {
    for (j = rows; j > i; j--) {
      printf(" ");
    }
    for (k = 1; k <= i; k++) {
      printf("* ");
    }
    printf("\n");
  }

  // Pattern 5
  printf("\nPattern 5:\n");
  for (i = 1; i <= rows; i++) {
    for (j = rows; j > i; j--) {
      printf(" ");
    }
    for (k = 1; k <= i * 2 - 1; k++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}