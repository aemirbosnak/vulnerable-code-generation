//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
  char input[256];
  double num1, num2;
  int operator;

  printf("Enter the first number: ");
  gets(input);
  num1 = strtod(input, NULL);

  printf("Enter the operator (+, -, *, /, or %): ");
  gets(input);
  operator = input[0];

  printf("Enter the second number: ");
  gets(input);
  num2 = strtod(input, NULL);

  switch (operator) {
    case '+':
      printf("The result is: %.2f\n", num1 + num2);
      break;
    case '-':
      printf("The result is: %.2f\n", num1 - num2);
      break;
    case '*':
      printf("The result is: %.2f\n", num1 * num2);
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: division by zero\n");
      } else {
        printf("The result is: %.2f\n", num1 / num2);
      }
      break;
    case '%':
      if (num2 == 0) {
        printf("Error: division by zero\n");
      } else {
        printf("The result is: %.2f\n", fmod(num1, num2));
      }
      break;
    default:
      printf("Error: invalid operator\n");
  }

  return 0;
}