//FormAI DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct bid {
  char name[20];
  int amount;
};

void insert_bid(struct bid *bids, int size) {
  printf("\nEnter bidder name: ");
  scanf("%s", bids[size].name);
  printf("Enter bid amount: ");
  scanf("%d", &bids[size].amount);
}

void highest_bid(struct bid *bids, int size) {
  int i, max_amount = 0;
  printf("\nBidder with highest bid: ");
  for (i = 0; i <= size; i++) {
    if (bids[i].amount > max_amount) {
      max_amount = bids[i].amount;
    }
  }
  for (i = 0; i <= size; i++) {
    if (bids[i].amount == max_amount) {
      printf("%s\n", bids[i].name);
    }
  }
}

void print_bids(struct bid *bids, int size) {
  int i;
  printf("\nBidders: \n");
  for (i = 0; i <= size; i++) {
    printf("%s: %d\n", bids[i].name, bids[i].amount);
  }
}

void bid(struct bid *bids, int size) {
  char choice;
  printf("\nYou are entering a bid...\n");
  insert_bid(bids, size);
  printf("Do you want to enter another bid? (y/n): ");
  scanf(" %c", &choice);
  if (choice == 'y') {
    bid(bids, size + 1);
  } else {
    printf("\nAll bids are in. Here are the results: \n");
    print_bids(bids, size);
    highest_bid(bids, size);
  }
}

int main() {
  int size = 0;
  struct bid bids[10];
  bid(bids, size);
  return 0;
}