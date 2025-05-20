//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dice structure
typedef struct die {
  int sides;
  int value;
} die;

// Function to roll a die
int roll_die(die *d) {
  // Get a random number between 1 and the number of sides on the die
  d->value = rand() % d->sides + 1;

  // Return the value of the die
  return d->value;
}

// Function to roll a set of dice
void roll_dice(die *dice, int num_dice) {
  // Roll each die in the set
  for (int i = 0; i < num_dice; i++) {
    roll_die(&dice[i]);
  }
}

// Function to print the values of a set of dice
void print_dice(die *dice, int num_dice) {
  // Print the value of each die in the set
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", dice[i].value);
  }

  // Print a newline
  printf("\n");
}

// Function to play a game of dice
void play_game(int num_dice, int num_rolls) {
  // Create a set of dice
  die dice[num_dice];

  // Roll the dice num_rolls times
  for (int i = 0; i < num_rolls; i++) {
    roll_dice(dice, num_dice);

    // Print the values of the dice
    print_dice(dice, num_dice);
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play a game of dice with 2 dice and 10 rolls
  play_game(2, 10);

  // Return 0 to indicate successful execution
  return 0;
}