//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: retro
// The Retro Digital Auction System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
  char name[20];
  int bid;
} Bidder;

typedef struct {
  char name[20];
  int price;
  Bidder* highest_bidder;
} Item;

// Function prototypes
void print_welcome_message();
void create_bidder(Bidder* bidder);
void create_item(Item* item);
void place_bid(Item* item, Bidder* bidder);
void print_highest_bidder(Item* item);
void print_goodbye_message();

// Main function
int main() {
  // Print welcome message
  print_welcome_message();

  // Create bidders
  Bidder bidder1;
  create_bidder(&bidder1);

  Bidder bidder2;
  create_bidder(&bidder2);

  // Create items
  Item item1;
  create_item(&item1);

  Item item2;
  create_item(&item2);

  // Place bids
  place_bid(&item1, &bidder1);
  place_bid(&item1, &bidder2);

  place_bid(&item2, &bidder1);
  place_bid(&item2, &bidder2);

  // Print highest bidders
  print_highest_bidder(&item1);
  print_highest_bidder(&item2);

  // Print goodbye message
  print_goodbye_message();

  return 0;
}

// Function definitions
void print_welcome_message() {
  printf("Welcome to the Retro Digital Auction System!\n");
  printf("=========================================\n\n");
}

void create_bidder(Bidder* bidder) {
  printf("Enter bidder name: ");
  scanf("%s", bidder->name);

  bidder->bid = 0;
}

void create_item(Item* item) {
  printf("Enter item name: ");
  scanf("%s", item->name);

  printf("Enter item price: ");
  scanf("%d", &item->price);

  item->highest_bidder = NULL;
}

void place_bid(Item* item, Bidder* bidder) {
  int bid;

  printf("%s, enter your bid for %s: ", bidder->name, item->name);
  scanf("%d", &bid);

  if (bid > item->price) {
    item->price = bid;
    item->highest_bidder = bidder;
  }
}

void print_highest_bidder(Item* item) {
  if (item->highest_bidder == NULL) {
    printf("No bids have been placed on %s.\n", item->name);
  } else {
    printf("The highest bidder for %s is %s with a bid of $%d.\n", item->name, item->highest_bidder->name, item->price);
  }
}

void print_goodbye_message() {
  printf("\nThank you for using the Retro Digital Auction System!\n");
}