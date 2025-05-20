//LLAMA2-13B DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SURPRISED 1

int main() {
  int num_guesses = 0;
  int correct_guesses = 0;
  int surprise_factor = 0;

  // Generate a random number between 1 and 100
  int random_number = rand() % 100 + 1;

  // Print the random number and ask the user to guess
  printf("I'm thinking of a number between 1 and 100... can you guess it?\n");
  printf("The number is: %d\n", random_number);

  // Loop until the user correctly guesses the number
  while (num_guesses < 10) {
    int guess = getchar() - '0';
    if (guess < 0 || guess > 99) {
      printf("Invalid guess. Try again!\n");
      num_guesses++;
      continue;
    }

    // Check if the user guessed the correct number
    if (guess == random_number) {
      correct_guesses++;
      surprise_factor++;
      break;
    }

    // If the user didn't guess the correct number, increase the surprise factor
    else {
      surprise_factor++;
    }

    // Print the correct number of guesses and the surprise factor
    printf("You have guessed %d out of %d correct numbers (surprise factor: %d).\n",
           correct_guesses, num_guesses, surprise_factor);
  }

  // Print the final surprise factor and the correct number of guesses
  printf("You guessed %d correct numbers (surprise factor: %d).\n",
         correct_guesses, surprise_factor);

  return SURPRISED;
}