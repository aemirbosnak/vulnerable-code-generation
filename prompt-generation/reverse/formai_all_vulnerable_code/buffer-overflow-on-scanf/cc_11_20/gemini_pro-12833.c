//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Oh my, you want me to roll a dice? Sure, let's do it!

  // Initialize the random number generator (RNG) with the current time (surprised!)
  srand(time(NULL));

  // Declare and initialize the variables
  int num_rolls;
  int dice_sides;
  int roll_results[100]; // Let's store up to 100 rolls for fun

  // Prompt the user to enter the number of rolls and the number of sides on the dice
  printf("Whoa! How many times do you want me to roll this dice? (1-100): ");
  scanf("%d", &num_rolls);
  printf("And how many sides are we talking about here? (1-100): ");
  scanf("%d", &dice_sides);

  // Validate the user input (don't want any surprises!)
  if (num_rolls < 1 || num_rolls > 100) {
    printf("Hey, keep it reasonable! Number of rolls should be between 1 and 100.\n");
    return 1;
  }
  if (dice_sides < 1 || dice_sides > 100) {
    printf("Whoa, whoa, slow down there! Number of sides should be between 1 and 100.\n");
    return 1;
  }

  // Roll the dice and store the results
  for (int i = 0; i < num_rolls; i++) {
    // Roll the dice and store the result
    roll_results[i] = rand() % dice_sides + 1; // Surprises might be waiting!
  }

  // Show the results in a table (for your viewing pleasure)
  printf("\nHere are the results of your dice roll(s):\n");
  printf("-----------------------------------------\n");
  printf("Roll\t| Result\n");
  printf("-----------------------------------------\n");
  for (int i = 0; i < num_rolls; i++) {
    printf("%d\t| %d\n", i + 1, roll_results[i]);
  }
  printf("-----------------------------------------\n");

  // Surprise! Let's show the most common result
  int max_count = 0;
  int most_common_result = 0;
  for (int i = 0; i < num_rolls; i++) {
    int count = 0;
    for (int j = 0; j < num_rolls; j++) {
      if (roll_results[i] == roll_results[j]) {
        count++;
      }
    }
    if (count > max_count) {
      max_count = count;
      most_common_result = roll_results[i];
    }
  }
  printf("\nSurprise! The most common result was %d, occurring %d time(s).\n", most_common_result, max_count);

  return 0;
}