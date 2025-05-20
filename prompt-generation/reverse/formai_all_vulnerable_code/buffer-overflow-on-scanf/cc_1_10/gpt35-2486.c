//FormAI DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_BIDS 5

int main() {
  // welcome message
  printf("Welcome to the Digital Auction!\n");

  // initialize variables
  int num_bids = 0;
  int bids[MAX_BIDS];

  // get user input
  printf("Enter your starting bid: ");
  scanf("%d", &bids[num_bids]);

  // check if starting bid is valid
  if (bids[num_bids] <= 0) {
    printf("Error: Starting bid must be greater than 0.\n");
    printf("Exiting program.\n");
    return 1;
  }

  // increase bid counter
  num_bids++;

  // start bidding loop
  while (num_bids < MAX_BIDS) {
    // display current bids
    printf("Current bids: ");
    for (int i = 0; i < num_bids; i++) {
      printf("%d ", bids[i]);
    }
    printf("\n");

    // get user input
    int new_bid;
    printf("Enter your bid: ");
    scanf("%d", &new_bid);

    // check if new bid is valid
    if (new_bid <= 0) {
      printf("Error: Bid must be greater than 0.\n");
      printf("Please enter a valid bid.\n");
      continue;
    } else if (new_bid <= bids[num_bids-1]) {
      printf("Error: Bid must be greater than previous highest bid.\n");
      printf("Please enter a valid bid.\n");
      continue;
    }

    // add new bid to array
    bids[num_bids] = new_bid;

    // increase bid counter
    num_bids++;

    // check if maximum number of bids has been reached
    if (num_bids == MAX_BIDS) {
      printf("Bidding is now closed.\n");
    }
  }

  // determine winning bid
  int winning_bid = bids[0];
  for (int i = 1; i < num_bids; i++) {
    if (bids[i] > winning_bid) {
      winning_bid = bids[i];
    }
  }

  // display winning bid
  printf("The winning bid is: %d\n", winning_bid);

  return 0;
}