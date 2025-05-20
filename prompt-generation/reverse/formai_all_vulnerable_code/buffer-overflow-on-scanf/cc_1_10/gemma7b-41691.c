//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 20

char buffer[MAX_BUFFER_SIZE];
int buffer_position = 0;
double result = 0.0;

void add_number(double number)
{
  if (buffer_position >= MAX_BUFFER_SIZE - 1)
  {
    return;
  }

  buffer[buffer_position++] = number;
  result += number;
}

void add_operator(char operator)
{
  if (buffer_position >= MAX_BUFFER_SIZE - 1)
  {
    return;
  }

  buffer[buffer_position++] = operator;
  switch (operator)
  {
    case '+':
      result = 0.0;
      break;
    case '-':
      result = -result;
      break;
    case '*':
      result = result * result;
      break;
    case '/':
      if (result == 0.0)
      {
        return;
      }
      result = result / result;
      break;
  }
}

void clear_buffer()
{
  buffer_position = 0;
  result = 0.0;
}

int main()
{
  char input;
  double number;

  printf("Welcome to the retro scientific calculator!\n");

  while (1)
  {
    printf("Enter an operator (+, -, *, /, C) or number: ");
    scanf("%c", &input);

    switch (input)
    {
      case 'C':
        clear_buffer();
        break;
      case '+':
      case '-':
      case '*':
      case '/':
        number = atof(buffer);
        add_operator(input);
        add_number(number);
        break;
      default:
        printf("Invalid input.\n");
    }

    if (buffer_position > 0)
    {
      printf("Current buffer: ");
      for (int i = 0; i < buffer_position; i++)
      {
        printf("%c ", buffer[i]);
      }

      printf(" = %.2lf\n", result);
    }
  }

  return 0;
}