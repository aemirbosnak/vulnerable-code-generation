//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

void draw_knight(int x, int y) {
  printf("K");
  for (int i = 0; i < x; i++) {
    printf(" ");
  }
  for (int i = 0; i < y; i++) {
    printf("\n");
  }
}

void draw_castle(int x, int y) {
  printf("H");
  for (int i = 0; i < x; i++) {
    printf("=");
  }
  printf("\n");
  for (int i = 0; i < y; i++) {
    printf("=");
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter the number of Fibonacci terms to generate:");
  scanf("%d", &n);

  int a, b, c;
  a = b = 1;
  c = 0;

  for (int i = 0; i < n; i++) {
    c = a + b;
    a = b;
    b = c;
  }

  printf("The Fibonacci sequence is:");
  for (int i = 0; i < n; i++) {
    printf("%d, ", a);
  }
  printf("\n");

  draw_knight(a, 5);
  draw_castle(b, 5);

  return 0;
}