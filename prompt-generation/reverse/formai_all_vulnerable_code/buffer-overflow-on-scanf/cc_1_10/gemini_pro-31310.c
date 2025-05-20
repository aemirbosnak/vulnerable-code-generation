//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: retro
// Retro Math Exercise: The Number Guessing Game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
  // Initialize random seed
  srand(time(NULL));

  // Generate a random number between min and max
  return min + (rand() % (max - min + 1));
}

// Function to check if the user's guess is correct
int checkGuess(int guess, int target) {
  if (guess == target) {
    return 1;
  } else if (guess < target) {
    return -1;
  } else {
    return 1;
  }
}

// Main program
int main() {
  // Set the target number
  int target = generateRandomNumber(1, 100);

  // Get the user's guess
  int guess;
  printf("Guess a number between 1 and 100: ");
  scanf("%d", &guess);

  // Check the user's guess
  int result = checkGuess(guess, target);

  // Print the result
  if (result == 1) {
    printf("Congratulations! You guessed the correct number.\n");
  } else if (result == -1) {
    printf("Your guess is too low.\n");
  } else {
    printf("Your guess is too high.\n");
  }

  return 0;
}