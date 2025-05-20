//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the bids
typedef struct {
    char bidder[100];
    int bid;
} Bid;

// Function to display the current highest bid
void displayHighestBid(Bid *bids, int numBids) {
    int highestBid = 0;

    for (int i = 0; i < numBids; i++) {
        if (bids[i].bid > highestBid) {
            highestBid = bids[i].bid;
        }
    }

    printf("Current Highest Bid: %d\n", highestBid);
}

// Function to add a new bid to the list
void addBid(Bid *bids, int *numBids, char *bidder, int bid) {
    bids[*numBids].bid = bid;
    strcpy(bids[*numBids].bidder, bidder);

    (*numBids)++;
}

// Function to process the bids and end the auction
void processBids(Bid *bids, int numBids) {
    printf("Bidding has ended!\n");
    displayHighestBid(bids, numBids);
}

int main() {
    Bid bids[100];
    int numBids = 0;
    char bidder[100];
    int bid;

    // Get the initial bid
    printf("Enter the initial bid: ");
    scanf("%d", &bid);
    addBid(bids, &numBids, bidder, bid);

    // Start the bidding process
    while (1) {
        printf("Enter the new bid (enter -1 to end bidding): ");
        scanf("%d", &bid);

        if (bid == -1) {
            break;
        }

        addBid(bids, &numBids, bidder, bid);
    }

    // Process the bids and end the auction
    processBids(bids, numBids);

    return 0;
}