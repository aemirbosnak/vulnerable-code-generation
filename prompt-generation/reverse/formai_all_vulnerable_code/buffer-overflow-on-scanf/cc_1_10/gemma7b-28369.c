//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];

void clear_buffer()
{
  buffer[0] = '\0';
}

void append_to_buffer(char character)
{
  int i = 0;
  for (; buffer[i] != '\0'; i++)
  {
    ;
  }
  buffer[i] = character;
  buffer[i + 1] = '\0';
}

int main()
{
  char operator;
  char number1[11];
  char number2[11];

  clear_buffer();

  // Get the first number
  printf("Enter the first number: ");
  scanf("%s", number1);

  // Get the operator
  printf("Enter the operator (+, -, *, /): ");
  scanf(" %c", &operator);

  // Get the second number
  printf("Enter the second number: ");
  scanf("%s", number2);

  // Calculate the result
  int result = 0;
  switch (operator)
  {
    case '+':
      result = atoi(number1) + atoi(number2);
      break;
    case '-':
      result = atoi(number1) - atoi(number2);
      break;
    case '*':
      result = atoi(number1) * atoi(number2);
      break;
    case '/':
      result = atoi(number1) / atoi(number2);
      break;
  }

  // Display the result
  printf("The result is: %d\n", result);

  return 0;
}