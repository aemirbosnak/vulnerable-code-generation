//Code Llama-13B DATASET v1.0 Category: Dice Roller ; Style: configurable
// Dice Roller
//
// This program generates a random number between 1 and 6 for each
// die roll and returns the result. The number of dice rolls and the
// modifier can be configured by the user.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int roll_dice(int num_dice, int modifier) {
  int rolls[num_dice];
  int total = 0;

  // Generate random numbers for each die roll
  srand(time(NULL));
  for (int i = 0; i < num_dice; i++) {
    rolls[i] = (rand() % 6) + 1;
    total += rolls[i];
  }

  // Add modifier
  total += modifier;

  // Print the results
  printf("Dice Rolls: ");
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", rolls[i]);
  }
  printf("\n");
  printf("Total: %d\n", total);

  return total;
}

// Main function
int main() {
  int num_dice = 2;
  int modifier = 0;

  // Get the number of dice rolls and modifier from the user
  printf("Enter the number of dice rolls: ");
  scanf("%d", &num_dice);
  printf("Enter the modifier: ");
  scanf("%d", &modifier);

  // Roll the dice
  roll_dice(num_dice, modifier);

  return 0;
}