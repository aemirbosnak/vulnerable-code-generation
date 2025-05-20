//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

int main()
{

  char buf[1000];
  FILE *fp;
  fp = fopen("spam.txt", "r");
  fscanf(fp, "%s", buf);
  fclose(fp);

  int spam_score = calculate_spam_score(buf);

  if (spam_score > 50)
  {
    printf("Spam alert! Score: %d\n", spam_score);
  }
  else
  {
    printf("No spam detected. Score: %d\n", spam_score);
  }

  return 0;
}

int calculate_spam_score(char *buf)
{
  int score = 0;

  // Check for common spam words
  char *spam_words[] = {"free", "lottery", "miracle", "prize"};
  for (int i = 0; i < 4; i++)
  {
    if (strstr(buf, spam_words[i]) != NULL)
    {
      score++;
    }
  }

  // Check for exclamation marks
  if (strstr(buf, "!!!"))
  {
    score++;
  }

  // Check for repetitive words
  char *repeat_words[] = {"the", "a", "of", "to"};
  for (int i = 0; i < 4; i++)
  {
    if (strstr(buf, repeat_words[i]) != NULL)
    {
      score++;
    }
  }

  // Check for unusual character combinations
  if (strstr(buf, "$%^&*") != NULL)
  {
    score++;
  }

  return score;
}