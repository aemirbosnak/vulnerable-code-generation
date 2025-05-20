//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a given number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}

// Function to calculate the sum of the digits of a given number
int sum_digits(int n) {
  int sum = 0;
  while (n != 0) {
    sum = (sum + (n % 10)) % 10;
    n /= 10;
  }
  return sum;
}

// Function to calculate the modular multiplicative inverse of a given number
int mod_inv(int a, int n) {
  int x = 0, y = 1;
  while (y > 0) {
    int temp = (a * y) % n;
    x = y;
    y = temp;
  }
  return x;
}

int main() {
  int n, m;
  printf("Enter a number: ");
  scanf("%d", &n);

  // Calculate the factorial of n
  int factorial_result = factorial(n);
  printf("The factorial of %d is %d\n", n, factorial_result);

  // Calculate the sum of the digits of n
  int sum_digits_result = sum_digits(n);
  printf("The sum of the digits of %d is %d\n", n, sum_digits_result);

  // Calculate the modular multiplicative inverse of n modulo 10
  int mod_inv_result = mod_inv(n, 10);
  printf("The modular multiplicative inverse of %d modulo 10 is %d\n", n, mod_inv_result);

  return 0;
}