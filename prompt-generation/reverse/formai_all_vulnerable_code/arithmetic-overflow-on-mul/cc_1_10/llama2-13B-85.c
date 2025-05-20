//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

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
  while (n > 0) {
    sum = (sum + (n % 10)) % 10;
    n /= 10;
  }
  return sum;
}

// Function to calculate the product of two given numbers
int product(int a, int b) {
  return a * b;
}

// Function to calculate the difference of two given numbers
int difference(int a, int b) {
  return a - b;
}

// Function to calculate the quotient of two given numbers
int quotient(int a, int b) {
  return a / b;
}

// Function to calculate the remainder of two given numbers
int remainder(int a, int b) {
  return a % b;
}

// Function to calculate the power of two given numbers
int power(int a, int b) {
  int result = 1;
  while (b > 0) {
    result *= a;
    b--;
  }
  return result;
}

int main() {
  // Initialize variables
  int num1 = 123, num2 = 456, result;
  char magic_number[MAGIC_NUMBER];

  // Calculate the factorial of num1
  int factorial_result = factorial(num1);

  // Calculate the sum of the digits of num1
  int sum_digits_result = sum_digits(num1);

  // Calculate the product of num1 and num2
  int product_result = product(num1, num2);

  // Calculate the difference of num1 and num2
  int difference_result = difference(num1, num2);

  // Calculate the quotient of num1 and num2
  int quotient_result = quotient(num1, num2);

  // Calculate the remainder of num1 and num2
  int remainder_result = remainder(num1, num2);

  // Calculate the power of num1 and num2
  int power_result = power(num1, num2);

  // Print the results
  printf("Factorial of %d is %d\n", num1, factorial_result);
  printf("Sum of digits of %d is %d\n", num1, sum_digits_result);
  printf("Product of %d and %d is %d\n", num1, num2, product_result);
  printf("Difference of %d and %d is %d\n", num1, num2, difference_result);
  printf("Quotient of %d and %d is %d\n", num1, num2, quotient_result);
  printf("Remainder of %d and %d is %d\n", num1, num2, remainder_result);
  printf("Power of %d and %d is %d\n", num1, num2, power_result);

  // Print the magic number
  printf("Magic number is %s\n", magic_number);

  return 0;
}