//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: multiplayer
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

void main() {
  int i, j, score = 0, words_completed = 0;
  char word[MAX_WORDS][20] = {
    "Apple",
    "Banana",
    "Orange",
    "Strawberry",
    "Peach",
    "Mango",
    "Grapes",
    "Pineapple",
    "Watermelon",
    "Apricot"
  };

  printf("Welcome to the Fruit Typing Speed Test!\n");
  printf("------------------------\n");

  // Start timer
  clock_t start_time = clock();

  // Get the user's input
  char input[20];

  // Loop over the words
  for (i = 0; i < MAX_WORDS; i++) {
    printf("Type the next word: ");

    // Get the user's input
    gets(input);

    // Check if the user's input matches the word
    if (strcmp(input, word[i]) == 0) {
      // Increment the user's score
      score++;

      // Increment the number of words completed
      words_completed++;
    }
  }

  // Stop timer
  clock_t end_time = clock();

  // Calculate the time taken
  int time_taken = (end_time - start_time) / CLOCKS_PER_SEC;

  // Display the results
  printf("\nYour score: %d", score);
  printf("\nWords completed: %d", words_completed);
  printf("\nTime taken: %d seconds", time_taken);

  // Calculate the user's speed
  int speed = (words_completed * 60) / time_taken;

  // Display the user's speed
  printf("\nYour speed: %d words per minute", speed);

  printf("\nThank you for playing the Fruit Typing Speed Test!");
  printf("\n");
}