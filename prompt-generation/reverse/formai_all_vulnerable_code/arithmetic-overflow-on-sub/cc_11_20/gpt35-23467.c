//FormAI DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>

int main() {
  // Welcome the user to the program
  printf("Welcome to the Arithmetic Calculator Program!\n\n");

  // Prompt the user for 2 numbers
  printf("Please enter the first number: ");
  int num1 = 0;
  scanf("%d", &num1);

  printf("Please enter the second number: ");
  int num2 = 0;
  scanf("%d", &num2);

  // Perform Arithmetic Operations
  int sum = num1 + num2;
  int diff = num1 - num2;
  int product = num1 * num2;
  float quotient = (float)num1 / num2;

  // Print the results of the arithmetic operations
  printf("\nHere are the results of the Arithmetic Operations:\n");
  printf("%d + %d = %d\n", num1, num2, sum);
  printf("%d - %d = %d\n", num1, num2, diff);
  printf("%d * %d = %d\n", num1, num2, product);
  printf("%d / %d = %.2f\n", num1, num2, quotient);

  // Check if the numbers are divisible by 2
  int even1 = num1 % 2 == 0 ? 1 : 0;
  int even2 = num2 % 2 == 0 ? 1 : 0;

  // Print the results of the divisibility test
  printf("\nHere are the results of the Divisibility Test:\n");
  printf("%d is %s\n", num1, even1 ? "even" : "odd");
  printf("%d is %s\n", num2, even2 ? "even" : "odd");

  // Check if any of the numbers are negative
  int negative1 = num1 < 0 ? 1 : 0;
  int negative2 = num2 < 0 ? 1 : 0;

  // Print the results of the negativity test
  printf("\nHere are the results of the Negativity Test:\n");
  if (negative1 && negative2) {
    printf("Both numbers are negative\n");
  } else if (negative1 || negative2) {
    printf("One of the numbers is negative\n");
  } else {
    printf("Neither of the numbers is negative\n");
  }

  // Exit the program
  printf("\nThank you for using the Arithmetic Calculator Program!\n");
  return 0;
}