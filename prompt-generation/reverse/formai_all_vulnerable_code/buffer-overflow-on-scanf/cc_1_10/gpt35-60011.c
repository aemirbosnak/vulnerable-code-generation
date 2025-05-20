//FormAI DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10 // Maximum number of bids allowed

// Auction item struct definition
typedef struct {
  char name[20];
  int starting_bid;
  int current_bid;
  char bidder[20];
} auction_item;

// Function prototypes
void initialize_item(auction_item *item, char *name, int starting_bid);
void display_item(auction_item item);
int get_bid(auction_item *item, char *name, int bid);

int main() {
  auction_item item1;
  initialize_item(&item1, "Football", 50);
  display_item(item1);
  
  int i;
  for (i = 1; i <= MAX_BIDS; i++) {
    char bidder[20];
    int bid;
    printf("Enter bidder name and bid amount: ");
    scanf("%s %d", bidder, &bid);
    
    if (get_bid(&item1, bidder, bid)) {
      printf("Congratulations, %s! You are the highest bidder.\n", bidder);
      display_item(item1);
      break;
    } else {
      printf("Sorry, %s. Your bid of %d is too low.\n", bidder, bid);
    }
  }
  
  if (i > MAX_BIDS) {
    printf("Auction ended with no winner.\n");
  }
  
  return 0;
}

// Initialize auction item with name and starting bid
void initialize_item(auction_item *item, char *name, int starting_bid) {
  strcpy(item->name, name);
  item->starting_bid = starting_bid;
  item->current_bid = starting_bid;
  strcpy(item->bidder, "None");
}

// Display auction item details
void display_item(auction_item item) {
  printf("\n%s\nStarting bid: $%d\nCurrent bid: $%d\nBidder: %s\n", item.name, item.starting_bid, item.current_bid, item.bidder);
}

// Update item with new bid if valid
int get_bid(auction_item *item, char *name, int bid) {
  if (bid > item->current_bid) {
    item->current_bid = bid;
    strcpy(item->bidder, name);
    return 1;
  } else {
    return 0;
  }
}