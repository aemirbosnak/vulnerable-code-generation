//FormAI DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int num_items;
  printf("Welcome to the Digital Auction System!\n");
  printf("How many items are you auctioning off today?\n");
  scanf("%d", &num_items);

  // allocate memory for item names and prices
  char** item_names = (char**) malloc(num_items * sizeof(char*));
  int* item_prices = (int*) malloc(num_items * sizeof(int));

  // get the names and starting prices of each item
  for (int i = 0; i < num_items; i++) {
    printf("Item #%d: What is the name of the item?\n", i+1);
    char* name = (char*) malloc(50 * sizeof(char)); // allocate memory for name
    scanf("%s", name);
    item_names[i] = name;

    printf("What is the starting price of the item?\n");
    int price;
    scanf("%d", &price);
    item_prices[i] = price;
  }

  int num_bidders;
  printf("How many bidders are participating in the auction?\n");
  scanf("%d", &num_bidders);

  // allocate memory for bidder names and bids
  char** bidder_names = (char**) malloc(num_bidders * sizeof(char*));
  int** bidder_bids = (int**) malloc(num_bidders * sizeof(int*));
  for (int i = 0; i < num_bidders; i++) {
    bidder_bids[i] = (int*) malloc(num_items * sizeof(int));
  }

  // get the names of each bidder
  for (int i = 0; i < num_bidders; i++) {
    printf("Bidder #%d: What is your name?\n", i+1);
    char* name = (char*) malloc(50 * sizeof(char)); // allocate memory for name
    scanf("%s", name);
    bidder_names[i] = name;
  }

  // start the auction
  printf("The auction has begun!\n");
  int highest_bid;
  char* highest_bidder;
  int item_index = 0;

  while (1) {
    // display current item being auctioned and its starting price
    printf("\n-----------------------\n");
    printf("Item: %s\n", item_names[item_index]);
    printf("Starting Price: $%d\n", item_prices[item_index]);

    // display current bids for the item
    printf("Current Bids:\n");
    for (int i = 0; i < num_bidders; i++) {
      printf("%s: $%d\n", bidder_names[i], bidder_bids[i][item_index]);
    }

    // get bids from bidders
    for (int i = 0; i < num_bidders; i++) {
      printf("\n%s, what is your bid for this item?\n", bidder_names[i]);
      int bid;
      scanf("%d", &bid);

      // check if bid is higher than previous highest bid
      if (bid > item_prices[item_index] && bid > bidder_bids[i][item_index]) {
        item_prices[item_index] = bid;
        bidder_bids[i][item_index] = bid;
        highest_bid = bid;
        highest_bidder = bidder_names[i];
      }
    }

    // display highest bidder and bid for the item
    printf("\nThe highest bidder for this item is: %s\n", highest_bidder);
    printf("The highest bid for this item is: $%d\n", highest_bid);

    // ask if the auction should continue
    printf("\nWould you like to continue the auction? (Y/N)\n");
    char choice[5];
    scanf("%s", choice);

    if (strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0) {
      break;
    } else {
      item_index++;
      if (item_index >= num_items) {
        break;
      }
    }
  }

  // display final results
  printf("\n-----------------------\n");
  printf("The auction has ended!\n\n");
  for (int i = 0; i < num_items; i++) {
    printf("%s sold for: $%d\n", item_names[i], item_prices[i]);
  }

  // free memory
  for (int i = 0; i < num_items; i++) {
    free(item_names[i]);
  }
  free(item_names);
  free(item_prices);

  for (int i = 0; i < num_bidders; i++) {
    free(bidder_names[i]);
    free(bidder_bids[i]);
  }
  free(bidder_names);
  free(bidder_bids);

  return 0;
}