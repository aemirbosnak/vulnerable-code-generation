//FormAI DATASET v1.0 Category: Pattern printing ; Style: genious
#include <stdio.h>

int main() {
  printf("\n\t<----- Genius C Pattern Printing ----->\n\n");

  int num, i, j, k;

  // First Pattern
  printf("\tPattern 1:\n");
  printf("\tEnter a number: ");
  scanf("%d", &num);
  for (i = 0; i < num; i++) {
    for (j = 0; j < i+1; j++) {
      printf("* ");
    }
    printf("\n");
  }

  // Second Pattern
  printf("\n\tPattern 2:\n");
  printf("\tEnter a number: ");
  scanf("%d", &num);
  for (i = 0; i < num; i++) {
    for (j = 0; j < num-i-1; j++) {
      printf(" ");
    }
    for (j = 0; j < 2*i+1; j++) {
      printf("*");
    }
    printf("\n");
  }

  // Third Pattern
  printf("\n\tPattern 3:\n");
  printf("\tEnter a number: ");
  scanf("%d", &num);
  k = num-1;
  for (i = 0; i < num; i++) {
    for (j = 0; j < k; j++) {
      printf(" ");
    }
    k--;
    for (j = 0; j < i*2+1; j++) {
      if (j == 0 || j == i*2 || i == num-1) {
        printf("*");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }

  // Fourth Pattern
  printf("\n\tPattern 4:\n");
  printf("\tEnter a number: ");
  scanf("%d", &num);
  k = 0;
  for (i = 1; i <= num; i++) {
    for (j = 1; j <= num-i; j++) {
      printf("  ");
    }
    while (k != 2*i-1) {
      printf("* ");
      k++;
    }
    k = 0;
    printf("\n");
  }

  printf("\n\t<----- End of Genius C Pattern Printing ----->\n");
  return 0;
}