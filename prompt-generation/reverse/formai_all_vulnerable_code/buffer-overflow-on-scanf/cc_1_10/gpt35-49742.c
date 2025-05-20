//FormAI DATASET v1.0 Category: Digital Auction System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BIDS 5 // maximum number of bids allowed per auction
#define MAX_AUCTIONS 3 // maximum number of auctions allowed

typedef struct {
  char name[50];
  int bidAmount;
} Bid;

typedef struct {
  int id;
  char item[100];
  int startingBid;
  bool open;
  Bid bids[MAX_BIDS];
  int numBids;
} Auction;

Auction auctions[MAX_AUCTIONS];
int numAuctions = 0;

void addAuction() {
  if (numAuctions == MAX_AUCTIONS) {
    printf("Max number of auctions reached.\n");
    return;
  }
  Auction newAuction;
  newAuction.id = numAuctions;
  printf("Enter item name: ");
  scanf("%s", newAuction.item);
  printf("Enter starting bid: $");
  scanf("%d", &newAuction.startingBid);
  newAuction.open = true;
  newAuction.numBids = 0;
  auctions[numAuctions++] = newAuction;
  printf("Auction created successfully.\n");
}

void bidOnAuction() {
  printf("Enter auction ID: ");
  int id;
  scanf("%d", &id);
  if (id < 0 || id >= numAuctions || auctions[id].open == false) {
    printf("Invalid auction ID.\n");
    return;
  }
  Auction* auction = &auctions[id];
  printf("Enter your name: ");
  char name[50];
  scanf("%s", name);
  printf("Enter your bid: $");
  int amount;
  scanf("%d", &amount);

  if (amount <= auction->startingBid) {
    printf("Bid must be higher than starting bid.\n");
    return;
  }
  if (auction->numBids == MAX_BIDS) {
    printf("Max number of bids reached for this auction.\n");
    return;
  }
  for (int i = 0; i < auction->numBids; i++) {
    if (strcmp(auction->bids[i].name, name) == 0) {
      printf("You have already placed a bid on this auction.\n");
      return;
    }
  }
  Bid newBid;
  strcpy(newBid.name, name);
  newBid.bidAmount = amount;
  auction->bids[auction->numBids++] = newBid;
  printf("Bid placed successfully.\n");
}

void closeAuction() {
  printf("Enter auction ID: ");
  int id;
  scanf("%d", &id);
  if (id < 0 || id >= numAuctions || auctions[id].open == false) {
    printf("Invalid auction ID or auction already closed.\n");
    return;
  }
  Auction* auction = &auctions[id];
  printf("Auction for item '%s' closed.\n", auction->item);
  printf("Winning bid: $%d by %s\n", 
          auction->bids[auction->numBids - 1].bidAmount,
          auction->bids[auction->numBids - 1].name);
  auction->open = false;
}

void printMenu() {
  printf("\n");
  printf("1. Add new auction\n");
  printf("2. Bid on auction\n");
  printf("3. Close auction\n");
  printf("4. Exit\n");
  printf("\nEnter choice: ");
}

int main() {
  int choice = 0;
  while (choice != 4) {
    printMenu();
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addAuction();
        break;
      case 2:
        bidOnAuction();
        break;
      case 3:
        closeAuction();
        break;
      case 4:
        // exit program
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  }
  return 0;
}