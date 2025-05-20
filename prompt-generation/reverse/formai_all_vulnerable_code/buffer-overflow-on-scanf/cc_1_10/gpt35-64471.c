//FormAI DATASET v1.0 Category: Digital Auction System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_BIDDERS 10

// struct to store bidder information
typedef struct {
  char name[20];
  float bid;
} Bidder;

// global variables
int num_bidders = 0;
Bidder bidders[MAX_BIDDERS];
float current_bid = 0.0;
char current_winner[20];

// function to add a bidder to the auction
void add_bidder() {
  if (num_bidders >= MAX_BIDDERS) {
    printf("Maximum number of bidders reached!\n");
    return;
  }
  Bidder new_bidder;
  printf("Enter bidder name: ");
  scanf("%s", new_bidder.name);
  new_bidder.bid = 0.0;
  bidders[num_bidders] = new_bidder;
  num_bidders++;
}

// function to display all bidders and their current bids
void display_bidders() {
  printf("Current bidders:\n");
  for (int i = 0; i < num_bidders; i++) {
    printf("%s: %.2f\n", bidders[i].name, bidders[i].bid);
  }
}

// function to handle bidding from a specific bidder
void* handle_bid(void* arg) {
  Bidder* bidder = (Bidder*) arg;
  float bid_amount;
  printf("%s, enter your bid (current bid is %.2f): ", bidder->name, current_bid);
  scanf("%f", &bid_amount);
  if (bid_amount <= current_bid) {
    printf("Bid must be higher than the current bid!\n");
    pthread_exit(NULL);
  }
  bidder->bid = bid_amount;
  current_bid = bid_amount;
  strcpy(current_winner, bidder->name);
  printf("%s is currently winning with a bid of %.2f.\n", current_winner, current_bid);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[MAX_BIDDERS];
  int rc;
  char action[10];
  while (1) {
    printf("Enter 'add' to add a bidder, 'display' to show current bidders, 'bid' to enter a bid, or 'quit' to exit.\n");
    scanf("%s", action);
    if (strcmp(action, "add") == 0) {
      add_bidder();
    } else if (strcmp(action, "display") == 0) {
      display_bidders();
    } else if (strcmp(action, "bid") == 0) {
      if (num_bidders == 0) {
        printf("There are no bidders!\n");
        continue;
      }
      // loop to create threads for each bidder to enter their bid
      for (int i = 0; i < num_bidders; i++) {
        rc = pthread_create(&threads[i], NULL, handle_bid, (void*) &bidders[i]);
        if (rc) {
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
        }
      }
      // loop to wait for all bidder threads to complete
      for (int i = 0; i < num_bidders; i++) {
        pthread_join(threads[i], NULL);
      }
    } else if (strcmp(action, "quit") == 0) {
      break;
    } else {
      printf("Invalid action!\n");
    }
  }
  printf("Auction ended. Winning bidder is %s with a bid of %.2f.\n", current_winner, current_bid);
  pthread_exit(NULL);
}