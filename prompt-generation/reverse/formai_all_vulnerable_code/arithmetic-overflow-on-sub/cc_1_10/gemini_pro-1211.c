//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int rollDie() {
  // Initialize random number generator
  srand(time(NULL));

  // Generate a random number between 1 and 6
  int roll = rand() % 6 + 1;

  return roll;
}

// Function to roll multiple dice
int* rollDice(int numDice) {
  // Create an array to store the results of the dice rolls
  int* rolls = malloc(sizeof(int) * numDice);

  // Roll each die and store the result in the array
  for (int i = 0; i < numDice; i++) {
    rolls[i] = rollDie();
  }

  return rolls;
}

// Function to print the results of the dice rolls
void printDiceRolls(int* rolls, int numDice) {
  // Print the results of each die roll
  for (int i = 0; i < numDice; i++) {
    printf("Die %d: %d\n", i + 1, rolls[i]);
  }
}

// Function to get the sum of the dice rolls
int getDiceSum(int* rolls, int numDice) {
  // Calculate the sum of the dice rolls
  int sum = 0;
  for (int i = 0; i < numDice; i++) {
    sum += rolls[i];
  }

  return sum;
}

// Function to get the average of the dice rolls
double getDiceAverage(int* rolls, int numDice) {
  // Calculate the average of the dice rolls
  double average = (double)getDiceSum(rolls, numDice) / numDice;

  return average;
}

// Function to get the standard deviation of the dice rolls
double getDiceStandardDeviation(int* rolls, int numDice) {
  // Calculate the sum of the squared differences from the mean
  double sumOfSquaredDifferences = 0;
  double average = getDiceAverage(rolls, numDice);
  for (int i = 0; i < numDice; i++) {
    sumOfSquaredDifferences += pow(rolls[i] - average, 2);
  }

  // Calculate the standard deviation
  double standardDeviation = sqrt(sumOfSquaredDifferences / (numDice - 1));

  return standardDeviation;
}

// Main function
int main() {
  // Get the number of dice to roll from the user
  int numDice;
  printf("Enter the number of dice to roll: ");
  scanf("%d", &numDice);

  // Roll the dice
  int* rolls = rollDice(numDice);

  // Print the results of the dice rolls
  printf("Dice rolls:\n");
  printDiceRolls(rolls, numDice);

  // Get the sum of the dice rolls
  int sum = getDiceSum(rolls, numDice);
  printf("Sum of dice rolls: %d\n", sum);

  // Get the average of the dice rolls
  double average = getDiceAverage(rolls, numDice);
  printf("Average of dice rolls: %f\n", average);

  // Get the standard deviation of the dice rolls
  double standardDeviation = getDiceStandardDeviation(rolls, numDice);
  printf("Standard deviation of dice rolls: %f\n", standardDeviation);

  // Free the memory allocated for the dice rolls
  free(rolls);

  return 0;
}