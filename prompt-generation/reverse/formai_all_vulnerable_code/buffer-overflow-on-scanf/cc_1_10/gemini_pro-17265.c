//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of dice to roll
#define NUM_DICE 2

// Define the number of sides on each die
#define NUM_SIDES 6

// Roll a single die and return the result
int roll_die() {
  // Get a random number between 1 and NUM_SIDES
  int roll = rand() % NUM_SIDES + 1;

  // Return the roll
  return roll;
}

// Roll a number of dice and return the sum of the results
int roll_dice(int num_dice) {
  // Initialize the sum to 0
  int sum = 0;

  // Roll each die and add the result to the sum
  for (int i = 0; i < num_dice; i++) {
    sum += roll_die();
  }

  // Return the sum
  return sum;
}

// Play a game of dice rolling
void play_game() {
  // Get the number of dice to roll from the user
  int num_dice;
  printf("How many dice do you want to roll? ");
  scanf("%d", &num_dice);

  // Roll the dice and get the sum
  int sum = roll_dice(num_dice);

  // Print the sum of the dice
  printf("You rolled a %d.\n", sum);

  // Check if the user won, lost, or tied
  if (sum == 7 || sum == 11) {
    printf("You win!\n");
  } else if (sum == 2 || sum == 3 || sum == 12) {
    printf("You lose!\n");
  } else {
    printf("You tied!\n");
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}