//FormAI DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>

int main() {
  // greet the user
  printf("Welcome to my arithmetic program!\n");
  printf("Please enter two integers.\n");

  // prompt user for two integers
  int num1, num2;
  printf("First integer: ");
  scanf("%d", &num1);
  printf("Second integer: ");
  scanf("%d", &num2);

  // perform arithmetic operations
  int sum = num1 + num2;
  int diff = num1 - num2;
  int prod = num1 * num2;
  float quotient = (float) num1 / num2;

  // display results to the user
  printf("\nHere are the arithmetic results:\n");
  printf("%d + %d = %d\n", num1, num2, sum);
  printf("%d - %d = %d\n", num1, num2, diff);
  printf("%d * %d = %d\n", num1, num2, prod);
  printf("%d / %d = %.2f\n", num1, num2, quotient);

  // check if numbers are prime
  int prime1 = is_prime(num1);
  int prime2 = is_prime(num2);

  // display prime results to the user
  if (prime1) {
    printf("\n%d is a prime number.\n", num1);
  } else {
    printf("\n%d is not a prime number.\n", num1);
  }

  if (prime2) {
    printf("%d is a prime number.\n", num2);
  } else {
    printf("%d is not a prime number.\n", num2);
  }

  return 0;
}

// function to check if a number is prime
int is_prime(int n) {
  if (n <= 1) {
    return 0;
  }

  for (int i = 2; i <= n/2; i++) {
    if (n % i == 0) {
      return 0;
    }
  }

  return 1;
}