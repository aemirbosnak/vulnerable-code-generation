//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100
#define NUM_WORDS 10

char words[NUM_WORDS][MAX_LENGTH] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};

int main() {
  int num_correct = 0, num_incorrect = 0;
  int num_words_typed = 0;
  int num_words_correct = 0;
  int num_words_incorrect = 0;
  int time_elapsed = 0;
  int i, j;
  char input_string[MAX_LENGTH];
  char word_to_type[MAX_LENGTH];
  char *correct_word = NULL;
  char *incorrect_word = NULL;
  char *word_to_type_copy = NULL;
  int correct_word_length = 0;
  int incorrect_word_length = 0;
  int word_to_type_length = 0;
  int time_diff = 0;
  struct timespec start_time, end_time;

  srand(time(NULL));
  i = rand() % NUM_WORDS;
  correct_word = words[i];
  correct_word_length = strlen(correct_word);
  word_to_type_copy = strdup(correct_word);
  word_to_type_length = strlen(word_to_type_copy);

  for (j = 0; j < word_to_type_length; j++) {
    word_to_type[j] = '*';
  }

  printf("Welcome to the Typing Speed Test!\n");
  printf("You will be typing the word \"%s\".\n", correct_word);
  printf("Please type as many words as possible in 60 seconds.\n");
  printf("Press enter to begin.\n");
  scanf("%*c");

  gettimeofday(&start_time, NULL);

  while (time_elapsed < 60) {
    printf("\r%d seconds remaining...", 60 - time_elapsed);
    fflush(stdout);
    usleep(1000000); // 1 second
    time_elapsed++;
  }

  printf("\n\nTime's up! Here are your results:\n");
  printf("Correct words: %d\n", num_words_correct);
  printf("Incorrect words: %d\n", num_words_incorrect);
  printf("Total words typed: %d\n", num_words_typed);
  printf("Words per minute: %d\n", (num_words_typed - num_words_incorrect) / (time_elapsed / 60));

  return 0;
}