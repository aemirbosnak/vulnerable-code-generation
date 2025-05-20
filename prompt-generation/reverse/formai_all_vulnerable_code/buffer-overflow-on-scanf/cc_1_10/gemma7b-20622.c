//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int top = -1;

void push(char data)
{
  if (top == MAX_BUFFER_SIZE - 1)
  {
    printf("Stack Overflow!\n");
    exit(1);
  }
  buffer[++top] = data;
}

char pop()
{
  if (top == -1)
  {
    printf("Stack Underflow!\n");
    exit(1);
  }
  return buffer[top--];
}

int evaluate_expression(char *expr)
{
  int i = 0;
  char operator;
  int operand1, operand2;

  if (*expr == '\0')
  {
    return 0;
  }

  push(*expr);

  for (i = 1; expr[i] != '\0'; i++)
  {
    operator = expr[i];
    operand1 = pop();
    operand2 = pop();

    switch (operator)
    {
      case '+':
        push(operand1 + operand2);
        break;
      case '-':
        push(operand1 - operand2);
        break;
      case '*':
        push(operand1 * operand2);
        break;
      case '/':
        if (operand2 == 0)
        {
          printf("Division by zero is undefined.\n");
          exit(1);
        }
        push(operand1 / operand2);
        break;
    }
  }

  return pop();
}

int main()
{
  char expr[MAX_BUFFER_SIZE];

  printf("Enter an expression: ");
  scanf("%s", expr);

  int result = evaluate_expression(expr);

  printf("The result is: %d\n", result);

  return 0;
}