//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: expert-level
// Auction.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
  char* name;
  int bid;
} Bidder;

typedef struct {
  char* name;
  int price;
} Item;

// Functions
void addBidder(Bidder** bidder_list, int* bidder_count, char* name, int bid) {
  Bidder* new_bidder = (Bidder*)malloc(sizeof(Bidder));
  new_bidder->name = strdup(name);
  new_bidder->bid = bid;
  bidder_list[(*bidder_count)++] = new_bidder;
}

void addItem(Item** item_list, int* item_count, char* name, int price) {
  Item* new_item = (Item*)malloc(sizeof(Item));
  new_item->name = strdup(name);
  new_item->price = price;
  item_list[(*item_count)++] = new_item;
}

int bidderCount(Bidder** bidder_list) {
  int count = 0;
  for (int i = 0; bidder_list[i] != NULL; i++) {
    count++;
  }
  return count;
}

int itemCount(Item** item_list) {
  int count = 0;
  for (int i = 0; item_list[i] != NULL; i++) {
    count++;
  }
  return count;
}

void clearBidderList(Bidder** bidder_list) {
  for (int i = 0; bidder_list[i] != NULL; i++) {
    free(bidder_list[i]->name);
    free(bidder_list[i]);
  }
  free(bidder_list);
}

void clearItemList(Item** item_list) {
  for (int i = 0; item_list[i] != NULL; i++) {
    free(item_list[i]->name);
    free(item_list[i]);
  }
  free(item_list);
}

void printBidderList(Bidder** bidder_list) {
  for (int i = 0; bidder_list[i] != NULL; i++) {
    printf("Bidder %s with bid %d\n", bidder_list[i]->name, bidder_list[i]->bid);
  }
}

void printItemList(Item** item_list) {
  for (int i = 0; item_list[i] != NULL; i++) {
    printf("Item %s with price %d\n", item_list[i]->name, item_list[i]->price);
  }
}

int main() {
  // Initialize bidder and item lists
  Bidder** bidder_list = (Bidder**)malloc(sizeof(Bidder*));
  Item** item_list = (Item**)malloc(sizeof(Item*));
  int bidder_count = 0;
  int item_count = 0;

  // Add bidders and items
  addBidder(bidder_list, &bidder_count, "John", 100);
  addBidder(bidder_list, &bidder_count, "Jane", 200);
  addBidder(bidder_list, &bidder_count, "Bob", 300);
  addItem(item_list, &item_count, "Item 1", 100);
  addItem(item_list, &item_count, "Item 2", 200);
  addItem(item_list, &item_count, "Item 3", 300);

  // Print bidder and item lists
  printBidderList(bidder_list);
  printItemList(item_list);

  // Clear bidder and item lists
  clearBidderList(bidder_list);
  clearItemList(item_list);

  return 0;
}