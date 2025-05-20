//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Function declarations
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);

// Main function
int main() {
  double num1, num2, result;
  char operation;

  printf("Welcome to the Scientific Calculator!\n");
  printf("Please enter the first number: ");
  scanf("%lf", &num1);
  printf("Please enter the second number: ");
  scanf("%lf", &num2);
  printf("Please enter the operation to perform (e.g. +, -, *, /): ");
  scanf(" %c", &operation);

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
  default:
    printf("Invalid operation!");
    return 1;
  }

  printf("The result is: %lf\n", result);
  return 0;
}

// Function definitions
double add(double num1, double num2) {
  return num1 + num2;
}

double subtract(double num1, double num2) {
  return num1 - num2;
}

double multiply(double num1, double num2) {
  return num1 * num2;
}

double divide(double num1, double num2) {
  if (num2 == 0) {
    printf("Cannot divide by zero!");
    return 0;
  }
  return num1 / num2;
}