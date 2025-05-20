//FormAI DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BID 100

typedef struct {
  char name[50];
  int bid;
} Bidder;

Bidder bidders[MAX_BID];
int num_bidders = 0;
int current_highest_bid = 0;
char current_leader[50];

void add_bidder(char *name, int bid) {
  if (num_bidders < MAX_BID) {
    strcpy(bidders[num_bidders].name, name);
    bidders[num_bidders].bid = bid;
    num_bidders++;
    if (bid > current_highest_bid) {
      current_highest_bid = bid;
      strcpy(current_leader, name);
    }
    printf("Bid added successfully!\n");
  } else {
    printf("Max number of bidders reached!\n");
  }
}

void list_bidders() {
  printf("Current bidders:\n");
  for (int i = 0; i < num_bidders; i++) {
    printf("%s - $%d\n", bidders[i].name, bidders[i].bid);
  }
  printf("\n");
}

int main() {
  char name[50];
  int bid;

  while (1) {
    printf("Enter bidder name or 'done' to exit: ");
    scanf("%s", name);
    if (strcmp(name, "done") == 0) {
      break;
    }
    printf("Enter bid amount: $");
    scanf("%d", &bid);
    add_bidder(name, bid);
  }

  printf("\nAll biddings are closed!\n");
  printf("Current leader is %s with a bid of $%d\n", current_leader, current_highest_bid);

  return 0;
}