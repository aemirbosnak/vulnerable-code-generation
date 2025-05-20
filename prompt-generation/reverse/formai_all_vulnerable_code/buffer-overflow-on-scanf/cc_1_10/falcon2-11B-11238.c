//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate a digital auction
void auction(int num_items, int bid_limit) {
    // Array to store the current bids
    int bids[num_items];

    // Initialize all bids to 0
    for (int i = 0; i < num_items; i++) {
        bids[i] = 0;
    }

    // Simulate bidding
    int current_bidder = 0;
    int current_bid = 0;

    srand(time(NULL)); // Initialize random number generator

    // Loop until all items are sold or no more bids are possible
    while (current_bidder < num_items && current_bid <= bid_limit) {
        // Select a random bidder
        current_bidder = rand() % num_items;

        // Print current bid information
        printf("Current Bidder: %d\n", current_bidder);
        printf("Current Bid: %d\n", current_bid);
        printf("Bids: ");
        for (int i = 0; i < num_items; i++) {
            printf("%d ", bids[i]);
        }
        printf("\n");

        // Prompt user for new bid
        int new_bid;
        printf("Enter a new bid (0 to exit): ");
        scanf("%d", &new_bid);

        // Update current bid and bids
        if (new_bid > current_bid) {
            current_bid = new_bid;
            bids[current_bidder] = new_bid;
        }

        // Print new bid information
        printf("New Bid: %d\n", current_bid);
        printf("Bids: ");
        for (int i = 0; i < num_items; i++) {
            printf("%d ", bids[i]);
        }
        printf("\n");
    }

    // Print final bid information
    printf("Final Bid: %d\n", current_bid);
    printf("Bids: ");
    for (int i = 0; i < num_items; i++) {
        printf("%d ", bids[i]);
    }
    printf("\n");
}

int main() {
    // Number of items
    int num_items = 5;

    // Bid limit
    int bid_limit = 100;

    // Run the auction
    auction(num_items, bid_limit);

    return 0;
}