//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
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

  while (1) {
    printf("\nEnter an expression:");
    scanf("%c", &input);

    switch (input) {
      case '\n':
        calculate_result();
        printf("Result: %.2lf\n", result);
        break;
      case '.':
        add_to_buffer(input);
        break;
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
        add_to_buffer(input);
        break;
      case '=':
        calculate_result();
        break;
      case 'C':
        clear_buffer();
        break;
    }
  }

  return 0;
}