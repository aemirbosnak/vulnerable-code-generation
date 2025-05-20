//FormAI DATASET v1.0 Category: Digital Auction System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_bidders;
  int current_bid = 0;
  int winning_bidder = 0;
  srand(time(0)); // seed random number generator with current time
  printf("Welcome to the digital auction system!\n\n");
  printf("How many bidders will participate in this auction? (Enter an integer): ");
  scanf("%d", &num_bidders);
  printf("\n");

  int* bidder_ids = malloc(num_bidders * sizeof(int)); // dynamically allocated array to store bidder IDs
  for(int i = 0; i < num_bidders; i++) {
    bidder_ids[i] = i + 1; // initialize bidder IDs
  }

  printf("The following bidders will participate in the auction:\n");
  for(int i = 0; i < num_bidders; i++) {
    printf("Bidder %d\n", bidder_ids[i]);
  }
  printf("\n");

  printf("Bidding will now commence!\n\n");
  while(num_bidders > 0) {
    int current_bidder = rand() % num_bidders; // randomly select bidder
    int bid_amount;
    printf("Bidder %d, what is your bid? (Enter an integer): ", bidder_ids[current_bidder]);
    scanf("%d", &bid_amount);
    printf("\n");
    if(bid_amount > current_bid) { // check if current bid is exceeded
      current_bid = bid_amount;
      winning_bidder = bidder_ids[current_bidder];
      printf("Bidder %d is currently winning with a bid of %d.\n\n", winning_bidder, current_bid);
    }
    else {
      printf("Sorry, your bid of %d is not high enough. Please try again.\n\n", bid_amount);
    }
    if(num_bidders > 1) {
      printf("There are %d bidders left in the auction.\n", num_bidders);
    }
    else {
      printf("There is 1 bidder left in the auction.\n");
    }
    printf("\n");
    for(int i = current_bidder; i < num_bidders - 1; i++) {
      bidder_ids[i] = bidder_ids[i+1]; // shift remaining bidders down in array
    }
    num_bidders--; // decrement number of bidders
  }

  printf("The winner of the auction is Bidder %d with a bid of %d! Congratulations!\n", winning_bidder, current_bid);

  free(bidder_ids); // free dynamically allocated memory
  return 0;
}