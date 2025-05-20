//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main()
{
  char input[100], output[100];
  int i, j, len;

  printf("Enter your Cat Language text: ");
  scanf("%[^\n]", input);

  len = strlen(input);

  for(i=0, j=0; i<len; i++, j++)
  {
    switch(input[i])
    {
      case 'c':
        output[j] = 'm';
        j++;
        output[j] = 'e';
        break;
      case 'a':
        output[j] = 'o';
        j++;
        output[j] = 'h';
        j++;
        output[j] = 'o';
        j++;
        output[j] = 'h';
        break;
      case 't':
        output[j] = 'w';
        j++;
        output[j] = 'o';
        j++;
        output[j] = 'o';
        j++;
        output[j] = 'f';
        break;
      default:
        output[j] = input[i];
    }
  }

  output[j] = '\0';

  printf("Translated text: %s", output);

  return 0;
}