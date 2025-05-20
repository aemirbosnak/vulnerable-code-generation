//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides for the dice
#define NUM_SIDES 6

// Define the maximum number of dice to roll
#define MAX_DICE 10

// Function to generate a random number between 1 and the number of sides
int roll_die(int num_sides)
{
  // Seed the random number generator with the current time
  srand(time(NULL));

  // Generate a random number between 1 and the number of sides
  int roll = rand() % num_sides + 1;

  return roll;
}

// Function to roll a set of dice and return the sum of the rolls
int roll_dice(int num_dice, int num_sides)
{
  int sum = 0;

  // Roll each die and add the result to the sum
  for (int i = 0; i < num_dice; i++)
  {
    sum += roll_die(num_sides);
  }

  return sum;
}

// Main function
int main()
{
  // Get the number of dice and the number of sides from the user
  int num_dice, num_sides;
  printf("Enter the number of dice: ");
  scanf("%d", &num_dice);
  printf("Enter the number of sides per die: ");
  scanf("%d", &num_sides);

  // Ensure the user input is valid
  if (num_dice < 1 || num_dice > MAX_DICE)
  {
    printf("Invalid number of dice. Please enter a number between 1 and %d.\n", MAX_DICE);
    return 1;
  }
  if (num_sides < 2)
  {
    printf("Invalid number of sides. Please enter a number greater than 1.\n");
    return 1;
  }

  // Roll the dice and display the sum of the rolls
  int sum = roll_dice(num_dice, num_sides);
  printf("The sum of the rolls is: %d\n", sum);

  return 0;
}