//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY 10

typedef struct CalculatorHistory {
  char operator;
  double operand;
  struct CalculatorHistory* next;
} CalculatorHistory;

CalculatorHistory* createHistory(char operator, double operand) {
  CalculatorHistory* history = (CalculatorHistory*)malloc(sizeof(CalculatorHistory));
  history->operator = operator;
  history->operand = operand;
  history->next = NULL;
  return history;
}

void addToHistory(CalculatorHistory** history, char operator, double operand) {
  CalculatorHistory* newHistory = createHistory(operator, operand);
  if (*history) {
    (*history)->next = newHistory;
  } else {
    *history = newHistory;
  }
}

double calculate(double num1, double num2, char operator) {
  switch (operator) {
    case '+':
      return num1 + num2;
    case '-':
      return num1 - num2;
    case '*':
      return num1 * num2;
    case '/':
      if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return -1;
      }
      return num1 / num2;
    default:
      printf("Error: Invalid operator.\n");
      return -1;
  }
}

int main() {
  double num1, num2;
  char operator;
  CalculatorHistory* history = NULL;

  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &operator);

  printf("Enter the first number: ");
  scanf("%lf", &num1);

  printf("Enter the second number: ");
  scanf("%lf", &num2);

  double result = calculate(num1, num2, operator);

  if (result != -1) {
    addToHistory(&history, operator, result);
    printf("The result is: %.2lf\n", result);
  }

  return 0;
}