//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Item structure
typedef struct item {
    char name[50];
    float price;
    int quantity;
} item;

// Bidder structure
typedef struct bidder {
    char name[50];
    float bid;
} bidder;

// Function to compare bids
int compareBids(const void *a, const void *b) {
    bidder *bidder1 = (bidder *)a;
    bidder *bidder2 = (bidder *)b;
    return bidder2->bid - bidder1->bid;
}

// Main function
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create an array of items
    item items[] = {
        {"iPhone 13", 999.99, 10},
        {"MacBook Pro", 1499.99, 5},
        {"Apple Watch Series 7", 399.99, 15},
        {"iPad Air", 599.99, 12},
        {"AirPods Pro", 249.99, 20}
    };

    // Create an array of bidders
    bidder bidders[] = {
        {"Alice", 1000.00},
        {"Bob", 1500.00},
        {"Carol", 2000.00},
        {"Dave", 2500.00},
        {"Eve", 3000.00}
    };

    // Get the number of items and bidders
    int numItems = sizeof(items) / sizeof(items[0]);
    int numBidders = sizeof(bidders) / sizeof(bidders[0]);

    // Start the auction
    printf("Welcome to the digital auction!\n");

    // Loop through each item
    for (int i = 0; i < numItems; i++) {
        item item = items[i];

        // Print the item information
        printf("\nItem #%d:\n", i + 1);
        printf("Name: %s\n", item.name);
        printf("Price: $%.2f\n", item.price);
        printf("Quantity: %d\n", item.quantity);

        // Get the bids for the item
        bidder bids[numBidders];
        for (int j = 0; j < numBidders; j++) {
            bidder bidder = bidders[j];

            // Get the bid amount
            printf("Bidder %s, please enter your bid: ", bidder.name);
            scanf("%f", &bidder.bid);

            // Check if the bid is valid
            if (bidder.bid < item.price) {
                printf("Invalid bid. The bid must be greater than or equal to the item price.\n");
                j--;
            } else {
                bids[j] = bidder;
            }
        }

        // Sort the bids in descending order
        qsort(bids, numBidders, sizeof(bidder), compareBids);

        // Find the highest bid
        bidder highestBid = bids[0];

        // Check if the highest bid is greater than or equal to the item price
        if (highestBid.bid >= item.price) {
            // The highest bid is valid. Sell the item to the highest bidder.
            printf("The highest bid for item #%d is $%.2f by %s.\n", i + 1, highestBid.bid, highestBid.name);
            item.quantity--;
        } else {
            // The highest bid is not valid. The item is not sold.
            printf("There were no valid bids for item #%d.\n", i + 1);
        }
    }

    // End the auction
    printf("\nThank you for participating in the auction!\n");

    return 0;
}