//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 1000

// Define a structure for Auction Item
struct AuctionItem {
  int item_id;
  char item_name[50];
  char item_description[100];
  float item_price;
  int bid_amount;
  char highest_bidder[50];
};

// Function prototypes
int display_menu();
void add_auction_item(struct AuctionItem items[], int size);
void list_auction_items(struct AuctionItem items[], int size);
void bid_on_item(struct AuctionItem items[], int size, int item_id, char bidder_name[50]);
void display_highest_bidder(struct AuctionItem items[], int size, int item_id);
void print_separator();

int main() {
  int option, item_id;
  char bidder_name[50];
  struct AuctionItem items[MAX_BID];
  int num_items = 0;
  srand(time(NULL)); // Set random seed value

  do {
    option = display_menu();

    switch(option) {
      case 1:
        add_auction_item(items, num_items);
        num_items++;
        print_separator();
        break;
      case 2:
        list_auction_items(items, num_items);
        print_separator();
        break;
      case 3:
        printf("Enter the Item ID that you want to bid on: ");
        scanf("%d", &item_id);
        printf("Enter your name: ");
        scanf("%s", bidder_name);
        bid_on_item(items, num_items, item_id, bidder_name);
        print_separator();
        break;
      case 4:
        printf("Enter the Item ID whose highest bidder you want to know: ");
        scanf("%d", &item_id);
        display_highest_bidder(items, num_items, item_id);
        print_separator();
        break;
      case 5:
        printf("Exiting the Auction System. Goodbye!\n");
        break;
      default:
        printf("Invalid option. Please try again.\n");
        print_separator();
    }
  } while(option != 5);

  return 0;
}

// Function to display the options menu
int display_menu() {
  int option;
  printf("C Digital Auction System\n");
  printf("1. Add an Auction Item\n");
  printf("2. List all Auction Items\n");
  printf("3. Bid on an Item\n");
  printf("4. Display Highest Bidder for an Item\n");
  printf("5. Exit\n");
  printf("Enter your option: ");
  scanf("%d", &option);
  return option;
}

// Function to add an Auction Item to the list
void add_auction_item(struct AuctionItem items[], int size) {
  items[size].item_id = size + 1; // Auto-increment item_id
  printf("Enter Item Name: ");
  scanf("%s", items[size].item_name);
  printf("Enter Item Description: ");
  scanf("%s", items[size].item_description);
  printf("Enter Item Price: ");
  scanf("%f", &items[size].item_price);
  items[size].bid_amount = 0; // Default bid_amount is 0
  strcpy(items[size].highest_bidder, "None"); // Default highest_bidder is None
  printf("Item Added Successfully!\n");
}

// Function to list all Auction Items
void list_auction_items(struct AuctionItem items[], int size) {
  printf("ID   NAME                 PRICE       BID AMOUNT  HIGHEST BIDDER\n");
  printf("-----------------------------------------------------------------\n");
  for(int i=0; i<size; i++) {
    printf("%-4d %-20s %-11.2f %-11d %-20s\n", items[i].item_id, items[i].item_name, items[i].item_price, items[i].bid_amount, items[i].highest_bidder);
  }
}

// Function to bid on an Item
void bid_on_item(struct AuctionItem items[], int size, int item_id, char bidder_name[50]) {
  // Check if item_id is valid
  if(item_id <= 0 || item_id > size) {
    printf("Invalid Item ID.\n");
    return;
  }

  // Get the item to bid on
  struct AuctionItem item = items[item_id-1];

  // Get the bid amount
  int bid_amount;
  printf("Enter Bid Amount: ");
  scanf("%d", &bid_amount);

  // Check if Bid Amount is greater than Item Price and the Previous Bid Amount
  if(bid_amount > item.item_price && bid_amount > item.bid_amount) {
    item.bid_amount = bid_amount; // Update the Bid Amount
    strcpy(item.highest_bidder, bidder_name); // Update the Highest Bidder
    items[item_id-1] = item; // Update the Item in the Array
    printf("Bid Placed Successfully! Congratulations %s, you are the highest bidder.\n", bidder_name);
  } else {
    printf("Sorry, your bid is not high enough. Please try again with a higher amount.\n");
  }
}

// Function to display the Highest Bidder for an Item
void display_highest_bidder(struct AuctionItem items[], int size, int item_id) {
  // Check if item_id is valid
  if(item_id <= 0 || item_id > size) {
    printf("Invalid Item ID.\n");
    return;
  }

  // Get the item to display highest bidder for
  struct AuctionItem item = items[item_id-1];

  // Display the Highest Bidder for the Item
  if(strcmp(item.highest_bidder, "None") != 0) {
    printf("The highest bidder for %s is %s with a bid amount of %d.\n", item.item_name, item.highest_bidder, item.bid_amount);
  } else {
    printf("No bids have been placed for %s yet.\n", item.item_name);
  }
}

// Function to print a separator line
void print_separator() {
  printf("-----------------------------------------------------------------\n");
}