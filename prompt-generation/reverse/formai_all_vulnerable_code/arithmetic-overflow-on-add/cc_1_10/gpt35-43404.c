//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess = 0;
  int randomNumber = 0;
  int numberOfGuesses = 0;
  int maxGuesses = 0;
  char playAgain = 'y';

  printf("Welcome to the Number Guessing Game!\n");
  printf("-----------------------------------\n");

  while (playAgain == 'y') {

    printf("Enter the maximum number for the game: ");
    scanf("%d", &maxGuesses);

    srand(time(NULL));
    randomNumber = rand() % maxGuesses + 1;

    printf("Guess a number between 1 and %d\n", maxGuesses);

    while (guess != randomNumber) {
      numberOfGuesses++;

      printf("\nGuess #%d: ", numberOfGuesses);
      scanf("%d", &guess);

      if (guess < randomNumber) {
        printf("Too low. Try again!\n");
      } else if (guess > randomNumber) {
        printf("Too high. Try again!\n");
      } else {
        printf("\nCongratulations! You guessed the number in %d attempt(s)!\n", numberOfGuesses);
      }
    }

    printf("\nDo you want to play again? (y/n) ");
    scanf(" %c", &playAgain);

    guess = 0;
    numberOfGuesses = 0;

  }

  printf("\nThanks for playing the game! Goodbye.\n");

  return 0;
}