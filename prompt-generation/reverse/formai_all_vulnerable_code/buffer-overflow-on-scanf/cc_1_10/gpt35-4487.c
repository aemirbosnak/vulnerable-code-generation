//FormAI DATASET v1.0 Category: Recursive ; Style: dynamic
#include <stdio.h>

/* Recursive Factorial Function */
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}

/* Recursive Fibonacci Function */
int fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

/* Main Function */
int main() {
  int choice = 0;

  printf("Choose an option:\n");
  printf("1. Factorial\n");
  printf("2. Fibonacci\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1: {
      int n;
      printf("Enter a number to find its factorial: ");
      scanf("%d", &n);
      printf("%d! = %d\n", n, factorial(n));
      break;
    }
    case 2: {
      int n;
      printf("Enter a number to find its fibonacci value: ");
      scanf("%d", &n);
      printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
      break;
    }
    default: {
      printf("Invalid choice!\n");
      break;
    }
  }

  return 0;
}