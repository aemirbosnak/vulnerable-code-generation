//Code Llama-13B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define FIB_MAX 100
#define WIDTH 80
#define HEIGHT 20

void print_fib(int n) {
  int fib[FIB_MAX];
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i <= n; i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }

  for (int i = 0; i <= n; i++) {
    printf("%d ", fib[i]);
  }
}

void print_fib_seq(int n) {
  int fib[FIB_MAX];
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i <= n; i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }

  for (int i = 0; i <= n; i++) {
    printf("%d ", fib[i]);
  }
}

void print_fib_seq_paranoid(int n) {
  int fib[FIB_MAX];
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i <= n; i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }

  for (int i = 0; i <= n; i++) {
    printf("%d ", fib[i]);
  }
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  print_fib_seq_paranoid(n);
  return 0;
}