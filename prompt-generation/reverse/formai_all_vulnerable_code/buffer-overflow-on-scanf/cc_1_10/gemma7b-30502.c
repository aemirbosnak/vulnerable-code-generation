//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

void spell_checker(char **word_list, int word_list_size)
{
  char word[MAX_WORD_LENGTH];
  int i, j, word_found = 0;

  printf("Enter a word: ");
  scanf("%s", word);

  for (i = 0; i < word_list_size; i++)
  {
    for (j = 0; j < MAX_WORD_LENGTH; j++)
    {
      if (strcmp(word, word_list[i]) == 0)
      {
        word_found = 1;
        break;
      }
    }
  }

  if (word_found)
  {
    printf("Word found.\n");
  }
  else
  {
    printf("Word not found.\n");
  }
}

int main()
{
  char **word_list = NULL;
  int word_list_size = 0;

  word_list = malloc(sizeof(char *) * word_list_size);

  word_list_size++;
  word_list[0] = "apple";

  word_list_size++;
  word_list[1] = "banana";

  word_list_size++;
  word_list[2] = "orange";

  spell_checker(word_list, word_list_size);

  free(word_list);

  return 0;
}