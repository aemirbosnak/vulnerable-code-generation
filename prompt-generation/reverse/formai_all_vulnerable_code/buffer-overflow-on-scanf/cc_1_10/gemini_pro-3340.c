//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of dice sides
#define SIDES 6

// Define the maximum number of dice to roll
#define MAX_DICE 10

// Define the maximum number of times to roll the dice
#define MAX_ROLLS 1000

// Define the configuration options
typedef struct {
  int num_dice;
  int num_rolls;
  int seed;
} config_t;

// Get the configuration options from the user
config_t get_config(void) {
  config_t config;

  printf("Enter the number of dice to roll (1-%d): ", MAX_DICE);
  scanf("%d", &config.num_dice);

  printf("Enter the number of times to roll the dice (1-%d): ", MAX_ROLLS);
  scanf("%d", &config.num_rolls);

  printf("Enter a seed for the random number generator (0 for system time): ");
  scanf("%d", &config.seed);

  return config;
}

// Roll the dice and print the results
void roll_dice(config_t config) {
  int i, j;
  int rolls[MAX_DICE][MAX_ROLLS];

  // Initialize the random number generator
  srand(config.seed);

  // Roll the dice
  for (i = 0; i < config.num_dice; i++) {
    for (j = 0; j < config.num_rolls; j++) {
      rolls[i][j] = rand() % SIDES + 1;
    }
  }

  // Print the results
  for (i = 0; i < config.num_dice; i++) {
    printf("Die %d: ", i + 1);
    for (j = 0; j < config.num_rolls; j++) {
      printf("%d ", rolls[i][j]);
    }
    printf("\n");
  }
}

// Main function
int main(void) {
  config_t config;

  // Get the configuration options from the user
  config = get_config();

  // Roll the dice and print the results
  roll_dice(config);

  return 0;
}