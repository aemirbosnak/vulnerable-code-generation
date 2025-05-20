//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // We're going to let the user roll some bones, baby!

  // Let's get some random numbers going, shall we?
  srand(time(NULL));

  // How many dice do you want to roll, big shot?
  int num_dice;
  printf("How many dice do you want to roll, you dice-rolling fiend?\n");
  scanf("%d", &num_dice);

  // You want to roll how many dice again?
  if (num_dice < 1 || num_dice > 100) {
    printf("Hey, no funny business! You can only roll between 1 and 100 dice.\n");
    return 1;
  }

  // Let's gather an army of dice!
  int dice[num_dice];

  // Time to shake 'em up!
  for (int i = 0; i < num_dice; i++) {
    dice[i] = rand() % 6 + 1;
  }

  // Now, let's show off our mighty dice rolls!
  printf("Behold, your dice-rolling extravaganza:\n");
  for (int i = 0; i < num_dice; i++) {
    printf("Die %d: %d\n", i + 1, dice[i]);
  }

  // Calculate the total roll.
  int total = 0;
  for (int i = 0; i < num_dice; i++) {
    total += dice[i];
  }

  // Time to reveal the grand total!
  printf("And the grand total is... drumroll please...\n");
  printf("... %d!\n", total);

  // Did you get lucky, punk?
  if (total == num_dice * 6) {
    printf("Wow, you're on a roll! You got all sixes!\n");
  } else if (total == num_dice) {
    printf("Aww, bummer. You got all ones. Better luck next time!\n");
  } else {
    printf("Not bad, not bad. Keep on rolling!\n");
  }

  return 0;
}