//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char str[1024];
  scanf("Enter text: ", str);

  int i = 0;
  for (; str[i] != '\0'; i++)
  {
    if (isupper(str[i]) && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U' && str[i] != 'Y')
    {
      str[i] = tolower(str[i]);
    }
  }

  char *p = str;
  while (*p)
  {
    if (ispunct(p))
    {
      *p = ' ';
    }
    p++;
  }

  char **words = NULL;
  int numWords = 0;
  char *word = strtok(str, " ");

  while (word)
  {
    words = realloc(words, (numWords + 1) * sizeof(char *));
    words[numWords++] = word;
    word = strtok(NULL, " ");
  }

  int spamScore = 0;
  for (int i = 0; i < numWords; i++)
  {
    if (strcmp(words[i], "free") == 0 || strcmp(words[i], "gratis") == 0 || strcmp(words[i], "lottery") == 0)
    {
      spamScore++;
    }
  }

  if (spamScore >= 3)
  {
    printf("Spam detected!\n");
  }
  else
  {
    printf("No spam detected.\n");
  }

  return 0;
}