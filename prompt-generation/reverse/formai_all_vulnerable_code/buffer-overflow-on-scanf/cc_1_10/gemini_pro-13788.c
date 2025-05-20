//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the dice faces
#define NUM_SIDES 6
char *faces[] = {"⚀", "⚁", "⚂", "⚃", "⚄", "⚅"};

// Function to roll a single die
int roll_die() {
  return rand() % NUM_SIDES + 1;
}

// Function to roll multiple dice
int roll_dice(int num_dice) {
  int result = 0;
  for (int i = 0; i < num_dice; i++) {
    result += roll_die();
  }
  return result;
}

// Function to print the results of a dice roll
void print_results(int num_dice, int result) {
  printf("Rolling %d dice:\n", num_dice);
  printf("Result: %d\n", result);
  printf("Faces: ");
  for (int i = 0; i < num_dice; i++) {
    printf("%s ", faces[roll_die() - 1]);
  }
  printf("\n\n");
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the number of dice to roll from the user
  int num_dice = 0;
  printf("How many dice do you want to roll? ");
  scanf("%d", &num_dice);

  // Roll the dice and print the results
  int result = roll_dice(num_dice);
  print_results(num_dice, result);

  return 0;
}