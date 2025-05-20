//FormAI DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>

int main() {
  int n = 50;
  printf("Welcome to the unique C arithmetic program!");
  printf("\n\n");

  // Generate Fibonacci sequence
  int fib[n];
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  // Print the Fibonacci sequence
  printf("The first %d numbers in the Fibonacci sequence are:\n", n);
  for (int i = 0; i < n; i++) {
    printf("%d ", fib[i]);
  }
  printf("\n\n");

  // Find the sum of all numbers from 1 to n
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  printf("The sum of all numbers from 1 to %d is %d.\n\n", n, sum);

  // Generate prime numbers up to n
  printf("The prime numbers up to %d are:\n", n);
  for (int i = 2; i <= n; i++) {
    int is_prime = 1;
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime) {
      printf("%d ", i);
    }
  }
  printf("\n\n");

  // Reverse a number
  int num = 12345;
  printf("The reverse of %d is ", num);
  int rev_num = 0;
  while (num != 0) {
    rev_num = rev_num * 10 + num % 10;
    num /= 10;
  }
  printf("%d.\n\n", rev_num);

  // Find the factorial of a number
  int x = 5;
  int factorial = 1;
  for (int i = 1; i <= x; i++) {
    factorial *= i;
  }
  printf("The factorial of %d is %d.\n\n", x, factorial);

  printf("Thank you for trying out the unique C arithmetic program!\n");

  return 0;
}