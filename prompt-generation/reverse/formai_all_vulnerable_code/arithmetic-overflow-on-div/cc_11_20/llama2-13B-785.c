//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 100

int main() {
  int num1, num2, result;
  char op;

  // Ask user for first number
  printf("Enter first number: ");
  scanf("%d", &num1);

  // Ask user for second number
  printf("Enter second number: ");
  scanf("%d", &num2);

  // Ask user for operation
  printf("Enter operation (+, -, *, /): ");
  scanf(" %c", &op);

  // Perform operation
  switch (op) {
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
    default:
      result = -1;
      break;
  }

  // Check for errors
  if (num1 == 0 || num2 == 0) {
    result = -2;
  } else if (op != '+' && op != '-' && op != '*' && op != '/') {
    result = -3;
  }

  // Display result and error message
  if (result == -1) {
    printf("Oops! Looks like you entered an invalid operation. Try again!\n");
  } else if (result == -2) {
    printf("Uh-oh! You entered zero as one of the numbers. Try again!\n");
  } else if (result == -3) {
    printf("Whoa! You entered a non-numeric character as the operation. Try again!\n");
  } else {
    printf("Result: %d\n", result);
  }

  return 0;
}