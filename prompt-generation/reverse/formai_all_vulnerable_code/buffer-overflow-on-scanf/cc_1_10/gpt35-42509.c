//FormAI DATASET v1.0 Category: Digital Auction System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed the random number generator with current time

    int minValue, maxValue, numBids;
    int highestBid, winningBidder, currentBidder;
    int *bidList;

    printf("Enter minimum value for the auction: ");
    scanf("%d", &minValue);

    printf("Enter maximum value for the auction: ");
    scanf("%d", &maxValue);

    printf("Enter number of bids for the auction: ");
    scanf("%d", &numBids);

    bidList = (int *)malloc(numBids * sizeof(int)); // Allocate memory for bidList

    printf("\nStarting the auction...\n");

    highestBid = minValue - 1; // Initialize highestBid to a value lower than minValue

    for (int i = 0; i < numBids; i++) {
        printf("\nBid #%d:\n", i + 1);
        printf("Current highest bid: $%d\n", highestBid);

        printf("Enter bidder number: ");
        scanf("%d", &currentBidder);

        printf("Enter bid amount: ");
        scanf("%d", &bidList[i]);

        if (bidList[i] > highestBid && bidList[i] <= maxValue) {
            highestBid = bidList[i];
            winningBidder = currentBidder;
        } else {
            printf("Invalid bid entered. Bid amount must be higher than current highest bid and less than or equal to the maximum value.\n");
            i--; // Redo this bid since it was invalid
        }
    }

    printf("\nAuction closed!\n");
    printf("Highest bid: $%d\n", highestBid);
    printf("Winner: Bidder #%d\n", winningBidder);

    free(bidList); // Free dynamically allocated memory

    return 0;
}