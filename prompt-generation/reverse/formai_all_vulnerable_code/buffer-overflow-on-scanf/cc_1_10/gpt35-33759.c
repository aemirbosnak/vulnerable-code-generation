//FormAI DATASET v1.0 Category: Digital Auction System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50
#define MIN_BID 10
#define MAX_BID 100

struct item {
  char name[ITEM_NAME_LENGTH];
  int current_bid;
  char highest_bidder[ITEM_NAME_LENGTH];
  int bid_count;
};

int num_items = 0;
struct item items[MAX_ITEMS];

void print_item(struct item i) {
  printf("Item: %s\n", i.name);
  printf("Current Bid: $%d\n", i.current_bid);
  printf("Highest Bidder: %s\n", i.highest_bidder);
  printf("Number of Bids: %d\n", i.bid_count);
}

void add_item() {
  if (num_items == MAX_ITEMS) {
    printf("Error: Maximum number of items has been reached\n");
    return;
  }

  struct item i;
  printf("Enter item name: ");
  scanf("%s", i.name);
  i.current_bid = 0;
  i.bid_count = 0;
  strcpy(i.highest_bidder, "None");

  items[num_items] = i;
  num_items++;

  printf("Item added successfully!\n");
}

int get_item_index(char *name) {
  for (int i = 0; i < num_items; i++) {
    if (strcmp(items[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

void place_bid() {
  printf("Enter item name: ");
  char item_name[ITEM_NAME_LENGTH];
  scanf("%s", item_name);

  int index = get_item_index(item_name);
  if (index == -1) {
    printf("Error: Item not found\n");
    return;
  }

  int bid_amount;
  printf("Enter bid amount ($%d - $%d): ", MIN_BID, MAX_BID);
  scanf("%d", &bid_amount);

  if (items[index].current_bid >= bid_amount) {
    printf("Error: Bid must be greater than current bid\n");
    return;
  }

  if (bid_amount < MIN_BID || bid_amount > MAX_BID) {
    printf("Error: Bid amount must be between $%d and $%d\n", MIN_BID, MAX_BID);
    return;
  }

  items[index].current_bid = bid_amount;
  strcpy(items[index].highest_bidder, "John Doe"); //TODO: replace with actual highest bidder name from user input
  items[index].bid_count++;

  printf("Bid placed successfully!\n");
}

void print_menu() {
  printf("\n--------------------------------------------------\n");
  printf("Digital Auction System\n");
  printf("--------------------------------------------------\n");
  printf("1. Add Item\n");
  printf("2. Place Bid\n");
  printf("3. List Items\n");
  printf("4. Exit\n");
  printf("--------------------------------------------------\n");
}

int main() {
  while (1) {
    print_menu();

    int user_choice;
    printf("Enter option number: ");
    scanf("%d", &user_choice);

    switch(user_choice) {
      case 1:
        add_item();
        break;
      case 2:
        place_bid();
        break;
      case 3:
        for (int i = 0; i < num_items; i++) {
          print_item(items[i]);
        }
        break;
      case 4:
        printf("Exiting program...\n");
        exit(0);
      default:
        printf("Error: Invalid option number\n");
        break;
    }
  }
  return 0;
}