//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int price;
} Item;

typedef struct {
  char *name;
  int bid;
} Bidder;

int main() {
  // Create an array of items to be auctioned.
  Item items[] = {
    {"Mona Lisa", 1000000},
    {"Starry Night", 500000},
    {"The Scream", 250000},
    {"Guernica", 150000},
    {"Water Lilies", 100000}
  };
  const int num_items = sizeof(items) / sizeof(Item);

  // Create an array of bidders.
  Bidder bidders[] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Carol", 0},
    {"Dave", 0},
    {"Eve", 0}
  };
  const int num_bidders = sizeof(bidders) / sizeof(Bidder);

  // Start the auction.
  printf("Welcome to the auction!\n");
  for (int i = 0; i < num_items; i++) {
    printf("Item %d: %s\n", i + 1, items[i].name);
    printf("Starting price: $%d\n", items[i].price);

    // Get bids from the bidders.
    for (int j = 0; j < num_bidders; j++) {
      printf("%s, what is your bid?\n", bidders[j].name);
      scanf("%d", &bidders[j].bid);
    }

    // Find the highest bid.
    int highest_bid = 0;
    Bidder *highest_bidder = NULL;
    for (int j = 0; j < num_bidders; j++) {
      if (bidders[j].bid > highest_bid) {
        highest_bid = bidders[j].bid;
        highest_bidder = &bidders[j];
      }
    }

    // Print the winning bid.
    printf("The winning bid is $%d by %s!\n", highest_bid, highest_bidder->name);

    // Update the item's price.
    items[i].price = highest_bid;
  }

  // End the auction.
  printf("Thank you for participating in the auction!\n");

  return 0;
}