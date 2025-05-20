//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int pos;
  double result;
} Calculator;

Calculator calculator = {
  .buffer = "",
  .pos = 0,
  .result = 0
};

void calculate(char operator, double num) {
  switch (operator) {
    case '+':
      calculator.result += num;
      break;
    case '-':
      calculator.result -= num;
      break;
    case '*':
      calculator.result *= num;
      break;
    case '/':
      if (num == 0) {
        printf("Cannot divide by zero\n");
        return;
      }
      calculator.result /= num;
      break;
    case '^':
      calculator.result = pow(calculator.result, num);
      break;
    default:
      printf("Invalid operator\n");
      return;
  }

  calculator.buffer[calculator.pos++] = operator;
  calculator.buffer[calculator.pos++] = num;
  calculator.buffer[calculator.pos++] = '=';
  calculator.buffer[calculator.pos] = '\0';
}

int main() {
  char input[MAX_BUFFER_SIZE];

  printf("Enter an expression: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    char operator = input[i];
    double num = atof(input + i + 1);

    calculate(operator, num);
  }

  printf("Result: %s\n", calculator.buffer);
  printf("Result: %.2lf\n", calculator.result);

  return 0;
}