//FormAI DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random bids
int generateBid() {
    int bid;
    srand(time(NULL));
    bid = rand() % 10000 + 1; // Generates a random bid between 1 and 10000
    return bid;
}

int main() {
    int startingBid = 5000;
    int currentBid;
    int numBids = 0;
    int maxBids = 10; // Maximum number of bids allowed
    int highestBid = startingBid; // The current highest bid
    int bidderID[maxBids]; // Array to store the IDs of the bidders
    int bidAmount[maxBids]; // Array to store the bid amounts of the bidders

    printf("Welcome to the Digital Auction System!\n");
    printf("The starting bid for this auction is $%d.\n", startingBid);

    // Loop to allow bidders to submit their bids
    while (numBids < maxBids) {
        printf("\nBidder #%d, what is your bid? ", numBids+1);
        scanf("%d", &currentBid);

        if (currentBid <= highestBid) {
            printf("\nSorry, your bid is not high enough. Please try again.\n");
            continue;
        }
        else if (currentBid >= 10000) {
            printf("\nSorry, the maximum bid allowed is $10000. Please try again.\n");
            continue;
        }
        else {
            bidderID[numBids] = numBids+1;
            bidAmount[numBids] = currentBid;
            highestBid = currentBid;
            numBids++;
            printf("\nYou are currently the highest bidder with a bid of $%d.\n", highestBid);
        }
    }

    printf("\nThe auction has ended. Here are the results:\n");

    // Loop to print out the results of the auction
    for (int i = 0; i < maxBids; i++) {
        printf("\nBidder #%d: $%d", bidderID[i], bidAmount[i]);
    }

    printf("\n\nThe winner of the auction is Bidder #%d with a winning bid of $%d!\n",
           bidderID[maxBids-1], bidAmount[maxBids-1]);

    // Generate some random bids for fun!
    printf("\n\nFor fun, here are some randomly generated bids:\n");
    for (int i = 0; i < 5; i++) {
        printf("Bid #%d: $%d\n", i+1, generateBid());
    }

    return 0;
}