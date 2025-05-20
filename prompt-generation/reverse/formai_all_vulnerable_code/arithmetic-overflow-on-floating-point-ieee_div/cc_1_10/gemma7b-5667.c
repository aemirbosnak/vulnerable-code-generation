//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  char buffer[MAX_BUFFER_SIZE];
  char operator;
  double num1, num2;
  double result;

  printf("C Scientific Calculator\n");
  printf("Enter an expression: ");

  // Get the user input
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  // Parse the input
  operator = buffer[0];
  num1 = atof(buffer + 1);
  num2 = atof(buffer + 3);

  // Calculate the result
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
      if (num2 == 0) {
        printf("Error: division by zero\n");
      } else {
        result = num1 / num2;
      }
      break;
    default:
      printf("Error: invalid operator\n");
  }

  // Display the result
  if (result != -1) {
    printf("The result is: %.2lf\n", result);
  }

  return 0;
}