//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to get the operator from the user
char getOperator() {
  char operator;
  printf("Enter an operator (+, -, *, /, %): ");
  scanf(" %c", &operator);
  return operator;
}

// Function to get the operands from the user
float getOperands() {
  float operand;
  printf("Enter an operand: ");
  scanf(" %f", &operand);
  return operand;
}

// Function to perform the calculation
float calculate(float operand1, float operand2, char operator) {
  float result;

  switch (operator) {
    case '+':
      result = operand1 + operand2;
      break;
    case '-':
      result = operand1 - operand2;
      break;
    case '*':
      result = operand1 * operand2;
      break;
    case '/':
      result = operand1 / operand2;
      break;
    case '%':
      result = fmod(operand1, operand2);
      break;
    default:
      printf("Invalid operator!\n");
      result = 0.0;
  }

  return result;
}

// Function to print the result
void printResult(float result) {
  printf("The result is: %f\n", result);
}

int main() {

  float operand1, operand2, result;
  char operator;

  // Get the operator from the user
  operator = getOperator();

  // Get the operands from the user
  operand1 = getOperands();
  operand2 = getOperands();

  // Perform the calculation
  result = calculate(operand1, operand2, operator);

  // Print the result
  printResult(result);

  return 0;
}