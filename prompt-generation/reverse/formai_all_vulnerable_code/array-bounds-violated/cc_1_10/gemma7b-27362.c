//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int buffer_position = 0;
char operator_stack[MAX_BUFFER_SIZE];
int operator_stack_position = -1;

void clear_buffer() {
  buffer_position = 0;
  memset(buffer, '\0', MAX_BUFFER_SIZE);
}

void add_to_buffer(char character) {
  if (buffer_position >= MAX_BUFFER_SIZE - 1) {
    return;
  }

  buffer[buffer_position++] = character;
}

void add_operator_to_stack(char operator) {
  if (operator_stack_position >= MAX_BUFFER_SIZE - 1) {
    return;
  }

  operator_stack[++operator_stack_position] = operator;
}

double calculate_result() {
  double result = 0.0;
  char operator = operator_stack[operator_stack_position];

  switch (operator) {
    case '+':
      result = atof(buffer) + calculate_result();
      break;
    case '-':
      result = atof(buffer) - calculate_result();
      break;
    case '*':
      result = atof(buffer) * calculate_result();
      break;
    case '/':
      result = atof(buffer) / calculate_result();
      break;
  }

  return result;
}

int main() {
  clear_buffer();
  add_to_buffer('5');
  add_to_buffer('2');
  add_to_buffer('+');
  add_to_buffer('3');
  add_to_buffer('-');
  add_to_buffer('4');
  add_to_buffer('=');

  double result = calculate_result();

  printf("The result is: %.2lf\n", result);

  return 0;
}