//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char data)
{
  if (top >= MAX - 1)
  {
    printf("Stack Overflow\n");
    exit(1);
  }
  stack[++top] = data;
}

char pop()
{
  if (top < 0)
  {
    printf("Stack Underflow\n");
    exit(1);
  }
  return stack[top--];
}

int main()
{
  char input[MAX], operator, result[MAX];
  int i = 0, num1, num2;

  printf("Enter an expression: ");
  scanf("%s", input);

  for (i = 0; input[i] != '\0'; i++)
  {
    if (input[i] >= 'a' && input[i] <= 'z')
    {
      push(input[i]);
    }
    else if (input[i] >= '0' && input[i] <= '9')
    {
      num1 = input[i] - '0';
      num2 = pop() - '0';
      result[i] = (num1 + num2) % 10 + '0';
      push(result[i]);
    }
  }

  printf("The result is: ");
  printf("%s\n", result);

  return 0;
}