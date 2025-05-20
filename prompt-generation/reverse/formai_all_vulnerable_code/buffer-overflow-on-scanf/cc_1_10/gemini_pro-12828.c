//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Welcome to the Dicey Domain!
  printf("Welcome to the Dicey Domain!\n");

  // Let's set the stage, shall we?
  printf("Gather 'round, folks, and prepare for a twist of fate.\n");
  printf("In this realm, the dice are our masters, and their whims are absolute.\n");

  // How many rolls shall we grace our lives with, traveler?
  int numRolls;
  printf("How many rolls do you seek, brave adventurer?\n");
  scanf("%d", &numRolls);

  // Let's get the dice rolling!
  srand(time(NULL)); // Seeding the chaos

  // The grand unveiling, where Destiny meets the Dice
  for (int i = 0; i < numRolls; i++) {
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    int total = die1 + die2;

    // The tale of two dice
    printf("Die 1: %d\n", die1);
    printf("Die 2: %d\n", die2);

    // Reveal the roll of Destiny!
    printf("Fate's Decree: %d\n", total);

    // A dash of wisdom with every roll
    switch (total) {
      case 2:
        printf("Two? A precarious balance, tread carefully.\n");
        break;
      case 7:
        printf("Seven! A touch of cosmic harmony, let its luck guide you.\n");
        break;
      case 12:
        printf("A dozen! A sign of grand fortune, embrace its power.\n");
        break;
      default:
        printf("May the whims of the dice be ever in your favor.\n");
    }
  }

  // Farewell, brave adventurer!
  printf("May your path be paved with favorable rolls, until we meet again!");

  return 0;
}