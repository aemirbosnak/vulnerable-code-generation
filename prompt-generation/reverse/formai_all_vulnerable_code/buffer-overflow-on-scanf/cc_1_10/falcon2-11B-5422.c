//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Auction {
    int itemId;
    int currentBid;
    int reservePrice;
    int timeLeft;
    int winner;
    int bidder;
};

int main() {
    srand(time(NULL)); // seed random number generator with current time

    // create a structure to hold auction data
    struct Auction auction;
    auction.itemId = 1;
    auction.currentBid = 0;
    auction.reservePrice = 10;
    auction.timeLeft = 60; // 60 seconds
    auction.winner = -1;
    auction.bidder = -1;

    // initialize auction state
    auction.timeLeft = 60;
    auction.currentBid = 0;
    auction.winner = -1;
    auction.bidder = -1;

    // main loop for auction
    while (auction.timeLeft > 0) {
        // print auction status
        printf("Auction status: %d, current bid: %d, time left: %d\n", auction.itemId, auction.currentBid, auction.timeLeft);

        // check for new bids
        if (auction.currentBid < auction.reservePrice) {
            printf("No bids meet the reserve price.\n");
        } else if (auction.currentBid == auction.reservePrice) {
            printf("Reserve price reached, auction continues.\n");
        } else {
            printf("Auction ends in %d seconds.\n", auction.timeLeft);
            auction.timeLeft--;
        }

        // check for winner
        if (auction.timeLeft == 0) {
            if (auction.currentBid >= auction.reservePrice) {
                auction.winner = auction.bidder;
            } else {
                auction.winner = -1;
            }
        }

        // process new bids
        int bid;
        printf("Enter your bid (0 to exit): ");
        scanf("%d", &bid);

        if (bid == 0) {
            break;
        } else if (bid > auction.currentBid) {
            auction.currentBid = bid;
            auction.bidder = getpid();
        }
    }

    // print auction result
    if (auction.winner!= -1) {
        printf("Auction winner: %d\n", auction.winner);
    } else {
        printf("Auction ends with no winner.\n");
    }

    return 0;
}