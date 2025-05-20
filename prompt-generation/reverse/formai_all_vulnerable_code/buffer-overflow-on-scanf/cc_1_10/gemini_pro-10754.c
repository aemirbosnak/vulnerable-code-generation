//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_SIDES 6
#define NUM_DICE 2

// Function to roll a single die
int rollDie() {
  return rand() % DICE_SIDES + 1;
}

// Function to roll multiple dice
int* rollDice(int numDice) {
  int* rolls = malloc(sizeof(int) * numDice);
  for (int i = 0; i < numDice; i++) {
    rolls[i] = rollDie();
  }
  return rolls;
}

// Function to print the results of a dice roll
void printDiceRoll(int* rolls, int numDice) {
  printf("You rolled: ");
  for (int i = 0; i < numDice; i++) {
    printf("%d ", rolls[i]);
  }
  printf("\n");
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the number of dice to roll from the user
  int numDice;
  printf("How many dice do you want to roll? ");
  scanf("%d", &numDice);

  // Roll the dice
  int* rolls = rollDice(numDice);

  // Print the results
  printDiceRoll(rolls, numDice);

  // Free the memory allocated for the rolls array
  free(rolls);

  return 0;
}