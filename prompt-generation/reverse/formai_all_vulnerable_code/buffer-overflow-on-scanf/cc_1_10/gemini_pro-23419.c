//GEMINI-pro DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The main function is the entry point of the program.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Declare the variables.
  int numberToGuess; // The number that the user has to guess.
  int guess; // The user's guess.
  int tries = 0; // The number of tries the user has made.
  int low = 0; // The lower bound of the range of numbers that the user can guess.
  int high = 100; // The upper bound of the range of numbers that the user can guess.
  
  // Generate a random number between 1 and 100.
  numberToGuess = rand() % 100 + 1;

  // Welcome the user to the game.
  printf("Welcome to the number guessing game!\n");
  printf("I have chosen a number between 1 and 100.\n");
  printf("Try to guess it in as few tries as possible.\n");
  printf("Good luck!\n");

  // Get the user's guess.
  while (guess != numberToGuess) {
    printf("\nWhat is your guess? ");
    scanf("%d", &guess);
    
    // Check if the user's guess is correct.
    if (guess == numberToGuess) {
      printf("Congratulations! You guessed the number in %d tries.\n", tries);
    } else {
      // Give the user a hint.
      if (guess < numberToGuess) {
        printf("Your guess is too low.\n");
      } else {
        printf("Your guess is too high.\n");
      }
      
      // Adjust the range of numbers that the user can guess.
      if (guess < numberToGuess) {
        low = guess + 1;
      } else {
        high = guess - 1;
      }
      
      // Increment the number of tries.
      tries++;
    }
  }

  return 0;
}