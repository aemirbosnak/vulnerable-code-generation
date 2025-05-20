//FormAI DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for the maximum number of items and bidders
#define MAX_AUCTION_ITEMS 10
#define MAX_BIDDERS 50

// Define a struct to represent an auction item
struct AuctionItem {
  char name[50];
  float starting_price;
  float current_bid;
  char current_bidder[50];
  int time_left;
  int item_id;
};

// Define a struct to represent a bidder
struct Bidder {
  char name[50];
  float balance;
  int num_bids;
  struct AuctionItem items_bid_on[MAX_AUCTION_ITEMS];
};

// Define functions to handle different actions in the auction system
void register_bidder(struct Bidder bidders[], int* num_bidders);
void add_item(struct AuctionItem auction_items[], int* num_items, struct Bidder bidders[], int num_bidders);
void place_bid(struct AuctionItem auction_items[], int num_items, struct Bidder bidders[], int num_bidders);
void display_items(struct AuctionItem auction_items[], int num_items);
void display_bidders(struct Bidder bidders[], int num_bidders);

int main() {
  // Seed the random number generator
  srand(time(0));
  
  // Initialize the array of auction items and number of items
  struct AuctionItem auction_items[MAX_AUCTION_ITEMS];
  int num_items = 0;
  
  // Initialize the array of bidders and number of bidders
  struct Bidder bidders[MAX_BIDDERS];
  int num_bidders = 0;
  
  // Display the options for the user
  printf("Welcome to the digital auction system!\n");
  printf("Please select an option:\n");
  printf("1. Register as a bidder\n");
  printf("2. Add an item for auction\n");
  printf("3. Place a bid\n");
  printf("4. Display auction items\n");
  printf("5. Display registered bidders\n");
  printf("6. Exit\n");
  
  // Loop until the user chooses to exit
  int choice;
  do {
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        register_bidder(bidders, &num_bidders);
        break;
      case 2:
        add_item(auction_items, &num_items, bidders, num_bidders);
        break;
      case 3:
        place_bid(auction_items, num_items, bidders, num_bidders);
        break;
      case 4:
        display_items(auction_items, num_items);
        break;
      case 5:
        display_bidders(bidders, num_bidders);
        break;
      case 6:
        printf("Thank you for using the digital auction system!\n");
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  } while (choice != 6);
  
  return 0;
}

void register_bidder(struct Bidder bidders[], int* num_bidders) {
  // Check if the maximum number of bidders has been reached
  if (*num_bidders >= MAX_BIDDERS) {
    printf("Maximum number of bidders exceeded\n");
    return;
  }
  
  // Get the name and balance of the new bidder
  printf("Enter bidder name: ");
  scanf("%s", bidders[*num_bidders].name);
  printf("Enter bidder balance: ");
  scanf("%f", &bidders[*num_bidders].balance);
  
  // Initialize the number of bids for the new bidder to 0
  bidders[*num_bidders].num_bids = 0;
  
  // Increment the number of bidders
  (*num_bidders)++;
  
  printf("Bidder registered successfully\n");
}

void add_item(struct AuctionItem auction_items[], int* num_items, struct Bidder bidders[], int num_bidders) {
  // Check if the maximum number of items has been reached
  if (*num_items >= MAX_AUCTION_ITEMS) {
    printf("Maximum number of items exceeded\n");
    return;
  }
  
  // Get the name and starting price of the new item
  printf("Enter item name: ");
  scanf("%s", auction_items[*num_items].name);
  printf("Enter item starting price: ");
  scanf("%f", &auction_items[*num_items].starting_price);
  
  // Set the current bid and bidder to the starting price and no bidder
  auction_items[*num_items].current_bid = auction_items[*num_items].starting_price;
  strcpy(auction_items[*num_items].current_bidder, "No bidder");
  
  // Generate a random time for the auction to end between 1 and 24 hours
  auction_items[*num_items].time_left = rand() % 24 + 1;
  
  // Assign a unique item ID
  auction_items[*num_items].item_id = *num_items + 1;
  
  // Increment the number of items
  (*num_items)++;
  
  printf("Item added successfully\n");
}

void place_bid(struct AuctionItem auction_items[], int num_items, struct Bidder bidders[], int num_bidders) {
  // Get the name of the bidder and item ID they want to bid on
  char bidder_name[50];
  int item_id;
  printf("Enter bidder name: ");
  scanf("%s", bidder_name);
  printf("Enter item ID: ");
  scanf("%d", &item_id);
  
  // Find the bidder in the array of bidders
  int bidder_index = -1;
  for (int i = 0; i < num_bidders; i++) {
    if (strcmp(bidders[i].name, bidder_name) == 0) {
      bidder_index = i;
      break;
    }
  }
  
  // Find the item in the array of auction items
  int item_index = -1;
  for (int i = 0; i < num_items; i++) {
    if (auction_items[i].item_id == item_id) {
      item_index = i;
      break;
    }
  }
  
  // Check if either the bidder or item was not found
  if (bidder_index == -1) {
    printf("Bidder not found\n");
    return;
  }
  if (item_index == -1) {
    printf("Item not found\n");
    return;
  }
  
  // Check if the bidder has already bid on this item
  for (int i = 0; i < bidders[bidder_index].num_bids; i++) {
    if (bidders[bidder_index].items_bid_on[i].item_id == item_id) {
      printf("Bidder has already bid on this item\n");
      return;
    }
  }
  
  // Check if the auction for this item has ended
  if (auction_items[item_index].time_left <= 0) {
    printf("Auction for this item has ended\n");
    return;
  }
  
  // Get the bid amount from the bidder
  float bid_amount;
  printf("Enter bid amount: ");
  scanf("%f", &bid_amount);
  
  // Check if the bid amount is higher than the current bid
  if (bid_amount <= auction_items[item_index].current_bid) {
    printf("Bid amount must be higher than current bid\n");
    return;
  }
  
  // Check if the bidder has enough balance to place the bid
  if (bid_amount > bidders[bidder_index].balance) {
    printf("Bidder does not have enough balance to place the bid\n");
    return;
  }
  
  // Update the current bid and bidder for the item
  auction_items[item_index].current_bid = bid_amount;
  strcpy(auction_items[item_index].current_bidder, bidder_name);
  
  // Add the item to the list of items the bidder has bid on
  bidders[bidder_index].items_bid_on[bidders[bidder_index].num_bids] = auction_items[item_index];
  bidders[bidder_index].num_bids++;
  
  // Subtract the bid amount from the bidder's balance
  bidders[bidder_index].balance -= bid_amount;
  
  printf("Bid placed successfully\n");
}

void display_items(struct AuctionItem auction_items[], int num_items) {
  printf("Auction items:\n");
  printf("Item ID\tName\tStarting Price\tCurrent Bid\tCurrent Bidder\tTime Left\n");
  for (int i = 0; i < num_items; i++) {
    printf("%d\t%s\t%.2f\t%.2f\t%s\t%d hours\n", auction_items[i].item_id, auction_items[i].name,
           auction_items[i].starting_price, auction_items[i].current_bid,
           auction_items[i].current_bidder, auction_items[i].time_left);
  }
}

void display_bidders(struct Bidder bidders[], int num_bidders) {
  printf("Registered bidders:\n");
  printf("Name\tBalance\tNumber of Bids\tItems Bid On\n");
  for (int i = 0; i < num_bidders; i++) {
    printf("%s\t%.2f\t%d\t", bidders[i].name, bidders[i].balance, bidders[i].num_bids);
    for (int j = 0; j < bidders[i].num_bids; j++) {
      printf("%s (bid %.2f), ", bidders[i].items_bid_on[j].name, bidders[i].items_bid_on[j].current_bid);
    }
    printf("\n");
  }
}