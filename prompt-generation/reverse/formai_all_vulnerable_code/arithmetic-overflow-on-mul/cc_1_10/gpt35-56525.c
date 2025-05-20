//FormAI DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>

int main() {
  int num1, num2, sum, difference, product;
  float quotient;

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Arithmetic operations
  sum = num1 + num2;
  difference = num1 - num2;
  product = num1 * num2;
  quotient = (float) num1 / num2;

  // Printing the results
  printf("--- Arithmetic Operations on %d and %d ---\n", num1, num2);
  printf("Sum: %d\n", sum);
  printf("Difference: %d\n", difference);
  printf("Product: %d\n", product);
  printf("Quotient: %.2f\n", quotient);

  // Checking if numbers are even or odd
  if (num1 % 2 == 0) {
    printf("%d is even.\n", num1);
  } else {
    printf("%d is odd.\n", num1);
  }

  if (num2 % 2 == 0) {
    printf("%d is even.\n", num2);
  } else {
    printf("%d is odd.\n", num2);
  }

  // Checking if numbers are prime or not
  int isnum1prime = 1;
  int isnum2prime = 1;

  for (int i = 2; i < num1 / 2; i++) {
    if (num1 % i == 0) {
      isnum1prime = 0;
      break;
    }
  }

  for (int j = 2; j < num2 / 2; j++) {
    if (num2 % j == 0) {
      isnum2prime = 0;
      break;
    }
  }

  if (isnum1prime == 1) {
    printf("%d is prime.\n", num1);
  } else {
    printf("%d is not prime.\n", num1);
  }

  if (isnum2prime == 1) {
    printf("%d is prime.\n", num2);
  } else {
    printf("%d is not prime.\n", num2);
  }

  return 0;
}