//FormAI DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold each auction item
typedef struct {
  char name[50];
  int startingPrice;
  int currentBid;
  char highestBidder[50];
  int isActive;
} AuctionItem;

// Function to display the main menu options
void displayMainMenu() {
  printf("Welcome to Digital Auction System!\n");
  printf("1. Auction an item\n");
  printf("2. View all active auctions\n");
  printf("3. Bid on an auction item\n");
  printf("4. Exit\n\n");
}

// Function to add an auction item to the system
void addAuctionItem(AuctionItem* items, int* itemCount) {
  AuctionItem newItem;
  printf("Enter the name of the item: ");
  scanf("%s", newItem.name);
  printf("Enter the starting price of the item: ");
  scanf("%d", &newItem.startingPrice);
  newItem.currentBid = newItem.startingPrice;
  printf("The current highest bidder for the item is: %s\n", newItem.highestBidder);
  newItem.isActive = 1;
  if (*itemCount == 0) {
    items = (AuctionItem*)malloc(sizeof(AuctionItem));
  } else {
    items = (AuctionItem*)realloc(items, (*itemCount + 1) * sizeof(AuctionItem));
  }
  items[*itemCount] = newItem;
  *itemCount += 1;
  printf("Item added successfully!\n");
}

// Function to view all active auction items
void viewActiveAuctions(AuctionItem* items, int itemCount) {
  printf("The following items are currently up for auction:\n");
  for (int i = 0; i < itemCount; i++) {
    if (items[i].isActive == 1) {
      printf("%d. %s\n", i+1, items[i].name);
    }
  }
}

// Function to place a bid on an auction item
void placeBid(AuctionItem* items, int itemCount) {
  int itemNumber;
  printf("Enter the number of the item you would like to bid on: ");
  scanf("%d", &itemNumber);
  if (itemNumber < 1 || itemNumber > itemCount) {
    printf("Invalid item number\n");
    return;
  }
  AuctionItem* item = &items[itemNumber - 1];
  if (item->isActive == 0) {
    printf("Item is no longer active for bidding\n");
    return;
  }
  int bidAmount;
  printf("Enter your bid amount: ");
  scanf("%d", &bidAmount);
  if (bidAmount <= item->currentBid) {
    printf("Bid amount must be higher than current bid of %d\n", item->currentBid);
    return;
  }
  char bidderName[50];
  printf("Enter your name: ");
  scanf("%s", bidderName);
  strcpy(item->highestBidder, bidderName);
  item->currentBid = bidAmount;
  printf("Bid accepted!\n");
}

int main() {
  int itemCount = 0;
  AuctionItem* items = NULL;
  int choice;
  do {
    displayMainMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addAuctionItem(items, &itemCount);
        break;
      case 2:
        viewActiveAuctions(items, itemCount);
        break;
      case 3:
        placeBid(items, itemCount);
        break;
      case 4:
        printf("Thank you for using Digital Auction System!\n");
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
    printf("\n");
  } while (choice != 4);

  free(items);
  return 0;
}