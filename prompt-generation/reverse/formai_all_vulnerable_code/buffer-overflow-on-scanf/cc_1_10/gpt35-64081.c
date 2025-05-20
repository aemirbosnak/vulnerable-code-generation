//FormAI DATASET v1.0 Category: Digital Auction System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold auction item details
typedef struct AuctionItem {
    char name[100];
    char description[500];
    char sellerName[100];
    float startPrice;
    float currentPrice;
} AuctionItem;

// Structure to hold bidder details
typedef struct Bidder {
    char name[100];
    float currentBid;
} Bidder;

// Function to get item details from the seller
AuctionItem createAuctionItem(char sellerName[]) {
    AuctionItem item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item description: ");
    scanf("%s", item.description);
    strcpy(item.sellerName, sellerName);
    printf("Enter starting price: ");
    scanf("%f", &item.startPrice);
    item.currentPrice = item.startPrice;
    return item;    
}

// Function to get bidder details
Bidder createBidder() {
    Bidder bidder;
    printf("Enter your name: ");
    scanf("%s", bidder.name);
    bidder.currentBid = 0.0;
    return bidder;
}

// Function to display item details
void displayItem(AuctionItem item) {
    printf("Item name: %s\n", item.name);
    printf("Item description: %s\n", item.description);
    printf("Seller name: %s\n", item.sellerName);
    printf("Starting price: %.2f\n", item.startPrice);
    printf("Current price: %.2f\n", item.currentPrice);
}

// Function to display bidder details
void displayBidder(Bidder bidder) {
    printf("Bidder name: %s\n", bidder.name);
    printf("Current bid: %.2f\n", bidder.currentBid);
}

int main() {
    int numBidders, i, j;
    AuctionItem item;
    Bidder *bidders;
    int winnerIndex = -1;

    // Get item details from the seller
    char sellerName[100];
    printf("Enter your name as the seller: ");
    scanf("%s", sellerName);
    item = createAuctionItem(sellerName);

    // Get number of bidders
    printf("Enter number of bidders: ");
    scanf("%d", &numBidders);
    bidders = (Bidder *) malloc(numBidders * sizeof(Bidder));

    // Get bidder details
    for (i = 0; i < numBidders; i++) {
        printf("Bidder %d\n", i+1);
        bidders[i] = createBidder();
    }

    // Conduct auction
    for (i = 0; i < numBidders; i++) {
        // Display item details for each bidder
        printf("Item details:\n");
        displayItem(item);

        // Display bidder details for each bidder
        printf("Bidder details:\n");
        displayBidder(bidders[i]);

        // Get bid from bidder
        float bid;
        printf("Enter bid: ");
        scanf("%f", &bid);
        
        // Check if bid is greater than current price and starting price
        if (bid > item.currentPrice && bid > item.startPrice) {
            item.currentPrice = bid;
            bidders[i].currentBid = bid;

            // Update winner index
            if (winnerIndex == -1 || bidders[i].currentBid > bidders[winnerIndex].currentBid) {
                winnerIndex = i;
            }
        }
    }

    // Display winner and item details
    printf("Winner:\n");
    displayBidder(bidders[winnerIndex]);
    printf("Item details:\n");
    displayItem(item);

    free(bidders);
    
    return 0;
}