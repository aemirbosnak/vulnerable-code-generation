//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int position;
  double result;
} Calculator;

void calculator_init(Calculator *calculator) {
  calculator->position = 0;
  calculator->result = 0.0;
}

void calculator_add(Calculator *calculator, double number) {
  calculator->result += number;
}

void calculator_subtract(Calculator *calculator, double number) {
  calculator->result -= number;
}

void calculator_multiply(Calculator *calculator, double number) {
  calculator->result *= number;
}

void calculator_divide(Calculator *calculator, double number) {
  if (number == 0) {
    printf("Error: division by zero is not allowed.\n");
    return;
  }
  calculator->result /= number;
}

void calculator_clear(Calculator *calculator) {
  calculator->position = 0;
  calculator->result = 0.0;
}

int main() {
  Calculator calculator;
  calculator_init(&calculator);

  char input[MAX_BUFFER_SIZE];
  printf("Enter an expression: ");
  fgets(input, MAX_BUFFER_SIZE, stdin);

  char *token = strtok(input, " ");

  while (token) {
    double number = atof(token);
    switch (*token) {
      case '+':
        calculator_add(&calculator, number);
        break;
      case '-':
        calculator_subtract(&calculator, number);
        break;
      case '*':
        calculator_multiply(&calculator, number);
        break;
      case '/':
        calculator_divide(&calculator, number);
        break;
      case 'C':
        calculator_clear(&calculator);
        break;
      default:
        printf("Error: invalid command.\n");
    }

    token = strtok(NULL, " ");
  }

  printf("The result is: %.2lf\n", calculator.result);

  return 0;
}