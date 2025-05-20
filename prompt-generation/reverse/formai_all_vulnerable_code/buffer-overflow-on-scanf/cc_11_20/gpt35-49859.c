//FormAI DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 5

typedef struct {
  int id;
  char* name;
  float highest_bid;
  int bidder_id;
} Item;

typedef struct {
  int id;
  char* name;
  float budget;
  int bid_count;
  Item** items_bid_on;
} Bidder;

Bidder bidders[MAX_BIDDERS];
Item items[MAX_ITEMS];

int main() {

  /* Initialize bidders and items */

  for (int i = 0; i < MAX_BIDDERS; i++) {
    bidders[i].id = i + 1;
    bidders[i].name = malloc(sizeof(char) * 20);
    sprintf(bidders[i].name, "Bidder %d", i + 1);
    bidders[i].budget = (i + 1) * 1000;
    bidders[i].bid_count = 0;
    bidders[i].items_bid_on = malloc(sizeof(Item*) * MAX_ITEMS);
  }

  for (int i = 0; i < MAX_ITEMS; i++) {
    items[i].id = i + 1;
    items[i].name = malloc(sizeof(char) * 20);
    sprintf(items[i].name, "Item %d", i + 1);
    items[i].highest_bid = 0;
    items[i].bidder_id = 0;
  }

  /* Begin bidding process */

  printf("Welcome to the digital auction system!\n");
  printf("The following items are available for bidding:\n");

  for (int i = 0; i < MAX_ITEMS; i++) {
    printf("Item %d: %s\n", items[i].id, items[i].name);

    for (int j = 0; j < MAX_BIDDERS; j++) {
      if (bidders[j].budget >= items[i].highest_bid) {
        printf("%s can bid up to $%.2f on this item.\n", bidders[j].name, bidders[j].budget);
      }
    }

    float new_bid;
    int bidder_id;

    printf("Enter a new bid for %s: $", items[i].name);
    scanf("%f", &new_bid);

    printf("Enter the ID of the bidder making this bid: ");
    scanf("%d", &bidder_id);

    if (new_bid > items[i].highest_bid && bidder_id >= 1 && bidder_id <= 10) {
      items[i].highest_bid = new_bid;
      items[i].bidder_id = bidder_id;

      for (int j = 0; j < MAX_BIDDERS; j++) {
        if (bidders[j].id == bidder_id) {
          bidders[j].budget -= new_bid;
          bidders[j].bid_count++;
          bidders[j].items_bid_on[bidders[j].bid_count - 1] = &items[i];
        }
      }

      printf("Bid accepted!\n");
    } else {
      printf("Invalid bid.\n");
    }
  }

  /* Display bidding results */

  printf("\nBidding has ended! Here are the results:\n");

  for (int i = 0; i < MAX_ITEMS; i++) {
    printf("%s was sold to %s for $%.2f.\n", items[i].name, bidders[items[i].bidder_id - 1].name, items[i].highest_bid);
  }

  printf("\nBidders and their winning items:\n");

  for (int i = 0; i < MAX_BIDDERS; i++) {
    printf("%s won %d items for a total cost of $%.2f.\n", bidders[i].name, bidders[i].bid_count, (i + 1) * 1000 - bidders[i].budget);

    for (int j = 0; j < MAX_ITEMS; j++) {
      if (items[j].bidder_id == bidders[i].id) {
        printf("- %s for $%.2f\n", items[j].name, items[j].highest_bid);
      }
    }
  }

  /* Free memory */

  for (int i = 0; i < MAX_BIDDERS; i++) {
    free(bidders[i].name);
    free(bidders[i].items_bid_on);
  }

  for (int i = 0; i < MAX_ITEMS; i++) {
    free(items[i].name);
  }

  return 0;
}