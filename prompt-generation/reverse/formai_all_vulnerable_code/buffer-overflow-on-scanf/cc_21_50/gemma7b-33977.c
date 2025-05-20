//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: mind-bending
#include <stdio.h>
#include <string.h>

#define PURR_SOUND "Meow!"
#define SNuggle_SOUND "Snuggle!"

int main()
{
  char input[100];
  int i, j, k;

  printf("Welcome to the C Cat Language Translator!\n");
  printf("Please enter a sentence: ");

  scanf("%s", input);

  for (i = 0; input[i] != '\0'; i++)
  {
    switch (input[i])
    {
      case 'a':
      case 'A':
        input[i] = 'a';
        break;
      case 'e':
      case 'E':
        input[i] = 'e';
        break;
      case 'i':
      case 'I':
        input[i] = 'i';
        break;
      case 'o':
      case 'O':
        input[i] = 'o';
        break;
      case 'u':
      case 'U':
        input[i] = 'u';
        break;
      default:
        input[i] = 'a';
    }
  }

  printf("Your translated sentence: ");

  for (j = 0; input[j] != '\0'; j++)
  {
    switch (input[j])
    {
      case 'a':
      case 'A':
        printf("Meow ");
        break;
      case 'e':
      case 'E':
        printf("Meow ");
        break;
      case 'i':
      case 'I':
        printf("Purr ");
        break;
      case 'o':
      case 'O':
        printf("Snuggle ");
        break;
      case 'u':
      case 'U':
        printf("Meow ");
        break;
      default:
        printf("%c ", input[j]);
    }
  }

  printf("\n");

  return 0;
}