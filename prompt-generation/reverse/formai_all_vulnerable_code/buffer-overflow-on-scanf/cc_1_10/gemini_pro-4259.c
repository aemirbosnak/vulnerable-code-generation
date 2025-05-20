//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides on the dice
#define NUM_SIDES 6

// Define the number of dice to roll
#define NUM_DICE 5

// Define the maximum number of rolls
#define MAX_ROLLS 10000

// Define the minimum number of rolls
#define MIN_ROLLS 1

// Define the maximum number of sides on the dice
#define MAX_SIDES 100

// Define the minimum number of sides on the dice
#define MIN_SIDES 1

// Define the maximum number of dice to roll
#define MAX_DICE 100

// Define the minimum number of dice to roll
#define MIN_DICE 1

// Define the maximum number of rolls
#define MAX_ROLLS 10000

// Define the minimum number of rolls
#define MIN_ROLLS 1

// Function to roll a single die
int roll_die(int sides) {
  // Check if the number of sides is valid
  if (sides < MIN_SIDES || sides > MAX_SIDES) {
    printf("Invalid number of sides: %d\n", sides);
    exit(1);
  }

  // Roll the die
  return rand() % sides + 1;
}

// Function to roll multiple dice
int roll_dice(int num_dice, int sides) {
  // Check if the number of dice is valid
  if (num_dice < MIN_DICE || num_dice > MAX_DICE) {
    printf("Invalid number of dice: %d\n", num_dice);
    exit(1);
  }

  // Check if the number of sides is valid
  if (sides < MIN_SIDES || sides > MAX_SIDES) {
    printf("Invalid number of sides: %d\n", sides);
    exit(1);
  }

  // Roll the dice
  int total = 0;
  for (int i = 0; i < num_dice; i++) {
    total += roll_die(sides);
  }

  return total;
}

// Function to print the results of a dice roll
void print_results(int num_rolls, int num_dice, int sides, int total) {
  // Print the number of rolls
  printf("Number of rolls: %d\n", num_rolls);

  // Print the number of dice
  printf("Number of dice: %d\n", num_dice);

  // Print the number of sides
  printf("Number of sides: %d\n", sides);

  // Print the total
  printf("Total: %d\n", total);
}

// Function to get the user input
void get_user_input(int *num_rolls, int *num_dice, int *sides) {
  // Get the number of rolls
  printf("Enter the number of rolls: ");
  scanf("%d", num_rolls);

  // Get the number of dice
  printf("Enter the number of dice: ");
  scanf("%d", num_dice);

  // Get the number of sides
  printf("Enter the number of sides: ");
  scanf("%d", sides);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the user input
  int num_rolls, num_dice, sides;
  get_user_input(&num_rolls, &num_dice, &sides);

  // Check if the user input is valid
  if (num_rolls < MIN_ROLLS || num_rolls > MAX_ROLLS) {
    printf("Invalid number of rolls: %d\n", num_rolls);
    exit(1);
  }

  if (num_dice < MIN_DICE || num_dice > MAX_DICE) {
    printf("Invalid number of dice: %d\n", num_dice);
    exit(1);
  }

  if (sides < MIN_SIDES || sides > MAX_SIDES) {
    printf("Invalid number of sides: %d\n", sides);
    exit(1);
  }

  // Roll the dice
  int total = roll_dice(num_dice, sides);

  // Print the results
  print_results(num_rolls, num_dice, sides, total);

  return 0;
}