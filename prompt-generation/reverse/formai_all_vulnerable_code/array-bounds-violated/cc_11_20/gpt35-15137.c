//FormAI DATASET v1.0 Category: Spell checking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char input[1000];
  char dictionary[5000][50];
  int dictionary_size = 0, error_count = 0;

  printf("Welcome to the Medieval Spell Checker!\n\n");

  FILE *f;
  f = fopen("dictionary.txt", "r");
  if (f == NULL)
  {
    printf("Error reading dictionary file.\n");
    return 1;
  }

  while (fgets(dictionary[dictionary_size], 50, f) != NULL)
  {
    dictionary[dictionary_size][strlen(dictionary[dictionary_size]) - 1] = '\0';
    dictionary_size++;
  }
  fclose(f);

  printf("Please enter your text: \n");
  fgets(input, 1000, stdin);
  input[strlen(input) - 1] = '\0';

  char *token = strtok(input, " ,.?!");

  while (token != NULL)
  {
    int flag = 0;
    for (int i = 0; i < dictionary_size; i++)
    {
      if (strcmp(token, dictionary[i]) == 0)
      {
        flag = 1;
        break;
      }
    }
    if (!flag)
    {
      error_count++;
      printf("%s is misspelled. Did you mean ", token);
      for (int i = 0; i < dictionary_size; i++)
      {
        if (strlen(token) == strlen(dictionary[i]))
        {
          int count = 0;
          for (int j = 0; j < strlen(token); j++)
            if (token[j] != dictionary[i][j])
              count++;
          if (count <= 1)
            printf("%s?", dictionary[i]);
        }
      }
      printf("\n");
    }
    token = strtok(NULL, " ,.?!");
  }

  if (error_count)
    printf("\n%d error(s) found, please check your spelling.\n", error_count);
  else
    printf("\nCongrats! No spelling errors found.\n");

  return 0;
}