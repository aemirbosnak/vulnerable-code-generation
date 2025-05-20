//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides for each die
#define D4_SIDES 4
#define D6_SIDES 6
#define D8_SIDES 8
#define D10_SIDES 10
#define D12_SIDES 12
#define D20_SIDES 20

// Define the maximum number of dice that can be rolled
#define MAX_DICE 10

// Define the maximum number of rolls for each die
#define MAX_ROLLS 100

// Define the data structure for a die
typedef struct die {
  int sides;
  int value;
} die_t;

// Define the data structure for a roll
typedef struct roll {
  int num_dice;
  die_t dice[MAX_DICE];
} roll_t;

// Function to roll a single die
int roll_die(die_t *die) {
  // Get a random number between 1 and the number of sides
  die->value = rand() % die->sides + 1;

  // Return the value of the die
  return die->value;
}

// Function to roll multiple dice
roll_t roll_dice(int num_dice, int sides) {
  // Create a new roll
  roll_t roll;

  // Set the number of dice in the roll
  roll.num_dice = num_dice;

  // Roll each die
  for (int i = 0; i < num_dice; i++) {
    roll.dice[i].sides = sides;
    roll.dice[i].value = roll_die(&roll.dice[i]);
  }

  // Return the roll
  return roll;
}

// Function to print the results of a roll
void print_roll(roll_t roll) {
  // Print the number of dice in the roll
  printf("Rolled %d dice:\n", roll.num_dice);

  // Print the value of each die
  for (int i = 0; i < roll.num_dice; i++) {
    printf("Die %d: %d\n", i + 1, roll.dice[i].value);
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the number of dice to roll
  int num_dice;
  printf("Enter the number of dice to roll: ");
  scanf("%d", &num_dice);

  // Get the number of sides for each die
  int sides;
  printf("Enter the number of sides for each die: ");
  scanf("%d", &sides);

  // Roll the dice
  roll_t roll = roll_dice(num_dice, sides);

  // Print the results of the roll
  print_roll(roll);

  return 0;
}