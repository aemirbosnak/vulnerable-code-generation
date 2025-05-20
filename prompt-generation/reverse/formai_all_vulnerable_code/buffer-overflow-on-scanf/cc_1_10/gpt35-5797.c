//FormAI DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_BIDS 10
#define MAX_NAME_LENGTH 20

// Function Declarations
void printItemInfo();
void startAuction();
void getNewBid();
void determineWinner();

// Global Variables
int currentBid = 0;
char winner[MAX_NAME_LENGTH];
int bids[MAX_BIDS];
char bidders[MAX_BIDS][MAX_NAME_LENGTH];
int numBids = 0;

// Main function
int main() {
  startAuction();
  getNewBid();
  determineWinner();
  return 0;
}

// Prints information about the item being auctioned
void printItemInfo() {
  printf("Welcome to our Digital Auction System!\n");
  printf("We are auctioning off a rare painting today.\n");
  printf("The starting bid is $500.\n");
}

// Starts the auction
void startAuction() {
  printItemInfo();
}

// Gets a new bid from the user
void getNewBid() {
  char name[MAX_NAME_LENGTH];
  int bidAmount;
  printf("Please enter your name: ");
  scanf("%s", name);
  printf("Please enter your bid: $");
  scanf("%d", &bidAmount);
  if (bidAmount > currentBid) {
    currentBid = bidAmount;
    strcpy(winner, name);
  }
  bids[numBids] = bidAmount;
  strcpy(bidders[numBids], name);
  numBids++;
  printf("Thank you, your bid has been submitted.\n");
}

// Determines the winner of the auction
void determineWinner() {
  printf("The auction is now closed.\n");
  if (numBids == 0) {
    printf("No bids were made.\n");
  } else {
    printf("The highest bid was $%d.\n", currentBid);
    printf("The winner is %s!\n", winner);
    printf("Here are the complete list of bids:\n");
    for (int i = 0; i < numBids; i++) {
      printf("%s: $%d\n", bidders[i], bids[i]);
    }
  }
}