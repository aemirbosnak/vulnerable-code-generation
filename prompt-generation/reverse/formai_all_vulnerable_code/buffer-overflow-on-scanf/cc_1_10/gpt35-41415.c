//FormAI DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed the random number generator with current time
  srand(time(NULL)); 
  
  // Introduce the game to the player
  printf("Welcome to Guess The Number!\n");
  printf("I have chosen a number between 1 and 100. Can you guess it?\n");

  // Generate a random number between 1 and 100
  int secret_number = rand() % 100 + 1;
  
  // Initialize player's guess and number of attempts
  int guess = 0;
  int attempts = 0;
  
  // Allow the player to make up to 7 guesses
  while (attempts < 7) {
    printf("Guess #%d: ", attempts+1);
    scanf("%d", &guess);
    
    // If the guess matches the secret number, the player wins
    if (guess == secret_number) {
      printf("Congratulations! You guessed the number in %d attempts.\n", attempts+1);
      break;
    }
    // If the guess is too high, ask the player to guess lower
    else if (guess > secret_number) {
      printf("Your guess is too high. Please guess lower.\n");
    }
    // If the guess is too low, ask the player to guess higher
    else {
      printf("Your guess is too low. Please guess higher.\n");
    }
    attempts++;
  }
  
  // If the player was not able to guess the number in 7 attempts, they lose
  if (attempts == 7) {
    printf("Sorry, you did not guess the number. The secret number was %d.\n", secret_number);
  }
  
  // End the game
  printf("Thanks for playing!");
  
  return 0;
}