//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate a random number between min and max
int random_int_in_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to check if a number is prime
int is_prime(int n) {
  if (n <= 1) return 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

// Function to play the game
void play_game() {
  // Set up the game
  int n = random_int_in_range(1, 100);
  int guesses = 0;

  // Get the player's guess
  printf("Guess a number between 1 and 100: ");
  int guess;
  scanf("%d", &guess);

  // Check if the guess is correct
  while (guess != n) {
    // Increment the number of guesses
    guesses++;

    // Print a message telling the player whether their guess is too high or too low
    if (guess > n) {
      printf("Your guess is too high. ");
    } else if (guess < n) {
      printf("Your guess is too low. ");
    }

    // Get the player's next guess
    printf("Guess again: ");
    scanf("%d", &guess);
  }

  // Print a message telling the player that they won
  printf("Congratulations! You guessed the correct number in %d guesses.\n", guesses);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}