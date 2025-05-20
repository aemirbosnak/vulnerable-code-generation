//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides for the dice
#define NUM_SIDES 6

// Function to roll a single die
int roll_die() {
  // Get a random number between 1 and NUM_SIDES
  int random_num = rand() % NUM_SIDES + 1;

  // Return the random number
  return random_num;
}

// Function to roll multiple dice and calculate the sum of the rolls
int roll_dice(int num_dice) {
  // Initialize the sum to 0
  int sum = 0;

  // Roll each die and add the result to the sum
  for (int i = 0; i < num_dice; i++) {
    sum += roll_die();
  }

  // Return the sum of the rolls
  return sum;
}

// Function to play a game of dice rolling
void play_game() {
  // Get the number of dice to roll from the user
  int num_dice;
  printf("How many dice would you like to roll? ");
  scanf("%d", &num_dice);

  // Roll the dice and calculate the sum of the rolls
  int sum = roll_dice(num_dice);

  // Print the sum of the rolls
  printf("You rolled a %d!\n", sum);

  // Check if the player won or lost
  if (sum >= 21) {
    printf("You win!\n");
  } else {
    printf("You lose!\n");
  }
}

// Main function
int main() {
  // Initialize the random seed
  srand(time(NULL));

  // Play the game of dice rolling
  play_game();

  return 0;
}