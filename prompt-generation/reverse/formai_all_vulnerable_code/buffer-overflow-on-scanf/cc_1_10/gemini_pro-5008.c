//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int roll_die(int num_sides) {
  return rand() % num_sides + 1;
}

// Function to roll multiple dice
int* roll_dice(int num_dice, int num_sides) {
  int* rolls = malloc(sizeof(int) * num_dice);
  for (int i = 0; i < num_dice; i++) {
    rolls[i] = roll_die(num_sides);
  }
  return rolls;
}

// Function to print the results of a dice roll
void print_dice_roll(int* rolls, int num_dice) {
  printf("Rolled %d dice:\n", num_dice);
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", rolls[i]);
  }
  printf("\n");
}

// Function to get the sum of a dice roll
int get_dice_roll_sum(int* rolls, int num_dice) {
  int sum = 0;
  for (int i = 0; i < num_dice; i++) {
    sum += rolls[i];
  }
  return sum;
}

// Function to get the average of a dice roll
double get_dice_roll_average(int* rolls, int num_dice) {
  return (double)get_dice_roll_sum(rolls, num_dice) / num_dice;
}

// Function to get the maximum value of a dice roll
int get_dice_roll_max(int* rolls, int num_dice) {
  int max = rolls[0];
  for (int i = 1; i < num_dice; i++) {
    if (rolls[i] > max) {
      max = rolls[i];
    }
  }
  return max;
}

// Function to get the minimum value of a dice roll
int get_dice_roll_min(int* rolls, int num_dice) {
  int min = rolls[0];
  for (int i = 1; i < num_dice; i++) {
    if (rolls[i] < min) {
      min = rolls[i];
    }
  }
  return min;
}

// Function to main
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Get the number of dice to roll
  int num_dice;
  printf("Enter the number of dice to roll: ");
  scanf("%d", &num_dice);

  // Get the number of sides on each die
  int num_sides;
  printf("Enter the number of sides on each die: ");
  scanf("%d", &num_sides);

  // Roll the dice
  int* rolls = roll_dice(num_dice, num_sides);

  // Print the results of the dice roll
  print_dice_roll(rolls, num_dice);

  // Get the sum of the dice roll
  int sum = get_dice_roll_sum(rolls, num_dice);
  printf("The sum of the dice roll is: %d\n", sum);

  // Get the average of the dice roll
  double average = get_dice_roll_average(rolls, num_dice);
  printf("The average of the dice roll is: %.2f\n", average);

  // Get the maximum value of the dice roll
  int max = get_dice_roll_max(rolls, num_dice);
  printf("The maximum value of the dice roll is: %d\n", max);

  // Get the minimum value of the dice roll
  int min = get_dice_roll_min(rolls, num_dice);
  printf("The minimum value of the dice roll is: %d\n", min);

  // Free the memory allocated for the rolls array
  free(rolls);

  return 0;
}