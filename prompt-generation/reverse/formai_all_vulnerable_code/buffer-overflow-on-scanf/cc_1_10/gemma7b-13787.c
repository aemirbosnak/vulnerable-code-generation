//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int buffer_position = 0;
int buffer_size = 0;

void clear_buffer() {
  buffer_position = 0;
  buffer_size = 0;
}

void add_to_buffer(char character) {
  if (buffer_size == MAX_BUFFER_SIZE) {
    return;
  }

  buffer[buffer_position++] = character;
  buffer_size++;
}

double calculate_expression() {
  char operator = '\0';
  double operand1 = 0.0;
  double operand2 = 0.0;

  for (int i = 0; buffer[i] != '\0'; i++) {
    switch (buffer[i]) {
      case '+':
        operator = '+';
        break;
      case '-':
        operator = '-';
        break;
      case '*':
        operator = '*';
        break;
      case '/':
        operator = '/';
        break;
      default:
        operand2 = operand2 * 10.0 + buffer[i] - '0';
    }

    switch (operator) {
      case '+':
        operand1 = operand2 + operand1;
        break;
      case '-':
        operand1 = operand2 - operand1;
        break;
      case '*':
        operand1 = operand2 * operand1;
        break;
      case '/':
        if (operand2 == 0) {
          return -1;
        }
        operand1 = operand2 / operand1;
        break;
    }

    clear_buffer();
  }

  return operand1;
}

int main() {
  char input[MAX_BUFFER_SIZE];

  printf("Enter an expression: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    add_to_buffer(input[i]);
  }

  double result = calculate_expression();

  if (result == -1) {
    printf("Error: Division by zero is not allowed.\n");
  } else {
    printf("The result is: %.2lf\n", result);
  }

  return 0;
}