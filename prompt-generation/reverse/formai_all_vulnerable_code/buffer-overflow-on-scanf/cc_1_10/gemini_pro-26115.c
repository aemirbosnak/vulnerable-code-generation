//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 10

int main() {
  // Seed the random number generator with the current time.
  srand(time(NULL));

  // Get the number of dice and sides from the user.
  int num_dice;
  int num_sides;
  printf("Enter the number of dice to roll: ");
  scanf("%d", &num_dice);
  printf("Enter the number of sides on each die: ");
  scanf("%d", &num_sides);

  // Check if the input is valid.
  if (num_dice <= 0 || num_dice > MAX_DICE) {
    printf("Invalid number of dice.\n");
    return 1;
  }
  if (num_sides <= 0 || num_sides > MAX_SIDES) {
    printf("Invalid number of sides.\n");
    return 1;
  }

  // Create an array to store the dice rolls.
  int rolls[MAX_DICE];

  // Roll the dice and store the results in the array.
  for (int i = 0; i < num_dice; i++) {
    rolls[i] = rand() % num_sides + 1;
  }

  // Print the dice rolls.
  printf("The dice rolls are:\n");
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", rolls[i]);
  }
  printf("\n");

  // Calculate the sum of the dice rolls.
  int sum = 0;
  for (int i = 0; i < num_dice; i++) {
    sum += rolls[i];
  }

  // Print the sum of the dice rolls.
  printf("The sum of the dice rolls is: %d\n", sum);

  return 0;
}