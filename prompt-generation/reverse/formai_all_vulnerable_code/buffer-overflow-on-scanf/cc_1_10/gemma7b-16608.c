//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

typedef struct Bidder {
  char name[20];
  int bid;
  struct Bidder *next;
} Bidder;

void insertBidder(Bidder **head, char *name, int bid) {
  Bidder *newBidder = malloc(sizeof(Bidder));
  strcpy(newBidder->name, name);
  newBidder->bid = bid;
  newBidder->next = NULL;

  if (*head == NULL) {
    *head = newBidder;
  } else {
    (*head)->next = newBidder;
  }
}

int main() {
  Bidder *head = NULL;
  int auction_id = 1;
  int current_bid = 0;
  char item_name[20];

  printf("Welcome to the C Digital Auction System!\n");

  // Get item name
  printf("Enter item name: ");
  scanf("%s", item_name);

  // Insert bidders
  insertBidder(&head, "John Doe", 5000);
  insertBidder(&head, "Jane Doe", 6000);
  insertBidder(&head, "Peter Pan", 7000);

  // Start bidding
  printf("Bidding starts! Enter your bid: ");
  scanf("%d", &current_bid);

  // Increment auction id and check if the bid is valid
  auction_id++;
  if (current_bid > MAX_BID) {
    printf("Error: Bid exceeds maximum limit.\n");
  } else {
    // Update the current bid and print the winner
    current_bid = MAX_BID;
    printf("Congratulations, %s, you won the auction for %s with a bid of %d.\n", head->name, item_name, current_bid);
  }

  return 0;
}