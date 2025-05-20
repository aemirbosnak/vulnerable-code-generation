//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Sherlock Holmes
/* 
  The Case of the Malicious Input
  
  By Sherlock Holmes
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

void sanitize_input(char* input);

int main()
{
  char input[MAX_INPUT_SIZE];

  printf("Hello there. Please input a string:\n");
  fgets(input, MAX_INPUT_SIZE, stdin);

  sanitize_input(input);

  printf("Your sanitized input is: %s\n", input);

  return 0;
}

void sanitize_input(char* input)
{
  int input_length = strlen(input);

  // Check for any newline characters and remove them
  if (input[input_length - 1] == '\n')
  {
    input[input_length - 1] = '\0';
    input_length--;
  }

  // Check for any semicolons and remove them
  for (int i = 0; i < input_length; i++)
  {
    if (input[i] == ';')
    {
      memmove(&input[i], &input[i + 1], input_length - i);
      input_length--;
    }
  }

  // Check for any apostrophes and remove them
  for (int i = 0; i < input_length; i++)
  {
    if (input[i] == '\'')
    {
      memmove(&input[i], &input[i + 1], input_length - i);
      input_length--;
    }
  }

  // Check for any backticks and remove them
  for (int i = 0; i < input_length; i++)
  {
    if (input[i] == '`')
    {
      memmove(&input[i], &input[i + 1], input_length - i);
      input_length--;
    }
  }

  // Check for any dollar signs and remove them
  for (int i = 0; i < input_length; i++)
  {
    if (input[i] == '$')
    {
      memmove(&input[i], &input[i + 1], input_length - i);
      input_length--;
    }
  }

  // Check for any pipes and remove them
  for (int i = 0; i < input_length; i++)
  {
    if (input[i] == '|')
    {
      memmove(&input[i], &input[i + 1], input_length - i);
      input_length--;
    }
  }

  // Check for any ampersands and remove them
  for (int i = 0; i < input_length; i++)
  {
    if (input[i] == '&')
    {
      memmove(&input[i], &input[i + 1], input_length - i);
      input_length--;
    }
  }

  // Check for any greater than symbols and remove them
  for (int i = 0; i < input_length; i++)
  {
    if (input[i] == '>')
    {
      memmove(&input[i], &input[i + 1], input_length - i);
      input_length--;
    }
  }

  // Check for any less than symbols and remove them
  for (int i = 0; i < input_length; i++)
  {
    if (input[i] == '<')
    {
      memmove(&input[i], &input[i + 1], input_length - i);
      input_length--;
    }
  }

  // Check for any parentheses and remove them
  for (int i = 0; i < input_length; i++)
  {
    if (input[i] == '(' || input[i] == ')')
    {
      memmove(&input[i], &input[i + 1], input_length - i);
      input_length--;
    }
  }

  // Check for any curly brackets and remove them
  for (int i = 0; i < input_length; i++)
  {
    if (input[i] == '{' || input[i] == '}')
    {
      memmove(&input[i], &input[i + 1], input_length - i);
      input_length--;
    }
  }

  // Check for any square brackets and remove them
  for (int i = 0; i < input_length; i++)
  {
    if (input[i] == '[' || input[i] == ']')
    {
      memmove(&input[i], &input[i + 1], input_length - i);
      input_length--;
    }
  }

  // Trim any leading or trailing whitespace
  while (isspace(input[0]))
  {
    memmove(&input[0], &input[1], input_length--);
  }
  while (input_length > 0 && isspace(input[input_length - 1]))
  {
    input_length--;
  }
  input[input_length] = '\0';
}