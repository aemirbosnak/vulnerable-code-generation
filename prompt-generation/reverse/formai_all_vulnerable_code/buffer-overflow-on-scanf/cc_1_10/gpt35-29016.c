//FormAI DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>

// Structure for an auction with item name, current bid, bidder name and bid increment
struct Auction {
    char itemName[100];
    double currentBid;
    char bidderName[100];
    double bidIncrement;
};

int main() {
    // Declare array of 5 auctions
    struct Auction auctions[5];
    
    // Prompt user for details of all 5 auctions
    for (int i = 0; i < 5; i++) {
        printf("Enter name of item for auction %d: ", i+1);
        scanf("%s", auctions[i].itemName);
        
        printf("Enter starting bid for auction %d: ", i+1);
        scanf("%lf", &auctions[i].currentBid);
        
        printf("Enter name of bidder for auction %d: ", i+1);
        scanf("%s", auctions[i].bidderName);
        
        printf("Enter bid increment for auction %d: ", i+1);
        scanf("%lf", &auctions[i].bidIncrement);
    }
    
    // Allow bidding on all auctions, one at a time
    for (int i = 0; i < 5; i++) {
        struct Auction currentAuction = auctions[i];
        printf("Auction %d: %s. Current bid: %.2lf by %s. Bid increment: %.2lf\n", i+1, 
            currentAuction.itemName, currentAuction.currentBid, currentAuction.bidderName, 
            currentAuction.bidIncrement);
        
        // Prompt user for new bid
        double newBid;
        printf("Enter your bid: ");
        scanf("%lf", &newBid);
        
        // Check if new bid is greater than current bid, and if so, update the auction
        if (newBid > currentAuction.currentBid) {
            printf("New bid accepted!\n");
            currentAuction.currentBid = newBid;
            printf("New bid for auction %d: %.2lf by you!\n", i+1, currentAuction.currentBid);
            strcpy(currentAuction.bidderName, "You");
        } else {
            printf("Bid rejected. Please bid a higher amount.\n");
        }
        
        // Update the auctions array with the new auction details
        auctions[i] = currentAuction;
    }
    
    // Print final details of all auctions
    printf("\nFinal auction details:\n");
    for (int i = 0; i < 5; i++) {
        struct Auction currentAuction = auctions[i];
        printf("Auction %d: %s. Final bid: %.2lf by %s.\n", i+1, 
            currentAuction.itemName, currentAuction.currentBid, currentAuction.bidderName);
    }
    
    return 0;
}