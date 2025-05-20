//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_cards = 0;
  char name[20];

  printf("Welcome to the Enchanted Oracle of Zoltan!\n");
  printf("Please provide your name: ");
  scanf("%s", name);

  printf("Greetings, %s, prepare for the cards of destiny.\n", name);

  // Shuffle the deck of cards
  srand(time(NULL));
  num_cards = rand() % 5 + 1;

  // Draw the cards
  printf("Your cards have been drawn: ");
  for (int i = 0; i < num_cards; i++) {
    switch (rand() % 4) {
      case 0:
        printf("Ace ");
        break;
      case 1:
        printf("Two ");
        break;
      case 2:
        printf("Three ");
        break;
      case 3:
        printf("Four ");
        break;
    }
  }

  // Interpret the cards
  switch (num_cards) {
    case 1:
      printf("One card suggests a path of destiny.\n");
      break;
    case 2:
      printf("Two cards foretell a crossroads.\n");
      break;
    case 3:
      printf("Three cards hint at a journey.\n");
      break;
    case 4:
      printf("Four cards promise fortune.\n");
      break;
    case 5:
      printf("Five cards bring wisdom.\n");
      break;
  }

  // Offer a prophecy
  printf("In the name of the Great Oracle, I prophesy that, %s, your future is bright. May the odds be ever in your favor.\n", name);

  return 0;
}