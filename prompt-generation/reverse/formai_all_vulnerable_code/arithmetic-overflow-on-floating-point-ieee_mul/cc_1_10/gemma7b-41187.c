//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  char buffer[MAX_BUFFER_SIZE];
  int i = 0;
  char operator;
  double num1, num2;
  double result;

  // Clear the buffer
  buffer[0] = '\0';

  // Loop until the user enters an operator
  while (1) {
    printf("Enter an operator (+, -, *, /, %): ");
    operator = getchar();

    // Check if the operator is valid
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
      break;
    } else {
      printf("Invalid operator.\n");
    }
  }

  // Get the first number from the user
  printf("Enter the first number: ");
  scanf("%lf", &num1);

  // Get the second number from the user
  printf("Enter the second number: ");
  scanf("%lf", &num2);

  // Perform the calculation
  switch (operator) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      result = num1 / num2;
      break;
  }

  // Display the result
  printf("The result is: %.2lf\n", result);

  return 0;
}