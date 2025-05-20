//FormAI DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a macro for the maximum number of bids allowed
#define MAX_BIDS 10

// Define a struct for a bid
struct Bid {
  int bidder_id;
  float amount;
};

// Define a struct for an item
struct Item {
  int item_id;
  char name[100];
  float starting_price;
  struct Bid bids[MAX_BIDS];
  int num_bids;
};

// Declare global variables
struct Item items[10];
int num_items = 0;

// Function to print the menu options
void print_menu() {
  printf("1. Add item\n");
  printf("2. List items\n");
  printf("3. Place bid\n");
  printf("4. List bids for item\n");
  printf("5. Exit\n");
}

// Function to add an item to the auction system
void add_item() {
  printf("Enter item name: ");
  scanf("%s", items[num_items].name);
  printf("Enter starting price: ");
  scanf("%f", &items[num_items].starting_price);
  items[num_items].item_id = num_items + 1;
  items[num_items].num_bids = 0;
  num_items++;
  printf("Item added!\n");
}

// Function to list all the items in the auction system
void list_items() {
  printf("Items:\n");
  for (int i = 0; i < num_items; i++) {
    printf("%d. %s ($%.2f)\n", items[i].item_id, items[i].name, items[i].starting_price);
  }
}

// Function to place a bid on an item
void place_bid() {
  int item_id, bidder_id;
  float amount;
  
  // Get the item ID from the user
  printf("Enter item ID: ");
  scanf("%d", &item_id);
  
  // Find the item in the array
  int idx = item_id - 1;
  if (idx < 0 || idx >= num_items) {
    printf("Invalid item ID!\n");
    return;
  }
  
  // Get the bidder ID from the user
  printf("Enter bidder ID: ");
  scanf("%d", &bidder_id);
  
  // Check if the bidder has already placed a bid on the item
  for (int i = 0; i < items[idx].num_bids; i++) {
    if (items[idx].bids[i].bidder_id == bidder_id) {
      printf("Bidder has already placed a bid on this item!\n");
      return;
    }
  }
  
  // Get the bid amount from the user
  printf("Enter bid amount: ");
  scanf("%f", &amount);
  
  // Check if the bid is higher than the starting price and the previous highest bid
  if (amount <= items[idx].starting_price) {
    printf("Bid is too low!\n");
    return;
  }
  for (int i = 0; i < items[idx].num_bids; i++) {
    if (amount <= items[idx].bids[i].amount) {
      printf("Bid is too low!\n");
      return;
    }
  }
  
  // Add the bid to the item's bids array
  struct Bid bid = {bidder_id, amount};
  items[idx].bids[items[idx].num_bids] = bid;
  items[idx].num_bids++;
  
  printf("Bid placed!\n");
}

// Function to list all the bids for an item
void list_bids() {
  int item_id;
  
  // Get the item ID from the user
  printf("Enter item ID: ");
  scanf("%d", &item_id);
  
  // Find the item in the array
  int idx = item_id - 1;
  if (idx < 0 || idx >= num_items) {
    printf("Invalid item ID!\n");
    return;
  }
  
  // Print each bid for the item
  printf("Bids for %s:\n", items[idx].name);
  for (int i = 0; i < items[idx].num_bids; i++) {
    printf("%d. Bidder ID: %d, Amount: $%.2f\n", i+1, items[idx].bids[i].bidder_id, items[idx].bids[i].amount);
  }
}

int main() {
  srand(time(NULL));
  
  int option = 0;
  
  while (option != 5) {
    print_menu();
    printf("Enter option: ");
    scanf("%d", &option);
    switch (option) {
      case 1:
        add_item();
        break;
      case 2:
        list_items();
        break;
      case 3:
        place_bid();
        break;
      case 4:
        list_bids();
        break;
      case 5:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid option!\n");
        break;
    }
  }
  
  return 0;
}