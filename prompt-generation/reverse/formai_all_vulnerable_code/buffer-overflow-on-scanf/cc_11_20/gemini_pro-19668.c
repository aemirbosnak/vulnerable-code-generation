//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numSides;
  int i, j;
  int diceRollTotal;
  int diceRollQty;
  int diceRollResult;
  int diceRollResults[100];
  int diceRollHistogram[100];

  srand(time(NULL));

  printf("OMG! Welcome to the Dice Roller Extravaganza!\n");
  printf("How many sides do your dice have, my friend? Choose wisely, for this will determine your destiny!\n");
  scanf("%d", &numSides);

  while (numSides < 1 || numSides > 100) {
    printf("Whoa, hold your horses there, partner! That's not a valid number of sides. Try again!\n");
    scanf("%d", &numSides);
  }

  printf("How many dice do you want to roll, brave adventurer? The more, the merrier!\n");
  scanf("%d", &diceRollQty);

  while (diceRollQty < 1 || diceRollQty > 100) {
    printf("Woah, there, buckaroo! That's not a valid number of dice. Try again!\n");
    scanf("%d", &diceRollQty);
  }

  diceRollTotal = 0;

  for (i = 0; i < diceRollQty; i++) {
    diceRollResult = rand() % numSides + 1;
    diceRollResults[i] = diceRollResult;
    diceRollTotal += diceRollResult;
  }

  printf("Prepare yourself for the grand unveiling! The dice have spoken, and their wisdom is revealed!\n");
  printf("Here are the results of your epic dice rolls:\n");

  for (i = 0; i < diceRollQty; i++) {
    printf("Dice %d: %d\n", i + 1, diceRollResults[i]);
  }

  printf("The grand total of your dice rolls is... drumroll please... %d!\n", diceRollTotal);

  for (i = 1; i <= numSides; i++) {
    diceRollHistogram[i - 1] = 0;
  }

  for (i = 0; i < diceRollQty; i++) {
    diceRollHistogram[diceRollResults[i] - 1]++;
  }

  printf("And now, for the pièce de résistance, the histogram of your dice rolls:\n");

  for (i = 1; i <= numSides; i++) {
    printf("Number %d: ", i);
    for (j = 0; j < diceRollHistogram[i - 1]; j++) {
      printf("*");
    }
    printf("\n");
  }

  printf("May the dice be ever in your favor, my friend! Until next time, may your rolls be spectacular!\n");

  return 0;
}