//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <time.h>

/* This program will test your typing speed by prompting you to type a sentence 
   and then measuring how long it takes you to type it within a given time limit */

int main() {
  char sentence[] = "The quick brown fox jumps over the lazy dog.";
  clock_t start_time, end_time;
  double time_elapsed;
  int max_time = 10; // Change this value to set the time limit in seconds.
  int typed_chars = 0;
  char c;

  printf("Type this sentence within %d seconds:\n\n", max_time);
  printf("%s\n\n", sentence);

  start_time = clock();

  while ((time_elapsed = ((double)(clock() - start_time)) / CLOCKS_PER_SEC) < max_time) {
    c = getchar();

    if (c == EOF) {
      printf("\n\nYou have terminated the program early.\n");
      return 0;
    }

    putchar(c);
    typed_chars++;

    if (typed_chars == sizeof(sentence) - 1) {
      // Check if the user has typed the entire sentence correctly.
      int i;

      for (i = 0; i < sizeof(sentence) - 1; i++) {
        if (sentence[i] != getchar()) {
          printf("\n\nYou made a mistake. Please try again.\n");
          return 0;
        }
      }

      end_time = clock();
      time_elapsed = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
      printf("\n\nCongratulations! You typed the sentence correctly in %.2f seconds.\n", time_elapsed);
      return 0;
    }
  }

  printf("\n\n\nTime limit exceeded. Please try again.\n");
  return 0;
}