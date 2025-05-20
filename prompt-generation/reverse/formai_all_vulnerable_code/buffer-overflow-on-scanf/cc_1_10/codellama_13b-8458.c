//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GUESSES 10
#define WORD_LENGTH 5
#define ALPHABET_SIZE 26

int main() {
  char word[WORD_LENGTH + 1];
  char guess[WORD_LENGTH + 1];
  int guessed_letters[ALPHABET_SIZE] = {0};
  int i, j;

  // Initialize random seed
  srand(time(NULL));

  // Generate a random word
  for (i = 0; i < WORD_LENGTH; i++) {
    word[i] = 'a' + rand() % ALPHABET_SIZE;
  }
  word[WORD_LENGTH] = '\0';

  // Game loop
  for (i = 0; i < MAX_GUESSES; i++) {
    // Print the word with underscores
    for (j = 0; j < WORD_LENGTH; j++) {
      printf("%c_ ", word[j]);
    }
    printf("\n");

    // Get a guess
    printf("Guess a letter: ");
    scanf(" %c", guess);
    guess[0] = tolower(guess[0]);

    // Check if the guess is in the word
    if (strchr(word, guess[0]) != NULL) {
      // If the guess is in the word, replace the underscores with the correct letter
      for (j = 0; j < WORD_LENGTH; j++) {
        if (word[j] == guess[0]) {
          word[j] = guess[0];
        }
      }
    } else {
      // If the guess is not in the word, update the guessed letters array
      guessed_letters[guess[0] - 'a'] = 1;
    }

    // Check if the word is complete
    if (strcmp(word, guess) == 0) {
      printf("Congratulations! You guessed the word: %s\n", word);
      return 0;
    }
  }

  // If the user ran out of guesses, print the word
  printf("Sorry, you ran out of guesses. The word was: %s\n", word);

  return 0;
}