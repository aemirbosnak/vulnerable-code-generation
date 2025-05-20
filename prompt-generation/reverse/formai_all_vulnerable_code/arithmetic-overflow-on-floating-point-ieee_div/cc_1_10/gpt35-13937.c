//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: statistical
#include <stdio.h>

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

void fibonacci_visualizer(int length) {
  if (length <= 0) {
    printf("Invalid length\n");
    return;
  }

  printf("Fibonacci Sequence:\n");

  int prev = 0;
  int curr = 1;

  printf("%d, ", prev);

  if (length == 1) {
    printf("\n");
    return;
  }

  printf("%d, ", curr);

  if (length == 2) {
    printf("\n");
    return;
  }

  for (int i = 3; i <= length; i++) {
    int next = prev + curr;
    printf("%d, ", next);
    prev = curr;
    curr = next;
  }

  printf("\n");

  printf("Fibonacci Sequence Ratio:\n");

  double fib_ratio[length];

  for (int i = 0; i < length; i++) {
    fib_ratio[i] = (double) fibonacci(i+1) / fibonacci(i);
  }

  for (int i = 0; i < length; i++) {
    printf("%.2f, ", fib_ratio[i]);
  }

  printf("\n");

  printf("Fibonacci Sequence Plotted:\n");

  for (int i = 0; i < length; i++) {
    int num_stars = fibonacci(i);
    for (int j = 0; j < num_stars; j++) {
      printf("*");
    }
    printf("\n");
  }
}

int main() {
  fibonacci_visualizer(10);
  return 0;
}