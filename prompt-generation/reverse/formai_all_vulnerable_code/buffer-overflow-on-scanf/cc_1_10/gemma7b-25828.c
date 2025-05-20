//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5
#define WORDS_PER_CATEGORY 3

int main() {
  char category[20];
  char word[20];
  int guesses = 0;
  int win = 0;
  int category_num = 0;

  // Seed the random number generator
  srand(time(NULL));

  // Choose a random category
  category_num = rand() % 3;

  // Get the category name
  switch (category_num) {
    case 0:
      strcpy(category, "Fruits");
      break;
    case 1:
      strcpy(category, "Vegetables");
      break;
    case 2:
      strcpy(category, "Animals");
      break;
  }

  // Get the word
  strcpy(word, "apple");

  // Start the game
  while (!win && guesses < MAX_GUESSES) {
    // Get the user's guess
    char guess[20];
    printf("Guess a word in the category of '%s': ", category);
    scanf("%s", guess);

    // Check if the guess is correct
    if (strcmp(guess, word) == 0) {
      win = 1;
    } else {
      guesses++;
    }

    // Print the remaining guesses
    printf("Guesses remaining: %d\n", MAX_GUESSES - guesses);
  }

  // End the game
  if (win) {
    printf("Congratulations! You won!\n");
  } else {
    printf("Sorry, you lost.\n");
  }

  return 0;
}