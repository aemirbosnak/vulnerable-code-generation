//FormAI DATASET v1.0 Category: Digital Auction System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BID_INCREMENT 5
#define MAX_BID 100
#define MIN_BID 25

int main()
{
    int current_bid = MIN_BID; // Starting bid
    int highest_bidder = 0; // ID of highest bidder
    int bid; // New bid
    int n_bidders; // Number of bidders
    int bidder_ids[10]; // IDs of bidders
    int i;

    // Generating random IDs for bidders
    srand((int)time(NULL));
    n_bidders = rand() % 10 + 1; // Maximum 10 bidders
    printf("Welcome to the Medieval Digital Auction System!\n");
    printf("There are %d bidders today\n", n_bidders);
    for (i = 0; i < n_bidders; i++) {
        bidder_ids[i] = rand() % 100 + 1; // Maximum ID 100
        printf("Bidder %d has joined the auction\n", bidder_ids[i]);
    }

    // Conducting the auction
    while (current_bid < MAX_BID) {
        printf("\nCurrent highest bid is %d gold coins\n", current_bid);

        // Getting the new bid
        printf("Enter your bid (minimum increment is %d): ", BID_INCREMENT);
        scanf("%d", &bid);

        // Validating the new bid
        if (bid < current_bid + BID_INCREMENT) {
            printf("Bid must be at least %d gold coins higher than the current bid!\n", BID_INCREMENT);
        }
        else if (bid > MAX_BID) {
            printf("Bid must be at most %d gold coins!\n", MAX_BID);
        }
        else {
            current_bid = bid;
            highest_bidder = bidder_ids[rand() % n_bidders];
            printf("Bid accepted! Bidder %d is now the highest bidder.\n", highest_bidder);
        }
    }

    // Auction ended
    printf("\nThe auction is over! Bidder %d won the auction with a bid of %d gold coins.\n", highest_bidder, current_bid);

    return 0;
}