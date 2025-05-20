//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int index;
  double result;
} Calculator;

void calculator_init(Calculator *calc) {
  calc->index = 0;
  calc->result = 0.0;
  memset(calc->buffer, 0, MAX_BUFFER_SIZE);
}

void calculator_add(Calculator *calc, double num) {
  calc->buffer[calc->index++] = '+';
  calc->buffer[calc->index++] = num + '0' - 0.0;
  calc->result += num;
}

void calculator_sub(Calculator *calc, double num) {
  calc->buffer[calc->index++] = '-';
  calc->buffer[calc->index++] = num + '0' - 0.0;
  calc->result -= num;
}

void calculator_mul(Calculator *calc, double num) {
  calc->buffer[calc->index++] = '*';
  calc->buffer[calc->index++] = num + '0' - 0.0;
  calc->result *= num;
}

void calculator_div(Calculator *calc, double num) {
  calc->buffer[calc->index++] = '/';
  calc->buffer[calc->index++] = num + '0' - 0.0;
  calc->result /= num;
}

void calculator_equal(Calculator *calc) {
  calc->buffer[calc->index] = '=';
  calc->buffer[calc->index + 1] = '\0';
  printf("%s = %.2lf\n", calc->buffer, calc->result);
}

int main() {
  Calculator calc;
  calculator_init(&calc);

  char input[MAX_BUFFER_SIZE];
  printf("Enter an expression: ");
  scanf("%s", input);

  double num;
  char operator;

  for (int i = 0; input[i] != '\0'; i++) {
    switch (input[i]) {
      case '+':
        operator = '+';
        num = atof(input + i + 1);
        calculator_add(&calc, num);
        break;
      case '-':
        operator = '-';
        num = atof(input + i + 1);
        calculator_sub(&calc, num);
        break;
      case '*':
        operator = '*';
        num = atof(input + i + 1);
        calculator_mul(&calc, num);
        break;
      case '/':
        operator = '/';
        num = atof(input + i + 1);
        calculator_div(&calc, num);
        break;
      case '=':
        calculator_equal(&calc);
        break;
    }
  }

  return 0;
}