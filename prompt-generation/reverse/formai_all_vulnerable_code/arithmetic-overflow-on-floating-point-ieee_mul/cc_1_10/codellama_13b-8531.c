//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: enthusiastic
/*
* Scientific Calculator Implementation Example Program
*
* This program is an example of a scientific calculator implementation in C.
* It provides a simple command-line interface for performing various scientific calculations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the calculator functions

double add(double a, double b) {
  return a + b;
}

double subtract(double a, double b) {
  return a - b;
}

double multiply(double a, double b) {
  return a * b;
}

double divide(double a, double b) {
  return a / b;
}

double sqrt(double a) {
  return sqrt(a);
}

double pow(double a, double b) {
  return pow(a, b);
}

double sin(double a) {
  return sin(a);
}

double cos(double a) {
  return cos(a);
}

double tan(double a) {
  return tan(a);
}

// Define the main function

int main() {
  // Declare variables
  double num1, num2, result;
  char operation;

  // Prompt the user for input
  printf("Enter a number: ");
  scanf("%lf", &num1);

  printf("Enter another number: ");
  scanf("%lf", &num2);

  printf("Enter an operation (+, -, *, /, sqrt, pow, sin, cos, tan): ");
  scanf(" %c", &operation);

  // Perform the selected operation
  switch (operation) {
    case '+':
      result = add(num1, num2);
      break;
    case '-':
      result = subtract(num1, num2);
      break;
    case '*':
      result = multiply(num1, num2);
      break;
    case '/':
      result = divide(num1, num2);
      break;
    case 'sqrt':
      result = sqrt(num1);
      break;
    case 'pow':
      result = pow(num1, num2);
      break;
    case 'sin':
      result = sin(num1);
      break;
    case 'cos':
      result = cos(num1);
      break;
    case 'tan':
      result = tan(num1);
      break;
    default:
      printf("Invalid operation");
      return 1;
  }

  // Print the result
  printf("Result: %lf", result);

  return 0;
}