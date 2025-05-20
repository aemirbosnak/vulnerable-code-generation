//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: introspective
#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h> // time()

// Function to roll a die with 'sides' sides and return the result.
int roll_die(int sides) {
  // Check if 'sides' is valid.
  if (sides < 2) {
    fprintf(stderr, "Error: Invalid number of sides for die (%d). Must be at least 2.\n", sides);
    exit(EXIT_FAILURE);
  }

  // Seed the random number generator using the current time.
  srand(time(NULL));

  // Generate a random number between 1 and 'sides'.
  return rand() % sides + 1;
}

// Function to simulate rolling 'num_dice' dice with 'sides' sides and print the results.
void roll_dice(int num_dice, int sides) {
  // Check if 'num_dice' is valid.
  if (num_dice < 1) {
    fprintf(stderr, "Error: Invalid number of dice to roll (%d). Must be at least 1.\n", num_dice);
    exit(EXIT_FAILURE);
  }

  // Check if 'sides' is valid.
  if (sides < 2) {
    fprintf(stderr, "Error: Invalid number of sides for die (%d). Must be at least 2.\n", sides);
    exit(EXIT_FAILURE);
  }

  // Roll the dice and print the results.
  for (int i = 0; i < num_dice; i++) {
    printf("Die %d: %d\n", i + 1, roll_die(sides));
  }
}

// Main function.
int main(void) {
  // Get the number of dice to roll from the user.
  int num_dice;
  printf("How many dice would you like to roll? ");
  scanf("%d", &num_dice);

  // Get the number of sides for each die from the user.
  int sides;
  printf("How many sides should each die have? ");
  scanf("%d", &sides);

  // Roll the dice and print the results.
  roll_dice(num_dice, sides);

  return EXIT_SUCCESS;
}