//FormAI DATASET v1.0 Category: Dice Roller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int rollDice() {
  return rand() % 6 + 1; // Generates a number between 1 to 6
}

int main() {
  srand(time(NULL)); // Initializes the random number generator

  printf("Welcome to the Dice Roller!\n");
  printf("How many dice would you like to roll? ");

  int numberOfDice;
  scanf("%d", &numberOfDice); // Takes the user input of number of dice

  printf("How many sides does each die have? ");

  int numberOfSides;
  scanf("%d", &numberOfSides); // Takes the user input of number of sides

  int sum = 0;
  bool isDouble = true;
  int previousRoll = 0;

  // Rolls the dice and keeps track of the sum, double and previous roll
  for (int i = 0; i < numberOfDice; i++) {
    int roll = rollDice();
    printf("Dice %d: %d\n", i+1, roll);

    sum += roll;

    if (roll != previousRoll) {
      isDouble = false;
    }

    previousRoll = roll;
  }

  // Prints the sum and if it's a double or not
  printf("Sum of the rolls: %d\n", sum);

  if (isDouble) {
    printf("Congratulations, you rolled a double!\n");
  } else {
    printf("Better luck next time, no doubles were rolled.\n");
  }

  return 0;
}