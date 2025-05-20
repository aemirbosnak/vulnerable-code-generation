//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 100000
#define MAGIC_NUMBER 42

int main() {
  int number, guess, attempts = 0;
  char message[50];

  srand(time(NULL));

  printf("Welcome to the Ultimate Arithmetic Adventure!\n");
  printf("I'm a cheerful arithmetic program, and I'm here to put your math skills to the test! \n");
  printf("Don't worry, I'll be gentle... unless you ask me to generate a random number between 1 and 100,000. \n");
  printf("In that case, I'll make sure to make you work for it! \n");
  printf("So, are you ready to begin? (type 'yes' to start)\n");

  while (1) {
    // Generate a random number between 1 and 100,000
    number = rand() % MAX_NUMBER;

    // Print the number and ask the user to guess
    printf("Here's your first challenge: %d\n", number);
    printf("Can you guess the correct answer? (type 'yes' to guess)\n");

    // Get the user's guess
    scanf(" %c", &guess);

    // Check if the user's guess is correct
    if (guess == 'yes') {
      // If the user's guess is correct, print a success message
      printf("CORRECT! You guessed %d, and I was thinking of %d. \n", guess, number);
      // Increment the attempts counter
      attempts++;

      // If the user's guess is incorrect, print an error message
    } else {
      printf("INCORRECT. The correct answer was %d, not %c. Better luck next time! \n", number, guess);
    }

    // Check if the user wants to continue
    printf("Do you want to continue? (type 'yes' to continue, 'no' to quit)\n");
    scanf(" %c", &guess);

    // If the user wants to quit, break out of the loop
    if (guess == 'no') break;
  }

  // Print a final message based on the number of attempts
  if (attempts == 0) {
    printf("You passed all challenges with flying colors! Congratulations, you are a math genius! \n");
  } else {
    printf("You failed %d challenges, but you still get a participation trophy! Better luck next time. \n", attempts);
  }

  return 0;
}