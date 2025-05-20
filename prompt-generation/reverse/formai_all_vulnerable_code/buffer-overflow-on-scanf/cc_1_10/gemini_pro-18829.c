//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int rollDie() {
  // Seed the random number generator with the current time
  srand(time(NULL));

  // Generate a random number between 1 and 6
  int roll = rand() % 6 + 1;

  return roll;
}

// Function to roll multiple dice
int* rollDice(int numDice) {
  // Allocate memory for the array of dice rolls
  int* rolls = malloc(sizeof(int) * numDice);

  // Roll each die and store the result in the array
  for (int i = 0; i < numDice; i++) {
    rolls[i] = rollDie();
  }

  return rolls;
}

// Function to print the results of a dice roll
void printDiceRoll(int* rolls, int numDice) {
  // Print the results of each die roll
  for (int i = 0; i < numDice; i++) {
    printf("Die %d: %d\n", i + 1, rolls[i]);
  }
}

// Main function
int main() {
  // Get the number of dice to roll from the user
  int numDice;
  printf("How many dice would you like to roll? ");
  scanf("%d", &numDice);

  // Roll the dice
  int* rolls = rollDice(numDice);

  // Print the results of the dice roll
  printDiceRoll(rolls, numDice);

  // Free the memory allocated for the array of dice rolls
  free(rolls);

  return 0;
}