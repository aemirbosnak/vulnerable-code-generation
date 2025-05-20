//FormAI DATASET v1.0 Category: Digital Auction System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_bid(int bid[]) {
  printf("Current Bids:\n");
  for (int i = 0; i < 10; ++i) {
    printf("Bid #%d: $%d.00\n", i + 1, bid[i]);
  }
}

int main() {
  int highest_bid = 0;
  int highest_bidder = 0;
  int bid[10] = {0};
  int user_choice = 0;

  printf("Welcome to our digital auction system!\n");

  while (1) {
    printf("\nYou may:\n1. View current bids.\n2. Place a bid.\n3. End the auction.\nYour choice: ");
    scanf("%d", &user_choice);

    if (user_choice == 1) {
      print_bid(bid);
    }
    else if (user_choice == 2) {
      printf("Please enter your bid amount: ");
      int user_bid;
      scanf("%d", &user_bid);

      // Check if user's bid is greater than highest bid
      if (user_bid > highest_bid) {
        highest_bid = user_bid;
        highest_bidder = rand() % 10 + 1; // Randomly assign bidder number
        printf("Success! You are now the highest bidder at $%d.00 with bidder #%d.\n", highest_bid, highest_bidder);
        for (int i = 0; i < 10; ++i) {
          if (bid[i] < highest_bid) {
            bid[i] = highest_bid;
            break;
          }
        }
      }
      else {
        printf("Sorry, your bid is not enough to be the highest.\n");
      }
    }
    else if (user_choice == 3) {
      printf("The auction ends now. The winner is bidder #%d with a bid of $%d.00.\n", highest_bidder, highest_bid);
      break;
    }
    else {
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}