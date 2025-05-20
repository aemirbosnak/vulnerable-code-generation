//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

struct Bidder {
  char name[20];
  int bid;
  struct Bidder* next;
};

void addBidder(struct Bidder** head) {
  struct Bidder* newBidder = (struct Bidder*)malloc(sizeof(struct Bidder));
  printf("Enter your name: ");
  scanf("%s", newBidder->name);
  printf("Enter your bid: ");
  scanf("%d", &newBidder->bid);
  newBidder->next = *head;
  *head = newBidder;
}

void printBids(struct Bidder* head) {
  struct Bidder* currentBidder = head;
  printf("Bids:\n");
  while (currentBidder) {
    printf("%s: %d\n", currentBidder->name, currentBidder->bid);
    currentBidder = currentBidder->next;
  }
}

int main() {
  struct Bidder* head = NULL;
  int numBids = 0;

  printf("Welcome to the Digital Auction System!\n");

  // Add bidders
  while (numBids < 3) {
    addBidder(&head);
    numBids++;
  }

  // Print bids
  printBids(head);

  // Determine winner
  struct Bidder* winner = head;
  for (struct Bidder* currentBidder = head; currentBidder; currentBidder = currentBidder->next) {
    if (currentBidder->bid > winner->bid) {
      winner = currentBidder;
    }
  }

  // Announce winner
  printf("The winner is: %s with a bid of %d\n", winner->name, winner->bid);

  return 0;
}