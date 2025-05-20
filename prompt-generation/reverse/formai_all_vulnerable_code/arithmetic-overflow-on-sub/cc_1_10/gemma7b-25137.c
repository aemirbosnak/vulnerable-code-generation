//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

int main()
{
  char words[MAX_WORDS][20] = {
    "The quick brown fox jumps over the lazy dog.",
    "A wise old owl sits on a tree.",
    "The cat sat on the mat.",
    "The red rose blooms bright.",
    "The green grass grows tall.",
    "The blue sky is clear.",
    "A merry little lamb hops high.",
    "The clock strikes twelve.",
    "The clock strikes one.",
    "The clock strikes two."
  };

  int i, j, k, time_taken = 0, total_words = 0;
  time_t start_time, end_time;

  printf("Please start reading the text below as quickly as possible:\n");
  for (i = 0; i < MAX_WORDS; i++)
  {
    printf("%s\n", words[i]);
  }

  start_time = time(NULL);
  scanf("Press any key when you have finished reading:");
  end_time = time(NULL);

  time_taken = end_time - start_time;
  total_words = 0;

  for (j = 0; j < MAX_WORDS; j++)
  {
    for (k = 0; words[j][k] != '\0'; k++)
    {
      if (words[j][k] != ' ')
      {
        total_words++;
      }
    }
  }

  printf("Your reading speed is: %.2f words per second.\n", (double)total_words / time_taken);
  printf("Total number of words read: %d\n", total_words);

  return 0;
}