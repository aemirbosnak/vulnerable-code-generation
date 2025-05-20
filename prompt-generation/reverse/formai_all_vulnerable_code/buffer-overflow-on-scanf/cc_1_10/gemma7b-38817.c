//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
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
  if (buffer_size >= MAX_BUFFER_SIZE) {
    return;
  }

  buffer[buffer_position++] = character;
  buffer_size++;
}

void calculate() {
  char operator = buffer[0];
  double number1 = atof(buffer[1]) ;
  double number2 = atof(buffer[2]) ;

  double result = 0.0;

  switch (operator) {
    case '+':
      result = number1 + number2;
      break;
    case '-':
      result = number1 - number2;
      break;
    case '*':
      result = number1 * number2;
      break;
    case '/':
      if (number2 == 0) {
        return;
      }
      result = number1 / number2;
      break;
  }

  printf("%f\n", result);
  clear_buffer();
}

int main() {
  char input[MAX_BUFFER_SIZE];

  printf("Enter an expression: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    add_to_buffer(input[i]);
  }

  calculate();

  return 0;
}