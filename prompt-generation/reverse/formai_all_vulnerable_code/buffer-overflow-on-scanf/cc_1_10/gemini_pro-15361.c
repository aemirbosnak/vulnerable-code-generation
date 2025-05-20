//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct to represent a die
typedef struct die {
  int sides;
  int value;
} die;

// Function to roll a die
int roll_die(die *die) {
  // Get a random number between 1 and the number of sides on the die
  die->value = rand() % die->sides + 1;
  return die->value;
}

// Function to print the results of a dice roll
void print_results(int num_dice, die *dice) {
  // Print the values of the dice
  printf("You rolled ");
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", dice[i].value);
  }
  printf("\n");

  // Calculate the sum of the dice
  int sum = 0;
  for (int i = 0; i < num_dice; i++) {
    sum += dice[i].value;
  }

  // Print the sum of the dice
  printf("The sum of the dice is %d\n", sum);
}

// Main function
int main(void) {
  // Initialize the random number generator
  srand(time(NULL));

  // Get the number of dice to roll from the user
  int num_dice;
  printf("How many dice would you like to roll? ");
  scanf("%d", &num_dice);

  // Create an array of dice
  die dice[num_dice];

  // Roll the dice
  for (int i = 0; i < num_dice; i++) {
    dice[i].sides = 6;
    roll_die(&dice[i]);
  }

  // Print the results of the dice roll
  print_results(num_dice, dice);

  return 0;
}