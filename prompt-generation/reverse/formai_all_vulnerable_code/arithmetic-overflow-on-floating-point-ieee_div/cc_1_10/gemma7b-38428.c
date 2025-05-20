//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  char buffer[MAX_BUFFER_SIZE];
  int i = 0;
  char operator;
  double num1, num2, result;

  printf("Enter an expression: ");

  // Get the user input
  while (1) {
    char ch = getchar();
    if (ch == '\n') {
      break;
    }
    buffer[i++] = ch;
  }

  // Parse the expression
  operator = buffer[0];
  num1 = atof(buffer[1] - '0');
  num2 = atof(buffer[2] - '0');

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
        printf("Cannot divide by zero\n");
      } else {
        result = num1 / num2;
      }
      break;
  }

  // Display the result
  printf("The result is: %.2lf\n", result);

  return 0;
}