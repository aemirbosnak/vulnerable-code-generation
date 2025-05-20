//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a die
int rollDie(int sides) {
  // Check if sides is valid
  if (sides <= 0) {
    printf("Error: Invalid number of sides for die.\n");
    return -1;
  }

  // Initialize random number generator
  srand(time(NULL));

  // Generate a random number between 1 and sides
  int roll = rand() % sides + 1;

  return roll;
}

// Function to play a game of dice
void playGame(int numDice, int sides) {
  // Check if numDice and sides are valid
  if (numDice <= 0 || sides <= 0) {
    printf("Error: Invalid parameters for game.\n");
    return;
  }

  // Initialize variables
  int total = 0;
  int rolls[numDice];

  // Roll the dice
  for (int i = 0; i < numDice; i++) {
    rolls[i] = rollDie(sides);
  }

  // Calculate the total
  for (int i = 0; i < numDice; i++) {
    total += rolls[i];
  }

  // Print the results
  printf("You rolled: ");
  for (int i = 0; i < numDice; i++) {
    printf("%d ", rolls[i]);
  }
  printf("\n");
  printf("Total: %d\n", total);
}

// Main function
int main() {
  // Get the number of dice and sides from the user
  int numDice, sides;
  printf("Enter the number of dice: ");
  scanf("%d", &numDice);
  printf("Enter the number of sides per die: ");
  scanf("%d", &sides);

  // Play the game
  playGame(numDice, sides);

  return 0;
}