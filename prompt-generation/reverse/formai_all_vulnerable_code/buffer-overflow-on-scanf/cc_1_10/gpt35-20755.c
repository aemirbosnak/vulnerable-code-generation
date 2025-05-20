//FormAI DATASET v1.0 Category: Digital Auction System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed random number generator with current time

  int num_bidders;
  printf("Welcome to the Digital Auction System!\n\n");
  printf("How many bidders are participating in this auction? ");
  scanf("%d", &num_bidders);

  // Allocate memory for bidder names and bids
  char** bidders = (char**) malloc(num_bidders * sizeof(char*));
  int* bids = (int*) malloc(num_bidders * sizeof(int));

  // Get bidder names and bids
  printf("Enter the names and bids for each bidder:\n");
  for(int i = 0; i < num_bidders; i++) {
    bidders[i] = (char*) malloc(20 * sizeof(char));
    printf("Bidder %d: ", i+1);
    scanf("%s %d", bidders[i], &bids[i]);
  }

  // Find highest bidder
  int highest_bid = 0;
  int winner_index;
  for(int i = 0; i < num_bidders; i++) {
    if(bids[i] > highest_bid) {
      highest_bid = bids[i];
      winner_index = i;
    }
  }

  // Announce winner and random consolation prize for other bidders
  printf("\nThe winner is: %s\n", bidders[winner_index]);
  printf("Congratulations on your purchase!\n\n");

  for(int i = 0; i < num_bidders; i++) {
    if(i != winner_index) {
      int consolation_prize = rand() % 100 + 1;
      printf("Sorry %s, your bid of %d was not successful.\n", bidders[i], bids[i]);
      printf("But you have won a consolation prize of $%d!\n\n", consolation_prize);
    }
  }

  // Free memory
  for(int i = 0; i < num_bidders; i++) {
    free(bidders[i]);
  }
  free(bidders);
  free(bids);

  return 0;
}