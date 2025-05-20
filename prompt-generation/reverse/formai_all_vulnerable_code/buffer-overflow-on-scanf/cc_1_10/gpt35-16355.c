//FormAI DATASET v1.0 Category: Digital Auction System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random bid amounts
int generateBidAmount() {
  srand(time(NULL));
  return rand() % 1000 + 1;
}

// Surrealist Auction structure
struct SurrealistAuction {
  char item[20];
  int minBid;
  int highestBid;
  char highestBidder[20];
};

int main() {
  // Create Surrealist Auction object
  struct SurrealistAuction auction;
  // Set item name and minimum bid amount
  printf("Enter the name of the item: ");
  scanf("%s", auction.item);
  printf("Enter the minimum bid amount (in dollars): ");
  scanf("%d", &auction.minBid);

  // Print auction details
  printf("\nThe Surrealist Auction for %s has started!\n", auction.item);
  printf("The minimum bid amount is %d dollars.\n\n", auction.minBid);

  // Loop until auction ends
  int isAuctionOver = 0;
  while (!isAuctionOver) {
    // Get new bid amount from user
    printf("Enter your bid amount (in dollars): ");
    int userBid;
    scanf("%d", &userBid);

    // Validate the bid amount
    if (userBid < auction.minBid) {
      printf("Your bid is lower than the minimum bid amount.\n");
      continue;
    }

    if (userBid <= auction.highestBid) {
      printf("Your bid is lower than the current highest bid.\n");
      continue;
    }

    // Update highest bid and bidder
    auction.highestBid = userBid;
    printf("Congratulations, you are now the highest bidder with a bid of %d dollars!\n", auction.highestBid);
    printf("Enter your name: ");
    char bidderName[20];
    scanf("%s", bidderName);
    sprintf(auction.highestBidder, "%s", bidderName);

    // Generate new bid amount for the next bidder
    auction.minBid = generateBidAmount();
    printf("\nThe minimum bid amount for the next bidder is: %d dollars\n\n", auction.minBid);

    // Check if auction is over
    printf("Enter 1 to end the auction or 0 to continue: ");
    int endAuction;
    scanf("%d", &endAuction);
    if (endAuction == 1) {
      isAuctionOver = 1;
    }
  }

  // Print the winner of the auction
  printf("\nThe Surrealist Auction for %s has ended.\n", auction.item);
  printf("The winner is %s with a bid of %d dollars!\n", auction.highestBidder, auction.highestBid);

  return 0;
}