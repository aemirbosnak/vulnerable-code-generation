//FormAI DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_AUCTIONS 5
#define MAX_BIDDERS 10

struct Auction {
  int id;
  int starting_price;
  int highest_bid;
  int bidder_id;
  int end_time;
};

int main() {
  srand(time(NULL)); // Seed the random number generator

  struct Auction auctions[MAX_AUCTIONS]; // Array to hold all auctions
  int num_auctions = 0; // Counter for number of auctions added so far

  struct Bidder {
    int id;
    int balance;
    int selected_auction;
  } bidders[MAX_BIDDERS]; // Array to hold all bidders
  int num_bidders = 0; // Counter for number of bidders added so far

  while (1) {
    printf("\nWelcome to the Digital Auction System!\n");

    // Menu options for user input
    printf("\n1. Create Auction\n");
    printf("2. Add Bidder\n");
    printf("3. View All Auctions\n");
    printf("4. View My Auctions\n");
    printf("5. View My Bids\n");
    printf("6. Place Bid\n");
    printf("7. Exit\n\n");

    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1: // Create Auction
        if (num_auctions == MAX_AUCTIONS) {
          printf("\nMaximum number of auctions reached.\n");
          break;
        }
        printf("\nEnter starting price: ");
        int starting_price;
        scanf("%d", &starting_price);

        struct Auction auction;
        auction.id = rand() % 10000 + 1; // Generate unique ID for auction
        auction.starting_price = starting_price;
        auction.highest_bid = starting_price;
        auction.bidder_id = -1; // No bidder yet
        auction.end_time = time(NULL) + 60; // Set auction end time to 1 minute from now
        auctions[num_auctions++] = auction;
        printf("\nAuction created successfully with ID %d.\n", auction.id);
        break;

      case 2: // Add Bidder
        if (num_bidders == MAX_BIDDERS) {
          printf("\nMaximum number of bidders reached.\n");
          break;
        }
        printf("\nEnter your balance: ");
        int balance;
        scanf("%d", &balance);

        struct Bidder bidder;
        bidder.id = rand() % 10000 + 1; // Generate unique ID for bidder
        bidder.balance = balance;
        bidder.selected_auction = -1; // No auction selected yet
        bidders[num_bidders++] = bidder;
        printf("\nBidder added successfully with ID %d.\n", bidder.id);
        break;

      case 3: // View All Auctions
        printf("\n*** ALL AUCTIONS ***\n\n");
        for (int i = 0; i < num_auctions; i++) {
          struct Auction auction = auctions[i];
          printf("ID: %d   Starting Price: %d   Highest Bid: %d   Bidder ID: %d   End Time: %ld\n",
                 auction.id, auction.starting_price, auction.highest_bid, auction.bidder_id, auction.end_time);
        }
        break;

      case 4: // View My Auctions
        printf("\n*** MY AUCTIONS ***\n\n");
        printf("Enter your bidder ID: ");
        int my_bidder_id;
        scanf("%d", &my_bidder_id);

        for (int i = 0; i < num_auctions; i++) {
          struct Auction auction = auctions[i];
          if (auction.bidder_id == my_bidder_id) {
            printf("ID: %d   Starting Price: %d   Highest Bid: %d   End Time: %ld\n",
                   auction.id, auction.starting_price, auction.highest_bid, auction.end_time);
          }
        }
        break;

      case 5: // View My Bids
        printf("\n*** MY BIDS ***\n\n");
        printf("Enter your bidder ID: ");
        int my_bidder_id2;
        scanf("%d", &my_bidder_id2);

        for (int i = 0; i < num_auctions; i++) {
          struct Auction auction = auctions[i];
          if (auction.bidder_id != -1 && auction.bidder_id == my_bidder_id2) {
            printf("Auction ID: %d   Bid Amount: %d\n", auction.id, auction.highest_bid);
          }
        }
        break;

      case 6: // Place Bid
        printf("\nEnter auction ID: ");
        int auction_id;
        scanf("%d", &auction_id);

        // Find the auction
        int auction_index = -1;
        for (int i = 0; i < num_auctions; i++) {
          if (auctions[i].id == auction_id) {
            auction_index = i;
            break;
          }
        }

        if (auction_index == -1) {
          printf("\nAuction not found.\n");
          break;
        }

        printf("Enter your bidder ID: ");
        int bidder_id;
        scanf("%d", &bidder_id);

        // Find the bidder
        int bidder_index = -1;
        for (int i = 0; i < num_bidders; i++) {
          if (bidders[i].id == bidder_id) {
            bidder_index = i;
            break;
          }
        }

        if (bidder_index == -1) {
          printf("\nBidder not found.\n");
          break;
        }

        // Check selected auction of this bidder
        if (bidders[bidder_index].selected_auction != -1 && bidders[bidder_index].selected_auction != auction_id) {
          printf("\nYou cannot bid on multiple auctions at the same time.\n");
          break;
        }

        int bid_amount;
        printf("Enter bid amount: ");
        scanf("%d", &bid_amount);

        // Check if bid amount is higher than highest bid
        if (bid_amount <= auctions[auction_index].highest_bid) {
          printf("\nBid amount is not higher than highest bid.\n");
          break;
        }

        // Check if bidder has enough balance
        if (bid_amount > bidders[bidder_index].balance) {
          printf("\nBidder does not have enough balance.\n");
          break;
        }

        // Update auction with new highest bid and bidder
        auctions[auction_index].highest_bid = bid_amount;
        auctions[auction_index].bidder_id = bidder_id;

        // Update bidder's selected auction and balance
        bidders[bidder_index].selected_auction = auction_id;
        bidders[bidder_index].balance -= bid_amount;

        printf("\nBid successfully placed.\n");
        break;

      case 7: // Exit
        printf("\nGoodbye!\n");
        return 0;

      default:
        printf("\nInvalid choice.\n");
        break;
    }
  }
}