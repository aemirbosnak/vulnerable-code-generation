//FormAI DATASET v1.0 Category: Digital Auction System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITEMS 5 // Number of items for auction
#define MIN_BID 50 // Minimum starting bid for each item
#define MAX_BID 1000 // Maximum bid allowed for each item

// Function to generate random starting prices for each item
void generatePrices(int prices[]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_ITEMS; i++) {
        prices[i] = (rand() % (MAX_BID - MIN_BID + 1)) + MIN_BID;
    }
}

int main() {
    int prices[NUM_ITEMS];
    generatePrices(prices);
    
    printf("Welcome to the Digital Auction System!\n\n");
    printf("We have the following items for auction with their starting bids:\n\n");
    
    // Display items and starting prices
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("Item %d: Starting bid - $%d\n", i+1, prices[i]);
    }
    
    printf("\nBidding will close in 10 minutes.\n\n");
    
    // Allow users to bid on items
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("\nEnter your bid for Item %d: ", i+1);
        int bid;
        scanf("%d", &bid);
        while (bid <= prices[i] || bid > MAX_BID) { // Validate bid
            printf("Invalid bid! Please enter a bid between $%d and $%d: ", prices[i]+1, MAX_BID);
            scanf("%d", &bid);
        }
        prices[i] = bid; // Update current price of item
    }
    
    printf("\nBidding has closed! Here are the final prices for each item:\n\n");
    
    // Display final prices for each item
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("Item %d: Final price - $%d\n", i+1, prices[i]);
    }
    
    return 0;
}