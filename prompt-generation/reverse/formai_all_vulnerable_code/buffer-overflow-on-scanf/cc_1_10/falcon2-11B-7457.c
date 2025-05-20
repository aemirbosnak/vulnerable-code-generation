//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize the auction
    int items = 10;
    int bids = 0;

    // Bid increment
    int bidIncrement = 1;

    // Array to store bids
    int bidsArr[items];

    // Create bids
    for (int i = 0; i < items; i++) {
        bidsArr[i] = 0;
    }

    // Simulate auction
    while (bids < items) {
        // Print current bids
        printf("Current bids: ");
        for (int i = 0; i < items; i++) {
            printf("%d ", bidsArr[i]);
        }
        printf("\n");

        // Get user's bid
        int userBid;
        printf("Enter your bid: ");
        scanf("%d", &userBid);

        // Check if bid is valid
        if (userBid < 1 || userBid > items) {
            printf("Invalid bid. Try again.\n");
            continue;
        }

        // Update bids array
        bidsArr[userBid - 1] += bidIncrement;

        // Check if item is sold
        if (bidsArr[userBid - 1] == items) {
            printf("Item %d is sold to user %d with a bid of %d.\n", userBid, userBid, bidsArr[userBid - 1]);
            bidsArr[userBid - 1] = 0;
            bids++;
        }
    }

    // Print final bids
    printf("Final bids: ");
    for (int i = 0; i < items; i++) {
        printf("%d ", bidsArr[i]);
    }
    printf("\n");

    // Print winner
    if (bids > 0) {
        printf("The winner is user %d with a bid of %d.\n", bidsArr[0], bidsArr[0]);
    }

    return 0;
}