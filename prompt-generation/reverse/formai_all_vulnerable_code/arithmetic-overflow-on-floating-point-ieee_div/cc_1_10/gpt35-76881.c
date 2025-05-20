//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  int i, j, word_count = 0, correct_words = 0;
  float total_time;
  char *words[10] = {"Hello", "world", "This", "is", "an", "example", "program", "written", "in", "C"};
  char word[10];

  // Display instructions
  printf("Welcome to the C Typing Speed Test!\n");
  printf("Type the following words as fast as you can:\n");
  for (i = 0; i < 10; i++) {
    printf("%s ", words[i]);
  }
  printf("\n");

  // Start timer
  clock_t start_time = clock();

  // Get user input
  for (i = 0; i < 10; i++) {
    scanf("%s", word);
    word_count++;

    // Check if word is correct
    for (j = 0; j < 10; j++) {
      if (word[j] != words[i][j]) {
        printf("Incorrect!\n");
        break;
      }
    }

    if (j == 10) {
      printf("Correct!\n");
      correct_words++;
    }
  }

  // End timer
  clock_t end_time = clock();
  total_time = (float)(end_time - start_time) / CLOCKS_PER_SEC;

  // Calculate words per minute
  float wpm = ((float)correct_words / total_time) * 60;

  // Display results
  printf("You typed %d words in %f seconds.\n", word_count, total_time);
  printf("Your typing speed is %.2f words per minute.\n", wpm);

  return 0;
}