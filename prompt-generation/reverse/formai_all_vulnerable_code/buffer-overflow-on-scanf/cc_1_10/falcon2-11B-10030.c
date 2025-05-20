//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BIDDERS 100
#define MAX_BIDS 10
#define MAX_PRICE 1000000

typedef struct bidder bidder_t;

struct bidder {
    char name[50];
    int bids[MAX_BIDS];
    int bid_count;
    int current_bid;
};

typedef struct auction auction_t;

struct auction {
    bidder_t bidders[MAX_BIDDERS];
    int num_bidders;
    int current_bidder;
    int num_bids;
    int current_bid;
};

int main() {
    srand(time(NULL));

    auction_t auction = {0, 0, 0, 0, 0};

    // Create some bidders
    bidder_t bidder1 = {
        "Alice",
        {rand() % MAX_PRICE, rand() % MAX_PRICE, rand() % MAX_PRICE},
        0,
        0
    };

    bidder_t bidder2 = {
        "Bob",
        {rand() % MAX_PRICE, rand() % MAX_PRICE, rand() % MAX_PRICE},
        0,
        0
    };

    bidder_t bidder3 = {
        "Charlie",
        {rand() % MAX_PRICE, rand() % MAX_PRICE, rand() % MAX_PRICE},
        0,
        0
    };

    // Add the bidders to the auction
    auction.bidders[0] = bidder1;
    auction.bidders[1] = bidder2;
    auction.bidders[2] = bidder3;
    auction.num_bidders = 3;

    // Start the auction
    auction.current_bidder = 0;
    auction.current_bid = 0;

    while (auction.current_bidder < auction.num_bidders) {
        printf("Bidder %d's turn!\n", auction.current_bidder + 1);

        // Ask for a bid
        printf("Enter your bid: ");
        scanf("%d", &auction.bidders[auction.current_bidder].bids[auction.num_bids]);

        // Check if the bid is valid
        if (auction.bidders[auction.current_bidder].bids[auction.num_bids] < auction.current_bid) {
            printf("Invalid bid!\n");
        } else {
            auction.bidders[auction.current_bidder].bids[auction.num_bids] = auction.current_bid;
            auction.bidders[auction.current_bidder].bid_count++;
            auction.current_bid = auction.bidders[auction.current_bidder].bids[auction.num_bids];
            auction.num_bids++;

            printf("New highest bid: %d\n", auction.current_bid);

            // Check if the auction is over
            if (auction.num_bids >= MAX_BIDS) {
                break;
            }

            auction.current_bidder++;
        }
    }

    // Print the results
    for (int i = 0; i < auction.num_bidders; i++) {
        printf("Bidder %d: %d bids, total bid amount: %d\n", i + 1, auction.bidders[i].bid_count, auction.bidders[i].current_bid);
    }

    return 0;
}