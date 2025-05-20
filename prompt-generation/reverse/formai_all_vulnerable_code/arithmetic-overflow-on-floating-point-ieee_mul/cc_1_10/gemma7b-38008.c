//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 255

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int pos;
  double result;
} Calculator;

Calculator* calculator_init() {
  Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
  calc->pos = 0;
  calc->result = 0.0;
  return calc;
}

void calculator_clear(Calculator* calc) {
  calc->pos = 0;
  calc->result = 0.0;
}

void calculator_add(Calculator* calc, double num) {
  calc->buffer[calc->pos++] = num;
  calc->result += num;
}

void calculator_subtract(Calculator* calc, double num) {
  calc->buffer[calc->pos++] = num;
  calc->result -= num;
}

void calculator_multiply(Calculator* calc, double num) {
  calc->buffer[calc->pos++] = num;
  calc->result *= num;
}

void calculator_divide(Calculator* calc, double num) {
  if (num == 0) {
    printf("Error: division by zero is not allowed.\n");
    return;
  }
  calc->buffer[calc->pos++] = num;
  calc->result /= num;
}

void calculator_equals(Calculator* calc) {
  double total = 0.0;
  for (int i = 0; i < calc->pos; i++) {
    total += (double)calc->buffer[i] * pow(10, calc->pos - i - 1);
  }
  calc->result = total;
}

int main() {
  Calculator* calc = calculator_init();

  // Perform calculator operations
  calculator_add(calc, 10.0);
  calculator_multiply(calc, 2.0);
  calculator_subtract(calc, 5.0);
  calculator_divide(calc, 4.0);
  calculator_equals(calc);

  // Display the result
  printf("The result is: %.2lf\n", calc->result);

  // Clear the calculator
  calculator_clear(calc);

  return 0;
}