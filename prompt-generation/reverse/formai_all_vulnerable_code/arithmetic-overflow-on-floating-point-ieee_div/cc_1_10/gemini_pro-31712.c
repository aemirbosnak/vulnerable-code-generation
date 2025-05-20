//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Function to get the operator from the user
char getOperator(void) {
  char operator;
  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c", &operator);
  return operator;
}

//Function to get the operands from the user
float getOperands(void) {
  float operand;
  printf("Enter an operand: ");
  scanf(" %f", &operand);
  return operand;
}

//Function to perform the calculation
float performCalculation(char operator, float operand1, float operand2) {
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
      if (operand2 == 0) {
        printf("Error: division by zero\n");
        return 0;
      }
      result = operand1 / operand2;
      break;
    default:
      printf("Error: invalid operator\n");
      return 0;
  }
  return result;
}

//Function to print the result
void printResult(float result) {
  printf("The result is: %f\n", result);
}

//Main function
int main(void) {
  char operator;
  float operand1, operand2, result;

  //Get the operator from the user
  operator = getOperator();

  //Get the operands from the user
  operand1 = getOperands();
  operand2 = getOperands();

  //Perform the calculation
  result = performCalculation(operator, operand1, operand2);

  //Print the result
  printResult(result);

  return 0;
}