//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
  char str[MAX];
  int i, sentiment = 0, pos = 0, neg = 0;
  FILE *fp;

  fp = fopen("sentiment.txt", "r");
  if (fp == NULL)
  {
    printf("Error opening file.\n");
    exit(1);
  }

  printf("Enter a sentence: ");
  scanf("%s", str);

  for (i = 0; str[i] != '\0'; i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      sentiment++;
    }
    else if (str[i] >= 'A' && str[i] <= 'Z')
    {
      sentiment++;
    }
    else if (str[i] == '"')
    {
      pos++;
    }
    else if (str[i] == '-')
    {
      neg++;
    }
  }

  fclose(fp);

  if (sentiment > pos)
  {
    printf("The sentiment of the sentence is positive.\n");
  }
  else if (sentiment < pos)
  {
    printf("The sentiment of the sentence is negative.\n");
  }
  else
  {
    printf("The sentiment of the sentence is neutral.\n");
  }

  return 0;
}