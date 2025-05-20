//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complex
#include <stdio.h>

void printFibonacci(int n) {
  int a = 0, b = 1, c, i;
  if (n < 1) return;

  printf("%d %d ", a, b);
  for (i = 3; i <= n; i++){
    c = a + b;
    a = b;
    b = c;
    printf("%d ", c);
  }
}

void drawFibonacci(int n) {
  int a = 0, b = 1, c, i;
  if (n < 1) return;

  for (i = 1; i <= n; i++){
    printf("%d. ", i);
    c = a + b;
    a = b;
    b = c;

    int j = 0;
    for (j = 1; j <= c; j++){
      if (j == 1 || j == c){
        printf("* ");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  int n;
  printf("Enter a number greater than 0: ");
  scanf("%d", &n);

  printf("\n");
  printf("*** Fibonacci Sequence ***\n");
  printFibonacci(n);

  printf("\n\n");
  printf("*** Fibonacci Sequence Visualizer ***\n");
  drawFibonacci(n);

  return 0;
}