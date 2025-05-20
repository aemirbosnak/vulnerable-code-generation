//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int dice1, dice2, total;
  char names[2][20];

  // Set the random seed
  srand(time(NULL));

  // Get the players' names
  printf("My Dearest, what is thy name?\n");
  scanf("%s", names[0]);
  printf("And what is thy beloved's name?\n");
  scanf("%s", names[1]);

  // Roll the dice
  dice1 = rand() % 6 + 1;
  dice2 = rand() % 6 + 1;
  total = dice1 + dice2;

  // Display the results
  printf("My love, %s, thy dice has rolled a %d!\n", names[0], dice1);
  printf("And my darling, %s, thy dice has rolled a %d!\n", names[1], dice2);
  printf("Together, your dice have rolled a total of %d!\n", total);

  // Interpret the results
  if (total == 2) {
    printf("Alas, a deuce! Such misfortune!\n");
  } else if (total == 3) {
    printf("Three! A number of balance and harmony.\n");
  } else if (total == 4) {
    printf("Four! A number of stability and foundation.\n");
  } else if (total == 5) {
    printf("Five! A number of change and adventure.\n");
  } else if (total == 6) {
    printf("Six! A number of luck and fortune.\n");
  } else if (total == 7) {
    printf("Seven! A number of mystery and magic.\n");
  } else if (total == 8) {
    printf("Eight! A number of abundance and prosperity.\n");
  } else if (total == 9) {
    printf("Nine! A number of completion and fulfillment.\n");
  } else if (total == 10) {
    printf("Ten! A number of perfection and wholeness.\n");
  } else if (total == 11) {
    printf("Eleven! A number of intuition and insight.\n");
  } else if (total == 12) {
    printf("Twelve! A number of harmony and balance.\n");
  }

  // End the program
  printf("May the dice forever be in your favor, my loves.\n");
  return 0;
}