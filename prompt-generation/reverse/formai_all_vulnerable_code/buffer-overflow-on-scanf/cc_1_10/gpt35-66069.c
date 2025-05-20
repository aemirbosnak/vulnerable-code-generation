//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>

int main(void)
{
  // Welcome Message
  printf("Welcome to the C Cat Language Translator!\n");
  
  // Input Text
  char input[100];
  printf("Enter your text in Cat language: ");
  scanf("%[^\n]", input);
  
  // Translation
  char output[100];
  int i = 0;
  while (input[i] != '\0')
  {
    if (input[i] == 'm')
    {
      output[i] = 'r';
    }
    else if (input[i] == 'e')
    {
      output[i] = 'a';
    }
    else if (input[i] == 'o')
    {
      output[i] = 'm';
    }
    else if (input[i] == 'w')
    {
      output[i] = 'n';
    }
    else if (input[i] == 't')
    {
      output[i] = 'h';
    }
    else if (input[i] == 'a')
    {
      output[i] = 'p';
    }
    else // if not a valid character, use original character
    {
      output[i] = input[i];
    }
    
    i++;
  }
  output[i] = '\0'; // add null terminator to output string
  
  // Output Translation
  printf("In regular language, it is: %s\n", output);
  
  return 0;
}