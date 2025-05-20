//FormAI DATASET v1.0 Category: Digital Auction System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// global variables
int highestBid = 0;
int bidderID = 0;
int remainingTime = 120;    // in seconds
int auctionEnded = 0;       // flag to check if auction has ended or not

// function to generate random bidder ID
int generateBidderID() {
    srand(time(NULL));
    return rand() % 1000 + 1;
}

// function to get input from bidder
int getBid(int bidderID) {
    int bid;
    printf("Bidder %d, enter your bid: ", bidderID);
    scanf("%d", &bid);
    return bid;
}

// function to check if bid is valid
int validateBid(int bid) {
    if (bid > highestBid) {
        highestBid = bid;
        return 1;
    }
    return 0;
}

int main() {
    printf("Welcome to the Digital Auction System!\n");
    printf("The auction will run for 2 minutes (120 seconds).\n\n");

    // start the auction
    time_t startTime = time(NULL);
    time_t currentTime;

    while (!auctionEnded) {
        currentTime = time(NULL);
        remainingTime = 120 - difftime(currentTime, startTime);
        if (remainingTime <= 0) {
            auctionEnded = 1;
            break;
        }

        bidderID = generateBidderID();
        int bid = getBid(bidderID);
        int isValidBid = validateBid(bid);

        if (isValidBid) {
            printf("\nBidder %d has the highest bid at $%d.\n\n", bidderID, highestBid);
        }
        else {
            printf("\nBidder %d, your bid of $%d is not valid. The current highest bid is $%d.\n\n", bidderID, bid, highestBid);
        }
    }

    // end the auction
    printf("The auction has ended.\n");
    printf("The winning bid is $%d by bidder %d.\n", highestBid, bidderID);

    return 0;
}