//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int buffer_position = 0;
double result = 0.0;

void clear_buffer() {
  buffer_position = 0;
  result = 0.0;
}

void add_number(double number) {
  if (buffer_position >= MAX_BUFFER_SIZE - 1) {
    return;
  }

  buffer[buffer_position++] = number;
  result += number;
}

void add_operator(char operator) {
  if (buffer_position >= MAX_BUFFER_SIZE - 1) {
    return;
  }

  buffer[buffer_position++] = operator;
}

void calculate() {
  double operand1 = buffer[0] - '0';
  double operand2 = buffer[1] - '0';

  switch (buffer[2]) {
    case '+':
      result = operand1 + operand2;
      break;
    case '-':
      result = operand1 - operand2;
      break;
    case '*':
      result = operand1 * operand2;
      break;
    case '/':
      if (operand2 == 0) {
        return;
      }
      result = operand1 / operand2;
      break;
  }

  clear_buffer();
  add_number(result);
}

int main() {
  char input[MAX_BUFFER_SIZE];

  printf("Enter an expression: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    switch (input[i]) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '.':
        add_number(input[i] - '0');
        break;
      case '+':
      case '-':
      case '*':
      case '/':
        add_operator(input[i]);
        break;
      case '=':
        calculate();
        break;
    }
  }

  printf("The result is: %.2lf\n", result);

  return 0;
}