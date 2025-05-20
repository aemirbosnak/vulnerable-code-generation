//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: retro
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct Word {
  char word[20];
  int score;
} Word;

Word words[MAX_WORDS] = {
  {"Apple", 0},
  {"Banana", 0},
  {"Orange", 0},
  {"Strawberry", 0},
  {"Mango", 0},
  {"Peach", 0},
  {"Grapes", 0},
  {"Pear", 0},
  {"Watermelon", 0},
  {"Pineapple", 0}
};

int main() {
  int i, j, time_start, time_end, total_time = 0, score = 0;
  char input[20];

  // Seed the random number generator
  srand(time(NULL));

  // Start the timer
  time_start = clock();

  // Display the words
  for (i = 0; i < MAX_WORDS; i++) {
    printf("%s ", words[i].word);
  }

  // Get the user's input
  printf("\nEnter a word: ");
  scanf("%s", input);

  // Check if the user's input is correct
  for (j = 0; j < MAX_WORDS; j++) {
    if (strcmp(input, words[j].word) == 0) {
      // Award points
      words[j].score++;
      score++;
    }
  }

  // End the timer
  time_end = clock();

  // Calculate the total time
  total_time = time_end - time_start;

  // Display the results
  printf("\nYour score: %d", score);
  printf("\nTotal time: %d seconds", total_time);

  return 0;
}