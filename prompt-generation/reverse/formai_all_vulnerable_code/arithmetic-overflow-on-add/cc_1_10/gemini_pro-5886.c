//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define the maximum number of items in the auction
#define MAX_ITEMS 100

// Define the maximum number of bids for each item
#define MAX_BIDS 10

// Define the maximum length of an item name
#define MAX_NAME_LENGTH 100

// Define the maximum length of a bid amount
#define MAX_BID_AMOUNT_LENGTH 20

// Define the minimum bid amount
#define MIN_BID_AMOUNT 1.00

// Define the maximum bid amount
#define MAX_BID_AMOUNT 10000.00

// Define the auction status
enum auction_status {
  AUCTION_OPEN,
  AUCTION_CLOSED
};

// Define the item struct
struct item {
  int id;
  char name[MAX_NAME_LENGTH];
  double reserve_price;
  double highest_bid;
  int highest_bidder_id;
  bool sold;
};

// Define the bid struct
struct bid {
  int id;
  int item_id;
  double amount;
  int bidder_id;
};

// Define the auction struct
struct auction {
  int id;
  char name[MAX_NAME_LENGTH];
  time_t start_time;
  time_t end_time;
  enum auction_status status;
  struct item items[MAX_ITEMS];
  struct bid bids[MAX_BIDS];
  int num_items;
  int num_bids;
};

// Function to create a new auction
struct auction* create_auction(char* name, time_t start_time, time_t end_time) {
  // Allocate memory for the auction
  struct auction* auction = (struct auction*)malloc(sizeof(struct auction));

  // Set the auction properties
  strcpy(auction->name, name);
  auction->start_time = start_time;
  auction->end_time = end_time;
  auction->status = AUCTION_OPEN;
  auction->num_items = 0;
  auction->num_bids = 0;

  // Return the auction
  return auction;
}

// Function to add an item to the auction
void add_item(struct auction* auction, char* name, double reserve_price) {
  // Check if the auction is open
  if (auction->status != AUCTION_OPEN) {
    printf("Error: Auction is not open.\n");
    return;
  }

  // Check if the number of items has reached the maximum
  if (auction->num_items == MAX_ITEMS) {
    printf("Error: Maximum number of items reached.\n");
    return;
  }

  // Add the item to the auction
  strcpy(auction->items[auction->num_items].name, name);
  auction->items[auction->num_items].reserve_price = reserve_price;
  auction->items[auction->num_items].highest_bid = 0.00;
  auction->items[auction->num_items].highest_bidder_id = 0;
  auction->items[auction->num_items].sold = false;
  auction->num_items++;
}

// Function to place a bid on an item
void place_bid(struct auction* auction, int item_id, double amount, int bidder_id) {
  // Check if the auction is open
  if (auction->status != AUCTION_OPEN) {
    printf("Error: Auction is not open.\n");
    return;
  }

  // Check if the item exists
  if (item_id < 0 || item_id >= auction->num_items) {
    printf("Error: Item does not exist.\n");
    return;
  }

  // Check if the bid amount is valid
  if (amount < MIN_BID_AMOUNT || amount > MAX_BID_AMOUNT) {
    printf("Error: Bid amount is invalid.\n");
    return;
  }

  // Check if the bidder is valid
  if (bidder_id < 0) {
    printf("Error: Bidder is invalid.\n");
    return;
  }

  // Add the bid to the auction
  auction->bids[auction->num_bids].id = auction->num_bids;
  auction->bids[auction->num_bids].item_id = item_id;
  auction->bids[auction->num_bids].amount = amount;
  auction->bids[auction->num_bids].bidder_id = bidder_id;
  auction->num_bids++;

  // Update the highest bid for the item
  if (amount > auction->items[item_id].highest_bid) {
    auction->items[item_id].highest_bid = amount;
    auction->items[item_id].highest_bidder_id = bidder_id;
  }
}

// Function to close the auction
void close_auction(struct auction* auction) {
  // Check if the auction is already closed
  if (auction->status != AUCTION_OPEN) {
    printf("Error: Auction is already closed.\n");
    return;
  }

  // Set the auction status to closed
  auction->status = AUCTION_CLOSED;

  // Mark all unsold items as sold
  for (int i = 0; i < auction->num_items; i++) {
    if (!auction->items[i].sold) {
      auction->items[i].sold = true;
    }
  }
}

// Function to get the current time
time_t get_current_time() {
  return time(NULL);
}

// Function to print the auction details
void print_auction(struct auction* auction) {
  printf("Auction Name: %s\n", auction->name);
  printf("Start Time: %s\n", ctime(&auction->start_time));
  printf("End Time: %s\n", ctime(&auction->end_time));
  printf("Status: %s\n", auction->status == AUCTION_OPEN ? "Open" : "Closed");
  printf("\n");
  printf("Items:\n");
  for (int i = 0; i < auction->num_items; i++) {
    printf("  %d. %s\n", i + 1, auction->items[i].name);
    printf("    Reserve Price: %.2f\n", auction->items[i].reserve_price);
    printf("    Highest Bid: %.2f\n", auction->items[i].highest_bid);
    printf("    Highest Bidder: %d\n", auction->items[i].highest_bidder_id);
    printf("    Sold: %s\n", auction->items[i].sold ? "Yes" : "No");
    printf("\n");
  }
  printf("\n");
  printf("Bids:\n");
  for (int i = 0; i < auction->num_bids; i++) {
    printf("  %d. Item ID: %d, Amount: %.2f, Bidder ID: %d\n",
      i + 1, auction->bids[i].item_id, auction->bids[i].amount, auction->bids[i].bidder_id);
  }
}

// Main function
int main() {
  // Create an auction
  struct auction* auction = create_auction("My Auction", time(NULL) + 600, time(NULL) + 3600);

  // Add some items to the auction
  add_item(auction, "Item 1", 10.00);
  add_item(auction, "Item 2", 20.00);
  add_item(auction, "Item 3", 30.00);

  // Place some bids on the items
  place_bid(auction, 0, 11.00, 1);
  place_bid(auction, 1, 21.00, 2);
  place_bid(auction, 2, 31.00, 3);

  // Print the auction details
  print_auction(auction);

  // Close the auction
  close_auction(auction);

  // Print the auction details again
  print_auction(auction);

  return 0;
}