//Code Llama-13B DATASET v1.0 Category: Error handling ; Style: Sherlock Holmes
/*
 * Unique C Error Handling Example Program in a Sherlock Holmes Style
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  int input;
  int result;
  char operation;
  char error_message[100];

  // Get input from user
  printf("Enter an operation (+, -, *, /): ");
  scanf("%c", &operation);

  // Get input from user
  printf("Enter two numbers: ");
  scanf("%d %d", &input, &input);

  // Perform operation
  switch (operation) {
    case '+':
      result = input + input;
      break;
    case '-':
      result = input - input;
      break;
    case '*':
      result = input * input;
      break;
    case '/':
      if (input == 0) {
        sprintf(error_message, "Cannot divide by zero");
        goto error;
      }
      result = input / input;
      break;
    default:
      sprintf(error_message, "Invalid operation");
      goto error;
  }

  // Print result
  printf("Result: %d\n", result);

  return 0;

error:
  printf("Error: %s\n", error_message);
  return 1;
}