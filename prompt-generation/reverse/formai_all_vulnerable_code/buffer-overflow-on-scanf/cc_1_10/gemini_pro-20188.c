//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides for each die
#define DIE_SIDES 6

// Define the maximum number of dice to roll
#define MAX_DICE 10

// Define the maximum total value for all dice
#define MAX_TOTAL 60

// Function to generate a random number between 1 and the number of sides for a die
int roll_die(int sides) {
  return rand() % sides + 1;
}

// Function to roll a specified number of dice and return the total value
int roll_dice(int num_dice) {
  int total = 0;
  for (int i = 0; i < num_dice; i++) {
    total += roll_die(DIE_SIDES);
  }
  return total;
}

// Function to print the results of the dice roll
void print_results(int num_dice, int total) {
  printf("You rolled %d dice and got a total of %d.\n", num_dice, total);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the number of dice to roll from the user
  int num_dice;
  printf("How many dice do you want to roll? (1-%d) ", MAX_DICE);
  scanf("%d", &num_dice);

  // Validate the number of dice entered by the user
  if (num_dice < 1 || num_dice > MAX_DICE) {
    printf("Invalid number of dice. Please enter a number between 1 and %d.\n", MAX_DICE);
    return 1;
  }

  // Roll the dice and get the total value
  int total = roll_dice(num_dice);

  // Print the results of the dice roll
  print_results(num_dice, total);

  return 0;
}