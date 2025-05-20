//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
  char name[256];
  int bid;
} Bidder;

typedef struct {
  char name[256];
  int price;
} Item;

// Global variables
Bidder bidders[100];
Item items[100];
int num_bidders = 0;
int num_items = 0;

// Function declarations
void add_bidder(char *name);
void add_item(char *name, int price);
void start_auction();
void end_auction();

// Main function
int main() {
  // Initialize the auction system
  add_bidder("Alice");
  add_bidder("Bob");
  add_bidder("Charlie");

  add_item("Painting", 100);
  add_item("Sculpture", 200);
  add_item("Vase", 50);

  // Start the auction
  start_auction();

  // End the auction
  end_auction();

  return 0;
}

// Function definitions
void add_bidder(char *name) {
  strcpy(bidders[num_bidders].name, name);
  num_bidders++;
}

void add_item(char *name, int price) {
  strcpy(items[num_items].name, name);
  items[num_items].price = price;
  num_items++;
}

void start_auction() {
  printf("Welcome to the auction!\n");
  printf("There are %d items up for auction:\n", num_items);

  for (int i = 0; i < num_items; i++) {
    printf("  - %s (%d)\n", items[i].name, items[i].price);
  }

  printf("\nPlease enter your bids below:\n");

  for (int i = 0; i < num_bidders; i++) {
    printf("%s: ", bidders[i].name);
    scanf("%d", &bidders[i].bid);
  }
}

void end_auction() {
  printf("\nThe auction is now closed.\n");

  for (int i = 0; i < num_items; i++) {
    int highest_bid = 0;
    int highest_bidder = -1;

    for (int j = 0; j < num_bidders; j++) {
      if (bidders[j].bid > highest_bid) {
        highest_bid = bidders[j].bid;
        highest_bidder = j;
      }
    }

    if (highest_bidder == -1) {
      printf("No one bid on %s.\n", items[i].name);
    } else {
      printf("%s won %s for %d.\n", bidders[highest_bidder].name, items[i].name, highest_bid);
    }
  }
}