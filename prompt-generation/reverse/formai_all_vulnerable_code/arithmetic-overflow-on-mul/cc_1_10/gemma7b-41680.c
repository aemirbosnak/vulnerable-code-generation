//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void calculate(char **buffer) {
  int i = 0, result = 0, sign = 1, number = 0;
  char operator = '\0';

  // Iterate over the buffer to find the operator
  for (i = 0; buffer[i] != '\0'; i++) {
    if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/') {
      operator = buffer[i];
      break;
    }
  }

  // Calculate the number
  for (i = 0; buffer[i] != '\0' && buffer[i] != operator; i++) {
    number = number * 10 + buffer[i] - '0';
  }

  // Apply the operator
  switch (operator) {
    case '+':
      result = number + sign * result;
      break;
    case '-':
      result = number - sign * result;
      break;
    case '*':
      result = number * sign * result;
      break;
    case '/':
      result = number / sign * result;
      break;
  }

  // Update the result
  buffer[0] = 'R';
  buffer[1] = '=';
  buffer[2] = (result % 10) + '0';
  buffer[3] = (result / 10) + '0';
  buffer[4] = '\0';
}

int main() {
  char buffer[MAX_BUFFER_SIZE] = "";

  // Get the calculator input
  printf("Enter an expression: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  // Remove the newline character
  buffer[strcspn(buffer, "\n")] = '\0';

  // Calculate the result
  calculate(buffer);

  // Print the result
  printf("The result is: %s\n", buffer);

  return 0;
}