//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define some constants and variables
#define MAX_NUMBER 1000
#define MAGIC_NUMBER 42
#define HAPPY_FACE ":) "
#define SAD_FACE ":( "

int main() {
  // Initialize some variables
  int number = 0;
  int guess = 0;
  int correct = 0;
  int attempts = 0;

  // Generate a random number between 1 and MAX_NUMBER
  srand(time(NULL));
  number = rand() % MAX_NUMBER;

  // Print the number and ask the user to guess
  printf("I'm thinking of a number between 1 and %d. Can you guess it?\n", MAX_NUMBER);
  printf("The number is: %d\n", number);

  // Loop until the user guesses correctly or runs out of attempts
  while (1) {
    // Ask the user for their guess
    printf("Enter your guess: ");
    scanf("%d", &guess);

    // Check if the user guessed correctly
    if (guess == number) {
      // Print a happy face and announce the correct guess
      printf(HAPPY_FACE "Correct! You guessed %d\n", number);
      correct++;
      break;
    }

    // If the user didn't guess correctly, print a sad face and decrement the attempts
    else {
      printf(SAD_FACE "Incorrect. You have %d attempts left\n", attempts);
      attempts--;
    }

    // If the user ran out of attempts, print a final message and exit
    if (attempts == 0) {
      printf("Sorry, you ran out of attempts. The correct answer was %d\n", number);
      exit(1);
    }
  }

  // Print the final score and exit
  printf("You guessed %d out of %d correctly (%.2f%%).\n", correct, attempts,
          (correct * 100) / attempts);
  exit(0);
}