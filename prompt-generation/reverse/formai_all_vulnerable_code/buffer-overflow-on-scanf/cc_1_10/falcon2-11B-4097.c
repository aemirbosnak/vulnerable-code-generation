//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDS 100
#define MAX_BIDDERS 10

int bids[MAX_BIDS];
int bidCount = 0;
int bidderCount = 0;

void printBids() {
    int i;
    for (i = 0; i < bidCount; i++) {
        printf("%d\n", bids[i]);
    }
}

void addBid(int bid) {
    if (bidCount < MAX_BIDS) {
        bids[bidCount] = bid;
        bidCount++;
    }
}

int getHighestBid() {
    int maxBid = bids[0];
    int i;
    for (i = 1; i < bidCount; i++) {
        if (bids[i] > maxBid) {
            maxBid = bids[i];
        }
    }
    return maxBid;
}

int main() {
    int bid;
    int highestBid = 0;
    int winner;

    printf("Welcome to the Digital Auction System!\n");

    while (bidderCount < MAX_BIDDERS) {
        printf("Bidder %d, enter your bid: ", bidderCount + 1);
        scanf("%d", &bid);
        addBid(bid);

        if (bid > highestBid) {
            highestBid = bid;
            winner = bidderCount;
        }

        if (bidCount == MAX_BIDS) {
            printf("Bidding period has ended.\n");
            break;
        }
    }

    if (bidCount == 0) {
        printf("No bids were placed.\n");
    } else {
        printf("The highest bid is %d, placed by bidder %d.\n", highestBid, winner);
    }

    printf("Bids:\n");
    printBids();

    return 0;
}