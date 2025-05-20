//FormAI DATASET v1.0 Category: Digital Auction System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEM_COUNT 5 // number of items for auction
#define BID_COUNT 3 // number of bids per item
#define NAME_LENGTH 20 // maximum length of bidder name

// Item struct
typedef struct item {
  int id;
  char name[20];
  float start_price;
  float current_bid;
  char highest_bidder[20];
} Item;

int main() {
  Item items[ITEM_COUNT]; // create array of items
  int i, j; // loop counters

  // initialize items
  for (i = 0; i < ITEM_COUNT; i++) {
    items[i].id = i + 1;
    sprintf(items[i].name, "Item %d", i + 1);
    items[i].start_price = (float)(rand() % 500 + 1); // generate random starting price between 1 and 500
    items[i].current_bid = items[i].start_price;
    strcpy(items[i].highest_bidder, "None");
  }

  // print item details
  printf("*** Auction Items ***\n");
  for (i = 0; i < ITEM_COUNT; i++) {
    printf("%d. %s - Starting Price: $%.2f\n", items[i].id, items[i].name, items[i].start_price);
  }

  // simulate bidding process
  for (i = 0; i < ITEM_COUNT; i++) { // iterate through items
    printf("\n*** Bidding for %s ***\n", items[i].name);
    for (j = 0; j < BID_COUNT; j++) { // iterate through bids
      char name[NAME_LENGTH];
      printf("Enter bidder name: ");
      scanf("%s", name);
      float bid;
      printf("Enter bid amount: $");
      scanf("%f", &bid);
      if (bid > items[i].current_bid) { // check if bid is higher than current bid
        items[i].current_bid = bid;
        strcpy(items[i].highest_bidder, name);
        printf("Bid accepted!\n");
      } else {
        printf("Bid must be higher than current bid of $%.2f\n", items[i].current_bid);
      }
    }
    printf("%s sold to %s for $%.2f\n", items[i].name, items[i].highest_bidder, items[i].current_bid);
  }

  return 0;
}