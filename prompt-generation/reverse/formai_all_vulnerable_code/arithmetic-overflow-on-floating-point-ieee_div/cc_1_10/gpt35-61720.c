//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main()
{
  char sentence[] = "The quick brown fox jumps over the lazy dog";
  int len = strlen(sentence);
  int errors = 0;
  int i = 0;
  int correct = 0;
  time_t start_time, end_time;
  double elapsed_time;

  printf("Type the following sentence:\n%s\n", sentence);
  printf("Press Enter when done:\n");

  time(&start_time);

  while (i < len)
  {
    char c = getchar();

    if (c == '\n')
    {
      break;
    }

    if (isalpha(c))
    {
      if (c == sentence[i])
      {
        i++;
        correct++;
      }
      else
      {
        errors++;
      }
    }
  }

  time(&end_time);

  elapsed_time = difftime(end_time, start_time);
  
  printf("\nYou typed %d correct characters out of %d\n", correct, len);
  printf("You made %d errors\n", errors);
  printf("Your total time: %.2f seconds\n", elapsed_time);
  printf("Your typing speed: %.2f characters per minute\n", correct / (elapsed_time / 60));

  return 0;
}