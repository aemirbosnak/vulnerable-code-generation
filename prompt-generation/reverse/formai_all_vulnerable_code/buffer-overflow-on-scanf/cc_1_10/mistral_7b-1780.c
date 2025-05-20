//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int rollDice(int numSides) {
  int result = 0;
  // Seed the random number generator
  srand(time(NULL));
  // Roll the dice
  result = rand() % numSides + 1;
  return result;
}

// Function to print out a funny message based on the dice roll
void printMessage(int roll) {
  switch (roll) {
    case 1:
      printf("You rolled a noble Number One, the Dice of Dawn!\n");
      break;
    case 2:
      printf("You rolled a sneaky Number Two, the Dice of Deception!\n");
      break;
    case 3:
      printf("You rolled a cunning Number Three, the Dice of Trickery!\n");
      break;
    case 4:
      printf("You rolled a witty Number Four, the Dice of Wit!\n");
      break;
    case 5:
      printf("You rolled a powerful Number Five, the Dice of Might!\n");
      break;
    case 6:
      printf("You rolled a legendary Number Six, the Dice of Legend!\n");
      break;
    default:
      printf("Error: Invalid dice roll!\n");
      break;
  }
}

int main() {
  int numRolls = 0;
  int numSides = 6;
  int roll = 0;

  printf("Welcome to The Dice Roller 3000, the most advanced dice rolling machine in the multiverse!\n");
  printf("How many dice do you want to roll? (Enter a number greater than zero)\n");
  scanf("%d", &numRolls);

  if (numRolls <= 0) {
    printf("Error: Invalid number of dice rolls!\n");
    return 1;
  }

  printf("How many sides does each die have? (Enter a number greater than zero)\n");
  scanf("%d", &numSides);

  if (numSides <= 0) {
    printf("Error: Invalid number of sides on the dice!\n");
    return 1;
  }

  printf("Rolling the dice...\n");

  for (int i = 0; i < numRolls; i++) {
    roll = rollDice(numSides);
    printMessage(roll);
  }

  printf("Roll complete! Have a nice day!\n");

  return 0;
}