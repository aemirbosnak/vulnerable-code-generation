//FormAI DATASET v1.0 Category: Digital Auction System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BIDDERS 10
#define MAX_BID_LENGTH 10

char bidders[MAX_BIDDERS][MAX_BID_LENGTH]; // list of all bidders
int bids[MAX_BIDDERS] = {0}; // list of all bids
int num_bidders = 0; // number of active bidders
int winning_bid = 0; // current winning bid

// function to add a new bidder to the list
void addBidder(char *name) {
  if (num_bidders >= MAX_BIDDERS) {
    printf("Sorry, the maximum number of bidders has been reached.\n");
    return;
  }
  strcpy(bidders[num_bidders], name);
  num_bidders++;
}

// function to place a bid
void placeBid(char *name, int amount) {
  for (int i = 0; i < num_bidders; i++) {
    if (strcmp(bidders[i], name) == 0) {
      if (amount > bids[i]) {
        bids[i] = amount;
        if (amount > winning_bid) {
          winning_bid = amount;
          printf("%s is currently winning with a bid of $%d.\n", name, amount);
        } else {
          printf("%s has been outbid with a new bid of $%d.\n", name, amount);
        }
      } else {
        printf("%s, your bid must be higher than your current bid of $%d.\n", name, bids[i]);
      }
      return;
    }
  }
  printf("Sorry, that bidder is not registered.\n");
}

int main() {
  char command[20], name[MAX_BID_LENGTH];
  int amount;
  
  printf("Welcome to the Digital Auction System!\n");
  
  while (true) {
    printf("\nPlease enter a command (add, bid, quit): ");
    scanf("%s", command);
    
    if (strcmp(command, "add") == 0) {
      printf("Please enter the name of the bidder: ");
      scanf("%s", name);
      addBidder(name);
    } else if (strcmp(command, "bid") == 0) {
      printf("Please enter the name of the bidder: ");
      scanf("%s", name);
      printf("Please enter the bid amount: ");
      scanf("%d", &amount);
      placeBid(name, amount);
    } else if (strcmp(command, "quit") == 0) {
      printf("Thank you for using the Digital Auction System!\n");
      break;
    } else {
      printf("Invalid command.\n");
    }
  }
  
  return 0;
}