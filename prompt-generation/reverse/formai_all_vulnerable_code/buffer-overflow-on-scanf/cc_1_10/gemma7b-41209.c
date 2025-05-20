//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 100000

struct Bid {
  char name[50];
  int amount;
  struct Bid* next;
};

void insertBid(struct Bid** head, char* name, int amount) {
  struct Bid* newBid = (struct Bid*)malloc(sizeof(struct Bid));
  strcpy(newBid->name, name);
  newBid->amount = amount;
  newBid->next = NULL;

  if (*head == NULL) {
    *head = newBid;
  } else {
    (*head)->next = newBid;
  }
}

int main() {
  struct Bid* head = NULL;
  int currentBid = 0;
  char name[50];
  int amount;

  // Simulate a random number of bidders
  int numBidders = rand() % 10 + 1;

  // Create and insert bids
  for (int i = 0; i < numBidders; i++) {
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your bid: ");
    scanf("%d", &amount);

    insertBid(&head, name, amount);
  }

  // Find the highest bid
  struct Bid* highestBid = head;
  while (highestBid->next) {
    if (highestBid->amount > currentBid) {
      currentBid = highestBid->amount;
      highestBid = highestBid->next;
    } else {
      highestBid = highestBid->next;
    }
  }

  // Print the highest bid
  printf("The highest bid is: %d, by %s", currentBid, highestBid->name);

  return 0;
}