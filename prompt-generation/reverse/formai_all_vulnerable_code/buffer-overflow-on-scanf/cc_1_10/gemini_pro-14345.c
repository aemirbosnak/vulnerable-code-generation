//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our magical array of auction items, each a treasure to be won
char *items[] = {
  "Golden Chalice of Enchantment",
  "Potion of Dreamy Visions",
  "Wand of Arcane Supremacy",
  "Tome of Ancient Secrets",
  "Amulet of Fortune's Favor",
};

// The initial bid for each item, a starting point for our bidding frenzy
int initialBids[] = {100, 200, 300, 400, 500};

// An array to store our spirited bidders, each with a unique name and a thirst for treasure
char *bidders[] = {
  "Sir Reginald the Bold",
  "Lady Anya the Enchantress",
  "Master Eamon the Alchemist",
  "Sorcerer Zorath the Arcane",
  "Bard Ophelia the Melodious",
};

// The main event, where the bidding madness unfolds
int main() {
  // Set the stage for our auction, a grand bazaar of digital dreams
  printf("Welcome, valiant bidders, to the Curious C Digital Auction!\n");

  // Present our enchanting array of items, each a beacon of desire
  printf("\nBehold, the treasures up for grabs:\n");
  for (int i = 0; i < sizeof(items) / sizeof(char *); i++) {
    printf("%d. %s\n", i + 1, items[i]);
  }

  // Initialize our auction items with their starting bids
  int currentBids[sizeof(items) / sizeof(char *)];
  memcpy(currentBids, initialBids, sizeof(currentBids));

  // Time for the bidding frenzy to commence!
  int itemChoice, bidValue;
  char bidderName[100];

  while (1) {
    // Let our bidders choose their desired item, a prize they long to possess
    printf("\nWhich item's fate do you seek to alter, bold bidder? (1-%d, or 0 to quit)\n", sizeof(items) / sizeof(char *));
    scanf("%d", &itemChoice);

    // Check if they've had enough of the bidding game
    if (itemChoice == 0) {
      printf("\nThank you for gracing our auction with your presence!\n");
      return 0;
    }

    // A valid item choice? Let's proceed, my curious bidder!
    if (itemChoice > 0 && itemChoice <= sizeof(items) / sizeof(char *)) {
      // Gather their esteemed name, a mark they shall leave on this digital canvas
      printf("And what might your noble name be, valiant bidder?\n");
      scanf("%s", bidderName);

      // Time to make their bid, a testament to their desire for the item's embrace
      printf("Speak, %s, what is your bid for this %s?\n", bidderName, items[itemChoice - 1]);
      scanf("%d", &bidValue);

      // Ensure they've bid higher than the current price, or face the consequences of disappointment
      if (bidValue > currentBids[itemChoice - 1]) {
        // A new high bid, a triumph for this daring bidder!
        currentBids[itemChoice - 1] = bidValue;
        printf("Marvelous, %s! Your bid now stands as the highest for %s!\n", bidderName, items[itemChoice - 1]);
      } else {
        // Alas, their bid falls short, a moment of sorrow for this aspiring treasure hunter
        printf("Alas, %s, your bid is too timid. The current bid for %s remains %d.\n", bidderName, items[itemChoice - 1], currentBids[itemChoice - 1]);
      }
    } else {
      // An invalid choice, a path that leads to confusion
      printf("Your request confounds us, noble bidder. Please choose an item between 1 and %d.\n", sizeof(items) / sizeof(char *));
    }
  }

  return 0;
}