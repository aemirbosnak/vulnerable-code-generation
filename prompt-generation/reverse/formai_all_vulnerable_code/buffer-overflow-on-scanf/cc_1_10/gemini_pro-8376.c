//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the range of the dice roll
#define MIN_ROLL 1
#define MAX_ROLL 6

// Custom dice rolling function
int rollDice(int numDice) {
  // Validate the number of dice being rolled
  if (numDice < 1) {
    printf("Error: Invalid number of dice (%d). Must be greater than 0.\n", numDice);
    exit(1);
  }

  // Initialize the total roll value
  int totalRoll = 0;

  // Roll the dice and accumulate the total
  for (int i = 0; i < numDice; i++) {
    // Generate a random number within the range of the dice
    int roll = rand() % (MAX_ROLL - MIN_ROLL + 1) + MIN_ROLL;
    totalRoll += roll;
  }

  return totalRoll;
}

int main() {
  // Enable truly random numbers by seeding the random number generator
  srand(time(NULL));

  // Create a captivating narrative for rolling the dice
  printf("\nWelcome to the realm of chance and destiny!\n");
  printf("As you embark on this journey, you will encounter a magical dice with the power to shape your destiny.\n\n");

  // Get the number of dice the user wants to roll
  int numDice;
  printf("Enter the number of dice you wish to roll: ");
  scanf("%d", &numDice);

  // Perform the dice roll and reveal the outcome
  int totalRoll = rollDice(numDice);
  printf("\nAnd now, with a flick of your wrist, the dice tumble and dance across the ethereal void.\n");
  printf("The fates have decreed that the sum of your rolls is... %d\n\n", totalRoll);

  // Provide a poetic interpretation of the roll result
  switch (totalRoll) {
    case 2:
      printf("Ah, a humble beginning! The path ahead may require finesse and cunning.\n");
      break;
    case 7:
      printf("A balanced and harmonious roll. The universe whispers of great potential.\n");
      break;
    case 12:
      printf("A sign of great fortune! The stars align in your favor, bringing success and prosperity.\n");
      break;
    default:
      printf("An enigmatic outcome. Embrace the unknown, for the future holds both challenges and triumphs.\n");
      break;
  }

  // Conclude with a touch of whimsy and wonder
  printf("\nAs the echoes of the dice fade into silence, remember that every roll is a whisper from the cosmic tapestry.\n");
  printf("May your journey be filled with adventure, wonder, and the eternal embrace of destiny.\n");

  return 0;
}