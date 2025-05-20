//FormAI DATASET v1.0 Category: Digital Auction System ; Style: expert-level
#include <stdio.h>

// function to display the time left for bidding
void displayTime(int timeLeft) {
    int min = timeLeft / 60;
    int sec = timeLeft % 60;
    printf("Time Left: %02d:%02d\n", min, sec);
}

int main() {
    // initializing variables and arrays
    int auctionTime = 300; // 5 minutes
    int currentBid = 0;
    int highestBid = 0;
    int currentBidder = 0;
    int bidderCount = 0;
    int bidderIds[10] = {0};
    int bidderBids[10] = {0};

    // display auction start message and time left
    printf("Welcome to the Digital Auction System!\n");
    displayTime(auctionTime);

    // loop through the auction time
    for (int i = 0; i < auctionTime; i++) {
        // check if there are any new bidders
        int newBidder;
        printf("\nNew bidder? (1 for yes, 0 for no): ");
        scanf("%d", &newBidder);
        if (newBidder == 1) {
            // check if the max number of bidders has been reached
            if (bidderCount == 10) {
                printf("Max number of bidders has been reached.\n");
                continue;
            }
            // get bidder info and add to arrays
            printf("Enter bidder ID: ");
            scanf("%d", &bidderIds[bidderCount]);
            printf("Enter starting bid: ");
            scanf("%d", &bidderBids[bidderCount]);
            bidderCount++;
        }

        // display current highest bid and bidder
        printf("\nCurrent highest bid: %d\n", highestBid);
        if (currentBidder == 0) {
            printf("No current bidder.\n");
        } else {
            printf("Current bidder: %d\n", currentBidder);
        }

        // check if there are any bids
        int newBid;
        printf("\nNew bid? (Enter 0 to pass): ");
        scanf("%d", &newBid);
        if (newBid > highestBid) {
            // update highest bid and current bidder
            highestBid = newBid;
            currentBidder = bidderIds[currentBid-1];
        } else if (newBid != 0) {
            // notify bidder that their bid is too low
            printf("Bid too low.\n");
        }

        // update current bid and display time left
        currentBid++;
        displayTime(auctionTime - i - 1);
    }

    // display auction end message and highest bidder info
    printf("Auction has ended.\n");
    printf("Highest bidder: %d\n", currentBidder);
    printf("Highest bid: %d\n", highestBid);

    return 0;
}