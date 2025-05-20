//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold bid details
typedef struct {
    char* name;
    int amount;
} Bid;

// Function to read bid details from user
Bid readBid(void) {
    Bid bid;
    printf("Enter your name: ");
    scanf("%s", bid.name);
    printf("Enter your bid amount: ");
    scanf("%d", &bid.amount);
    return bid;
}

// Function to print highest bid
void printHighestBid(Bid* bids, int numBids) {
    if (numBids == 0) {
        printf("No bids yet.\n");
    } else {
        int maxAmount = 0;
        int maxIndex = 0;
        for (int i = 0; i < numBids; i++) {
            if (bids[i].amount > maxAmount) {
                maxIndex = i;
                maxAmount = bids[i].amount;
            }
        }
        printf("%s has the highest bid of %d.\n", bids[maxIndex].name, bids[maxIndex].amount);
    }
}

// Function to get next highest bid
void getNextHighestBid(Bid* bids, int numBids, Bid* nextBid) {
    if (numBids == 0) {
        printf("No bids yet.\n");
    } else {
        int maxAmount = 0;
        int maxIndex = 0;
        for (int i = 0; i < numBids; i++) {
            if (bids[i].amount > maxAmount) {
                maxIndex = i;
                maxAmount = bids[i].amount;
            }
        }
        if (maxIndex!= numBids - 1) {
            nextBid->name = bids[maxIndex + 1].name;
            nextBid->amount = bids[maxIndex + 1].amount;
        } else {
            nextBid->name = "";
            nextBid->amount = 0;
        }
    }
}

// Main function
int main() {
    Bid bids[100];
    int numBids = 0;

    while (1) {
        printf("Enter your bid or 0 to exit: ");
        Bid bid = readBid();
        if (bid.amount == 0) {
            break;
        } else {
            bids[numBids] = bid;
            numBids++;
            printf("Bid entered: %s - %d\n", bid.name, bid.amount);
        }
    }

    printHighestBid(bids, numBids);

    printf("Next highest bid: ");
    getNextHighestBid(bids, numBids, &bids[numBids - 1]);
    printf("Next highest bid: %s - %d\n", bids[numBids - 1].name, bids[numBids - 1].amount);

    return 0;
}