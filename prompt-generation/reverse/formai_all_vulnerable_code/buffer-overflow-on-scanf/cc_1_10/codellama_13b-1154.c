//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: all-encompassing
/*
 * A terminal-based game example program
 *
 * The program will ask the user to input their name and then
 * start a game of Hangman, where the user has to guess
 * a word by providing one letter at a time.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LENGTH 10
#define MAX_GUESSES 6

void play_game(char *name, char *word);
void get_guess(char *guess);
void check_guess(char *guess, char *word);

int main() {
  char name[20];
  char word[WORD_LENGTH + 1];
  char guess[1];

  printf("Welcome to Hangman!\n");
  printf("What is your name? ");
  scanf("%s", name);

  srand(time(NULL));
  for (int i = 0; i < WORD_LENGTH; i++) {
    word[i] = '*';
  }
  word[WORD_LENGTH] = '\0';

  play_game(name, word);

  return 0;
}

void play_game(char *name, char *word) {
  char guess[1];
  int guesses = 0;

  printf("You are playing as %s\n", name);
  printf("The word is %d letters long\n", WORD_LENGTH);

  while (guesses < MAX_GUESSES) {
    printf("Guess a letter: ");
    scanf("%s", guess);

    check_guess(guess, word);

    if (guesses == MAX_GUESSES - 1) {
      printf("You have %d guesses left\n", MAX_GUESSES - guesses);
    } else {
      printf("You have %d guesses left\n", MAX_GUESSES - guesses);
    }

    if (strcmp(word, guess) == 0) {
      printf("Congratulations, you guessed the word!\n");
      break;
    } else if (guesses == MAX_GUESSES) {
      printf("Sorry, you ran out of guesses. The word was %s\n", word);
      break;
    }
  }
}

void get_guess(char *guess) {
  printf("Guess a letter: ");
  scanf("%s", guess);
}

void check_guess(char *guess, char *word) {
  int found = 0;
  int index = 0;

  while (index < WORD_LENGTH && !found) {
    if (word[index] == guess[0]) {
      found = 1;
    }
    index++;
  }

  if (found) {
    printf("You guessed the letter %c\n", guess[0]);
  } else {
    printf("You didn't guess the letter %c\n", guess[0]);
  }
}