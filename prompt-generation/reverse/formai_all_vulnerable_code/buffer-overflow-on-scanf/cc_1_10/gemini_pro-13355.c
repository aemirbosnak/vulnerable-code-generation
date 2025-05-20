//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides for the dice
#define NUM_SIDES 6

// Function to roll a single die
int roll_die() {
  // Generate a random number between 1 and NUM_SIDES
  int roll = rand() % NUM_SIDES + 1;

  // Return the random number
  return roll;
}

// Function to roll multiple dice
int roll_dice(int num_dice) {
  // Initialize the total roll to 0
  int total_roll = 0;

  // Loop through each die and roll it
  for (int i = 0; i < num_dice; i++) {
    // Roll the die and add the result to the total roll
    total_roll += roll_die();
  }

  // Return the total roll
  return total_roll;
}

// Function to print the results of a dice roll
void print_results(int num_dice, int total_roll) {
  // Print the number of dice rolled and the total roll
  printf("You rolled %d dice and got a total of %d.\n", num_dice, total_roll);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Get the number of dice to roll from the user
  int num_dice;
  printf("How many dice do you want to roll? ");
  scanf("%d", &num_dice);

  // Roll the dice and get the total roll
  int total_roll = roll_dice(num_dice);

  // Print the results of the dice roll
  print_results(num_dice, total_roll);

  return 0;
}