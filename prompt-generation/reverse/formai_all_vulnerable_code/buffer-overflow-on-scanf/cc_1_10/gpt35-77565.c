//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int max_guess = 5; // max number of guesses
  int guess_count = 0; // current number of guesses
  int number_to_guess = 0;
  int guess = 0; // user's guess
  int i; // loop variable
  
  // seed the random number generator
  srand(time(NULL));
  
  // generate a random number between 1 and 100
  number_to_guess = rand() % 100 + 1;
  
  // print welcome message
  printf("Welcome to the Guessing Game!\n");
  printf("I'm thinking of a number between 1 and 100.\n");
  
  // main loop
  while (guess_count < max_guess) {
    // get user's guess
    printf("Guess #%d of %d: ", guess_count + 1, max_guess);
    scanf("%d", &guess);
    
    // check if the guess is correct
    if (guess == number_to_guess) {
      printf("Congratulations! You guessed the number in %d tries.\n", guess_count + 1);
      break;
    }
    else if (guess < number_to_guess) {
      printf("Too low!\n");
    }
    else {
      printf("Too high!\n");
    }
    
    // increment guess count
    guess_count++;
  }
  
  // print message if user did not guess the number
  if (guess_count == max_guess) {
    printf("Sorry, you did not guess the number. It was %d.\n", number_to_guess);
  }
  
  return 0;
}