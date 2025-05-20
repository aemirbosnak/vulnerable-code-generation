//FormAI DATASET v1.0 Category: Digital Auction System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store bid information
typedef struct {
  char bidderName[30];
  int bidAmount;
} Bid;

// Function to display current bid information
void displayBid(Bid currentBid) {
  printf("Current bid: %d $ by %s\n", currentBid.bidAmount, currentBid.bidderName);
}

// Function to check if bid amount is valid
int isValidBid(Bid currentBid, int newBidAmount) {
  if (newBidAmount > currentBid.bidAmount) {
    return 1;
  }
  return 0;
}

// Function to update current bid information
Bid updateBid(Bid currentBid, char bidderName[], int newBidAmount) {
  strcpy(currentBid.bidderName, bidderName);
  currentBid.bidAmount = newBidAmount;
  return currentBid;
}

int main() {
  Bid currentBid = {"Nobody", 0}; // Initialize current bid to default values
  char bidderName[30];
  int newBidAmount;

  printf("Welcome to the digital auction system!\n\n");

  while (1) {
    printf("Current highest bid:\n");
    displayBid(currentBid);

    printf("Enter bidder name (or 'quit' to exit): ");
    scanf("%s", bidderName);
    if (!strcmp(bidderName, "quit")) {
      break;
    }

    printf("Enter bid amount: ");
    scanf("%d", &newBidAmount);
    if (isValidBid(currentBid, newBidAmount)) {
      currentBid = updateBid(currentBid, bidderName, newBidAmount);
      printf("Bid accepted!\n");
    } else {
      printf("Invalid bid amount. Please enter a higher bid.\n");
    }

    printf("\n");
  }

  printf("Auction closed. Final bid:\n");
  displayBid(currentBid);

  return 0;
}