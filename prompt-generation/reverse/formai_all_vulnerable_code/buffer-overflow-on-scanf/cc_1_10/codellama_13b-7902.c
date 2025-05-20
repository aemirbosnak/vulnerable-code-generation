//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: cheerful
// Auction System in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store bid information
struct Bid {
  char name[30];
  int amount;
};

// Function to display bid information
void displayBid(struct Bid bid) {
  printf("Bidder: %s\n", bid.name);
  printf("Amount: %d\n", bid.amount);
}

// Function to get bid information
struct Bid getBid(char *name) {
  struct Bid bid;
  printf("Enter your name: ");
  scanf("%s", bid.name);
  printf("Enter your bid amount: ");
  scanf("%d", &bid.amount);
  return bid;
}

// Function to calculate the highest bid
int getHighestBid(struct Bid bid1, struct Bid bid2) {
  if (bid1.amount > bid2.amount) {
    return bid1.amount;
  } else {
    return bid2.amount;
  }
}

int main() {
  struct Bid bid1, bid2;
  int highestBid;

  // Get bid information for bidder 1
  bid1 = getBid("Bidder 1");
  displayBid(bid1);

  // Get bid information for bidder 2
  bid2 = getBid("Bidder 2");
  displayBid(bid2);

  // Calculate the highest bid
  highestBid = getHighestBid(bid1, bid2);
  printf("The highest bid is: %d\n", highestBid);

  return 0;
}