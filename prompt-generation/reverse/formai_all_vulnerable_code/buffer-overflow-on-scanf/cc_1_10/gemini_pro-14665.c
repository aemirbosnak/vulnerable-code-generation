//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides on the dice
#define NUM_SIDES 6

// Define the maximum number of rolls
#define MAX_ROLLS 100

// Define the minimum number of rolls
#define MIN_ROLLS 1

// Declare the main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Get the number of rolls from the user
  int num_rolls;
  printf("How many rolls would you like? (1-100): ");
  scanf("%d", &num_rolls);

  // Check if the number of rolls is valid
  if (num_rolls < MIN_ROLLS || num_rolls > MAX_ROLLS) {
    printf("Invalid number of rolls. Please enter a number between 1 and 100.\n");
    return 1;
  }

  // Roll the dice num_rolls times
  int rolls[num_rolls];
  for (int i = 0; i < num_rolls; i++) {
    rolls[i] = rand() % NUM_SIDES + 1;
  }

  // Print the results
  printf("Your rolls:\n");
  for (int i = 0; i < num_rolls; i++) {
    printf("%d ", rolls[i]);
  }
  printf("\n");

  // Calculate the sum of the rolls
  int sum = 0;
  for (int i = 0; i < num_rolls; i++) {
    sum += rolls[i];
  }

  // Print the sum of the rolls
  printf("The sum of your rolls is: %d\n", sum);

  // Calculate the average of the rolls
  double average = (double)sum / num_rolls;

  // Print the average of the rolls
  printf("The average of your rolls is: %.2f\n", average);

  // Return 0 to indicate successful execution
  return 0;
}