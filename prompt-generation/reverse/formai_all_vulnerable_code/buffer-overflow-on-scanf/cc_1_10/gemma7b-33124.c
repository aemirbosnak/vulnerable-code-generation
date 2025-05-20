//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

int main() {
  char words[MAX_WORDS][20] = {
    "The quick brown fox jumps over the lazy dog.",
    "A wise old owl sits on a tree.",
    "The early bird gets the worm.",
    "A red rose blooms in the sun.",
    "A gentle breeze blows through the leaves.",
    "The stars twinkle in the night sky.",
    "The moon shines brightly.",
    "A rainbow's arc colors the sky.",
    "The river flows to the sea.",
    "A ship sails the open waves."
  };

  char guessWord[20];
  int guessWordLength = 0;
  int correctGuesses = 0;
  time_t startTime, endTime;

  printf("Welcome to the C Typing Speed Test!\n");
  printf("Please guess a word from the list below:\n");

  for (int i = 0; i < MAX_WORDS; i++) {
    printf("%d. %s\n", i + 1, words[i]);
  }

  printf("Enter your guess:");
  scanf("%s", guessWord);

  guessWordLength = strlen(guessWord);

  startTime = time(NULL);

  for (int i = 0; i < guessWordLength; i++) {
    if (guessWord[i] == words[0][i]) {
      correctGuesses++;
    }
  }

  endTime = time(NULL);

  printf("Your guess was %s. You guessed %d out of %d words correctly.\n", guessWord, correctGuesses, MAX_WORDS);
  printf("Your typing speed was %d words per second.\n", (correctGuesses * MAX_WORDS) / (endTime - startTime));

  return 0;
}