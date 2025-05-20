//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

void word_frequency(char **arr, int n)
{
  int i, j, count = 0, **word_freq = NULL;

  word_freq = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
  {
    word_freq[i] = (int *)malloc(MAX * sizeof(int));
    for (j = 0; j < MAX; j++)
      word_freq[i][j] = 0;
  }

  for (i = 0; i < n; i++)
  {
    char *word = arr[i];
    int len = strlen(word);
    for (j = 0; j < len; j++)
    {
      word_freq[i][word[j]]++;
    }
  }

  for (i = 0; i < n; i++)
  {
    printf("%s: ", arr[i]);
    for (j = 0; j < MAX; j++)
    {
      if (word_freq[i][j] > 0)
        printf("%c: %d, ", j, word_freq[i][j]);
    }
    printf("\n");
  }

  free(word_freq);
}

int main()
{
  char **arr = NULL;
  int n = 0;

  printf("Enter the number of sentences: ");
  scanf("%d", &n);

  arr = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++)
  {
    arr[i] = (char *)malloc(MAX * sizeof(char));
  }

  printf("Enter the sentences: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%[^\n]%*c", arr[i]);
  }

  word_frequency(arr, n);

  free(arr);

  return 0;
}