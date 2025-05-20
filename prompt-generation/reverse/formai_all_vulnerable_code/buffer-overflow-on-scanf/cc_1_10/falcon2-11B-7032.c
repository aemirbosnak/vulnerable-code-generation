//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int bid;
    int bidder;
    int item;
} Bidder;

int main() {
    // Create a vector of bids
    Bidder bids[10];

    // Initialize bids
    for (int i = 0; i < 10; i++) {
        bids[i].bid = 0;
        bids[i].bidder = 0;
        bids[i].item = 0;
    }

    // Create a vector of items
    int items[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Set up the auction
    printf("Welcome to the Digital Auction System!\n");
    printf("Please enter your bids:\n");

    // Start the auction
    for (int i = 0; i < 10; i++) {
        printf("Bid %d:\n", i + 1);

        // Get the bidder's bid
        int bidder;
        printf("Enter your bid: ");
        scanf("%d", &bidder);

        // Get the item the bidder is bidding on
        int item;
        printf("Enter the item number: ");
        scanf("%d", &item);

        // Check if the bidder is eligible to bid on the item
        if (item > 0 && item <= 10) {
            if (bids[item - 1].bidder == 0) {
                // Update the bid
                bids[item - 1].bid = bidder;
                bids[item - 1].bidder = bidder;
                bids[item - 1].item = item;
            } else {
                // Bidder is not eligible to bid on this item
                printf("Sorry, you are not eligible to bid on this item.\n");
            }
        } else {
            // Invalid item number
            printf("Invalid item number.\n");
        }
    }

    // Print out the winning bid
    printf("The winning bid is %d on item %d.\n", bids[0].bid, bids[0].item);

    // Clean up memory
    for (int i = 0; i < 10; i++) {
        bids[i].bidder = 0;
        bids[i].item = 0;
    }

    return 0;
}