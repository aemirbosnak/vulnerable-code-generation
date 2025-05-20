//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numBids = 0;
    int maxBid = 0;
    int currentBidder = 0;
    int currentBid = 0;
    int bidIncrement = 10;
    srand(time(NULL));

    printf("Welcome to the Digital Auction System!\n");
    printf("Please enter the number of items for auction:\n");
    int numItems = 0;
    scanf("%d", &numItems);
    printf("Enter the number of bids for each item:\n");
    int numBidsPerItem = 0;
    scanf("%d", &numBidsPerItem);

    for (int i = 0; i < numItems; i++) {
        printf("Enter the starting bid for item %d:\n", i+1);
        int startingBid = 0;
        scanf("%d", &startingBid);

        for (int j = 0; j < numBidsPerItem; j++) {
            printf("Enter bid for item %d, bidder %d:\n", i+1, j+1);
            int bid = 0;
            scanf("%d", &bid);

            if (bid > maxBid) {
                maxBid = bid;
                currentBidder = j+1;
                currentBid = bid;
            }

            if (j+1 == numBidsPerItem) {
                printf("Congratulations! You have won item %d at a bid of $%d!\n", i+1, currentBid);
                break;
            }

            if (bid < startingBid) {
                printf("Invalid bid, please enter a higher bid.\n");
                continue;
            }

            if (bid == startingBid) {
                printf("Bid received, continue bidding for item %d, bidder %d.\n", i+1, j+1);
            }

            if (bid > startingBid + bidIncrement) {
                printf("Bid received, continue bidding for item %d, bidder %d.\n", i+1, j+1);
            }

            if (bid == startingBid + bidIncrement) {
                printf("Bid received, continue bidding for item %d, bidder %d.\n", i+1, j+1);
            }

            if (bid > startingBid + 2*bidIncrement) {
                printf("Bid received, continue bidding for item %d, bidder %d.\n", i+1, j+1);
            }

            if (bid == startingBid + 2*bidIncrement) {
                printf("Bid received, continue bidding for item %d, bidder %d.\n", i+1, j+1);
            }
        }
    }

    return 0;
}