//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Our parsing function! So excited!
int parse(char *input) {
  // Let's jump around the input like a kangaroo!
  int index = 0;
  int result = 0;

  // Look for the start of a number!
  while (input[index] != '\0' && !isdigit(input[index])) {
    index++;
  }

  // We found a number! Let's leap over it!
  while (isdigit(input[index])) {
    result *= 10;
    result += input[index] - '0';
    index++;
  }

  // Now, let's look for an operator!
  while (input[index] != '\0' && !strchr("+-*/", input[index])) {
    index++;
  }

  // We found an operator! Let's jump on it!
  char operator = input[index];
  index++;

  // Time for another number! Let's hop over it!
  int operand2 = 0;
  while (isdigit(input[index])) {
    operand2 *= 10;
    operand2 += input[index] - '0';
    index++;
  }

  // Let's perform the operation!
  switch (operator) {
    case '+':
      result += operand2;
      break;
    case '-':
      result -= operand2;
      break;
    case '*':
      result *= operand2;
      break;
    case '/':
      if (operand2 == 0) {
        printf("Error: Division by zero!\n");
        return -1;
      }
      result /= operand2;
      break;
    default:
      printf("Error: Invalid operator!\n");
      return -1;
  }

  // We're done! Let's jump around and celebrate!
  return result;
}

int main() {
  // Let's get some input from the user!
  char input[100];
  printf("Enter an expression: ");
  fgets(input, 100, stdin);

  // Parse the input!
  int result = parse(input);

  // Print the result!
  if (result != -1) {
    printf("Result: %d\n", result);
  }

  return 0;
}