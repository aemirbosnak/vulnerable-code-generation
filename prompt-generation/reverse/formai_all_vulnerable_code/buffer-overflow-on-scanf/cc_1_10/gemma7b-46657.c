//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int buffer_position = 0;

void append_to_buffer(char character)
{
  if (buffer_position >= MAX_BUFFER_SIZE - 1)
  {
    return;
  }

  buffer[buffer_position++] = character;
}

void clear_buffer()
{
  buffer_position = 0;
}

int main()
{
  char operator;
  char number1;
  char number2;

  printf("Enter an operator (+, -, *, /, %): ");
  scanf("%c", &operator);

  printf("Enter the first number: ");
  scanf("%c", &number1);

  printf("Enter the second number: ");
  scanf("%c", &number2);

  append_to_buffer(number1);
  append_to_buffer(operator);
  append_to_buffer(number2);

  switch (operator)
  {
    case '+':
      printf("The result is: %c\n", (number1 - number2) + number2);
      break;
    case '-':
      printf("The result is: %c\n", number1 - number2);
      break;
    case '*':
      printf("The result is: %c\n", number1 * number2);
      break;
    case '/':
      if (number2 == 0)
      {
        printf("Cannot divide by zero!\n");
      }
      else
      {
        printf("The result is: %c\n", number1 / number2);
      }
      break;
    default:
      printf("Invalid operator.\n");
  }

  clear_buffer();

  return 0;
}