//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define PARANOIA_LEVEL 10

int main(int argc, char * argv[])
{
  // Check for proper usage
  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s <number of dice>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse the number of dice
  int num_dice;
  if (sscanf(argv[1], "%d", &num_dice) != 1)
  {
    fprintf(stderr, "Invalid number of dice: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Check for valid number of dice
  if (num_dice < 1 || num_dice > 100)
  {
    fprintf(stderr, "Invalid number of dice: %d\n", num_dice);
    return EXIT_FAILURE;
  }

  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the dice
  int dice[num_dice];
  for (int i = 0; i < num_dice; i++)
  {
    dice[i] = 0;
  }

  // Roll the dice
  for (int i = 0; i < num_dice; i++)
  {
    // Generate a random number between 1 and 6
    int roll = rand() % 6 + 1;

    // Check if the roll is valid
    if (roll < 1 || roll > 6)
    {
      fprintf(stderr, "Invalid roll: %d\n", roll);
      return EXIT_FAILURE;
    }

    // Add the roll to the dice
    dice[i] += roll;
  }

  // Calculate the total
  int total = 0;
  for (int i = 0; i < num_dice; i++)
  {
    total += dice[i];
  }

  // Calculate the average
  double average = (double)total / num_dice;

  // Print the results
  printf("Number of dice: %d\n", num_dice);
  printf("Rolls: ");
  for (int i = 0; i < num_dice; i++)
  {
    printf("%d ", dice[i]);
  }
  printf("\n");
  printf("Total: %d\n", total);
  printf("Average: %.2f\n", average);

  return EXIT_SUCCESS;
}