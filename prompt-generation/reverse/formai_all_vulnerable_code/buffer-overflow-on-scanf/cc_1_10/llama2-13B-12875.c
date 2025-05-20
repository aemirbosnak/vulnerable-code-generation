//LLAMA2-13B DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESS 100
#define MAX_WORD_LENGTH 20

// Declare a function to generate a random word
void generate_word(char *word) {
  int i, j;
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    word[i] = 'a' + (rand() % 26);
  }
}

// Declare a function to check if a guess is correct
int check_guess(char *word, char guess) {
  int i;
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    if (word[i] != guess) {
      return 0;
    }
  }
  return 1;
}

int main() {
  // Declare a word to guess
  char word[MAX_WORD_LENGTH];
  generate_word(word);

  // Declare a guess
  char guess;

  // Loop until the guess is correct
  while (1) {
    printf("Guess a letter: ");
    scanf(" %c", &guess);

    // Check if the guess is correct
    if (check_guess(word, guess)) {
      break;
    }

    // Print a hint if the guess is incorrect
    if (guess >= 'a' && guess <= 'z') {
      printf("Too low! Try again...\n");
    } else if (guess >= 'A' && guess <= 'Z') {
      printf("Too high! Try again...\n");
    } else {
      printf("Invalid character. Try again...\n");
    }
  }

  // Print the correct answer
  printf("Congratulations! You guessed the word: %s\n", word);

  return 0;
}