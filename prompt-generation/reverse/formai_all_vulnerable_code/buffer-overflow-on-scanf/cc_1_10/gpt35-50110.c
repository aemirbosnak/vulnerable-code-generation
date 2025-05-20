//FormAI DATASET v1.0 Category: Digital Auction System ; Style: portable
// C Digital Auction System

#include<stdio.h>
#include<string.h>

// Structure to store each auction item
struct auctionItem {
  char name[50];
  char description[100];
  int currentBid;
  char highestBidder[50];
};

// Global variables
struct auctionItem items[10]; // Array of auction items
int numItems = 0; // Number of items in the auction

// Function to add a new item to the auction
void addItem() {
  char name[50];
  char description[100];
  int startingBid;

  // Get details of the new item from the user
  printf("Enter the name of the item: ");
  scanf("%s", name);
  printf("Enter a brief description of the item: ");
  scanf("%s", description);
  printf("Enter the starting bid: ");
  scanf("%d", &startingBid);

  // Create a new item with the details provided
  struct auctionItem newItem;
  strcpy(newItem.name, name);
  strcpy(newItem.description, description);
  newItem.currentBid = startingBid;
  strcpy(newItem.highestBidder, "");

  // Add the new item to the array of items
  items[numItems] = newItem;
  numItems++;

  printf("Item added to auction.\n");
}

// Function to display all items in the auction
void displayItems() {
  printf("Items in Auction:\n");
  for (int i = 0; i < numItems; i++) {
    printf("%d: %s - %s - Current Bid: %d - Highest Bidder: %s\n", i+1, items[i].name, items[i].description, items[i].currentBid, items[i].highestBidder);
  }
}

// Function to place a bid on an item
void placeBid() {
  int itemNum;
  int bidAmount;
  char bidderName[50];

  // Display all items in the auction
  displayItems();

  // Get the item number and bid details from the user
  printf("Enter the number of the item you wish to bid on: ");
  scanf("%d", &itemNum);
  printf("Enter your name: ");
  scanf("%s", bidderName);
  printf("Enter your bid amount: ");
  scanf("%d", &bidAmount);

  // Check if the bid is higher than the current bid for the item
  if (bidAmount <= items[itemNum-1].currentBid) {
    printf("Your bid was not high enough.\n");
    return;
  }

  // Update the item's current bid and highest bidder
  items[itemNum-1].currentBid = bidAmount;
  strcpy(items[itemNum-1].highestBidder, bidderName);

  printf("Bid placed.\n");
}

// Main function
int main() {
  int choice;

  do {
    // Display menu
    printf("\n\nDigital Auction System\n");
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Place Bid\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addItem();
        break;
      case 2:
        displayItems();
        break;
      case 3:
        placeBid();
        break;
      case 4:
        printf("Goodbye.\n");
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }

  } while (choice != 4);

  return 0;
}