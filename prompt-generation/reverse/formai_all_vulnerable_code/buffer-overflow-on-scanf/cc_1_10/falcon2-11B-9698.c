//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize random seed
  srand(time(NULL));

  // Define auction parameters
  int numItems = 5;
  int maxBid = 100;

  // Initialize bids
  int bids[numItems];
  for (int i = 0; i < numItems; i++) {
    bids[i] = 0;
  }

  // Start the auction
  printf("Welcome to the Digital Auction!\n");
  printf("There are %d items up for auction.\n", numItems);
  printf("The maximum bid is %d.\n", maxBid);

  int itemNum = 0;
  while (itemNum < numItems) {
    int currentBid = bids[itemNum];
    int newBid = currentBid + 1;

    printf("Item %d is up for bid. Current bid is %d.\n", itemNum + 1, currentBid);
    printf("New bid: ");
    scanf("%d", &newBid);

    if (newBid > maxBid) {
      printf("Invalid bid. Maximum bid is %d.\n", maxBid);
      continue;
    }

    bids[itemNum] = newBid;
    itemNum++;
  }

  // Display the winners
  for (int i = 0; i < numItems; i++) {
    if (bids[i] == maxBid) {
      printf("Winner of item %d: ", i + 1);
      printf("%d\n", maxBid);
    }
  }

  return 0;
}