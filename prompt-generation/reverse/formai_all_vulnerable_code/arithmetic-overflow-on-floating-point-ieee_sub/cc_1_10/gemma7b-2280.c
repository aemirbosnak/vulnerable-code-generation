//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void calculate(char **buffer, int *index, double *result) {
  double num1, num2;
  char operator;

  // Extract operator and operands from the buffer
  operator = buffer[*index];
  num1 = atof(buffer[*index - 1]);
  num2 = atof(buffer[*index - 2]);

  // Perform the calculation
  switch (operator) {
    case '+':
      *result = num1 + num2;
      break;
    case '-':
      *result = num1 - num2;
      break;
    case '*':
      *result = num1 * num2;
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: division by zero\n");
        return;
      }
      *result = num1 / num2;
      break;
  }

  // Increment the index and clear the operator from the buffer
  *index++;
  buffer[*index - 1] = '\0';
}

int main() {
  char buffer[MAX_BUFFER_SIZE];
  int index = 0;
  double result = 0.0;

  // Get the calculator input
  printf("Enter an expression: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  // Remove the newline character from the input
  buffer[strcspn(buffer, "\n")] = '\0';

  // Calculate the result
  while (buffer[index] != '\0') {
    calculate(&buffer, &index, &result);
  }

  // Print the result
  printf("The result is: %.2lf\n", result);

  return 0;
}