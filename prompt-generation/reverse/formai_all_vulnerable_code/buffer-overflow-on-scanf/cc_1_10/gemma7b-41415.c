//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int buffer_position = 0;

void add_to_buffer(char character)
{
  if (buffer_position >= MAX_BUFFER_SIZE - 1)
  {
    return;
  }

  buffer[buffer_position++] = character;
}

char read_from_buffer()
{
  if (buffer_position == 0)
  {
    return '\0';
  }

  return buffer[buffer_position - 1];
}

int main()
{
  char input_character;
  char operator;
  double number1;
  double number2;
  double result;

  printf("Enter an operator (+, -, *, /, %): ");
  operator = read_from_buffer();

  printf("Enter the first number: ");
  scanf("%lf", &number1);

  printf("Enter the second number: ");
  scanf("%lf", &number2);

  switch (operator)
  {
    case '+':
      result = number1 + number2;
      break;
    case '-':
      result = number1 - number2;
      break;
    case '*':
      result = number1 * number2;
      break;
    case '/':
      if (number2 == 0)
      {
        printf("Cannot divide by zero\n");
        return 1;
      }
      result = number1 / number2;
      break;
    default:
      printf("Invalid operator\n");
      return 1;
  }

  printf("The result is: %.2lf\n", result);

  return 0;
}