//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Recursive factorial function
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}

// Main function
int main() {
  int n, i;
  long long int result;

  // Ask user for input
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  // Calculate factorial using recursive function
  result = factorial(n);

  // Print result
  printf("The factorial of %d is %lld\n", n, result);

  // Calculate and print the sum of digits
  for (i = 1; i <= n; i++) {
    result = result + (n % 10) * pow(10, i-1);
  }
  printf("The sum of digits is %lld\n", result);

  // Calculate and print the product of digits
  for (i = 1; i <= n; i++) {
    result = result * (n % 10) * pow(10, i-1);
  }
  printf("The product of digits is %lld\n", result);

  return 0;
}

// Pow function
long long int pow(long long int base, int exp) {
  long long int result = 1;
  while (exp > 0) {
    result *= base;
    exp--;
  }
  return result;
}