//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MIN_DICE_SIDES 4
#define MAX_DICE_SIDES 20

// Function prototypes
int roll_dice(int num_dice, int num_sides);
void print_results(int num_dice, int num_sides, int *results);

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the number of dice and sides from the user
  int num_dice, num_sides;
  printf("Enter the number of dice: ");
  scanf("%d", &num_dice);
  printf("Enter the number of sides on each dice: ");
  scanf("%d", &num_sides);

  // Validate the user input
  if (num_dice < 1 || num_dice > 10) {
    printf("Invalid number of dice. Please enter a number between 1 and 10.\n");
    return 1;
  } else if (num_sides < MIN_DICE_SIDES || num_sides > MAX_DICE_SIDES) {
    printf("Invalid number of sides. Please enter a number between %d and %d.\n", MIN_DICE_SIDES, MAX_DICE_SIDES);
    return 1;
  }

  // Roll the dice
  int *results = malloc(sizeof(int) * num_dice);
  for (int i = 0; i < num_dice; i++) {
    results[i] = roll_dice(1, num_sides);
  }

  // Print the results
  print_results(num_dice, num_sides, results);

  // Free the allocated memory
  free(results);

  return 0;
}

int roll_dice(int num_dice, int num_sides) {
  int result = 0;
  for (int i = 0; i < num_dice; i++) {
    result += (rand() % num_sides) + 1;
  }
  return result;
}

void print_results(int num_dice, int num_sides, int *results) {
  printf("You rolled %d dice with %d sides each.\n", num_dice, num_sides);
  printf("The results are:\n");
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", results[i]);
  }
  printf("\n");
}