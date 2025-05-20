//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int buffer_position = 0;
int number_stack[MAX_BUFFER_SIZE];
int number_stack_position = -1;

void push(int number)
{
  number_stack[++number_stack_position] = number;
}

int pop()
{
  return number_stack[number_stack_position--];
}

int main()
{
  char input[MAX_BUFFER_SIZE];
  int i = 0;
  int number = 0;

  buffer_position = 0;
  number_stack_position = -1;

  printf("Enter an expression: ");
  scanf("%s", input);

  for (i = 0; input[i] != '\0'; i++)
  {
    if (input[i] >= '0' && input[i] <= '9')
    {
      number = number * 10 + input[i] - '0';
      push(number);
    }
    else
    {
      switch (input[i])
      {
        case '+':
          push(pop() + pop());
          break;
        case '-':
          push(pop() - pop());
          break;
        case '*':
          push(pop() * pop());
          break;
        case '/':
          push(pop() / pop());
          break;
        case '=':
          printf("The result is: %d\n", pop());
          break;
      }
    }
  }

  return 0;
}