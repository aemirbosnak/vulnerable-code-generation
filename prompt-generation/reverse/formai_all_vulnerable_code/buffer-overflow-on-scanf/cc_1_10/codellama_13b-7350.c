//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GUESSES 10
#define WORD_LENGTH 8

// Function prototypes
void welcome();
void display_board();
int guess_letter();
void check_guess();
void reveal_word();
void game_over();

// Global variables
char word[WORD_LENGTH + 1];
char guessed_letters[WORD_LENGTH];
int guesses_left;
int correct_guesses;

int main() {
  // Initialize variables
  guesses_left = MAX_GUESSES;
  correct_guesses = 0;
  srand(time(NULL));

  // Generate random word
  int i;
  for (i = 0; i < WORD_LENGTH; i++) {
    word[i] = 'a' + rand() % 26;
  }
  word[WORD_LENGTH] = '\0';

  // Welcome message
  welcome();

  // Play game
  while (guesses_left > 0) {
    // Display board
    display_board();

    // Get guess
    int guess = guess_letter();

    // Check guess
    check_guess(guess);

    // Update board
    if (correct_guesses == WORD_LENGTH) {
      reveal_word();
      game_over();
      break;
    }
  }

  // Game over
  if (guesses_left == 0) {
    reveal_word();
    game_over();
  }

  return 0;
}

void welcome() {
  printf("Welcome to Hangman!\n");
  printf("-------------------\n");
}

void display_board() {
  int i;
  for (i = 0; i < WORD_LENGTH; i++) {
    if (guessed_letters[i] == 'Y') {
      printf("%c ", word[i]);
    } else {
      printf("_ ");
    }
  }
  printf("\n");
}

int guess_letter() {
  char guess;
  printf("Guess a letter: ");
  scanf(" %c", &guess);
  return guess;
}

void check_guess(int guess) {
  int i;
  for (i = 0; i < WORD_LENGTH; i++) {
    if (word[i] == guess) {
      guessed_letters[i] = 'Y';
      correct_guesses++;
    }
  }
  if (correct_guesses == WORD_LENGTH) {
    printf("You won! The word was '%s'.\n", word);
  } else {
    printf("Incorrect guess. You have %d guesses left.\n", guesses_left - 1);
    guesses_left--;
  }
}

void reveal_word() {
  printf("The word was '%s'.\n", word);
}

void game_over() {
  printf("Game over.\n");
}