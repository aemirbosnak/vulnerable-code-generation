//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: lively
#include <stdio.h>
#include <string.h>

#define MAX 100

void spell_checker(char **words, int word_count)
{
  int i, j, found = 0;
  char word[MAX];

  printf("Enter a word: ");
  scanf("%s", word);

  for (i = 0; i < word_count; i++)
  {
    if (strcmp(word, words[i]) == 0)
    {
      found = 1;
      break;
    }
  }

  if (found)
  {
    printf("Word found: %s\n", words[i]);
  }
  else
  {
    printf("Word not found.\n");
  }
}

int main()
{
  char **words = NULL;
  int word_count = 0;

  words = malloc(sizeof(char *) * MAX);

  words[word_count++] = "apple";
  words[word_count++] = "banana";
  words[word_count++] = "orange";
  words[word_count++] = "grapefruit";

  spell_checker(words, word_count);

  free(words);

  return 0;
}