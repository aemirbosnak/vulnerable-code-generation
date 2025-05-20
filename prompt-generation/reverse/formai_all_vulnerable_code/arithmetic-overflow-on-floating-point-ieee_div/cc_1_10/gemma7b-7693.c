//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
  char buffer[MAX_BUFFER_SIZE];
  int pos = 0;
  char operator = '\0';
  double number = 0.0;

  printf("Calculator v0.1\n");

  // Loop until the user enters an exit command
  while (strcmp(buffer, "exit") != 0)
  {
    // Get the user input
    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the user input
    pos = 0;
    operator = '\0';
    number = 0.0;
    while (buffer[pos] != '\0')
    {
      // Check if the character is a number
      if (isdigit(buffer[pos]))
      {
        // Convert the character to a number
        number = number * 10 + buffer[pos] - '0';
      }
      // Check if the character is an operator
      else if (operator == '\0')
      {
        // Store the operator
        operator = buffer[pos];
      }
      // Increment the position
      pos++;
    }

    // Calculate the result
    double result = 0.0;
    switch (operator)
    {
      case '+':
        result = number + result;
        break;
      case '-':
        result = number - result;
        break;
      case '*':
        result = number * result;
        break;
      case '/':
        if (number == 0)
        {
          printf("Error: division by zero\n");
        }
        else
        {
          result = number / result;
        }
        break;
    }

    // Print the result
    printf("Result: %.2lf\n", result);
  }

  return 0;
}