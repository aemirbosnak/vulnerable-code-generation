//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  printf("Pattern 1:\n");
  for (int i = 1; i <= num; i++) {
    for (int j = num; j >= i; j--) {
      printf("* ");
    }
    printf("\n");
  }

  printf("Pattern 2:\n");
  for (int i = num; i >= 1; i--) {
    for (int j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  printf("Pattern 3:\n");
  for (int i = 1; i <= num; i++) {
    for (int j = 1; j <= i; j++) {
      printf("%d ", i);
    }
    printf("\n");
  }

  printf("Pattern 4:\n");
  for (int i = 1; i <= num; i++) {
    for (int j = num; j >= i; j--) {
      printf("%d ", i);
    }
    printf("\n");
  }

  printf("Pattern 5:\n");
  for (int i = 1; i <= num; i++) {
    for (int j = 1; j <= num; j++) {
      if (i == j) {
        printf("* ");
      } else {
        printf("%d ", i*j);
      }
    }
    printf("\n");
  }

  return 0;
}