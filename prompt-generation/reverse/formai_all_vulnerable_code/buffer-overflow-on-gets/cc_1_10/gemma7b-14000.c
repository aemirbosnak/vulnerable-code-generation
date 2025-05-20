//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char str[100];
  printf("Enter a word: ");
  gets(str);

  int i = 0;
  while (str[i] != '\0')
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      str[i] = str[i] - 32;
    }
    i++;
  }

  char word[20];
  int j = 0;
  while (str[j] != '\0')
  {
    word[j] = str[j];
    j++;
  }

  FILE *fp;
  fp = fopen("dictionary.txt", "r");
  char line[100];

  int found = 0;
  while (fgets(line, 100, fp) != NULL)
  {
    if (strcmp(line, word) == 0)
    {
      found = 1;
    }
  }

  fclose(fp);

  if (found)
  {
    printf("Word found.\n");
  }
  else
  {
    printf("Word not found.\n");
  }

  return 0;
}