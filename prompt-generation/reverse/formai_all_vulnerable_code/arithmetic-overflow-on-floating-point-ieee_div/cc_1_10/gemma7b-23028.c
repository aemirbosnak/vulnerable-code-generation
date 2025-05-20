//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 20

char buffer[MAX_BUFFER_SIZE];
int buffer_position = 0;

void clear_buffer() {
  buffer_position = 0;
  buffer[0] = '\0';
}

void append_to_buffer(char character) {
  if (buffer_position >= MAX_BUFFER_SIZE - 1) {
    return;
  }

  buffer[buffer_position++] = character;
  buffer[buffer_position] = '\0';
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
        printf("Cannot divide by zero!\n");
      } else {
        printf("%f / %f = %f\n", num1, num2, num1 / num2);
      }
      break;
  }

  clear_buffer();
}

int main() {
  char input;

  clear_buffer();

  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c", &input);

  append_to_buffer(input);

  printf("Enter the first number: ");
  scanf(" %lf", &buffer[buffer_position++]);

  printf("Enter the second number: ");
  scanf(" %lf", &buffer[buffer_position++]);

  calculate();

  return 0;
}