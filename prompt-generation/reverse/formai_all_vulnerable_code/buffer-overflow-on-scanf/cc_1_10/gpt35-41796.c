//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 100
#define MAX_ITEM_NAME 50

int main() {
  int bid_amounts[MAX_BIDS] = {0};
  char bid_names[MAX_BIDS][MAX_ITEM_NAME];
  int num_bids = 0;

  // Initialize random number generator
  srand(time(0));

  // Welcome message
  printf("Welcome to the Digital Auction System!\n");

  // Get user input
  int num_items;
  printf("Enter the number of items to auction: ");
  scanf("%d", &num_items);

  // Auction loop
  for (int i = 0; i < num_items; i++) {
    // Generate item name
    char item_name[MAX_ITEM_NAME];
    sprintf(item_name, "Item %d", i + 1);

    // Auction item
    printf("\nAuctioning %s\n", item_name);
    printf("Enter your name to bid: ");
    char name[MAX_ITEM_NAME];
    scanf("%s", name);
    int bid_amount;
    printf("Enter your bid amount (must be greater than previous bids): ");
    scanf("%d", &bid_amount);

    // Check bid amount
    if (bid_amount <= bid_amounts[num_bids - 1]) {
      printf("Your bid amount must be greater than previous bids!\n");
      i--;
      continue;
    }

    // Add bid to list
    bid_amounts[num_bids] = bid_amount;
    strcpy(bid_names[num_bids], name);
    num_bids++;

    // Print current bids
    printf("\nCurrent bids:\n");
    for (int j = 0; j < num_bids; j++) {
      printf("%s bid %d\n", bid_names[j], bid_amounts[j]);
    }

    // Generate random delay
    int delay = rand() % 5 + 1;
    printf("\nSold to %s for %d!\n", bid_names[num_bids - 1], bid_amounts[num_bids - 1]);
    printf("Please wait %d seconds for next item...\n", delay);
    sleep(delay);
  }

  // Auction complete
  printf("\nAuction complete!\n");
  return 0;
}