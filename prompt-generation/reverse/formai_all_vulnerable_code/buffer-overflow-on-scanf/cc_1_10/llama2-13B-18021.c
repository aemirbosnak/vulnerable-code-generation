//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the factorial of a given number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Function to calculate the sum of the first n positive integers
int sum_first_n(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

// Function to calculate the product of the first n positive integers
int product_first_n(int n) {
  int product = 1;
  for (int i = 1; i <= n; i++) {
    product *= i;
  }
  return product;
}

int main() {
  int n, m, sum, product;

  // Get the value of n from the user
  printf("Enter a positive integer n: ");
  scanf("%d", &n);

  // Calculate and print the factorial of n
  printf("The factorial of n is: %d\n", factorial(n));

  // Calculate and print the sum of the first n positive integers
  printf("The sum of the first n positive integers is: %d\n", sum_first_n(n));

  // Calculate and print the product of the first n positive integers
  printf("The product of the first n positive integers is: %d\n", product_first_n(n));

  return 0;
}