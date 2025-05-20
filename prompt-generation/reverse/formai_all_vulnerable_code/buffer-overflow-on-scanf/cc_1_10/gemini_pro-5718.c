//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides on the dice
#define NUM_SIDES 6

// Define the maximum number of rolls
#define MAX_ROLLS 10000

// Define the probability of rolling each side
#define PROB_OF_ROLLING_EACH_SIDE 1.0 / NUM_SIDES

// Define the function to roll the dice
int roll_dice() {
  // Get a random number between 1 and NUM_SIDES
  int roll = rand() % NUM_SIDES + 1;

  // Return the roll
  return roll;
}

// Define the function to simulate rolling the dice multiple times
void simulate_rolling_dice(int num_rolls) {
  // Create an array to store the frequencies of each side
  int frequencies[NUM_SIDES];
  
  for (int i = 0; i < NUM_SIDES; i++) {
    frequencies[i] = 0;
  }

  // Roll the dice num_rolls times
  for (int i = 0; i < num_rolls; i++) {
    // Get the roll
    int roll = roll_dice();

    // Increment the frequency of the roll
    frequencies[roll - 1]++;
  }

  // Print the frequencies of each side
  printf("Side  Frequency (Actual)  Frequency (Expected)\n");
  printf("----  --------  --------------------\n");
  for (int i = 0; i < NUM_SIDES; i++) {
    printf("%4d  %8d  %18.6f\n", i + 1, frequencies[i], num_rolls * PROB_OF_ROLLING_EACH_SIDE);
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the number of rolls from the user
  int num_rolls;
  printf("Enter the number of rolls: ");
  scanf("%d", &num_rolls);

  // Simulate rolling the dice num_rolls times
  simulate_rolling_dice(num_rolls);

  return 0;
}