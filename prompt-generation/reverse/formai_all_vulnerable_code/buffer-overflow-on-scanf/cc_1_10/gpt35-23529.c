//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10

typedef struct {
  int id;
  char item_name[20];
  float base_price;
  float highest_bid;
  int seller_id;
  int num_bids;
  int buyer_ids[MAX_BIDS];
  float bids[MAX_BIDS];
} auction_item_t;

auction_item_t items[3];

int num_items = 3;

int find_item_by_id(int item_id) {
  for (int i = 0; i < num_items; i++) {
    if (items[i].id == item_id) {
      return i;
    }
  }

  return -1;
}

int main() {
  // Initialize item data
  items[0].id = 1;
  strcpy(items[0].item_name, "Macbook Pro");
  items[0].base_price = 1000.00;
  items[0].highest_bid = 1000.00;
  items[0].seller_id = 1;
  items[0].num_bids = 0;

  items[1].id = 2;
  strcpy(items[1].item_name, "iPhone XS");
  items[1].base_price = 600.00;
  items[1].highest_bid = 600.00;
  items[1].seller_id = 2;
  items[1].num_bids = 0;

  items[2].id = 3;
  strcpy(items[2].item_name, "Samsung Galaxy S10");
  items[2].base_price = 500.00;
  items[2].highest_bid = 500.00;
  items[2].seller_id = 3;
  items[2].num_bids = 0;

  // Print item info
  printf("Items for Auction:\n");
  printf("====================\n");
  for (int i = 0; i < num_items; i++) {
    printf("%d. %s (base price: $%.2f)\n", items[i].id, items[i].item_name, items[i].base_price);
  }
  printf("\n");

  // Get item id to bid on
  printf("Enter item id to bid on: ");
  int item_id;
  scanf("%d", &item_id);
  int item_index = find_item_by_id(item_id);
  if (item_index == -1) {
    printf("Invalid item id! Exiting...\n");
    return -1;
  }

  // Print item info
  printf("\n");
  printf("Item Info:\n");
  printf("==========\n");
  printf("Name: %s\n", items[item_index].item_name);
  printf("Base Price: $%.2f\n", items[item_index].base_price);
  printf("Highest Bid: $%.2f\n", items[item_index].highest_bid);
  printf("\n");

  // Get bid amount
  printf("Enter bid amount: ");
  float bid_amount;
  scanf("%f", &bid_amount);

  // Validate bid amount
  if (bid_amount <= items[item_index].highest_bid) {
    printf("Bid amount must be greater than highest bid! Exiting...\n");
    return -1;
  }

  // Update item data
  items[item_index].highest_bid = bid_amount;
  items[item_index].buyer_ids[items[item_index].num_bids] = rand() % 100 + 1;
  items[item_index].bids[items[item_index].num_bids] = bid_amount;
  items[item_index].num_bids++;

  // Print bid information
  printf("\n");
  printf("Bid Info:\n");
  printf("=========\n");
  printf("Item: %s\n", items[item_index].item_name);
  printf("Bidder Id: %d\n", items[item_index].buyer_ids[items[item_index].num_bids-1]);
  printf("Bid Amount: $%.2f\n", items[item_index].bids[items[item_index].num_bids-1]);

  return 0;
}