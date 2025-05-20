//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of lives and the maximum number of guesses
#define LIVES 3
#define MAX_GUESSES 10

// Define the range of numbers to guess
#define MIN_NUMBER 1
#define MAX_NUMBER 100

// Function to generate a random number within the specified range
int generate_random_number() {
  return (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;
}

// Function to print the current state of the game
void print_game_state(int guesses, int lives, int guess, int number) {
  printf("Guesses: %d\n", guesses);
  printf("Lives: %d\n", lives);
  printf("Guess: %d\n", guess);
  printf("Number: %d\n", number);
}

// Function to check if the guess is correct
int check_guess(int guess, int number) {
  return guess == number;
}

// Function to process the guess
void process_guess(int guess, int number, int* guesses, int* lives, int* score) {
  // If the guess is correct, increment the score and generate a new number
  if (check_guess(guess, number)) {
    (*score)++;
    number = generate_random_number();
  } else {
    // If the guess is incorrect, decrement the number of lives
    (*lives)--;
  }
}

// Function to print the final score
void print_final_score(int score) {
  printf("Final Score: %d\n", score);
}

// Function to play the game
void play_game() {
  // Generate a random number
  int number = generate_random_number();

  // Initialize the game state
  int guesses = 0;
  int lives = LIVES;
  int score = 0;

  // Loop until the player runs out of lives
  while (lives > 0) {
    // Print the current state of the game
    print_game_state(guesses, lives, 0, number);

    // Get the player's guess
    int guess = 0;
    scanf("%d", &guess);

    // Process the guess
    process_guess(guess, number, &guesses, &lives, &score);

    // Print the updated state of the game
    print_game_state(guesses, lives, guess, number);
  }

  // Print the final score
  print_final_score(score);
}

int main() {
  // Set the random number seed
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}