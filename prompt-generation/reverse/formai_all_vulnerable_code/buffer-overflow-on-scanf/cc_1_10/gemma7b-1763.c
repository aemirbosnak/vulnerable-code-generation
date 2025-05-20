//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];

void clear_buffer() {
  memset(buffer, 0, MAX_BUFFER_SIZE);
}

void append_to_buffer(char character) {
  int index = 0;
  for (index = 0; buffer[index] != '\0'; index++) {}
  buffer[index] = character;
}

void calculate() {
  char operator = buffer[0];
  double num1 = atof(buffer + 1);
  double num2 = atof(buffer + 2);

  switch (operator) {
    case '+':
      printf("%f + %f = %f\n", num1, num2, num1 + num2);
      break;
    case '-':
      printf("%f - %f = %f\n", num1, num2, num1 - num2);
      break;
    case '*':
      printf("%f * %f = %f\n", num1, num2, num1 * num2);
      break;
    case '/':
      if (num2 == 0) {
        printf("Cannot divide by zero\n");
      } else {
        printf("%f / %f = %f\n", num1, num2, num1 / num2);
      }
      break;
  }

  clear_buffer();
}

int main() {
  char input;
  int state = 0;

  clear_buffer();

  while (1) {
    printf("Enter an operation (+, -, *, /, =): ");
    scanf(" %c", &input);

    switch (input) {
      case '=':
        calculate();
        break;
      case '(':
      case ')':
      case ' ':
      case '\n':
        break;
      default:
        append_to_buffer(input);
    }

    if (state == 1) {
      calculate();
    }

    if (input == '=') {
      state = 1;
    }
  }

  return 0;
}