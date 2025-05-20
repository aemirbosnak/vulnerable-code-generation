//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: relaxed
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

void add_to_buffer(char character) {
  if (buffer_position >= MAX_BUFFER_SIZE - 1) {
    return;
  }

  buffer[buffer_position++] = character;
}

void calculate_result() {
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
      result /= operand;
      break;
  }

  clear_buffer();
}

int main() {
  char input;

  printf("Enter an expression: ");

  // Loop until the user enters an EOF character
  while ((input = getchar()) != EOF) {
    // Check if the input is a number or an operator
    if (input >= '0' && input <= '9') {
      add_to_buffer(input);
    } else if (input == '+' || input == '-' || input == '*' || input == '/') {
      calculate_result();
      add_to_buffer(input);
    } else if (input == '=') {
      calculate_result();
      printf("The result is: %.2lf\n", result);
      clear_buffer();
    }
  }

  return 0;
}