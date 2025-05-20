//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

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

void calculator_add(Calculator* calc, double num) {
  sprintf(calc->buffer + calc->pos, "%f", num);
  calc->pos += strlen(calc->buffer + calc->pos) + 1;
  calc->result += num;
}

void calculator_subtract(Calculator* calc, double num) {
  sprintf(calc->buffer + calc->pos, "%f", num);
  calc->pos += strlen(calc->buffer + calc->pos) + 1;
  calc->result -= num;
}

void calculator_multiply(Calculator* calc, double num) {
  sprintf(calc->buffer + calc->pos, "%f", num);
  calc->pos += strlen(calc->buffer + calc->pos) + 1;
  calc->result *= num;
}

void calculator_divide(Calculator* calc, double num) {
  sprintf(calc->buffer + calc->pos, "%f", num);
  calc->pos += strlen(calc->buffer + calc->pos) + 1;
  if (num == 0) {
    printf("Cannot divide by 0\n");
  } else {
    calc->result /= num;
  }
}

void calculator_clear(Calculator* calc) {
  calc->pos = 0;
  calc->result = 0.0;
}

int main() {
  Calculator* calc = calculator_init();

  char input[MAX_BUFFER_SIZE];
  printf("Enter an expression: ");
  scanf("%s", input);

  char* token = strtok(input, " ");

  while (token) {
    double num = atof(token);
    switch (*token) {
      case '+':
        calculator_add(calc, num);
        break;
      case '-':
        calculator_subtract(calc, num);
        break;
      case '*':
        calculator_multiply(calc, num);
        break;
      case '/':
        calculator_divide(calc, num);
        break;
      default:
        printf("Invalid operator\n");
    }

    token = strtok(NULL, " ");
  }

  printf("Result: %f\n", calc->result);
  calculator_clear(calc);

  return 0;
}