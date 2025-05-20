//FormAI DATASET v1.0 Category: Digital Auction System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_BIDS 10
#define MAX_BID_LEN 50
#define MAX_NAME_LEN 20

struct Bid {
  char bidder[MAX_NAME_LEN];
  double amount;
};

int num_bids = 0;
struct Bid bids[MAX_BIDS];

void print_bids() {
  printf("\nCurrent bid list:\n");
  for (int i = 0; i < num_bids; i++) {
    printf("%s: $%.2f\n", bids[i].bidder, bids[i].amount);
  }
}

void place_bid() {
  // Make sure there's room for the bid
  if (num_bids >= MAX_BIDS) {
    printf("Sorry, no more bids can be placed.\n");
    return;
  }
  
  // Get bidder name and amount
  char bidder[MAX_NAME_LEN];
  double amount;
  printf("What is your name? ");
  scanf("%s", bidder);
  printf("What is your bid amount? $");
  scanf("%lf", &amount);
  
  // Check if the bid is higher than the current highest bid
  int highest_bid_index = -1;
  double highest_bid_amount = 0;
  for (int i = 0; i < num_bids; i++) {
    if (bids[i].amount > highest_bid_amount) {
      highest_bid_amount = bids[i].amount;
      highest_bid_index = i;
    }
  }
  if (amount <= highest_bid_amount) {
    printf("Sorry, your bid must be higher than the current highest bid of $%.2f.\n", highest_bid_amount);
    return;
  }
  
  // Add the bid to the list
  strncpy(bids[num_bids].bidder, bidder, MAX_NAME_LEN);
  bids[num_bids].amount = amount;
  num_bids++;
  printf("Bid placed successfully!\n");
}

int main() {
  char input[10];
  while (1) {
    // Display options
    printf("\nWhat would you like to do?\n");
    printf("1. Place a bid\n");
    printf("2. View current bids\n");
    printf("3. Exit program\n");
    printf("Enter a number: ");
    
    // Get user input
    scanf("%s", input);
    
    // Process input
    if (strcmp(input, "1") == 0) {
      place_bid();
    } else if (strcmp(input, "2") == 0) {
      print_bids();
    } else if (strcmp(input, "3") == 0) {
      printf("\nGoodbye!\n");
      break;
    } else {
      printf("\nInvalid input. Please enter a number 1-3.\n");
    }
  }
  
  return 0;
}