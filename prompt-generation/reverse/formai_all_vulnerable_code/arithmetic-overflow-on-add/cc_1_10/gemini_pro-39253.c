//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int rollDie(int numSides) {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random number between 1 and numSides
  int roll = 1 + rand() % numSides;

  // Return the roll
  return roll;
}

// Function to roll a set of dice
int *rollDice(int numDice, int numSides) {
  // Allocate memory for the array of dice rolls
  int *rolls = malloc(sizeof(int) * numDice);

  // Roll each die and store the roll in the array
  for (int i = 0; i < numDice; i++) {
    rolls[i] = rollDie(numSides);
  }

  // Return the array of dice rolls
  return rolls;
}

// Function to print the results of a dice roll
void printDiceRoll(int *rolls, int numDice) {
  // Print the dice rolls
  for (int i = 0; i < numDice; i++) {
    printf("%d ", rolls[i]);
  }

  // Print a newline
  printf("\n");
}

// Function to get the sum of a set of dice rolls
int getDiceRollSum(int *rolls, int numDice) {
  // Initialize the sum to 0
  int sum = 0;

  // Add each roll to the sum
  for (int i = 0; i < numDice; i++) {
    sum += rolls[i];
  }

  // Return the sum
  return sum;
}

// Function to get the average of a set of dice rolls
double getDiceRollAverage(int *rolls, int numDice) {
  // Get the sum of the rolls
  int sum = getDiceRollSum(rolls, numDice);

  // Calculate the average
  double average = (double)sum / numDice;

  // Return the average
  return average;
}

// Function to get the maximum value of a set of dice rolls
int getDiceRollMax(int *rolls, int numDice) {
  // Initialize the max value to the first roll
  int max = rolls[0];

  // Iterate over the remaining rolls and update the max value if necessary
  for (int i = 1; i < numDice; i++) {
    if (rolls[i] > max) {
      max = rolls[i];
    }
  }

  // Return the max value
  return max;
}

// Function to get the minimum value of a set of dice rolls
int getDiceRollMin(int *rolls, int numDice) {
  // Initialize the min value to the first roll
  int min = rolls[0];

  // Iterate over the remaining rolls and update the min value if necessary
  for (int i = 1; i < numDice; i++) {
    if (rolls[i] < min) {
      min = rolls[i];
    }
  }

  // Return the min value
  return min;
}

// Function to print the statistics of a set of dice rolls
void printDiceRollStatistics(int *rolls, int numDice) {
  // Print the sum of the rolls
  int sum = getDiceRollSum(rolls, numDice);
  printf("Sum: %d\n", sum);

  // Print the average of the rolls
  double average = getDiceRollAverage(rolls, numDice);
  printf("Average: %.2f\n", average);

  // Print the maximum value of the rolls
  int max = getDiceRollMax(rolls, numDice);
  printf("Maximum: %d\n", max);

  // Print the minimum value of the rolls
  int min = getDiceRollMin(rolls, numDice);
  printf("Minimum: %d\n", min);
}

// Main function
int main() {
  // Get the number of dice to roll and the number of sides on each die
  int numDice;
  int numSides;
  printf("Enter the number of dice to roll: ");
  scanf("%d", &numDice);
  printf("Enter the number of sides on each die: ");
  scanf("%d", &numSides);

  // Roll the dice
  int *rolls = rollDice(numDice, numSides);

  // Print the results of the dice roll
  printDiceRoll(rolls, numDice);

  // Print the statistics of the dice roll
  printDiceRollStatistics(rolls, numDice);

  // Free the memory allocated for the array of dice rolls
  free(rolls);

  return 0;
}