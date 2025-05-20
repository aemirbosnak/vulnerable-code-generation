//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item structure
typedef struct item {
    char name[50];
    int price;
} Item;

// Bidder structure
typedef struct bidder {
    char name[50];
    int bid;
} Bidder;

// Function to compare two bidders
int compareBidders(const void *a, const void *b) {
    Bidder *bidder1 = (Bidder *)a;
    Bidder *bidder2 = (Bidder *)b;
    return bidder2->bid - bidder1->bid;
}

// Function to find the highest bidder
Bidder *findHighestBidder(Bidder *bidders, int numBidders) {
    if (numBidders == 0) {
        return NULL;
    }
    Bidder *highestBidder = bidders;
    for (int i = 1; i < numBidders; i++) {
        if (bidders[i].bid > highestBidder->bid) {
            highestBidder = &bidders[i];
        }
    }
    return highestBidder;
}

// Function to run the auction
void runAuction(Item *item) {
    // Initialize the list of bidders
    Bidder bidders[100];
    int numBidders = 0;

    // Prompt the user to enter bids
    printf("Enter your name and bid (or 'q' to quit): ");
    while (1) {
        Bidder bidder;
        scanf("%s %d", bidder.name, &bidder.bid);
        if (strcmp(bidder.name, "q") == 0) {
            break;
        }
        bidders[numBidders++] = bidder;
    }

    // Find the highest bidder
    Bidder *highestBidder = findHighestBidder(bidders, numBidders);

    // Print the results of the auction
    if (highestBidder == NULL) {
        printf("No bids were placed.\n");
    } else {
        printf("The highest bidder is %s with a bid of %d.\n", highestBidder->name, highestBidder->bid);
    }
}

int main() {
    // Initialize the item
    Item item;
    strcpy(item.name, "Painting");
    item.price = 100;

    // Run the auction
    runAuction(&item);

    return 0;
}