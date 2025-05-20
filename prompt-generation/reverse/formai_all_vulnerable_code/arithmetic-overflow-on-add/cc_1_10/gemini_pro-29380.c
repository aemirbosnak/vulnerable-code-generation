//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
  // Initialize the random number generator with the current time
  srand(time(NULL));

  // Read the number of dice to roll from the user
  int numDice;
  printf("How many dice do you want to roll? ");
  scanf("%d", &numDice);

  // Read the number of sides on each die from the user
  int numSides;
  printf("How many sides are on each die? ");
  scanf("%d", &numSides);

  // Roll the dice and store the results in an array
  int dice[numDice];
  for (int i = 0; i < numDice; i++) {
    dice[i] = rand() % numSides + 1;
  }

  // Display the results of the roll
  printf("You rolled:\n");
  for (int i = 0; i < numDice; i++) {
    printf("%d ", dice[i]);
  }
  printf("\n");

  // Calculate the total score of the roll
  int totalScore = 0;
  for (int i = 0; i < numDice; i++) {
    totalScore += dice[i];
  }

  // Display the total score of the roll
  printf("Your total score is %d.\n", totalScore);

  // Check if the user rolled a Yahtzee (all dice the same)
  int yahtzee = 1;
  for (int i = 1; i < numDice; i++) {
    if (dice[i] != dice[0]) {
      yahtzee = 0;
      break;
    }
  }

  // Display a message if the user rolled a Yahtzee
  if (yahtzee) {
    printf("Congratulations! You rolled a Yahtzee!\n");
  }

  return 0;
}