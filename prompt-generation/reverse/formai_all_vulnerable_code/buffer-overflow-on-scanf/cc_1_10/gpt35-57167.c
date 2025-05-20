//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int score = 0; // initializing global variable for score

// function to generate random numbers
int generateRandomNumber(int lower, int upper) {
  int num = (rand() % (upper - lower + 1)) + lower;
  return num;
}

// function to check if the guess is correct or not
int checkGuess(int guess, int number) {
  if (guess < number) {
    printf("Too low!\n");
    return 0;
  } else if (guess > number) {
    printf("Too high!\n");
    return 0;
  } else {
    printf("Correct!\n");
    return 1;
  }
}

int main() {
  srand(time(0)); // seeding random number generator with current time
  int lower = 1, upper = 100; // initializing lower and upper bounds
  int number = generateRandomNumber(lower, upper); // generating random number
  int guess, numGuesses = 0; // initializing variables for guess and number of guesses

  printf("Guess the number between %d and %d!\n", lower, upper);

  // loop to take guesses until correct answer is given
  while(1) {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    numGuesses++; // incrementing number of guesses

    // checking if guess is correct
    if (checkGuess(guess, number)) {
      printf("Congratulations, you have guessed the number in %d tries!\n", numGuesses);
      score += numGuesses; // adding current score to total score
      printf("Your current score is: %d\n", score);
      printf("Would you like to play again? (y/n) ");
      char playAgain;
      scanf(" %c", &playAgain);
      if (playAgain == 'y') {
        number = generateRandomNumber(lower, upper);
        numGuesses = 0;
        printf("Guess the number between %d and %d!\n", lower, upper);
        continue;
      } else {
        printf("Thanks for playing! Your final score is: %d\n", score);
        break;
      }
    }
  }

  return 0;
}