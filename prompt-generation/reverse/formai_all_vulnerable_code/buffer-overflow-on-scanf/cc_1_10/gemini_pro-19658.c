//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the random number generator.
#define RAND_MAX 2147483647

// Define the number of guesses.
#define NUM_GUESSES 10

int main(void) {
  // Set the random seed.
  srand(time(NULL));

  // Generate a random number.
  int num = rand() % 100 + 1;

  // Get the user's guess.
  int guess;
  printf("Guess a number between 1 and 100: ");
  scanf("%d", &guess);

  // Keep track of the number of guesses.
  int num_guesses = 1;

  // Check if the user's guess is correct.
  while (guess != num && num_guesses < NUM_GUESSES) {
    // If the user's guess is too low, tell them to guess higher.
    if (guess < num) {
      printf("Your guess is too low. Guess again: ");
      scanf("%d", &guess);
    }
    // If the user's guess is too high, tell them to guess lower.
    else {
      printf("Your guess is too high. Guess again: ");
      scanf("%d", &guess);
    }

    // Increment the number of guesses.
    num_guesses++;
  }

  // Check if the user guessed the number correctly.
  if (guess == num) {
    printf("Congratulations! You guessed the number correctly in %d guesses.\n", num_guesses);
  }
  // If the user did not guess the number correctly, tell them the correct number.
  else {
    printf("Sorry, you did not guess the number correctly. The correct number is %d.\n", num);
  }

  return 0;
}