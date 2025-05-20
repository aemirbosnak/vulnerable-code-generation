//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: interoperable
// Digital Auction System in Interoperable Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures
typedef struct {
  char* item;
  int starting_price;
  int reserve_price;
  int current_price;
  int bids;
  char* bidder;
  time_t bid_time;
} Auction;

typedef struct {
  char* username;
  char* password;
} User;

// Functions
void display_menu();
void create_auction(Auction* auction);
void bid(Auction* auction, User* user);
void view_auction(Auction* auction);
void close_auction(Auction* auction);

// Main Function
int main() {
  Auction auction;
  User user;

  display_menu();
  printf("Enter your choice: ");
  int choice;
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      create_auction(&auction);
      break;
    case 2:
      bid(&auction, &user);
      break;
    case 3:
      view_auction(&auction);
      break;
    case 4:
      close_auction(&auction);
      break;
    default:
      printf("Invalid choice!\n");
      break;
  }

  return 0;
}

// Function Definitions
void display_menu() {
  printf("Digital Auction System in Interoperable Style\n");
  printf("1. Create Auction\n");
  printf("2. Bid\n");
  printf("3. View Auction\n");
  printf("4. Close Auction\n");
}

void create_auction(Auction* auction) {
  printf("Enter item name: ");
  scanf("%s", auction->item);
  printf("Enter starting price: ");
  scanf("%d", &auction->starting_price);
  printf("Enter reserve price: ");
  scanf("%d", &auction->reserve_price);
  auction->current_price = auction->starting_price;
  auction->bids = 0;
}

void bid(Auction* auction, User* user) {
  printf("Enter bid amount: ");
  int bid_amount;
  scanf("%d", &bid_amount);
  if (bid_amount > auction->current_price) {
    auction->current_price = bid_amount;
    auction->bids++;
    printf("Bid placed successfully!\n");
  } else {
    printf("Bid amount is lower than current price.\n");
  }
}

void view_auction(Auction* auction) {
  printf("Item: %s\n", auction->item);
  printf("Starting price: %d\n", auction->starting_price);
  printf("Current price: %d\n", auction->current_price);
  printf("Bids: %d\n", auction->bids);
  printf("Highest bidder: %s\n", auction->bidder);
  printf("Bid time: %s\n", ctime(&auction->bid_time));
}

void close_auction(Auction* auction) {
  if (auction->current_price >= auction->reserve_price) {
    printf("Auction closed successfully!\n");
  } else {
    printf("Auction closed unsuccessfully.\n");
  }
}