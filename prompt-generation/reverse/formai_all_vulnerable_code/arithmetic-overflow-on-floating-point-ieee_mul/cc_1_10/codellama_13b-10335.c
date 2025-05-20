//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: inquisitive
// Scientific Calculator Implementation in C
#include <stdio.h>
#include <stdlib.h>

// Function to perform mathematical operations
void performOperation(char op, float num1, float num2) {
  float result;
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
      printf("Invalid operation\n");
      return;
  }
  printf("Result: %f\n", result);
}

// Function to perform trigonometric operations
void performTrigonometricOperation(char op, float num) {
  float result;
  switch (op) {
    case 's':
      result = sin(num);
      break;
    case 'c':
      result = cos(num);
      break;
    case 't':
      result = tan(num);
      break;
    default:
      printf("Invalid operation\n");
      return;
  }
  printf("Result: %f\n", result);
}

// Main function to handle user input
int main() {
  char operation;
  float num1, num2;
  printf("Enter an operation (+, -, *, /, s, c, t): ");
  scanf("%c", &operation);
  printf("Enter two numbers: ");
  scanf("%f %f", &num1, &num2);
  if (operation == 's' || operation == 'c' || operation == 't') {
    performTrigonometricOperation(operation, num1);
  } else {
    performOperation(operation, num1, num2);
  }
  return 0;
}