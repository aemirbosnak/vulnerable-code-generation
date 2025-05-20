//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Claude Shannon
/* This C Browser Plugin program is an example of a simple calculator that performs basic arithmetic operations.
It is inspired by Claude Shannon's work in information theory, which focused on encoding and transmitting information efficiently. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function Declarations
void add(double num1, double num2);
void subtract(double num1, double num2);
void multiply(double num1, double num2);
void divide(double num1, double num2);

int main()
{
  char operation;
  double num1, num2;

  printf("Welcome to the Calculator Plugin Program!\n");
  printf("Please input an arithmetic operation ( +, -, *, or / ): ");
  scanf("%c", &operation);

  printf("\nEnter the first number: ");
  scanf("%lf", &num1);

  printf("\nEnter the second number: ");
  scanf("%lf", &num2);

  switch(operation)
  {
    case '+':
      add(num1, num2);
      break;
    case '-':
      subtract(num1, num2);
      break;
    case '*':
      multiply(num1, num2);
      break;
    case '/':
      divide(num1, num2);
      break;
    default:
      printf("Invalid Operation. Please enter a valid arithmetic operator ( +, -, *, or / )");
      break;
  }

  return 0;
}

// Function Definitions
void add(double num1, double num2)
{
  double result = num1 + num2;
  printf("Result: %lf", result);
}

void subtract(double num1, double num2)
{
  double result = num1 - num2;
  printf("Result: %lf", result);
}

void multiply(double num1, double num2)
{
  double result = num1 * num2;
  printf("Result: %lf", result);
}

void divide(double num1, double num2)
{
  if(num2 == 0) // Division by Zero Check
  {
    printf("Error: Division by Zero");
    return;
  }
  double result = num1 / num2;
  printf("Result: %lf", result);
}