//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int buffer_position = 0;
double result = 0.0;

void clear_buffer() {
  buffer_position = 0;
  result = 0.0;
}

void append_to_buffer(char character) {
  if (buffer_position >= MAX_BUFFER_SIZE - 1) {
    return;
  }

  buffer[buffer_position++] = character;
}

void process_buffer() {
  char operator = buffer[buffer_position - 1];
  double operand = atof(buffer);

  switch (operator) {
    case '+':
      result += operand;
      break;
    case '-':
      result -= operand;
      break;
    case '*':
      result *= operand;
      break;
    case '/':
      if (operand == 0) {
        return;
      }
      result /= operand;
      break;
  }

  clear_buffer();
}

int main() {
  char input;

  while (1) {
    printf("Enter an expression: ");
    scanf("%c", &input);

    if (input == '\n') {
      process_buffer();
      printf("The result is: %.2lf\n", result);
    } else {
      append_to_buffer(input);
    }
  }

  return 0;
}