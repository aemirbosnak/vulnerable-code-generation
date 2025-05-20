//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

typedef struct Calculator {
  int num1;
  int num2;
  char operator;
} Calculator;

void calculate(Calculator *calc) {
  switch (calc->operator) {
    case '+':
      calc->num1 += calc->num2;
      break;
    case '-':
      calc->num1 -= calc->num2;
      break;
    case '*':
      calc->num1 *= calc->num2;
      break;
    case '/':
      if (calc->num2 == 0) {
        printf("Error: Divide by zero is not allowed.\n");
        return;
      }
      calc->num1 /= calc->num2;
      break;
  }
  printf("The result is: %d\n", calc->num1);
}

int main() {
  Calculator calc;
  calc.num1 = 0;
  calc.num2 = 0;
  calc.operator = '\0';

  printf("Welcome to the Grand Calculator of Old!\n");
  printf("Please enter an operator (+, -, *, /): ");
  scanf("%c", &calc.operator);

  printf("Please enter two numbers: ");
  scanf("%d %d", &calc.num1, &calc.num2);

  calculate(&calc);

  return 0;
}